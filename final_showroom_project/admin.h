#pragma once
#include"car.h"
#include "garage.h"
#include "showrooms.h"
#include "service.h" 
//#include "files_op.h"
class admin
{
public:
	static vector<showrooms> list_showrooms;
	static vector<garage> list_garages;
	static vector<service> list_services;
	vector<service> list_services_temp;
	vector<car> list_cars;
	int arr[50];
	int count = 0;
	int j = 0;
	////marwa
	//string name;
	//string password;
	////int id;
	//bool loginasAdmin();
	//bool checkAdmainFound(string name, string pass);

	//admin();
	//~admin();
	////marwa

	//todo
public:
	int admin_id;
	string admin_name;
	string admin_password;

	admin();

	//todo
public:
	void show_all_rooms();
	void delete_car_after_buy(int id);
	void delete_showroom();
	void delete_car();
	void get_cars_from_file();
	void set_cars_to_file();
	int find_car_id();
	void delete_garage();
	void delete_service(int id);
	void delete_service_from_garage();
	void set_services_to_file();
	void admin_view();
	void add_room();
	void add_car();
	void temp();
	void add_garage();
	void add_service();
	void get_garage_from_file();
	void get_service_info_delete();
	void get_service_info();
	void update_car();
	int find_room_id();
	int find_garage_id();
	void update_room();
	void update_service();
	void update_garage();
	void get_rooms_from_file();
	void set_rooms_to_file();
	void set_garages_to_file();


	void delete_showroom_from_cars(int id);

};

