#pragma once
#include <iostream>
#include <mysql.h>
#include "Properties.h"
#include <string>

using namespace std;

class DBConnectUtil
{
private:

	MYSQL* conn;

	ConnectProperties property;

public:
	int qstate;

	MYSQL_RES* res;

	MYSQL_ROW row;

	DBConnectUtil();

	MYSQL* getConnnect();

	void closeConnect();

	void init();

	void execute(string sql);

	MYSQL_RES* select(string sql, string title = "");
};

