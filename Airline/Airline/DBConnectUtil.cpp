#include "DBConnectUtil.h"

template<class T>
DBConnectUtil<T>::DBConnectUtil()
{
	init();
}

template<class T>
MYSQL* DBConnectUtil<T>::getConnnect()
{
	return this->conn;
}

template<class T>
void DBConnectUtil<T>::closeConnect()
{
	mysql_close(this->conn);
}

template<class T>
void DBConnectUtil<T>::init()
{
	this->conn = mysql_init(0);
	this->conn = mysql_real_connect(conn, property.HOST, property.USER_NAME, property.PASSWORD, property.DB_NAME, property.PORT, NULL, 0);
	if (!conn) {
		std::cout << "Error connect";
		exit(1);
	}
}

template<class T>
void DBConnectUtil<T>::execute(T sql)
{
	T insert_query = sql;

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

template<class T>
MYSQL_RES* DBConnectUtil<T>::select(T sql, T title)
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
