#pragma once
#include <iostream>
#include <mysql.h>
#include "Properties.h"
#include <string>

using namespace std;

template<typename T>
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

	void execute(T sql);

	MYSQL_RES* select(T sql, T title = "");
};

