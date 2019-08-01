#pragma once

#include <iostream>
#include <string>

using namespace std;

class FlightDetail
{
private:

	string flightId;

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

	void setFlightId(string flightId);

	string getFlightId();

	void setFlightNo(string flightNo);

	string getFlightNo();

	void setFlightName(string flightName);

	string getFlightName();

	void setFlightFrom(string flightFrom);

	string getFlightFrom();

	void setFlightDestination(string flightDestination);

	string getFlightDestination();

	void setFlightTime(string flightTime);

	string getFlightTime();

	void setFlightAmount(string flightAmount);

	string getFlightAmount();

	void setFlightLeave(string flightLeave);

	string getFlightLeave();

	void setFlightArrive(string flightArrive);

	string getFlightArrive();

	void setFlightAvailable(string flightAvailable);

	string getFlightAvailable();

	void setComfirm(bool comfirm);

	bool getComfirm();

	void input();

	void inputClone(FlightDetail flightDetailTmp);

	void inputUpdateFlightLeaveArrive(FlightDetail flightDetailTmp);

};

