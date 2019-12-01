#pragma once
#include <vector>
#include "Elevator.h"
#include "UpDownButton.h"

using namespace std;

class ElevatorBay
{
public:
	ElevatorBay(int bayNumber);

	int GetElevatorBayNumber();
	void AddElevators(Elevator &elevator);
	void AddUpDownButton(UpDownButton &upDownButton);
	UpDownButton &GetUpDownButton(int floornumber, Direction direction);
	vector<Elevator> &GetElevatorList();
	void CreateAndAddElevators(ElevatorBay *elevatorBay, int numberOfElevators);
	void CreateAndAddUpDownButtons(ElevatorBay *elevatorBay, int bottomFloor, int topFloor);
	bool CheckIfUpDownButtonExist(ElevatorBay *elevatorbay, int floorNumber, Direction direction);

private:
	vector<Elevator> Elevators;
	int BayNumber;
	vector<UpDownButton> UpDownButtons;
};

