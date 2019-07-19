// AirlinesReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string.h>
#include <iostream>
#include<cstdio>
#include <mysqlx/xdevapi.h>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
//using namespace mysqlx;
using namespace std;
#define FLIGHT_DETAIL_TABLE "flightdetails_tb";

void displayMenu() {
	cout << "====================================================================" << endl;
	cout << "                   Airlines Reservation System Menu                 " << endl;
	cout << "====================================================================" << endl;
	cout << "1.Reserve Seat."    << endl;
	cout << "2.User Ticket."     << endl;
	cout << "3.Flights Schedule."<< endl;
	cout << "4.Display Passenger"<< endl;
	cout << "5.Flight Details."  << endl;
}


class UserReseration {
      private: 
		  string name;
		  string phone;
		  string passportno;
		  string ticket;
		  string flightno;
		  string address;
      public:
		  void setName(string name) {
			  this->name = name;
		  }

		  void setPhone(string phone) {
			  this->phone = phone;
		  }
          
		  void setPassportno(string passportno) {
			  this->passportno = passportno;
		  }

		  void setTicket(string ticket) {
			  this->ticket = ticket;
		  }
          
		  void setFlightno(string flightNo) {
			  this->flightno = flightNo;
		  }

		  void setAddress(string address) {
			  this->address = address;
		  }

		  string getName() {
			  return this->name;
		  }

		  string getPhone() {
			  return this->phone;
		  }

		  string getPassportno() {
			  return this->passportno;
		  }

		  string getTicket() {
			  return this->ticket;
		  }

		  string getFlightno() {
			  return this->flightno;
		  }

		  string getAddress() {
			  return this->address;
		  }
};

class DBResponse {
   public:
	    mysqlx::Table connectToDb(string tableName) {
		   mysqlx::Session sess("localhost", 33060, "root", "123456");
		   mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
		   mysqlx::Table table = db.getTable(tableName);
		   return table;
	   }
};
void runMain();
void flightDetail();
void reserveSeat() {
	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Reserve Seat Menu" << endl << endl;
	string u_name;
	string u_phone;
	string u_passportno;
	string u_ticket;
	string u_flightno;
	string u_address;
	cin.ignore(1, '\n');
	cout << "Enter User Name: ";
	getline(cin, u_name);
	cout << "Enter User Phone No: ";
	getline(cin, u_phone);
	cout << "Enter User PassPost: ";
	getline(cin, u_passportno);
	cout << "Enter User Ticket: ";
	getline(cin, u_ticket);
	cout << "Enter User Address: ";
	getline(cin, u_address);
    // get All Flight
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("flightdetails_tb");
	mysqlx::RowResult results = table.select("f_no","f_name","f_from","f_destination","f_time","f_amount","f_leave","f_arrive","f_available").execute();
	if (results.count() > 0) {
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("| %-20s | %-20s | %-20s | %-20s | %-20s |\n", "Flight No", "From", "Destination", "Time", "Amount");
		for (mysqlx::Row row : results.fetchAll())
		{
			cout << "| " << row[0] << "              | " << row[2] << "               | " << row[3] << "              | " << row[4] << "               | " << row[5] << endl;
		}
		printf("--------------------------------------------------------------------------------------------------------\n");
	}
	cout << "Enter Flight No: ";
	getline(cin, u_flightno);

	// insert value
	mysqlx::Table table2 = db.getTable("userreservation_tb");
	mysqlx::Result response = table2.insert("u_name", "u_phone", "u_passportno", "u_ticket", "u_flightno", "u_address")
		.values(u_name, u_phone, u_passportno, u_ticket, u_flightno, u_address).execute();
	if (response.getAffectedItemsCount()) {
		cout << "Insert Success" << endl;
	}
	else {
		cout << "Insert Failed" << endl;
	}
	char choose;
	cout << "Press 'm' to Menu and 'a' to Reserve Again Or Any other key to exit: ";
	cin >> choose;
	if (choose == 'm' || choose == 'M') {
		runMain();
	}
	else if (choose == 'a' || choose == 'A') {
		reserveSeat();
	}
	else {
		exit(0);
	}
	
}

