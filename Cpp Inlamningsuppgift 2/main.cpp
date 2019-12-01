#include "Controller.h"
#include "Elevator.h"
#include "Building.h"
#include <iostream>

//Not a properly written function! But a working and easy way to create a test building.
Building CreatorOfEverything()
{
	int numberOfBays, bottomFloor, topFloor, numberOfElevators;
	cout << "Creater of everything." << endl << "--------------------" << endl;
	cout << endl << "Enter Number of elevator bays: ";
	cin >> numberOfBays;
	Building newBuilding(numberOfBays);
	for (int i = 0; i < numberOfBays; i++)
	{
		cout << endl << "Enter bottom floor number for bay " << i + 1 << ": ";
		cin >> bottomFloor;
		cout << endl << "Enter top floor number for bay " << i + 1 << ": ";
		cin >> topFloor;
		newBuilding.GetElevatorBay(i + 1)->CreateAndAddUpDownButtons(newBuilding.GetElevatorBay(i + 1), bottomFloor, topFloor);
		cout << endl << "Enter number of elevators for bay " << i + 1 << ": ";
		cin >> numberOfElevators;
		newBuilding.GetElevatorBay(i + 1)->CreateAndAddElevators(newBuilding.GetElevatorBay(i + 1), numberOfElevators);
		for (int k = 0; k < numberOfElevators; k++)
			newBuilding.GetElevatorBay(i + 1)->GetElevatorList()[k].CreateAndAddFloorButtons(newBuilding.GetElevatorBay(i + 1)->
				GetElevatorList()[k], bottomFloor, topFloor);
	}
	return newBuilding;
}

int main()
{
	Building building = CreatorOfEverything();
	Controller controller;
	controller.TestMasterFunction(&building);
	controller.TestMasterFunction(&building);
	controller.TestMasterFunction(&building);
	controller.TestMasterFunction(&building);
	controller.TestMasterFunction(&building);
	controller.TestMasterFunction(&building);

	system("pause");
	return 0;
}