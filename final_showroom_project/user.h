

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "showrooms.h"
#include "admin.h"
#include "buy_rent.h"
#include "service_process.h"
using namespace std;
class user
{
public:
	int id;
	string name;
	string password;
	showrooms show;
	admin admin1;
	vector <buy_rent> list_buy_rent;
	vector <service_process> list_service_process;
	user();
	void get_information();

	void search_about_car(int index_of_user);

	void search_about_garage(int index_of_user);

	void search_about_showroom(int index_of_user);

	void view_showrooms();

	void view_garage();

	void get_buy_rent_file();

	void set_buy_rent_file();

	//bool search_about_car(int Cid,int x);

	void buy_car(int index_of_user);

	void search_about_service(int index_of_user);

	void rent_car(int index_of_user);

	void get_service_process_file();

	void set_service_process_file();

	void use_service(int index_of_user);

	void history(int index_of_user);

};

