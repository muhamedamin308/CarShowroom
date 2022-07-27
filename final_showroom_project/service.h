#pragma once
#include <string>
#include <vector>

using namespace std;
class service
{
public:

	int service_id;
	string service_name;
	string service_price;
public:

	service();
	void set_service_information();
	void add_service();
	int service_garage_id;



};

