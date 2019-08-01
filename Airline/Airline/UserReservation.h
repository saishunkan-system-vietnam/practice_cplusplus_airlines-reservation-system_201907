#pragma once
//#include "DBConnectUtil.h"

#include <iostream>
#include <string>

using namespace std;

class UserReservation
{
private:
	string name;
	string phone;
	string passport;
	string ticket;
	string flightNo;
	string address;
	bool comfirm;
public:

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return this->name;
	}

	void setPhone(string phone) {
		this->phone = phone;
	}

	string getPhone() {
		return this->phone;
	}

	void setPassport(string passport) {
		this->passport = passport;
	}

	string getPassport() {
		return this->passport;
	}

	void setTicket(string ticket) {
		this->ticket = ticket;
	}

	string getTicket() {
		return this->ticket;
	}

	void setFlightNo(string flightNo) {
		this->flightNo = flightNo;
	}

	string getFlightNo() {
		return this->flightNo;
	}

	void setAddress(string address) {
		this->address = address;
	}

	string getAddress() {
		return this->address;
	}

	void setComfirm(bool comfirm) {
		this->comfirm = comfirm;
	}

	bool getComfirm() {
		return this->comfirm;
	}

	void input() {
		cout << "Name: ";
		getline(cin, this->name);
		cout << "Phone: ";
		getline(cin, this->phone);
		cout << "Passport: ";
		getline(cin, this->passport);
		cout << "Ticket: ";
		getline(cin, this->ticket);
		cout << "Flight No: ";
		getline(cin, this->flightNo);
		cout << "Address: ";
		getline(cin, this->address);
	}

	void inputName() {
		getline(cin, this->name);
	}
};

