#include "FlightDetail.h"

void FlightDetail::setFlightId(string flightId) {
	this->flightId = flightId;
}

string FlightDetail::getFlightId() {
	return this->flightId;
}

void FlightDetail::setFlightNo(string flightNo) {
	this->flightNo = flightNo;
}

string FlightDetail::getFlightNo() {
	return this->flightNo;
}

void FlightDetail::setFlightName(string flightName) {
	this->flightName = flightName;
}

string FlightDetail::getFlightName() {
	return this->flightName;
}

void FlightDetail::setFlightFrom(string flightFrom) {
	this->flightFrom = flightFrom;
}

string FlightDetail::getFlightFrom() {
	return this->flightFrom;
}

void FlightDetail::setFlightDestination(string flightDestination) {
	this->flightDestination = flightDestination;
}

string FlightDetail::getFlightDestination() {
	return this->flightDestination;
}

void FlightDetail::setFlightTime(string flightTime) {
	this->flightTime = flightTime;
}

string FlightDetail::getFlightTime() {
	return this->flightTime;
}

void FlightDetail::setFlightAmount(string flightAmount) {
	this->flightAmount = flightAmount;
}

string FlightDetail::getFlightAmount() {
	return this->flightAmount;
}

void FlightDetail::setFlightLeave(string flightLeave) {
	this->flightLeave = flightLeave;
}

string FlightDetail::getFlightLeave() {
	return this->flightLeave;
}

void FlightDetail::setFlightArrive(string flightArrive) {
	this->flightArrive = flightArrive;
}

string FlightDetail::getFlightArrive() {
	return this->flightArrive;
}

void FlightDetail::setFlightAvailable(string flightAvailable) {
	this->flightAvailable = flightAvailable;
}

string FlightDetail::getFlightAvailable() {
	return this->flightAvailable;
}

void FlightDetail::setComfirm(bool comfirm) {
	this->comfirm = comfirm;
}

bool FlightDetail::getComfirm() {
	return this->comfirm;
}

void FlightDetail::input() {
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

void FlightDetail::inputClone(FlightDetail flightDetailTmp) {

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

void FlightDetail::inputUpdateFlightLeaveArrive(FlightDetail flightDetailTmp) {
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