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
void AddFlight();
int UpdateFlight(string);
int DeleteFlight(string);
int FlightLeaveArrive();

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
		this->conn = mysql_real_connect(conn, property.HOST, property.USER_NAME, property.PASSWORD, property.DB_NAME, property.PORT, NULL, 0);
		if (!conn) {
			cout << "Error connect";
			exit(1);
		}
		/*else {
			cout << "Error connect";
		}*/
	}

	void addNew(string sql) {
		init();
		string insert_query = sql;

		const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

		qstate = mysql_query(getConnnect(), q);

		if (!qstate)
		{
			cout << endl << "Successfully added in database." << endl;
		}
		else
		{
			cout << "Insert error";
		}
	}

	void update(string sql) {
		string insert_query = sql;

		const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

		qstate = mysql_query(getConnnect(), q);

		if (!qstate)
		{
			cout << "Successfully updated in database." << endl;
		}
		else
		{
			cout << "Update error";
		}
	}

	MYSQL_RES* select(string sql, string title = "") {
		string query = sql;
		const char* q = query.c_str();
		qstate = mysql_query(getConnnect(), q);

		cout << endl;
		cout << title << endl;
		if (!qstate)
		{
			res = mysql_store_result(getConnnect());
			return res;
		}
		else
		{
			cout << "Query Execution Problem!" << mysql_errno(getConnnect()) << endl;
		}
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
		cin >> comfirm;
		if (comfirm) {
			string insert_query = "INSERT INTO userreservation_tb (u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address) VALUES ('" + name + "','" + phone + "','" + passport + "','" + ticket + "','" + flightNo + "','" + address + "')";
			dBConnect.addNew(insert_query);
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
		res = dBConnect.select(findbyname_query, "Result of search for keyword '" + name + "'");
		while ((row = mysql_fetch_row(res)))
		{
			cout << "Ticket No.: " << row[4] << "\nUser Name: " << row[1] << "\nUser Phone No.: " << row[2] << "\nUser Passport: " << row[3] << "\nFlight No.: " << row[5] << "\nUser Address: " << row[6] << endl << endl;
		}
	}

	void DisplayPassenger() {
		dBConnect.init();
		string query = "SELECT * FROM userreservation_tb";
		res = dBConnect.select(query, "--- Display Passenger ---");
		printf("-------------------------------------------------------------------------------------------------------------\n");
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "User Name.", "User Phone", "User Passport", "Ticket", "Flight No", "User Address");
		while ((row = mysql_fetch_row(res))) {
			printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[2], row[3], row[4], row[5], row[6]);
		}
		printf("------------------------------------------------------------------------------------------------------------\n");
	}
};

