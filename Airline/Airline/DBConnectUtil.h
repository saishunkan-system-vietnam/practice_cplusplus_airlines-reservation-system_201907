#pragma once
#include <iostream>
#include <mysql.h>
#include "Properties.h"
#include <string>

using namespace std;

class DBConnectUtil
{
private:

	MYSQL* conn = nullptr;

protected:

	DBConnectUtil();

	void init();

public:

	MYSQL* getConnnect();

	void closeConnect();

};

