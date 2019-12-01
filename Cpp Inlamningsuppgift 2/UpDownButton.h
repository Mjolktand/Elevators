#pragma once
#include "Button.h"
#include "Direction.h"

class ElevatorBay;

class UpDownButton : public Button
{
public:
	UpDownButton(int floorNumber, Direction direction, ElevatorBay *elevatorBay);

	Direction GetDirection();
	ElevatorBay *GetElevatorBay();

private:
	Direction direction;
	ElevatorBay *Elevatorbay;
};