void userTicket() {
	system("cls");
	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "User Ticket Menu" << endl << endl;
	cin.ignore(1, '\n');
	string name;
	cout << "Enter User Name: ";
	getline(cin, name);
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("userreservation_tb");
	mysqlx::RowResult results = table.select("u_name", "u_phone", "u_passportno", "u_ticket", "u_flightno", "u_address").where("u_name like '%" + name + "%'").execute();
	if (results.count() > 0) {
		for (mysqlx::Row row : results.fetchAll()) {
			cout << "User Name: " << row[0] << endl;
			cout << "User Phone: " << row[1] << endl;
			cout << "User PassPort: " << row[2] << endl;
			cout << "User Ticket: " << row[3] << endl;
			cout << "User FlightNo: " << row[4] << endl;
			cout << "User Address: " << row[5] << endl << endl;
			
		}
		
	}
	else {
		cout << "No Data";
	}
	char choose;
	cout << "Press 'm' to Menu ,'a' to search again and any other key to exit: ";
	cin >> choose;
	if (choose == 'm' || choose == 'M') {
		 runMain();
	}
	else if (choose == 'a' || choose == 'A') {
		userTicket();
	}
	else {
		exit(0);
	}
}
void flightsSchedule() {
	system("cls");
	

	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Flight Schedule" << endl << endl;
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("flightdetails_tb");
	mysqlx::RowResult results = table.select("f_no", "f_from", "f_destination", "f_leave", "f_arrive").execute();
	if (results.count() > 0) {
		printf("-------------------------------------------------------------------------------------------\n");
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
		for (mysqlx::Row row : results.fetchAll()) {
			cout << "| " << row[0] << "         | " << row[1] << "          | " << row[2] << "         | " << row[3] << "         | " << row[4] << endl;
		}
		printf("-------------------------------------------------------------------------------------------\n");
	}
	else {
		cout << "No Data " << endl;
	}
	// Exit code
	char choose;
	cout << "Press 'm' or 'M' to Menu and any other key to Exit: ";
	cin >> choose;
	if (choose == 'm' || choose == 'M') {
		runMain();
	}
	else {
		exit(0);
	}
}

void displayPassenger() {
	system("cls");
	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Display Passenger Menu" << endl << endl;
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("userreservation_tb");
	mysqlx::RowResult results = table.select().execute();
	if (results.count() > 0) {
		printf("------------------------------------------------------------------------------------------------------------------\n");
		    cout << "| " << "User Name" << "           | " << "Phone No." << "      | " << "Passport No." << "       | " << "Ticket No." << "      | " << "Flight No." << "         | " << "Address" << endl;
		for (mysqlx::Row row : results.fetchAll()) {
			cout << "| " << row[1] << "           | " << row[2] << "      | " << row[3] << "       | " << row[4] << "      | " << row[5] << "         | " << row[6] << endl;
		}
		printf("------------------------------------------------------------------------------------------------------------------\n");
	}
	
		char choose;
		cout << "Press 'm' or 'M' to Menu and any other key to Exit: ";
		cin >> choose;
		if (choose == 'm' || choose == 'M') {
			runMain();
		}
		else {
			exit(0);
		}

}

