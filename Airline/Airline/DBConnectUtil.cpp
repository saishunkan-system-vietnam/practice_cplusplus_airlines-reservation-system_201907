#include "DBConnectUtil.h"

int qstateUtil;
MYSQL_RES* resUtil;

DBConnectUtil::DBConnectUtil()
{
	init();
}

MYSQL* DBConnectUtil::getConnnect()
{
	return this->conn;
}

void DBConnectUtil::closeConnect()
{
	mysql_close(this->conn);
}

void DBConnectUtil::init()
{
	this->conn = mysql_init(0);
	this->conn = mysql_real_connect(conn, property.HOST, property.USER_NAME, property.PASSWORD, property.DB_NAME, property.PORT, NULL, 0);
	if (!conn) {
		std::cout << "Error connect";
		exit(1);
	}
}

void DBConnectUtil::addNew(string sql)
{
	string insert_query = sql;

	const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

	qstateUtil = mysql_query(getConnnect(), q);

	if (!qstateUtil)
	{
		cout << endl << "Successfully added in database." << endl;
		closeConnect();
	}
	else
	{
		cout << "Insert error";
	}
}

void DBConnectUtil::update(string sql)
{
	string insert_query = sql;

	const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

	qstateUtil = mysql_query(getConnnect(), q);

	if (!qstateUtil)
	{
		cout << "Successfully updated in database." << endl;
		closeConnect();
	}
	else
	{
		cout << "Update error";
	}
}

MYSQL_RES* DBConnectUtil::select(string sql, string title)
{
	string query = sql;
	const char* q = query.c_str();
	qstateUtil = mysql_query(getConnnect(), q);

	cout << endl;
	cout << title << endl;
	if (!qstateUtil)
	{
		resUtil = mysql_store_result(getConnnect());
		return resUtil;
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(getConnnect()) << endl;
	}
}
