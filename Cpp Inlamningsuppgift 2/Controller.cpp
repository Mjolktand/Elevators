#include "Controller.h"
#include "Elevator.h"
#include "ElevatorBay.h"
#include "Building.h"
#include <iostream>

void Controller::SetArrived(Elevator *elevator, ElevatorBay *elevatorBay)
{
	elevator->GetFloorButton(elevator->GetCurrentFloor()).SetIsOn(false);
	if (elevatorBay->CheckIfUpDownButtonExist(elevatorBay, elevator->GetCurrentFloor(), elevator->GetCurrentMovement()))
	{
		elevatorBay->GetUpDownButton(elevator->GetCurrentFloor(), elevator->GetCurrentMovement()).SetIsOn(false);
	}
	elevator->SetCurrentMovement(Direction_Still);
}

void Controller::SendElevator(Elevator *elevator, int floorNumber)
{
	int currentfloor = elevator->GetCurrentFloor();
	if (currentfloor > floorNumber)
	{
		elevator->SetCurrentMovement(Direction_Down);
		for (int i = currentfloor - 1; i >= floorNumber; i--)
		{
			elevator->SetCurrentFloor(i);
		}
	}
	else if (currentfloor < floorNumber)
	{
		elevator->SetCurrentMovement(Direction_Up);
		for (int i = currentfloor + 1; i <= floorNumber; i++)
		{
			elevator->SetCurrentFloor(i);
		}
	}
}

void Controller::PushFloorButton(Elevator *elevator, int floorNumber)
{
	elevator->GetFloorButton(floorNumber).SetIsOn(true);
}

Elevator *Controller::FindElevator(ElevatorBay *elevatorBay, int floorNumber, Direction direction)
{
	int floorDiff = 0;
	while (true)
	{
		for (int i = 0; i < elevatorBay->GetElevatorList().size(); i++)
		{
			if ((floorDiff == elevatorBay->GetElevatorList()[i].GetCurrentFloor() - floorNumber ||
				floorDiff == floorNumber - elevatorBay->GetElevatorList()[i].GetCurrentFloor()) &&
				elevatorBay->GetElevatorList()[i].GetCurrentMovement() == Direction_Still)
			{
				return &elevatorBay->GetElevatorList()[i];
			}
		}
		floorDiff++;
	}
}

void Controller::PushUpDownButton(ElevatorBay *elevatorBay, int floorNumber, Direction direction)
{
	if (elevatorBay->CheckIfUpDownButtonExist(elevatorBay, floorNumber, direction))
	{ 
		elevatorBay->GetUpDownButton(floorNumber, direction).SetIsOn(true);
	}
}

void Controller::TestMasterFunction(Building *building)
{
	int elevatorBayNumber, floorNumber;
	Direction direction;
	char directionChoice;
	std::cout << endl << "Testing stuff." << endl << "------------------" <<endl;
	std::cout << endl << "Enter baynumber: ";
	std::cin >> elevatorBayNumber;
	std::cout << endl << "Enter floornumber: ";
	std::cin >> floorNumber;
	std::cout << endl << "Enter direction (u for up/d for down): ";
	std::cin >> directionChoice;
	if (directionChoice = 'u')
	{
		direction = Direction_Up;
	}
	if (directionChoice = 'd')
	{
		direction = Direction_Down;
	}
	ElevatorBay *elevatorBay = building->GetElevatorBay(elevatorBayNumber);
	PushUpDownButton(elevatorBay, floorNumber, direction);
	Elevator *chosenElevator = FindElevator(elevatorBay, floorNumber, direction);
	SendElevator(chosenElevator, floorNumber);
	SetArrived(chosenElevator, elevatorBay);
	int floorRequest;
	std::cout << endl << "PLING! you can now enter the floor destination: ";
	std::cin >> floorRequest;
	PushFloorButton(chosenElevator, floorRequest);
	SendElevator(chosenElevator, floorRequest);
	SetArrived(chosenElevator, elevatorBay);
	std::cout << endl << "PLING! You have arrived at floor " << chosenElevator->GetCurrentFloor();
}