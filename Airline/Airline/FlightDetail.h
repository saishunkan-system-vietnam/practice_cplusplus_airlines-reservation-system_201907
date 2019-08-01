#pragma once
//#include "DBConnectUtil.h"
//#include "DBConnectUtil.cpp"

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

	void setFlightId(string flightId) {
		this->flightId = flightId;
	}

	string getFlightId() {
		return this->flightId;
	}

	void setFlightNo(string flightNo) {
		this->flightNo = flightNo;
	}

	string getFlightNo() {
		return this->flightNo;
	}

	void setFlightName(string flightName) {
		this->flightName = flightName;
	}

	string getFlightName() {
		return this->flightName;
	}

	void setFlightFrom(string flightFrom) {
		this->flightFrom = flightFrom;
	}

	string getFlightFrom() {
		return this->flightFrom;
	}

	void setFlightDestination(string flightDestination) {
		this->flightDestination = flightDestination;
	}

	string getFlightDestination() {
		return this->flightDestination;
	}

	void setFlightTime(string flightTime) {
		this->flightTime = flightTime;
	}

	string getFlightTime() {
		return this->flightTime;
	}

	void setFlightAmount(string flightAmount) {
		this->flightAmount = flightAmount;
	}

	string getFlightAmount() {
		return this->flightAmount;
	}

	void setFlightLeave(string flightLeave) {
		this->flightLeave = flightLeave;
	}

	string getFlightLeave() {
		return this->flightLeave;
	}

	void setFlightArrive(string flightArrive) {
		this->flightArrive = flightArrive;
	}

	string getFlightArrive() {
		return this->flightArrive;
	}

	void setFlightAvailable(string flightAvailable) {
		this->flightAvailable = flightAvailable;
	}

	string getFlightAvailable() {
		return this->flightAvailable;
	}

	void setComfirm(bool comfirm) {
		this->comfirm = comfirm;
	}

	bool getComfirm() {
		return this->comfirm;
	}

	void input() {
		cout << "No: ";
		getline(cin, this->flightNo);
		cout << "Flight Name: ";
		getline(cin, this->flightName);
		cout << "Flight From: ";
		getline(cin, this->flightFrom);
		cout << "Flight Destination: ";
		getline(cin, this->flightDestination);
		cout << "Flight Time: ";
		getline(cin, this->flightTime);
		cout << "Flight Amount: ";
		getline(cin, this->flightAmount);
		cout << "Flight Leave: ";
		getline(cin, this->flightLeave);
		cout << "Flight Arrive: ";
		getline(cin, this->flightArrive);
		cout << "Flight Avaiable: ";
		getline(cin, this->flightAvailable);
	}

	void inputClone(FlightDetail flightDetailTmp) {

		if (flightDetailTmp.getFlightId() != "") {
			this->flightId = flightDetailTmp.getFlightId();
		}

		cout << "No (input x if field don't need update): ";
		getline(cin, this->flightNo);
		if (flightNo == "x") {
			this->flightNo = flightDetailTmp.getFlightNo();
		}
		cout << "Flight Name (input x if field don't need update): ";
		getline(cin, this->flightName);
		if (flightName == "x") {
			this->flightName = flightDetailTmp.getFlightName();
		}
		cout << "Flight From (input x if field don't need update): ";
		getline(cin, this->flightFrom);
		if (flightFrom == "x") {
			this->flightFrom = flightDetailTmp.getFlightFrom();
		}
		cout << "Flight Destination (input x if field don't need update): ";
		getline(cin, this->flightDestination);
		if (flightDestination == "x") {
			this->flightDestination = flightDetailTmp.getFlightDestination();
		}
		cout << "Flight Time (input x if field don't need update): ";
		getline(cin, this->flightTime);
		if (flightTime == "x") {
			this->flightTime = flightDetailTmp.getFlightTime();
		}
		cout << "Flight Amount (input x if field don't need update): ";
		getline(cin, this->flightAmount);
		if (flightAmount == "x") {
			this->flightAmount = flightDetailTmp.getFlightAmount();
		}
		cout << "Flight Leave (input x if field don't need update): ";
		getline(cin, this->flightLeave);
		if (flightLeave == "x") {
			this->flightLeave = flightDetailTmp.getFlightLeave();
		}
		cout << "Flight Arrive (input x if field don't need update): ";
		getline(cin, this->flightArrive);
		if (flightArrive == "x") {
			this->flightArrive = flightDetailTmp.getFlightArrive();
		}
		cout << "Flight Avaiable (input x if field don't need update): ";
		getline(cin, this->flightAvailable);
		if (flightAvailable == "x") {
			this->flightAvailable = flightDetailTmp.getFlightAvailable();
		}
	}

	void inputUpdateFlightLeaveArrive(FlightDetail flightDetailTmp) {
		cin.ignore(INT64_MAX, '\n');
		cout << "Change Flight Leave (input x to not change): ";
		getline(cin, this->flightLeave);
		if (flightLeave == "x") {
			this->flightLeave = flightDetailTmp.getFlightLeave();
		}
		cout << "Change Flight Arrive (input x to not change): ";
		getline(cin, this->flightArrive);
		if (flightArrive == "x") {
			this->flightArrive = flightDetailTmp.getFlightArrive();
		}
		cout << "Change Flight Available (input x to not change): ";
		getline(cin, this->flightAvailable);
		if (flightAvailable == "x") {
			this->flightAvailable = flightDetailTmp.getFlightAvailable();
		}
	}

};

