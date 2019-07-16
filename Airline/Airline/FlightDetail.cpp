#include "FlightDetail.h"

int qstate;
MYSQL_RES* resFd;
MYSQL_ROW rowFd;

void FlightDetail::FlightSchedule()
{
	string query = "SELECT * FROM flightdetails_tb";
	resFd = dBConnect.select(query, "--- Flight Schedule ---");
	printf("-------------------------------------------------------------------------------------------\n");
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
	while ((rowFd = mysql_fetch_row(resFd))) {
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", rowFd[1], rowFd[3], rowFd[4], rowFd[7], rowFd[8]);
	}
	printf("-------------------------------------------------------------------------------------------\n");
}

void FlightDetail::AddFlight()
{
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

int FlightDetail::updateFlight(string flightId)
{
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
	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
	const char* q = findbyid_query.c_str();
	qstate = mysql_query(dBConnect.getConnnect(), q);
	if (!qstate) {
		resFd = mysql_store_result(dBConnect.getConnnect());
		result = resFd->row_count;
		if (result > 0) {
			while ((rowFd = mysql_fetch_row(resFd)))
			{
				cout << "Flight No.: " << rowFd[1] << "\nFlight Name: " << rowFd[2] << "\nFlight From: " << rowFd[3] << "\nFlight Destination: " << rowFd[4] << "\nFlight Time: " << rowFd[5] << "\nFlight Amount: " << rowFd[6] << endl << endl;
				flightIdTmp = rowFd[0];
				flightNoTmp = rowFd[1];
				flightNameTmp = rowFd[2];
				flightFromTmp = rowFd[3];
				flightDestinationTmp = rowFd[4];
				flightTimeTmp = rowFd[5];
				flightAmountTmp = rowFd[6];
				flightLeaveTmp = rowFd[7];
				flightArriveTmp = rowFd[8];
				flightAvailableTmp = rowFd[9];
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

int FlightDetail::deleteFlight(string flightId)
{
	int result = -1;
	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
	resFd = dBConnect.select(findbyid_query);
	result = resFd->row_count;
	if (result > 0) {
		while ((rowFd = mysql_fetch_row(resFd)))
		{
			this->flightNo = rowFd[1];
			this->flightName = rowFd[2];
			this->flightName = rowFd[2];
			this->flightFrom = rowFd[3];
			this->flightDestination = rowFd[4];
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

int FlightDetail::flightLeaveArrive()
{
	string flightId;
	string flightLeaveTmp;
	string flightArriveTmp;
	string flightAvailableTmp;
	string query = "SELECT * FROM flightdetails_tb";
	resFd = dBConnect.select(query);
	if (resFd->row_count > 0) {
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight ID", "Flight No.", "From", "Destination", "Leave", "Arrive");
		while ((rowFd = mysql_fetch_row(resFd)))
		{
			printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", rowFd[0], rowFd[1], rowFd[3], rowFd[4], rowFd[7], rowFd[8]);
		}
		printf("-----------------------------------------------------------------------------------------------------------\n");
	comeback:cout << "Choose ID item want select: ";
		cin >> flightId;
		string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
		resFd = dBConnect.select(findbyid_query);
		if (resFd->row_count > 0) {
			while ((rowFd = mysql_fetch_row(resFd)))
			{
				cout << "Flight No.: " << rowFd[1] << "\nFlight Name: " << rowFd[2] << "\nFlight From: " << rowFd[3] << "\nFlight Destination: " << rowFd[4] << "\nFlight Time: " << rowFd[5] << "\nFlight Amount: " << rowFd[6] << endl << endl;
				flightLeaveTmp = rowFd[7];
				flightArriveTmp = rowFd[8];
				flightAvailableTmp = rowFd[9];
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
