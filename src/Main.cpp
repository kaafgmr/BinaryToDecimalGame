#include "NoEntiendo.hpp"
#include "Bit.hpp"
#include "DtBABtD.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

std::vector<Bit*> CreateBits(int size, int amount)
{
	std::vector<Bit*> bytes;

	for (int x = 0; x < amount; x++)
	{
		float increment = NOE_ObtenAnchoPantalla() / amount;

		bytes.push_back(new Bit(increment * 0.5f + x * increment, NOE_ObtenAltoPantalla() * 0.5f, size/(amount*0.3f)));
	}

	return bytes;
}

void main()
{
	NOE_Inicia();
	
	char DecimalNumber[100];
	int numberOfBits = 8;
	int bitSize = 100;
	std::vector<Bit*> bitsList;

	bitsList = CreateBits(bitSize, numberOfBits);

	while(!NOE_ObtenTeclaPulsada(NOE_TECLA_ESCAPE))
	{
		NOE_Actualiza();
		std::vector<int> states;

		if (NOE_ObtenTeclaAbajo(NOE_TECLA_W))
		{
			numberOfBits++;
			if (numberOfBits >= 8)
			{
				numberOfBits = 8;
			}
			bitsList = CreateBits(bitSize, numberOfBits);
		}
		else if (NOE_ObtenTeclaAbajo(NOE_TECLA_S))
		{
			numberOfBits--;
			if (numberOfBits <= 0)
			{
				numberOfBits = 1;
			}
			bitsList = CreateBits(bitSize, numberOfBits);
		}

		for (int i = 0; i < numberOfBits; i++)
		{
			bitsList[i]->Update();
			states.push_back(bitsList[i]->getState());
		}

		//set the text value
		int BinaryNumber = VectorToInt(states);
		sprintf(DecimalNumber, "%d", BinaryToDecimal(BinaryNumber));

		NOE_LimpiaPantalla(255 / 2, 255 / 2, 255 / 2);

		for (int i = 0; i < numberOfBits; i++)
		{
			bitsList[i]->Draw();
		}

		//draws the text
		NOE_DibujaTexto(DecimalNumber, 20, 600, 100, 100, 0);

		NOE_MuestraPantalla();
	}
	
	NOE_Finaliza();
}