void addNewFlight() {
	system("cls");

	// Variables
	string flightNo = "";
	string flightName = "";
	string flightFrom = "";
	string flightDestination = "";
	string flightTime = "";
	string flightAmount = "";
	string flightAvailability = "";

	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Add New Flight Menu" << endl << endl;
	cin.ignore(1, '\n');
	cout << "Enter Flight No: ";
	getline(cin,flightNo);
	cout << "Enter Flight Name: ";
	getline(cin, flightName);
	cout << "Enter Flight From: ";
	getline(cin, flightFrom);
	cout << "Enter User Destination: ";
	getline(cin, flightDestination);
	cout << "Enter Flight Time: ";
	getline(cin, flightTime);
	cout << "Enter Amount: ";
	getline(cin, flightAmount);
	cout << "Enter Flight Availability (A (Available) / N (Not Available)): ";
	getline(cin, flightAvailability);
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("flightdetails_tb");
	mysqlx::Result response = table.insert("f_no", "f_name", "f_from", "f_destination", "f_time", "f_amount", "f_leave", "f_arrive", "f_available")
		                           .values(flightNo, flightName, flightFrom, flightDestination, flightTime, flightAmount, flightAvailability)
		                           .execute();
	if (response.getAutoIncrementValue()) {
		cout << "Insert Success";
	}
	else {
		cout << "Insert Failed";
	}
	char choose;
	cout << "Press 'm' to flight details Menu and 'a' to insert again or Any Other key to exit: ";
	cin >> choose;
	if (choose == 'm' || choose == 'M') {
		flightDetail();
	}
	else if (choose == 'a' || choose == 'A') {
		addNewFlight();
	}
	else {
		exit(0);
	}

}

void editFlight() {
	system("cls");
	string flightNo = "";
	string flightName = "";
	string flightFrom = "";
	string flightDestination = "";
	string flightTime = "";
	string flightAmount = "";
	string items[5000];
	int itemId;
	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForId = 0;
	string strid = "";
	//Store Variables
	string storeColumnId = "";
	string storeFlightNo = "";
	string storeFlightName = "";
	string storeFlightFrom = "";
	string storeFlightDestination = "";
	string storeFlightTime = "";
	string storeFlightAmount = "";
	int storeIndex1 = 0, storeIndex2 = 0;
	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Edit Flight Record" << endl;
	mysqlx::Session sess("localhost", 33060, "root", "123456");
	mysqlx::Schema db = sess.getSchema("airlines-reservation-system");
	mysqlx::Table table = db.getTable("flightdetails_tb");
	mysqlx::RowResult results = table.select("f_id","f_no","f_name","f_from","f_destination","f_time").execute();
	if (results.count() > 0) {
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("| %-10s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Column ID", "Flight No.", "Flight Name", "From", "Destination", "Time");
		for (mysqlx::Row row : results.fetchAll()) {
			cout << "  | " << row[0] << "     | " << row[1] << "         | " << row[2] << "       | " << row[3] << "       | " << row[4] << "      | " << row[5] << "       | "<< endl;
		    items[indexForId] = std::to_string(row[0].get<int>());
			cout << items[0];
			indexForId++;
		}
		printf("--------------------------------------------------------------------------------------------------------\n");
	}
	else {
		cout << "No Data";
	}
	try
	{
		cout << endl;
		cout << "Enter Item Column Id: ";
		cin >> itemId;
		cout << endl;
	}
	catch (exception e)
	{
		cout << "Please Enter a valid NUMBER." << endl;
		HaveException = true;
		goto ExitMenu;
	}

	if (HaveException == false) {
		stringstream streamid;
		streamid << itemId;
		streamid >> strid;
		for (int i = 0; i < indexForId; i++) {
			if (strid != items[i]) {
				NotInDatabase = true;
			}
			else {
				NotInDatabase = false;
				break;
			}
		}
	}
		
		if (NotInDatabase == false) {
			mysqlx::RowResult flight_detail = table.select("f_id","f_no", "f_name", "f_from", "f_destination", "f_time", "f_amount").where("f_id = " + strid).execute();;
			if (flight_detail.count() > 0) {
				for (mysqlx::Row row : flight_detail.fetchAll()) {
					cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
					storeColumnId = to_string(row[0].get<int>());
					storeFlightNo = row[1].get<string>();
					storeFlightName = row[2].get<string>();
					storeFlightFrom = row[3].get<string>();
					storeFlightDestination = row[4].get<string>();
					storeFlightTime = row[5].get<string>();
					storeFlightAmount = row[6].get<string>();
				}

				cin.ignore(1, '\n');
				cout << "Enter Flight No. (X to not change): ";
				getline(cin, flightNo);
				if (flightNo == "X") {
					flightNo = storeFlightNo;
				}
				cout << "Enter Flight Name (X to not change): ";
				getline(cin, flightName);
				if (flightName == "X")
				{
					flightName = storeFlightName;
				}
				cout << "Enter From (X to not change): ";
				getline(cin, flightFrom);
				if (flightFrom == "X")
				{
					flightFrom = storeFlightFrom;
				}
				cout << "Enter Destination (X to not change): ";
				getline(cin, flightDestination);
				if (flightDestination == "X")
				{
					flightDestination = storeFlightDestination;
				}
				cout << "Enter Time (X to not change): ";
				cin >> flightTime;
				if (flightTime == "X")
				{
					flightTime = storeFlightTime;
				}
				cout << "Enter Amount (X to not change): ";
				cin >> flightAmount;
				if (flightAmount == "X")
				{
					flightAmount = storeFlightAmount;
				}

				mysqlx::Result response = table.update().set("f_no", flightNo)
					.set("f_name", flightName)
					.set("f_from", flightFrom)
					.set("f_destination", flightDestination)
					.set("f_time", flightTime)
					.set("f_amount", flightAmount).where("f_id = " + strid).execute();
				if (response.getAffectedItemsCount()) {
					cout << "Update Success";
				}
				else {
					cout << "Update Failed";
				}
					                        
			}
		}
	else {
		cout << "Item not found in Database";
	}
	char choose;
  ExitMenu:

	cout << "Press 'm' to Menu,'e' to edit another item and any other key to exit: ";
	cin >> choose;
	if (choose == 'm' || choose == 'M') {
		flightDetail();
	}
	else if (choose == 'e' || choose == 'E') {
		editFlight();
	}
	else {
		exit(0);
	}
}

