#pragma once
#include "DBConnectUtil.h"

class UserReservation: public DBConnectUtil<string>
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
	void ReserveSeat();

	void UserTicket();

	void DisplayPassenger();
};

