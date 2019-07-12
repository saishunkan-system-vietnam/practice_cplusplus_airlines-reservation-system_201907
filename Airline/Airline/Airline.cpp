// Airline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <mysql.h>
#include <string>
#include <windows.h>



using namespace std;

void ReserveSeat();
void UserTicket();
void FlightSchedule();
void DisplayPassenger();
void SelectFunctionSubMenu(int);

int qstate;
MYSQL_ROW row;
MYSQL_RES* res;


struct ConnectProperties
{
	const char* HOST = "localhost";
	const int PORT = 3306;
	const char* USER_NAME = "root";
	const char* PASSWORD = "hungphuc";
	const char* DB_NAME = "cpp_airlinereservation_db";
};

class DBConnect {
	private:
		MYSQL* conn;
		ConnectProperties property;
	public:
		MYSQL* getConnnect() {
			return this->conn;
		}

		void init() {
			this->conn = mysql_init(0);
			this->conn = mysql_real_connect(conn, property.HOST, property.USER_NAME, property.PASSWORD,property.DB_NAME, property.PORT,NULL,0);
			if (!conn) {
				cout << "Error connect";
				exit(1);
			}
			/*else {
				cout << "Error connect";
			}*/
		}

		void addNew(string array[], int size) {
			/*for (int i = 0; i < size; i++) {
				cout << array[i] << endl;
			}*/
		}
		
};

class UserReservation {
	private:
		DBConnect dBConnect;
		string name;
		string phone;
		string passport;
		string ticket;
		string flightNo;
		string address;
		bool comfirm;
	public:
		DBConnect getDBConnect() {
			return this->dBConnect;
		}
	void ReserveSeat() {
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
		cin>>comfirm;
		if (comfirm) {
			dBConnect.init();
			string insert_query = "INSERT INTO userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) VALUES ('" + name + "','" + phone + "','" + passport + "','" + ticket + "','" + flightNo + "','" + address + "')";

			const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

			qstate = mysql_query(dBConnect.getConnnect(), q);

			if (!qstate)
			{
				cout << endl << "Successfully added in database." << endl;
			}
			else
			{
				cout << "Insert error";
			}
		}
		else {
			cout << "Error handle";
		}
	}

	void UserTicket() {
		cout << "----Search ticket by name---" << endl;
		cout << "Search with Name: ";
		getline(cin, this->name);
		dBConnect.init();
		string findbyname_query = "SELECT * FROM userreservation_tb WHERE u_name like '%" + name + "%'";
		const char* q = findbyname_query.c_str();
		qstate = mysql_query(dBConnect.getConnnect(), q);

		cout << endl;
		cout << "Showing Ticket of " << name << endl << endl;
		if (!qstate)
		{
			res = mysql_store_result(dBConnect.getConnnect());
			while ((row = mysql_fetch_row(res)))
			{
				cout << "Ticket No.: " << row[4] << "\nUser Name: " << row[1] << "\nUser Phone No.: " << row[2] << "\nUser Passport: " << row[3] << "\nFlight No.: " << row[5] << "\nUser Address: " << row[6] << endl << endl;
			}
		}
		else
		{
			cout << "Query Execution Problem!" << mysql_errno(dBConnect.getConnnect()) << endl;
		}

	}

	void DisplayPassenger() {
		dBConnect.init();
		string query = "SELECT * FROM userreservation_tb";
		const char* q = query.c_str();
		qstate = mysql_query(dBConnect.getConnnect(), q);

		cout << endl;
		cout << "-------Display Passenger-----------" << endl << endl;
		if (!qstate)
		{
			res = mysql_store_result(dBConnect.getConnnect());
			printf("-------------------------------------------------------------------------------------------------------------\n");
			printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "User Name.", "User Phone", "User Passport", "Ticket", "Flight No","User Address");
			while ((row = mysql_fetch_row(res)))
			{
				printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
			}
			printf("------------------------------------------------------------------------------------------------------------\n");
		}
		else
		{
			cout << "Query Execution Problem!" << mysql_errno(dBConnect.getConnnect()) << endl;
		}
	}
};

