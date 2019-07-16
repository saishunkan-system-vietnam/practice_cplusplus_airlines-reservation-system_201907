#pragma once
#include "DBConnectUtil.h"

class UserReservation
{
private:
	DBConnectUtil dBConnect;
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

