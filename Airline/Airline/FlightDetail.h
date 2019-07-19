#pragma once
#include "DBConnectUtil.h"
#include "DBConnectUtil.cpp"

class FlightDetail: public DBConnectUtil<string>
{
private:
	string flightNo;
	string flightName;
	string flightFrom;
	string flightDestination;
	string flightTime;
	string flightAmount;
	string flightLeave;
	string flightArrive;
	string flightAvailable;
	bool comfirm;
public:
	void FlightSchedule();

	void AddFlight();

	int updateFlight(string flightId);

	int deleteFlight(string flightId);

	int flightLeaveArrive();
};

