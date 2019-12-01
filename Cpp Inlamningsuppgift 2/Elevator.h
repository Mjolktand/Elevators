#pragma once
#include "Direction.h"
#include "FloorButton.h"
#include <vector>
using namespace std;

class Elevator
{
public:
	Elevator(int elevatorNumber, int elevatorBayNumber);

	int GetElevatorNumber();
	int GetElevatorBayNumber();
	void AddFloorButton(FloorButton floorbutton);
	void SetCurrentFloor(int floor);
	int GetCurrentFloor();
	void SetCurrentMovement(Direction direction);
	Direction GetCurrentMovement();
	FloorButton &GetFloorButton(int floorNumber);
	void CreateAndAddFloorButtons(Elevator &elevator, int bottomFloor, int topFloor);

private:
	int ElevatorNumber;
	int ElevatorBayNumber;
	vector<FloorButton> FloorButtons;
	int CurrentFloor;
	Direction CurrentMovement;
};

