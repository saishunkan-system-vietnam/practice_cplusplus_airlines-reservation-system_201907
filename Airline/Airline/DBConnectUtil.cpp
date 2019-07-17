#include "DBConnectUtil.h"


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

void DBConnectUtil::execute(string sql)
{
	string insert_query = sql;

	const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

	qstate = mysql_query(getConnnect(), q);

	if (!qstate)
	{
		cout << endl << "Successfully execute in database." << endl;
		closeConnect();
	}
	else
	{
		cout << "Execute error";
	}
}

MYSQL_RES* DBConnectUtil::select(string sql, string title)
{
	string query = sql;
	const char* q = query.c_str();
	qstate = mysql_query(getConnnect(), q);

	cout << endl;
	cout << title << endl;
	if (!qstate)
	{
		res = mysql_store_result(getConnnect());
		return res;
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(getConnnect()) << endl;
	}
}
