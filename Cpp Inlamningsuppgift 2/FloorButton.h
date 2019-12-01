#pragma once
#include "Button.h"

class Elevator;

class FloorButton : public Button
{
public:
	FloorButton(int FloorNumber, Elevator &elevator);

	Elevator &GetElevator();
	int GetFloorNumber();

private:
	Elevator *elevator;
};