void deleteFlight() {

}

void flightLeaveArrive() {

}

void flightDetail() {
	system("cls");
	system("title Airlines Reservation System Program");
	system("color 0f");

	int chooseOneFromMenu = 0;
	cout << "Welcome To Airlines Reservation System" << endl << endl;
	cout << "Airlines Reservation System Menu" << endl;
	cout << "1. Add Flight." << endl;
	cout << "2. Edit Flight." << endl;
	cout << "3. Delete Flight." << endl;
	cout << "4. Flight Leave And Arrive." << endl;
	cout << "5. Back To Menu." << endl;
	cout << "Choose One: ";
	cin >> chooseOneFromMenu;

	switch (chooseOneFromMenu)
	{
	case 1:
		addNewFlight();
		break;
	case 2:
		editFlight();
		break;
	case 3:
		deleteFlight();
		break;
	case 4:
		flightLeaveArrive();
		break;
	case 5:
		//main
		break;
	default:
		cout << "Please choose between The Given Numbers. Press Enter To Continue...";
		system("cls");
		flightDetail();
		break;
	}
}
void runMain() {
	system("cls");
	int menuChoice;
	char confirm;

	displayMenu();
	cout << "Nhap lua chon cua ban (1-5):";
	cin >> menuChoice;

	switch (menuChoice) {
	case 1: reserveSeat(); break;
	case 2: userTicket(); break;
	case 3: flightsSchedule(); break;
	case 4: displayPassenger(); break;
	case 5: flightDetail(); break;
	case 6:
	ExitProgram:
		cout << "Program terminating.Are you sure?(y/N):";
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y') {
			exit(0);
		}
		else if (confirm == 'n' || confirm == 'N') {
			system("cls");
			//main(NULL, NULL);
		}
		else {
			cout << "Next time choose after read the corresponding line." << endl;
			goto ExitProgram;
		}
		break;
	default:
		cout << "Please choose between The Given Numbers. Press Enter To Continue...";
		system("cls");
		//main(NULL, NULL);
		break;
	}
}
int main(int argc, const char* argv[])
{
	runMain();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
