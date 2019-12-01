#include "FloorButton.h"

FloorButton::FloorButton(int FloorNumber, Elevator &elevator) : Button(FloorNumber)
{
	this->elevator = &elevator;
}

Elevator &FloorButton::GetElevator()
{
	return *elevator;
}

int FloorButton::GetFloorNumber()
{
	return this->FloorNumber;
}