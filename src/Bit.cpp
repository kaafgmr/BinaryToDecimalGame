#include "Bit.hpp"
#include "NoEntiendo.hpp"

Bit::Bit(float pX, float pY, float r)
{
	posX = pX;
	posY = pY;
	state = 0;
	Radius = r;
}

void Bit::Draw()
{
	NOE_DibujaDisco(posX, posY, Radius, 255 * state, 255 * state, 255 * state);
}


bool abajo = false;
bool ObtenClickIzquierdoAbajo()
{
	if (NOE_ObtenBotonRaton(NOE_BOTONRATON_PRINCIPAL) && abajo == false)
	{
		abajo = true;
		return abajo;
	}
	else if (!NOE_ObtenBotonRaton(NOE_BOTONRATON_PRINCIPAL))
	{
		abajo = false;
	}

	return false;
}

bool Bit::Collides()
{
	float leftCorner = posX - Radius;
	float rightCorner = posX + Radius;
	float upperCorner = posY - Radius;
	float bottomCorner = posY + Radius;

	if (NOE_ObtenPosicionRatonX() > leftCorner &&
		NOE_ObtenPosicionRatonX() < rightCorner &&
		NOE_ObtenPosicionRatonY() > upperCorner &&
		NOE_ObtenPosicionRatonY() < bottomCorner)
	{
		return true;
	}

	return false;
}

void Bit::Click()
{
	if (Collides() && ObtenClickIzquierdoAbajo())
	{
		state = state == 0 ? 1 : 0;
	}
}

void Bit::Update()
{
	Click();
}

float Bit::getPosX()
{
	return posX;
}

float Bit::getPosY()
{
	return posY;
}

int Bit::getState()
{
	return state;
}

Bit::~Bit()
{
	
}