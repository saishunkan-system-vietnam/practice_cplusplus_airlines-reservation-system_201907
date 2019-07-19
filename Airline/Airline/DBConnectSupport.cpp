#include "DBConnectSupport.h"
template<typename T>
DBConnectSupport<T>* DBConnectSupport<T>::instance = nullptr;

template<typename T>
DBConnectSupport<T>* DBConnectSupport<T>::GetInstance()
{
	if (!instance) {
		instance = new DBConnectSupport;
	}
	return instance;
}
