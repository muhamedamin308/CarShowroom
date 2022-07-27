#pragma once
#include <string>
#include <vector>
#include"car.h"
#include"service.h"
using namespace std;
class garage
{
public:

	int garage_id;
	string garage_name;
	string garage_location;
	string garage_phone;
	vector <service> listOfService;
public:

	garage();
	void set_garage_information();
};

