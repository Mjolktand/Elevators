#include "Building.h"



Building::Building(int numberOfbays)
{
	for (int i = 0; i < numberOfbays; i++)
	{
		int bayNumber = i + 1;
		ElevatorBay newElevatorBay(bayNumber);
		AddElevatorBay(newElevatorBay);
	}
}

void Building::AddElevatorBay(ElevatorBay elevatorBay)
{
	ElevatorBays.push_back(elevatorBay);
}

ElevatorBay *Building::GetElevatorBay(int bayNumber)
{
	for (int i = 0; i < ElevatorBays.size(); i++)
	{
		if (i + 1 == bayNumber)
		{
			return &ElevatorBays[i];
		}
	}
	return NULL;
}