class FlightDetail {
private:
	DBConnect dBConnect;
	string flightNo;
	string flightName;
	string flightFrom;
	string flightDestination;
	string flightTime;
	string flightAmount;
	string flightLeave;
	string flightArrive;
	string flightAvailable;
	bool comfirm;
public:
	void FlightSchedule() {
		dBConnect.init();
		string query = "SELECT * FROM flightdetails_tb";
		res = dBConnect.select(query, "--- Flight Schedule ---");
		printf("-------------------------------------------------------------------------------------------\n");
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
		while ((row = mysql_fetch_row(res))) {
			printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[3], row[4], row[7], row[8]);
		}
		printf("-------------------------------------------------------------------------------------------\n");
	}

	void AddFlight() {
		cout << "----Input information detail Flight---" << endl;
		cout << "No: ";
		getline(cin, this->flightNo);
		cout << "Flight Name: ";
		getline(cin, this->flightName);
		cout << "Flight From: ";
		getline(cin, this->flightFrom);
		cout << "Flight Destination: ";
		getline(cin, this->flightDestination);
		cout << "Flight Time: ";
		getline(cin, this->flightTime);
		cout << "Flight Amount: ";
		getline(cin, this->flightAmount);
		cout << "Flight Leave: ";
		getline(cin, this->flightLeave);
		cout << "Flight Arrive: ";
		getline(cin, this->flightArrive);
		cout << "Flight Avaiable: ";
		getline(cin, this->flightAvailable);
		cout << "Are you sure you want to add flight ? ";
		cin >> comfirm;
		if (comfirm) {
			string insert_query = "INSERT INTO flightdetails_tb (f_no, f_name,f_from, f_destination, f_time, f_amount, f_leave, f_arrive, f_available) VALUES ('" + flightNo + "','" + flightName + "','" + flightFrom + "','" + flightDestination + "','" + flightTime + "','" + flightAmount + "','" + flightLeave + "','" + flightArrive + "','" + flightAvailable + "')";
			dBConnect.addNew(insert_query);
		}
		else {
			cout << "Error handle";
		}
	}

	int updateFlight(string flightId) {
		int result = -1;
		string flightIdTmp;
		string flightNoTmp;
		string flightNameTmp;
		string flightFromTmp;
		string flightDestinationTmp;
		string flightTimeTmp;
		string flightAmountTmp;
		string flightLeaveTmp;
		string flightArriveTmp;
		string flightAvailableTmp;
		dBConnect.init();
		string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
		const char* q = findbyid_query.c_str();
		qstate = mysql_query(dBConnect.getConnnect(), q);
		if (!qstate) {
			res = mysql_store_result(dBConnect.getConnnect());
			result = res->row_count;
			if (result > 0) {
				while ((row = mysql_fetch_row(res)))
				{
					cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
					flightIdTmp = row[0];
					flightNoTmp = row[1];
					flightNameTmp = row[2];
					flightFromTmp = row[3];
					flightDestinationTmp = row[4];
					flightTimeTmp = row[5];
					flightAmountTmp = row[6];
					flightLeaveTmp = row[7];
					flightArriveTmp = row[8];
					flightAvailableTmp = row[9];
				}
				cout << "----Input information for update Flight---" << endl;
				cout << "No (input x if field don't need update): ";
				getline(cin, this->flightNo);
				if (flightNo == "x") {
					this->flightNo = flightNoTmp;
				}
				cout << "Flight Name (input x if field don't need update): ";
				getline(cin, this->flightName);
				if (flightName == "x") {
					flightName = flightNameTmp;
				}
				cout << "Flight From (input x if field don't need update): ";
				getline(cin, this->flightFrom);
				if (flightFrom == "x") {
					flightFrom = flightFromTmp;
				}
				cout << "Flight Destination (input x if field don't need update): ";
				getline(cin, this->flightDestination);
				if (flightDestination == "x") {
					flightDestination = flightDestinationTmp;
				}
				cout << "Flight Time (input x if field don't need update): ";
				getline(cin, this->flightTime);
				if (flightTime == "x") {
					flightTime = flightTimeTmp;
				}
				cout << "Flight Amount (input x if field don't need update): ";
				getline(cin, this->flightAmount);
				if (flightAmount == "x") {
					flightAmount = flightAmountTmp;
				}
				cout << "Flight Leave (input x if field don't need update): ";
				getline(cin, this->flightLeave);
				if (flightLeave == "x") {
					flightLeave = flightLeaveTmp;
				}
				cout << "Flight Arrive (input x if field don't need update): ";
				getline(cin, this->flightArrive);
				if (flightArrive == "x") {
					flightArrive = flightArriveTmp;
				}
				cout << "Flight Avaiable (input x if field don't need update): ";
				getline(cin, this->flightAvailable);
				if (flightAvailable == "x") {
					flightAvailable = flightAvailableTmp;
				}
				cout << "Are you sure you want to update flight ? ";
				cin >> comfirm;
				if (comfirm) {
					string update_query = "UPDATE flightdetails_tb SET f_no = '" + this->flightNo + "', f_name = '" + this->flightName + "',f_from = '" + this->flightFrom + "', f_destination = '" + this->flightDestination + "',f_time = '" + this->flightTime + "',f_amount = '" + this->flightAmount + "',f_leave = '" + this->flightLeave + "',f_arrive = '" + this->flightArrive + "', f_available = '" + this->flightAvailable + "' WHERE f_id = '" + flightIdTmp + "' ";
					dBConnect.update(update_query);
				}
				else {
					return 9999;
				}
			}
			else {
				cout << "No item in database" << endl;
				return result;
			}
		}
		else {
			cout << "Query Execution Problem!" << mysql_errno(dBConnect.getConnnect()) << endl;
		}
		return result;
	}

	int deleteFlight(string flightId) {
		int result = -1;
		dBConnect.init();
		string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
		res = dBConnect.select(findbyid_query);
		result = res->row_count;
		if (result > 0) {
			while ((row = mysql_fetch_row(res)))
			{
				this->flightNo = row[1];
				this->flightName = row[2];
				this->flightName = row[2];
				this->flightFrom = row[3];
				this->flightDestination = row[4];
			}
			cout << "Are you sure you want to Delete flight " << flightNo << " of " << flightName << " from " << flightFrom << " to " << flightDestination << " ? ";
			cin >> comfirm;
			if (comfirm) {
				string delete_query = "DELETE FROM flightdetails_tb WHERE f_id = '" + flightId + "' ";
				dBConnect.update(delete_query);
			}
			else {
				return 9999;
			}
		}
		else {
			cout << "No item in database" << endl;
			return result;
		}
	}

	int flightLeaveArrive() {
		string flightId;
		string flightLeaveTmp;
		string flightArriveTmp;
		string flightAvailableTmp;
		dBConnect.init();
		string query = "SELECT * FROM flightdetails_tb";
		res = dBConnect.select(query);
		if (res->row_count > 0) {
			printf("--------------------------------------------------------------------------------------------------------\n");
			printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight ID", "Flight No.", "From", "Destination", "Leave", "Arrive");
			while ((row = mysql_fetch_row(res)))
			{
				printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[3], row[4], row[7], row[8]);
			}
			printf("-----------------------------------------------------------------------------------------------------------\n");
			comeback:cout << "Choose ID item want select: ";
			cin >> flightId;
			string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
			res = dBConnect.select(findbyid_query);
			if (res->row_count > 0) {
				while ((row = mysql_fetch_row(res)))
				{
					cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
					flightLeaveTmp = row[7];
					flightArriveTmp = row[8];
					flightAvailableTmp = row[9];
				}
				cin.ignore(INT64_MAX, '\n');
				cout << "Change Flight Leave (input x to not change): ";
				getline(cin, this->flightLeave);
				if (flightLeave == "x") {
					flightLeave = flightLeaveTmp;
				}
				cout << "Change Flight Arrive (input x to not change): ";
				getline(cin, this->flightArrive);
				if (flightArrive == "x") {
					flightArrive = flightArriveTmp;
				}
				cout << "Change Flight Available (input x to not change): ";
				getline(cin, this->flightAvailable);
				if (flightAvailable == "x") {
					flightAvailable = flightAvailableTmp;
				}
				cout << "Are you sure you want to update flight ? ";
				cin >> comfirm;
				if (comfirm) {
					string update_query = "UPDATE flightdetails_tb SET f_leave = '" + this->flightLeave + "',f_arrive = '" + this->flightArrive + "', f_available = '" + this->flightAvailable + "' WHERE f_id = '" + flightId + "' ";
					dBConnect.update(update_query);
					return 1;
				}
				else {
					return 9999;
				}
			}
			else {
				cout << "No item in database" << endl;
				goto comeback;
			}
		}
		else {
			cout << "No item in database" << endl;
		}
		return 0;
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

