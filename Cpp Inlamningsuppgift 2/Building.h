#pragma once
#include <vector>
#include "ElevatorBay.h"

using namespace std;

class Building
{
public:
	Building(int numberOfbays);

	void AddElevatorBay(ElevatorBay elevatorBay);
	ElevatorBay *GetElevatorBay(int bayNumber);

private:
	vector<ElevatorBay> ElevatorBays;
};

