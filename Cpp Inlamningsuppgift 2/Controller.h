#pragma once
#include "Direction.h"

class Elevator;
class ElevatorBay;
class Building;

class Controller
{
public:
	void SetArrived(Elevator *elevator, ElevatorBay *elevatorBay);
	void SendElevator(Elevator *elevator, int floorNumber);
	void PushFloorButton(Elevator *elevator, int floorNumber);
	Elevator *FindElevator(ElevatorBay *elevatorBay, int floorNumber, Direction direction);
	void PushUpDownButton(ElevatorBay *elevatorBay, int floorNumber, Direction direction);
	void TestMasterFunction(Building *building);
	
private:
	Building *building;
};

