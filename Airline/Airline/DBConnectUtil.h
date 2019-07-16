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

	DBConnectUtil();

	MYSQL* getConnnect();

	void closeConnect();

	void init();

	void addNew(string sql);

	void update(string sql);

	MYSQL_RES* select(string sql, string title = "");
};

