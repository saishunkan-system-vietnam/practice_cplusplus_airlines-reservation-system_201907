#pragma once

#include "BaseService.h"
#include "ActionDB.h"
#include "FlightDetail.h"

class FlightDetailService: public ActionDB, public BaseService<string>
{
	public:

		void FlightSchedule();

		void AddFlight();

		int updateFlight(string flightId);

		int deleteFlight(string flightId);

		int flightLeaveArrive();

};

