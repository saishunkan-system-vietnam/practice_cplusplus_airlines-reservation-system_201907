#pragma once
#include "DBConnectUtil.h"

class FlightDetail: public DBConnectUtil
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

