// Airline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <windows.h>
#include "BaseService.h"
#include "UserReservationService.h"
#include "FlightDetailService.h"



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

void SelectFunctionSubMenu(int n, BaseService<string>* baseService) {
	int tmp, result;
	string flightId;
	switch (n)
	{
	case 1:
		baseService->AddFlight();
		Sleep(3000);
		break;
	case 2:
	input:cout << "Input Id item need update: ";
		cin >> flightId;
		cin.ignore(INT64_MAX, '\n');
		result = baseService->updateFlight(flightId);
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
		result = baseService->deleteFlight(flightId);
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
		result = baseService->flightLeaveArrive();
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

void SelectFunction(int n, BaseService<string>* baseService) {
	int tmp;
	int sub;
	baseService = new UserReservationService();
	switch (n)
	{
	case 1:
		baseService->ReserveSeat();
		Sleep(1000);
		system("cls");
		Menu();
		break;
	case 2:
		baseService->UserTicket();
		BackToMenu(tmp);
		break;
	case 3:
		baseService = new FlightDetailService();
		baseService->FlightSchedule();
		BackToMenu(tmp);
		break;
	case 4:
		baseService->DisplayPassenger();
		BackToMenu(tmp);
		break;
	case 5:
		baseService = new FlightDetailService();
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
				SelectFunctionSubMenu(sub, baseService);
				goto action;
			}
		}
		else {
			goto input;
		}
		break;
	case 6:
		cout << "You exited system. See you again!!!" << endl;
		exit(1);
	default:
		break;
	}
}

int main()
{
	BaseService<string>* baseService = NULL;
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
			SelectFunction(n, baseService);
		}
	} while (n);
	delete baseService;
}

