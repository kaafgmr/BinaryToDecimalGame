#include "DtBABtD.hpp"
#include <math.h>

int VectorToInt(std::vector<int> V)
{
	int integer = 0;

	for (int i = 0; i < V.size(); i++)
	{
		integer += V[i] * pow(10, V.size() - 1 - i);
	}

	return integer;
}

std::vector<int> IntToVector(int integer)
{
	std::vector<int> V;
	
	while (integer > 0)
	{
		int Remainder = integer % 10;
		integer = integer / 10;
		V.push_back(Remainder);
	}

	std::reverse(V.begin(), V.end());

	return V;
}

int DecimalToBinary(int d) 
{
	std::vector<int> BN;
	int BinaryNumber = d;

	while (BinaryNumber > 0)
	{
		int Remainder = BinaryNumber % 2;
		BinaryNumber /= 2;
		BN.push_back(Remainder);
	}

	std::reverse(BN.begin(), BN.end());

	BinaryNumber = VectorToInt(BN);

	return BinaryNumber;
}

int BinaryToDecimal(int b)
{
	std::vector<int> BinaryNumber;
	int Decimal = 0;

	BinaryNumber = IntToVector(b);

	std::reverse(BinaryNumber.begin(), BinaryNumber.end());

	for (int i = 0; i < BinaryNumber.size(); i++)
	{
		Decimal = Decimal + BinaryNumber[i] * pow(2, i);
	}

	return Decimal;
}