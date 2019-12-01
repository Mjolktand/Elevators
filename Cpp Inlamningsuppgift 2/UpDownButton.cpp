#include "UpDownButton.h"

UpDownButton::UpDownButton(int floorNumber, Direction direction, ElevatorBay *elevatorBay) : Button(floorNumber)
{
	this->direction = direction;
	this->Elevatorbay = elevatorBay;
}

Direction UpDownButton::GetDirection() 
{
	return this->direction;
}

ElevatorBay *UpDownButton::GetElevatorBay() 
{
	return this->Elevatorbay;
}