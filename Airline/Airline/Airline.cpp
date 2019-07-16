// Airline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <windows.h>
#include "Properties.h"
#include "UserReservation.h"
#include "FlightDetail.h"

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
