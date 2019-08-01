#pragma once

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

	void setName(string name);

	string getName();

	void setPhone(string phone);

	string getPhone();

	void setPassport(string passport);

	string getPassport();

	void setTicket(string ticket);

	string getTicket();

	void setFlightNo(string flightNo);

	string getFlightNo();

	void setAddress(string address);

	string getAddress();

	void setComfirm(bool comfirm);

	bool getComfirm();

	void input();

	void inputName();
};

