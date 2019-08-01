#include "UserReservation.h"

void UserReservation::setName(string name) {
	this->name = name;
}

string UserReservation::getName() {
	return this->name;
}

void UserReservation::setPhone(string phone) {
	this->phone = phone;
}

string UserReservation::getPhone() {
	return this->phone;
}

void UserReservation::setPassport(string passport) {
	this->passport = passport;
}

string UserReservation::getPassport() {
	return this->passport;
}

void UserReservation::setTicket(string ticket) {
	this->ticket = ticket;
}

string UserReservation::getTicket() {
	return this->ticket;
}

void UserReservation::setFlightNo(string flightNo) {
	this->flightNo = flightNo;
}

string UserReservation::UserReservation::getFlightNo() {
	return this->flightNo;
}

void UserReservation::setAddress(string address) {
	this->address = address;
}

string UserReservation::getAddress() {
	return this->address;
}

void UserReservation::setComfirm(bool comfirm) {
	this->comfirm = comfirm;
}

bool UserReservation::getComfirm() {
	return this->comfirm;
}

void UserReservation::input() {
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
}

void UserReservation::inputName() {
	getline(cin, this->name);
}

