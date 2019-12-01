#include "Elevator.h"


Elevator::Elevator(int elevatorNumber, int elevatorBayNumber)
{
	this->ElevatorNumber = elevatorNumber;
	this->ElevatorBayNumber = elevatorBayNumber;
	this->SetCurrentMovement(Direction_Still);
}

int Elevator::GetElevatorNumber()
{
	return this->ElevatorNumber;
}
int Elevator::GetElevatorBayNumber() 
{
	return this->ElevatorBayNumber;
}

void Elevator::AddFloorButton(FloorButton floorButton)
{
	FloorButtons.push_back(floorButton);
}

void Elevator::SetCurrentFloor(int floor)
{
	this->CurrentFloor = floor;
}

int Elevator::GetCurrentFloor()
{
	return this->CurrentFloor;
}

void Elevator::SetCurrentMovement(Direction direction)
{
	this->CurrentMovement = direction;
}

Direction Elevator::GetCurrentMovement()
{
	return this->CurrentMovement;
}

FloorButton &Elevator::GetFloorButton(int floorNumber)
{
	for (int i = 0; i < FloorButtons.size(); i++)
	{
		if (FloorButtons[i].GetFloorNumber() == floorNumber)
		{
			return FloorButtons[i];
		}
	}
}

void Elevator::CreateAndAddFloorButtons(Elevator &elevator, int bottomFloor, int topFloor)
{
	for (int i = bottomFloor; i <= topFloor; i++)
	{
		FloorButton newFloorButton(i, elevator);
		elevator.AddFloorButton(newFloorButton);
	}
}