#include "UserReservationService.h"

void UserReservationService::ReserveSeat()
{
	bool comfirm = false;
	UserReservation userReservation;
	cout << "----Input information passenger and Flights---" << endl;
	userReservation.input();
	cout << "Are you sure you want to add passengers to the flight ? ";
	cin >> comfirm;
	if (comfirm) {
		string insert_query = "INSERT INTO userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) VALUES ('" + userReservation.getName() + "','" + userReservation.getPhone() + "','" + userReservation.getPassport() + "','" + userReservation.getTicket() + "','" + userReservation.getFlightNo() + "','" + userReservation.getAddress() + "')";
		execute(insert_query);
	}
	else {
		cout << "Error handle";
	}
}

void UserReservationService::UserTicket()
{
	MYSQL_ROW row;
	UserReservation userReservation;
	cout << "----Search ticket by name---" << endl;
	cout << "Search with Name: ";
	userReservation.inputName();
	string findbyname_query = "SELECT * FROM userreservation_tb WHERE u_name like '%" + userReservation.getName() + "%'";
	res = select(findbyname_query);
	while ((row = mysql_fetch_row(res)))
	{
		cout << "Ticket No.: " << row[4] << "\nUser Name: " << row[1] << "\nUser Phone No.: " << row[2] << "\nUser Passport: " << row[3] << "\nFlight No.: " << row[5] << "\nUser Address: " << row[6] << endl << endl;
	}
}

void UserReservationService::DisplayPassenger()
{
	MYSQL_ROW row;
	string query = "SELECT * FROM userreservation_tb";
	res = select(query);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "User Name.", "User Phone", "User Passport", "Ticket", "Flight No", "User Address");
	while ((row = mysql_fetch_row(res))) {
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
}
