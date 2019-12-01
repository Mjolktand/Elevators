#include "Button.h"

Button::Button(int floorNumber)
{
    this->FloorNumber = floorNumber;
	SetIsOn(false);
}

bool Button::GetIsOn()
{
	return this->IsOn;
}

int Button::GetFloorNumber()
{
	return this->FloorNumber;
}

void Button::SetIsOn(bool Bool)
{
	this->IsOn = Bool;
}