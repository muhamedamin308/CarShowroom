#pragma once
#include <string>
#include <vector>
#include"car.h"
//#include "files_op.h"


class showrooms
{
public:

	int showrooms_id;
	string showrooms_name;
	string showrooms_location;
	string showrooms_phone;
	vector<car> ListOfCars;
public:

	showrooms();
	void set_room_informatin();
	void add_car();
	void get_cars_from_file();
	void get_cars_from_file(int id);
	void set_cars_to_file();
	void update_car();


};


