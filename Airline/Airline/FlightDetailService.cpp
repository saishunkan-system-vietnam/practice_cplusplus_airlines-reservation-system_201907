#include "FlightDetailService.h"

void FlightDetailService::FlightSchedule()
{
	MYSQL_ROW row;
	string query = "SELECT * FROM flightdetails_tb";
	res = select(query);
	printf("-------------------------------------------------------------------------------------------\n");
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
	while ((row = mysql_fetch_row(res))) {
		printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[3], row[4], row[7], row[8]);
	}
	printf("-------------------------------------------------------------------------------------------\n");
}

void FlightDetailService::AddFlight()
{
	bool confirm = false;
	FlightDetail flightDetail;
	cout << "----Input information detail Flight---" << endl;
	flightDetail.input();
	cout << "Are you sure you want to add flight ? ";
	cin >> confirm;
	if (confirm) {
		string insert_query = "INSERT INTO flightdetails_tb (f_no, f_name,f_from, f_destination, f_time, f_amount, f_leave, f_arrive, f_available) VALUES ('" + flightDetail.getFlightNo() + "','" + flightDetail.getFlightName() + "','" + flightDetail.getFlightFrom() + "','" + flightDetail.getFlightDestination() + "','" + flightDetail.getFlightTime() + "','" + flightDetail.getFlightAmount() + "','" + flightDetail.getFlightLeave() + "','" + flightDetail.getFlightArrive() + "','" + flightDetail.getFlightAvailable() + "')";
		execute(insert_query);
	}
	else {
		cout << "Error handle";
	}
}

int FlightDetailService::updateFlight(string flightId)
{
	MYSQL_ROW row;
	int result = -1;
	bool confirm = false;
	FlightDetail flightDetailTmp;
	FlightDetail flightDetail;
	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
	const char* q = findbyid_query.c_str();
	qstate = mysql_query(getConnect(), q);
	if (!qstate) {
		res = mysql_store_result(getConnect());
		result = res->row_count;
		if (result > 0) {
			while ((row = mysql_fetch_row(res)))
			{
				cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
				flightDetailTmp.setFlightId(row[0]);
				flightDetailTmp.setFlightNo(row[1]);
				flightDetailTmp.setFlightName(row[2]);
				flightDetailTmp.setFlightFrom(row[3]);
				flightDetailTmp.setFlightDestination(row[4]);
				flightDetailTmp.setFlightTime(row[5]);
				flightDetailTmp.setFlightAmount(row[6]);
				flightDetailTmp.setFlightLeave(row[7]);
				flightDetailTmp.setFlightArrive(row[8]);
				flightDetailTmp.setFlightAvailable(row[9]);
			}
			cout << "----Input information for update Flight---" << endl;
			flightDetail.inputClone(flightDetailTmp);
			cout << "Are you sure you want to update flight ? ";
			cin >> confirm;
			if (confirm) {
				string update_query = "UPDATE flightdetails_tb SET f_no = '" + flightDetail.getFlightNo() + "', f_name = '" + flightDetail.getFlightName() + "',f_from = '" + flightDetail.getFlightFrom() + "', f_destination = '" + flightDetail.getFlightDestination() + "',f_time = '" + flightDetail.getFlightTime() + "',f_amount = '" + flightDetail.getFlightAmount() + "',f_leave = '" + flightDetail.getFlightLeave() + "',f_arrive = '" + flightDetail.getFlightArrive() + "', f_available = '" + flightDetail.getFlightAvailable() + "' WHERE f_id = '" + flightDetail.getFlightId() + "' ";
				execute(update_query);
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
		cout << "Query Execution Problem!" << mysql_errno(getConnect()) << endl;
	}
	return result;
}

int FlightDetailService::deleteFlight(string flightId)
{
	MYSQL_ROW row;
	int result = -1;
	bool confirm = false;
	FlightDetail flightDetail;
	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
	res = select(findbyid_query);
	result = res->row_count;
	if (result > 0) {
		while ((row = mysql_fetch_row(res)))
		{
			flightDetail.setFlightNo(row[1]);
			flightDetail.setFlightName(row[2]);
			flightDetail.setFlightFrom(row[3]);
			flightDetail.setFlightDestination(row[4]);
		}
		cout << "Are you sure you want to Delete flight " << flightDetail.getFlightNo()<< " of " << flightDetail.getFlightName() << " from " << flightDetail.getFlightFrom() << " to " << flightDetail.getFlightDestination() << " ? ";
		cin >> confirm;
		if (confirm) {
			string delete_query = "DELETE FROM flightdetails_tb WHERE f_id = '" + flightId + "' ";
			execute(delete_query);
		}
		else {
			return 9999;
		}
	}
	else {
		cout << "No item in database" << endl;
		return result;
	}
	return result;
}

int FlightDetailService::flightLeaveArrive()
{
	MYSQL_ROW row;
	bool confirm = false;
	string flightId;
	FlightDetail flightDetailTmp;
	FlightDetail flightDetail;
	string query = "SELECT * FROM flightdetails_tb";
	res = select(query);
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
		res = select(findbyid_query);
		if (res->row_count > 0) {
			while ((row = mysql_fetch_row(res)))
			{
				cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
				flightDetailTmp.setFlightLeave(row[7]);
				flightDetailTmp.setFlightArrive(row[8]);
				flightDetailTmp.setFlightAvailable(row[9]);
			}
			flightDetail.inputUpdateFlightLeaveArrive(flightDetailTmp);
			cout << "Are you sure you want to update flight ? ";
			cin >> confirm;
			if (confirm) {
				string update_query = "UPDATE flightdetails_tb SET f_leave = '" + flightDetail.getFlightLeave() + "',f_arrive = '" + flightDetail.getFlightArrive() + "', f_available = '" + flightDetail.getFlightAvailable() + "' WHERE f_id = '" + flightId + "' ";
				execute(update_query);
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
	return -1;
}
