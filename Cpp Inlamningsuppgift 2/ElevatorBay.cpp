#include "ElevatorBay.h"

ElevatorBay::ElevatorBay(int bayNumber)
{
	this->BayNumber = bayNumber;
}

int ElevatorBay::GetElevatorBayNumber()
{
	return this->BayNumber;
}

void ElevatorBay::AddElevators(Elevator &elevator)
{
	Elevators.push_back(elevator);
}

void ElevatorBay::AddUpDownButton(UpDownButton &upDownButton)
{
	UpDownButtons.push_back(upDownButton);
}

UpDownButton &ElevatorBay::GetUpDownButton(int floornumber, Direction direction)
{
	for (int i = 0; i < UpDownButtons.size(); i++)
	{
		if (UpDownButtons[i].GetFloorNumber() == floornumber && UpDownButtons[i].GetDirection() == direction)
		{
			return UpDownButtons[i];
		}
	}
}

vector<Elevator> &ElevatorBay::GetElevatorList()
{
	return this->Elevators;
}

void ElevatorBay::CreateAndAddElevators(ElevatorBay *elevatorBay, int numberOfElevators)
{
	for (int i = 0; i < numberOfElevators; i++)
	{
		Elevator newElevator(i + 1, elevatorBay->GetElevatorBayNumber());
		elevatorBay->AddElevators(newElevator);
	}
}

void ElevatorBay::CreateAndAddUpDownButtons(ElevatorBay *elevatorBay, int bottomFloor, int topFloor)
{
	for (int i = bottomFloor; i <= topFloor; i++)
	{
		if (i != bottomFloor)
		{
			UpDownButton newUpDownButton(i, Direction_Down, elevatorBay);
			elevatorBay->AddUpDownButton(newUpDownButton);
		}
		if (i != topFloor)
		{
			UpDownButton newUpDownButton(i, Direction_Up, elevatorBay);
			elevatorBay->AddUpDownButton(newUpDownButton);
		}
	}
}

bool ElevatorBay::CheckIfUpDownButtonExist(ElevatorBay *elevatorbay, int floorNumber, Direction direction)
{
	for (int i = 0; i < elevatorbay->UpDownButtons.size(); i++)
	{
		if (elevatorbay->UpDownButtons[i].GetFloorNumber() == floorNumber && elevatorbay->UpDownButtons[i].GetDirection() == direction)
		{
			return true;
		}
	}
	return false;
}