class FlightDetail {
	private:
		DBConnect dBConnect;
		string flightNo;
		string flightName;
		string flightDestination;
		string flightTime;
		string flightAmount;
		string flightLeave;
		string flightArrive;
		string flightAvailable;
	public:
		void FlightSchedule() {
			dBConnect.init();
			string query = "SELECT * FROM flightdetails_tb";
			const char* q = query.c_str();
			qstate = mysql_query(dBConnect.getConnnect(), q);

			cout << endl;
			cout << "-------Flight Schedule-----------"<< endl << endl;
			if (!qstate)
			{
				res = mysql_store_result(dBConnect.getConnnect());
				printf("-------------------------------------------------------------------------------------------\n");
				printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
				while ((row = mysql_fetch_row(res)))
				{
					printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[3], row[4], row[7], row[8]);
				}
				printf("-------------------------------------------------------------------------------------------\n");
			}
			else
			{
				cout << "Query Execution Problem!" << mysql_errno(dBConnect.getConnnect()) << endl;
			}
		}
};

void Menu() {
	cout << "------------------MENU-----------------" << endl;
	cout << "1. Reserve Seat" << endl;
	cout << "2. User Ticket" << endl;
	cout << "3.	Flights Schedule" << endl;
	cout << "4. Display Passenger" << endl;
	cout << "5. Flight Details" << endl;
	cout << "6.	Exits" << endl;
	cout << "------------------END-----------------" << endl;
}

void subMenu() {
	cout << "------------------FLIGHT DETAILS-----------------" << endl;
	cout << "1. Add Flight" << endl;
	cout << "2. Edit Flight" << endl;
	cout << "3.	Delete Flight" << endl;
	cout << "4. Flight Leave And Arrive" << endl;
	cout << "5.	Back To Menu" << endl;
	cout << "------------------END-----------------" << endl;
}

void BackToMenu(int &tmp) {
	label:cout << "Input 99 for Back to menu: ";
	cin >> tmp;
	if (tmp == 99) {
		system("cls");
		Menu();
		tmp = 0;
	}
	else {
		goto label;
	}
	
}

void SelectFunction(int n) {
	int tmp;
	int sub;
	switch (n)
	{
	case 1:
		ReserveSeat();
		Sleep(1000);
		system("cls");
		Menu();
		break;
	case 2:
		UserTicket();
		BackToMenu(tmp);
		break;
	case 3:
		FlightSchedule();
		BackToMenu(tmp);
		break;
	case 4:
		DisplayPassenger();
		BackToMenu(tmp);
		break;
	case 5:
		action:system("cls");
		subMenu();
		input:cout << "Select function in menu: ";
			cin >> sub;
			if (sub >=1 || sub <= 5) {
				if (sub == 5) {
					system("cls");
					Menu();
				}
				else {
					SelectFunctionSubMenu(sub);
					goto action;
				}
			}
			else {
				goto input;
			}
		break;
	case 6:
		cout << "case 6";
		break;
	default:
		break;
	}
}

void SelectFunctionSubMenu(int n) {
	int tmp;
	switch (n)
	{
	case 1:
		cout << "OK";
		Sleep(3000);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
}

void ReserveSeat() {
	UserReservation user;
	user.ReserveSeat();
}

void UserTicket() {
	UserReservation user;
	user.UserTicket();
}

void FlightSchedule() {
	FlightDetail flightDetail;
	flightDetail.FlightSchedule();
}

void DisplayPassenger() {
	UserReservation user;
	user.DisplayPassenger();
}

int main()
{
	int n;
	Menu();
	do {
		cout << "Number function: ";
		input:cin >> n;
		if (n < 1 || n>6) {
			cout << "Error" << endl;
			cout << "Please choose function number in menu: ";
			goto input;
		}
		else {
			cin.ignore(INT64_MAX, '\n');
			SelectFunction(n);
		}
	} while (n);
}
