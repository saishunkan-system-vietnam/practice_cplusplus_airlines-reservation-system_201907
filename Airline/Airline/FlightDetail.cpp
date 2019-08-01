//#include "FlightDetail.h"
//
//
//void FlightDetail::FlightSchedule()
//{
//	string query = "SELECT * FROM flightdetails_tb";
//	res = select(query, "--- Flight Schedule ---");
//	printf("-------------------------------------------------------------------------------------------\n");
//	printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight No.", "From", "Destination", "Leave", "Arrive");
//	while ((row = mysql_fetch_row(res))) {
//		printf("| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[1], row[3], row[4], row[7], row[8]);
//	}
//	printf("-------------------------------------------------------------------------------------------\n");
//}
//
//void FlightDetail::AddFlight()
//{
//	cout << "----Input information detail Flight---" << endl;
//	cout << "No: ";
//	getline(cin, this->flightNo);
//	cout << "Flight Name: ";
//	getline(cin, this->flightName);
//	cout << "Flight From: ";
//	getline(cin, this->flightFrom);
//	cout << "Flight Destination: ";
//	getline(cin, this->flightDestination);
//	cout << "Flight Time: ";
//	getline(cin, this->flightTime);
//	cout << "Flight Amount: ";
//	getline(cin, this->flightAmount);
//	cout << "Flight Leave: ";
//	getline(cin, this->flightLeave);
//	cout << "Flight Arrive: ";
//	getline(cin, this->flightArrive);
//	cout << "Flight Avaiable: ";
//	getline(cin, this->flightAvailable);
//	cout << "Are you sure you want to add flight ? ";
//	cin >> comfirm;
//	if (comfirm) {
//		string insert_query = "INSERT INTO flightdetails_tb (f_no, f_name,f_from, f_destination, f_time, f_amount, f_leave, f_arrive, f_available) VALUES ('" + flightNo + "','" + flightName + "','" + flightFrom + "','" + flightDestination + "','" + flightTime + "','" + flightAmount + "','" + flightLeave + "','" + flightArrive + "','" + flightAvailable + "')";
//		execute(insert_query);
//	}
//	else {
//		cout << "Error handle";
//	}
//}
//
//int FlightDetail::updateFlight(string flightId)
//{
//	int result = -1;
//	string flightIdTmp;
//	string flightNoTmp;
//	string flightNameTmp;
//	string flightFromTmp;
//	string flightDestinationTmp;
//	string flightTimeTmp;
//	string flightAmountTmp;
//	string flightLeaveTmp;
//	string flightArriveTmp;
//	string flightAvailableTmp;
//	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
//	const char* q = findbyid_query.c_str();
//	qstate = mysql_query(getConnnect(), q);
//	if (!qstate) {
//		res = mysql_store_result(getConnnect());
//		result = res->row_count;
//		if (result > 0) {
//			while ((row = mysql_fetch_row(res)))
//			{
//				cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
//				flightIdTmp = row[0];
//				flightNoTmp = row[1];
//				flightNameTmp = row[2];
//				flightFromTmp = row[3];
//				flightDestinationTmp = row[4];
//				flightTimeTmp = row[5];
//				flightAmountTmp = row[6];
//				flightLeaveTmp = row[7];
//				flightArriveTmp = row[8];
//				flightAvailableTmp = row[9];
//			}
//			cout << "----Input information for update Flight---" << endl;
//			cout << "No (input x if field don't need update): ";
//			getline(cin, this->flightNo);
//			if (flightNo == "x") {
//				this->flightNo = flightNoTmp;
//			}
//			cout << "Flight Name (input x if field don't need update): ";
//			getline(cin, this->flightName);
//			if (flightName == "x") {
//				flightName = flightNameTmp;
//			}
//			cout << "Flight From (input x if field don't need update): ";
//			getline(cin, this->flightFrom);
//			if (flightFrom == "x") {
//				flightFrom = flightFromTmp;
//			}
//			cout << "Flight Destination (input x if field don't need update): ";
//			getline(cin, this->flightDestination);
//			if (flightDestination == "x") {
//				flightDestination = flightDestinationTmp;
//			}
//			cout << "Flight Time (input x if field don't need update): ";
//			getline(cin, this->flightTime);
//			if (flightTime == "x") {
//				flightTime = flightTimeTmp;
//			}
//			cout << "Flight Amount (input x if field don't need update): ";
//			getline(cin, this->flightAmount);
//			if (flightAmount == "x") {
//				flightAmount = flightAmountTmp;
//			}
//			cout << "Flight Leave (input x if field don't need update): ";
//			getline(cin, this->flightLeave);
//			if (flightLeave == "x") {
//				flightLeave = flightLeaveTmp;
//			}
//			cout << "Flight Arrive (input x if field don't need update): ";
//			getline(cin, this->flightArrive);
//			if (flightArrive == "x") {
//				flightArrive = flightArriveTmp;
//			}
//			cout << "Flight Avaiable (input x if field don't need update): ";
//			getline(cin, this->flightAvailable);
//			if (flightAvailable == "x") {
//				flightAvailable = flightAvailableTmp;
//			}
//			cout << "Are you sure you want to update flight ? ";
//			cin >> comfirm;
//			if (comfirm) {
//				string update_query = "UPDATE flightdetails_tb SET f_no = '" + this->flightNo + "', f_name = '" + this->flightName + "',f_from = '" + this->flightFrom + "', f_destination = '" + this->flightDestination + "',f_time = '" + this->flightTime + "',f_amount = '" + this->flightAmount + "',f_leave = '" + this->flightLeave + "',f_arrive = '" + this->flightArrive + "', f_available = '" + this->flightAvailable + "' WHERE f_id = '" + flightIdTmp + "' ";
//				execute(update_query);
//			}
//			else {
//				return 9999;
//			}
//		}
//		else {
//			cout << "No item in database" << endl;
//			return result;
//		}
//	}
//	else {
//		cout << "Query Execution Problem!" << mysql_errno(getConnnect()) << endl;
//	}
//	return result;
//}
//
//int FlightDetail::deleteFlight(string flightId)
//{
//	int result = -1;
//	string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
//	res = select(findbyid_query);
//	result = res->row_count;
//	if (result > 0) {
//		while ((row = mysql_fetch_row(res)))
//		{
//			this->flightNo = row[1];
//			this->flightName = row[2];
//			this->flightName = row[2];
//			this->flightFrom = row[3];
//			this->flightDestination = row[4];
//		}
//		cout << "Are you sure you want to Delete flight " << flightNo << " of " << flightName << " from " << flightFrom << " to " << flightDestination << " ? ";
//		cin >> comfirm;
//		if (comfirm) {
//			string delete_query = "DELETE FROM flightdetails_tb WHERE f_id = '" + flightId + "' ";
//			execute(delete_query);
//		}
//		else {
//			return 9999;
//		}
//	}
//	else {
//		cout << "No item in database" << endl;
//		return result;
//	}
//}
//
//int FlightDetail::flightLeaveArrive()
//{
//	string flightId;
//	string flightLeaveTmp;
//	string flightArriveTmp;
//	string flightAvailableTmp;
//	string query = "SELECT * FROM flightdetails_tb";
//	res = select(query);
//	if (res->row_count > 0) {
//		printf("--------------------------------------------------------------------------------------------------------\n");
//		printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", "Flight ID", "Flight No.", "From", "Destination", "Leave", "Arrive");
//		while ((row = mysql_fetch_row(res)))
//		{
//			printf("| %-15s| %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[3], row[4], row[7], row[8]);
//		}
//		printf("-----------------------------------------------------------------------------------------------------------\n");
//	comeback:cout << "Choose ID item want select: ";
//		cin >> flightId;
//		string findbyid_query = "SELECT * FROM flightdetails_tb WHERE f_id = '" + flightId + "'";
//		res = select(findbyid_query);
//		if (res->row_count > 0) {
//			while ((row = mysql_fetch_row(res)))
//			{
//				cout << "Flight No.: " << row[1] << "\nFlight Name: " << row[2] << "\nFlight From: " << row[3] << "\nFlight Destination: " << row[4] << "\nFlight Time: " << row[5] << "\nFlight Amount: " << row[6] << endl << endl;
//				flightLeaveTmp = row[7];
//				flightArriveTmp = row[8];
//				flightAvailableTmp = row[9];
//			}
//			cin.ignore(INT64_MAX, '\n');
//			cout << "Change Flight Leave (input x to not change): ";
//			getline(cin, this->flightLeave);
//			if (flightLeave == "x") {
//				flightLeave = flightLeaveTmp;
//			}
//			cout << "Change Flight Arrive (input x to not change): ";
//			getline(cin, this->flightArrive);
//			if (flightArrive == "x") {
//				flightArrive = flightArriveTmp;
//			}
//			cout << "Change Flight Available (input x to not change): ";
//			getline(cin, this->flightAvailable);
//			if (flightAvailable == "x") {
//				flightAvailable = flightAvailableTmp;
//			}
//			cout << "Are you sure you want to update flight ? ";
//			cin >> comfirm;
//			if (comfirm) {
//				string update_query = "UPDATE flightdetails_tb SET f_leave = '" + this->flightLeave + "',f_arrive = '" + this->flightArrive + "', f_available = '" + this->flightAvailable + "' WHERE f_id = '" + flightId + "' ";
//				execute(update_query);
//				return 1;
//			}
//			else {
//				return 9999;
//			}
//		}
//		else {
//			cout << "No item in database" << endl;
//			goto comeback;
//		}
//	}
//	else {
//		cout << "No item in database" << endl;
//	}
//	return 0;
//}
