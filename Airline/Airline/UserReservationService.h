#pragma once

#include "BaseService.h"
#include "ActionDB.h"
#include "UserReservation.h"

class UserReservationService : public ActionDB, public BaseService<string>
{
	public:

		void ReserveSeat();

		void UserTicket();

		void DisplayPassenger();
};

