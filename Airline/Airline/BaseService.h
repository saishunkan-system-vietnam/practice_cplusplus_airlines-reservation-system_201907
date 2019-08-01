#pragma once

template <class T>
class BaseService 
{
public:

	virtual void ReserveSeat() {};

	virtual void UserTicket() {};

	virtual void DisplayPassenger() {};

	virtual void FlightSchedule() {};

	virtual void AddFlight() {};

	virtual int updateFlight(T flightId) {};

	virtual int deleteFlight(T flightId) {};

	virtual int flightLeaveArrive() { return -1; };
};
