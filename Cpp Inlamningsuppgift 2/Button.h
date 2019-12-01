#pragma once
class Button
{
public:
    Button(int floorNumber);
	
	bool GetIsOn();
	int GetFloorNumber();
	void SetIsOn(bool Bool);

protected:
	int FloorNumber;
	bool IsOn;
};
