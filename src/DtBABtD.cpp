#include "DtBABtD.hpp"
#include <math.h>
#include <stdio.h>
#include <vector>

int DecimalToBinary(int d) 
{
	int DN = d;
	std::vector<int> BN;
	int BinaryNumber = 0;

	while (DN != 0)
	{
		int Remainder = DN % 2;
		DN = DN / 2;
		BN.push_back(Remainder);
	}

	std::reverse(BN.begin(), BN.end());

	for (int i = 0; i < BN.size(); i++)
	{
		BinaryNumber += BN[i] * pow(10, BN.size() - 1 - i);
	}

	return BinaryNumber;
}

int BinaryToDecimal(int b)
{
	std::vector<int> BinaryNumber;

	while (b > 0)
	{
		int Remainder = b % 10;
		BinaryNumber.push_back(Remainder);
		b /= 10;
	}
	std::reverse(BinaryNumber.begin(), BinaryNumber.end());

	int sum = 0;

	for (int i = 0; i < BinaryNumber.size(); i++)
	{
		std::vector<int> bit;
		bit.push_back(BinaryNumber[BinaryNumber.size() - 1 - i]);
		sum += bit[0] * pow(2, i);
	}

	return sum;
}