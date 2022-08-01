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
	
	while (integer != 0)
	{
		int Remainder = integer % 2;
		integer = integer / 2;
		V.push_back(Remainder);
	}

	return V;
}

int DecimalToBinary(int d) 
{
	std::vector<int> BN;
	int BinaryNumber = 0;

	BN = IntToVector(d);

	std::reverse(BN.begin(), BN.end());

	BinaryNumber = VectorToInt(BN);

	return BinaryNumber;
}

int BinaryToDecimal(int b)
{
	std::vector<int> BinaryNumber;

	BinaryNumber = IntToVector(b);

	std::reverse(BinaryNumber.begin(), BinaryNumber.end());

	int Decimal = VectorToInt(BinaryNumber);

	return Decimal;
}