void BackToMenu(int& tmp) {
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
		if (sub >= 1 || sub <= 5) {
			if (sub == 5) {
				system("cls");
				Menu();
			}
			else {
				cin.ignore(INT64_MAX, '\n');
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
	int tmp, result;
	string flightId;
	switch (n)
	{
	case 1:
		AddFlight();
		Sleep(3000);
		break;
	case 2:
	input:cout << "Input Id item need update: ";
		cin >> flightId;
		cin.ignore(INT64_MAX, '\n');
		result = UpdateFlight(flightId);
		if (result == 9999) {
			break;
		}
		if (result > 0) {
			cout << "Update success";
			Sleep(3000);
		}
		else {
			goto input;
		}
		break;
	case 3:
	flightId:cout << "Input Id item need delete: ";
		cin >> flightId;
		cin.ignore(INT64_MAX, '\n');
		result = DeleteFlight(flightId);
		if (result == 9999) {
			break;
		}
		if (result > 0) {
			cout << "Delete success";
			Sleep(3000);
		}
		else {
			goto flightId;
		}
		break;
	case 4:
		result = FlightLeaveArrive();
		if (result == 9999) {
			break;
		}
		if (result > 0) {
			cout << "Update success";
			Sleep(3000);
		}
		else {
			cout << "Error";
		}
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

void AddFlight() {
	FlightDetail flightDetail;
	flightDetail.AddFlight();
}

int UpdateFlight(string flightId) {
	FlightDetail flightDetail;
	int result = flightDetail.updateFlight(flightId);
	return result;
}

int DeleteFlight(string flightId) {
	FlightDetail flightDetail;
	int result = flightDetail.deleteFlight(flightId);
	return result;
}

int FlightLeaveArrive() {
	FlightDetail flightDetail;
	int result = flightDetail.flightLeaveArrive();
	return result;
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
