#include "UserReservation.h"


void UserReservation::ReserveSeat()
{
	cout << "----Input information passenger and Flights---" << endl;
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
	cout << "Are you sure you want to add passengers to the flight ? ";
	cin >> comfirm;
	if (comfirm) {
		string insert_query = "INSERT INTO userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) VALUES ('" + name + "','" + phone + "','" + passport + "','" + ticket + "','" + flightNo + "','" + address + "')";
		execute(insert_query);
	}
	else {
		cout << "Error handle";
	}
}

void UserReservation::UserTicket()
{
	cout << "----Search ticket by name---" << endl;
	cout << "Search with Name: ";
	getline(cin, this->name);
	string findbyname_query = "SELECT * FROM userreservation_tb WHERE u_name like '%" + name + "%'";
	res = select(findbyname_query, "Result of search for keyword '" + name + "'");
	while ((row = mysql_fetch_row(res)))
	{
		cout << "Ticket No.: " << row[4] << "\nUser Name: " << row[1] << "\nUser Phone No.: " << row[2] << "\nUser Passport: " << row[3] << "\nFlight No.: " << row[5] << "\nUser Address: " << row[6] << endl << endl;
	}
}

void UserReservation::DisplayPassenger()
{
	string query = "SELECT * FROM userreservation_tb";
	res = select(query, "--- Display Passenger ---");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "User Name.", "User Phone", "User Passport", "Ticket", "Flight No", "User Address");
	while ((row = mysql_fetch_row(res))) {
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
}
