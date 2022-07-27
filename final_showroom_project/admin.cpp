#include "admin.h"
#include<iostream>
#include<string>
#include "Register.h"
#include<istream>
#include<ctime>
#include<vector>
#include <sstream>
#include<fstream>
using namespace std;
//initialize for static vectors
vector<garage>admin::list_garages;
vector<service>admin::list_services;
vector<showrooms> admin::list_showrooms;

void admin::delete_car_after_buy(int id)
{
	for (int i = 0; i < list_cars.size(); i++)
	{
		if (list_cars[i].car_id == id) {
			list_cars.erase(list_cars.begin() + i);
			break;
		}

	}
	set_cars_to_file();
}
void admin::delete_showroom() {
	get_rooms_from_file();
	int id;
	id = find_room_id();
	for (int i = 0; i < list_showrooms.size(); i++) {
		if (id == list_showrooms[i].showrooms_id) {
			list_showrooms.erase(list_showrooms.begin() + i);
			cout << "Deleted successufully " << endl;
			break;
		}

	}
	set_rooms_to_file();
	delete_showroom_from_cars(id);
}
void admin::delete_showroom_from_cars(int id) {
	get_cars_from_file();

	bool test;
	for (int i = 0; i < list_cars.size(); i++) {
		test = false;
		if (id == list_cars[i].showroom_id) {
			if (((i + 1) != list_cars.size()) && (id == list_cars[i + 1].showroom_id)) {

				test = true;

			}
			list_cars.erase(list_cars.begin() + i);



			if (test == true)
				i--;
		}
	}
	list_cars.pop_back();
	set_cars_to_file();
}
void admin::delete_car() {
	get_cars_from_file();
	int id;
	id = find_car_id();
	for (int i = 0; i < list_cars.size(); i++)
	{
		if (list_cars[i].car_id == id) {
			list_cars.erase(list_cars.begin() + i);
			cout << "Deleted successfully " << endl;
			break;
		}

	}
	list_cars.pop_back();
	set_cars_to_file();

}
void admin::get_cars_from_file() {
	car temp;
	fstream car_file;
	car_file.open("cars.text", ios::in);
	list_cars.clear();
	string s;
	while (!car_file.eof()) {

		getline(car_file, s, ',');
		temp.showroom_id = atoi(s.c_str());//convert to int
		getline(car_file, s, ',');
		temp.car_id = atoi(s.c_str());//convert to int
		getline(car_file, s, ',');
		temp.car_make = s;
		getline(car_file, s, ',');
		temp.car_model = s;
		getline(car_file, s, ',');
		temp.car_price = atof(s.c_str());//convert to double
		getline(car_file, s, ',');
		temp.car_year = atoi(s.c_str());//convert to int
		getline(car_file, s, ',');
		temp.rented = atoi(s.c_str());//convert to int
		getline(car_file, s);
		temp.returned_time = atoi(s.c_str());//convert to int
		if (temp.returned_time < time(0)) {
			temp.rented = true;
		}
		list_cars.push_back(temp);

	}
	//list_cars.pop_back();
	car_file.close();
}

void admin::set_cars_to_file() {
	fstream file_out;
	file_out.clear();
	file_out.open("cars.text", ios::out);
	for (int i = 0; i < list_cars.size(); i++) {
		file_out << list_cars[i].showroom_id << ',' << list_cars[i].car_id << ',' << list_cars[i].car_make << ',' << list_cars[i].car_model << ',' << list_cars[i].car_price << ',' << list_cars[i].car_year << ',' << list_cars[i].rented << ',' << list_cars[i].returned_time << endl;
	}
	file_out.close();
}

int admin::find_car_id() {
	cout<<"\n----------------------------------------------------\n";
	bool founded = false;

	int id;
	int action;
	get_cars_from_file();
	cout << "\n\t\tEnter car id :\t";
	cin >> id;
	for (int i = 0; i < list_cars.size(); i++) {
		if (list_cars[i].car_id == id) {
			founded = true;

			break;
		}

	}
	if (!founded) {
		cout << "\n There isn't car id like that!! to enter id again press 1 to go for main press 2" << endl;
		cout << "\t\tEnter your decision : "; cin >> action;
		switch (action)
		{
		case 1: find_car_id();
			break;
		case 2:admin_view();
		default:exit;
			break;
		}
		return 0;
	}
	else {
		cout << "\n\t\tFounded" << endl;
		return id;
	}
}

void admin::delete_garage() {
	int id = 0;
	id = find_garage_id();
	get_garage_from_file();
	for (int i = 0; i < list_garages.size(); i++) {
		if (id == list_garages[i].garage_id) {
			list_garages.erase(list_garages.begin() + i);
			cout << "Deleted successfully" << endl;
			set_garages_to_file();
			break;
		}
	}
	delete_service(id);
}void admin::delete_service(int id) {
	get_service_info_delete();
	bool test;
	for (int i = 0; i < list_services.size(); i++) {
		test = false;
		if (list_services[i].service_garage_id == id) {

			if (((i + 1) != list_services.size()) && (id == list_services[i + 1].service_garage_id)) {
				test = true;
			}

			list_services.erase(list_services.begin() + i);

			if (test == true) {
				i--;
			}
		}
	}
	//list_services.pop_back();
	set_services_to_file();
}
//void admin::delete_service(int id) {
//	get_service_info_delete();
//	for (int i = 0; i < list_services.size(); i++) {
//		if (list_services[i].service_garage_id == id) {
//			list_services.erase(list_services.begin() + i);
//		}
//	}
//	set_services_to_file();
//}
void admin::delete_service_from_garage() {
	get_service_info_delete();
	int id;
	int id_garage = 0;
	int temp_garage_id = 0;
	int temp_service_id = 0;
	bool flag = false;
	bool flag_service_id = false;
	bool flag_garage_id = false;
	bool matching = false;
	cout << "\n\t\t Enter id of service that you want to delete : ";
	cin >> id;

	while (flag == false) {
		for (int i = 0; i < list_services.size(); i++) {
			if (id == list_services[i].service_id) {
				flag_service_id = true;
				temp_service_id = id;
				break;
			}
		}
		if (flag_service_id == true) {
			while (flag_garage_id == false) {
				cout << "\n\t\t Enter garage id that you want to delete this service from : ";
				cin >> id_garage;
				for (int i = 0; i < list_services.size(); i++) {
					if (id_garage == list_services[i].service_garage_id) {
						flag_garage_id = true;
						temp_garage_id = id_garage;
						break;
					}
				}
				if (flag_garage_id == false) {
					cout << "\n\t\tWRONG GARAGE ID , RETRY ...." << endl;
					continue;
				}
			}
		}
		else if (flag_service_id == false) {
			cout << "\n\t\tWRONG ID , RETRY....";
			delete_service_from_garage();
			break;
		}
		if (flag_garage_id == true) {
			flag = true;
			break;
		}

	}

	for (int i = 0; i < list_services.size(); i++) {
		if (list_services[i].service_id == temp_service_id && list_services[i].service_garage_id == temp_garage_id) {
			list_services.erase(list_services.begin() + i);
			matching = true;
			cout << "\n\t\tDeleted successfully" << endl;
			set_services_to_file();
			break;
		}
	}
	if (matching == false) {

		cout << "\n\t\tNO MATCH , RETRY....." << endl;
		delete_service_from_garage();

	}

}
void admin::set_services_to_file()
{
	fstream service_file;
	service_file.clear();
	service_file.open("service.text", ios::out);
	for (int i = 0; i < list_services.size(); i++) {
		service_file << endl << list_services[i].service_id << ',' << list_services[i].service_name << ',' << list_services[i].service_price << ',' << list_services[i].service_garage_id;

	}

	service_file.close();

}

void admin::admin_view() {
	Register ss;


	int action;
	cout<<"\n----------------------------------------------------\n";
	cout << "\n\t\t\t>>> welcome to our project<<<\n\n";
	cout << "\n\t\t1- Add .";
	cout << "\n\t\t2- Update .";
	cout << "\n\t\t3- Delete .";
	cout << "\n\t\t4- log out .";
	cin >> action;
	switch (action)
	{

	case 1:cout<<"\n----------------------------------------------------\n";
		cout << "\n\t\t1- Add car .";
		cout << "\n\t\t2- Add showroom .";
		cout << "\n\t\t3- Add garage .";
		cout << "\n\t\t4- Add service .";
		cout << "\n\t\t5- Back to main .";
		cout << "\n\tEnter your Choice : ";
		cin >> action;
		switch (action)
		{
		case 1:add_car();
			break;
		case 2:add_room();
			break;
		case 3:add_garage();
			break;
		case 4:add_service();
			break;
		case 5:admin_view();
			break;
		default:cout << "\n\t\t\t!!!unavailable process";
			break;
		}
		//admin_view();
		break;
	case 2:cout<<"\n----------------------------------------------------\n";
		cout << "\n\t\t1- update car .";
		cout << "\n\t\t2- update showroom .";
		cout << "\n\t\t3- update garage .";
		cout << "\n\t\t4- update service .";
		cout << "\n\t\t5- back to main  .";
		cin >> action;
		switch (action)
		{
		case 1:update_car();
			break;
		case 2:update_room();
			break;
		case 3:update_garage();
			break;
		case 4:update_service();
			break;
		case 5:admin_view();
			break;
		default:cout << "\n\t\t\t!!!unavailable process";
			break;
		}
		//admin_view();
		break;
	case 3:cout<<"\n----------------------------------------------------\n";
		cout << "\n\t\t1- delete car .";
		cout << "\n\t\t2- delete showroom .";
		cout << "\n\t\t3- delete garage .";
		cout << "\n\t\t4- delete service .";
		cout << "\n\t\t5- back to main.";
		cin >> action;
		switch (action)
		{
		case 1:delete_car();
			break;
		case 2:delete_showroom();
			break;
		case 3:delete_garage();
			break;
		case 4:delete_service_from_garage();
			break;
		case 5:admin_view();
			break;
		default:cout << "\n\t\t\t!!!!unavilable process";
			admin_view();
			break;
		}

		break;
	case 4:
		cout<<"\n----------------------------------------------------\n";
		ss.menuView();
		break;
	default:

		admin_view();
		break;
	}
	admin_view();
}

void admin::get_garage_from_file() {
	garage temp;
	fstream garage_file;
	garage_file.open("garage.text", ios::in);
	list_garages.clear();
	string s;
	while (!garage_file.eof()) {
		getline(garage_file, s, ',');
		temp.garage_id = atoi(s.c_str());
		getline(garage_file, s, ',');
		temp.garage_name = s;
		getline(garage_file, s, ',');
		temp.garage_location = s;
		getline(garage_file, s);
		temp.garage_phone = s;
		list_garages.push_back(temp);
	}
	list_garages.pop_back();   // ليه هيمسح اخر حاجه ؟


}
void admin::get_service_info_delete() {
	service temp;
	fstream service_file;
	service_file.open("service.text", ios::in);
	list_services.clear();
	string s;

	while (!service_file.eof()) {
		getline(service_file, s, ',');
		temp.service_id = atoi(s.c_str());
		getline(service_file, s, ',');
		temp.service_name = s;
		getline(service_file, s, ',');
		temp.service_price = s;
		getline(service_file, s);
		temp.service_garage_id = atoi(s.c_str());
		list_services.push_back(temp);
	}
	//list_services.pop_back();
}
void admin::get_service_info()
{
	service temp;
	fstream service_file;
	service_file.open("service.text", ios::in);
	list_services.clear();
	string s;

	while (!service_file.eof()) {
		getline(service_file, s, ',');
		temp.service_id = atoi(s.c_str());
		getline(service_file, s, ',');
		temp.service_name = s;
		getline(service_file, s, ',');
		temp.service_price = s;
		getline(service_file, s);
		temp.service_garage_id = atoi(s.c_str());
		list_services.push_back(temp);
	}

	for (int i = 0; i < list_services_temp.size(); i++) {

		list_services.push_back(list_services_temp[i]);

	}
	list_services_temp.clear();
	// list_services.pop_back();
}

void admin::get_rooms_from_file() {
	showrooms temp;
	fstream rooms_file;
	rooms_file.open("rooms.text", ios::in);
	list_showrooms.clear();//clear data of vector to not dublicate DATA
	string s;

	while (!rooms_file.eof()) {
		getline(rooms_file, s, ',');
		temp.showrooms_id = atoi(s.c_str());
		getline(rooms_file, s, ',');
		temp.showrooms_name = s;
		getline(rooms_file, s, ',');
		temp.showrooms_location = s;
		getline(rooms_file, s);
		temp.showrooms_phone = s;
		list_showrooms.push_back(temp);
	}
	list_showrooms.pop_back();
	rooms_file.close();
}


void admin::set_rooms_to_file() {
	fstream rooms_file;
	rooms_file.clear();
	rooms_file.open("rooms.text", ios::out);
	for (int i = 0; i < list_showrooms.size(); i++) {
		rooms_file << list_showrooms[i].showrooms_id << ',' << list_showrooms[i].showrooms_name << ',' << list_showrooms[i].showrooms_location << ',' << list_showrooms[i].showrooms_phone << endl;

	}
	rooms_file.close();
}
void admin::set_garages_to_file() {
	fstream garage_file;
	garage_file.clear();
	garage_file.open("garage.text", ios::out);
	for (int i = 0; i < list_garages.size(); i++) {
		garage_file << list_garages[i].garage_id << ',' << list_garages[i].garage_name << ',' << list_garages[i].garage_location << ',' << list_garages[i].garage_phone << endl;

	}
	garage_file.close();
}

int admin::find_room_id() {
	cout<<"\n----------------------------------------------------\n";
	bool founded = false;
	int id;
	int action;
	get_rooms_from_file();
	show_all_rooms();
	cout << "\n\t\tEnter showroom id : ";
	cin >> id;
	for (int i = 0; i < list_showrooms.size(); i++) {
		if (list_showrooms[i].showrooms_id == id) {
			founded = true;
			break;
		}

	}
	if (!founded) {
		cout << "\n\t\t there isn't show room id like that!! to enter id again press 1 to go for main press 2 ...";
		cout << " \n\t Your Decision is : "; cin >> action;
		switch (action)
		{
		case 1: find_room_id();
			break;
		case 2:admin_view();
		default:exit;
			break;
		}
		return 0;
	}
	else {
		cout << "\n\t\tFounded" << endl;
		return id;
	}
	//eturn id;
}
int admin::find_garage_id()
{

	cout<<"\n----------------------------------------------------\n";
	bool founded = false;
	int id;
	int action;
	get_garage_from_file();
	cout << "\n\t\tEnter garage id :";
	cin >> id;
	for (int i = 0; i < list_garages.size(); i++) {
		if (list_garages[i].garage_id == id) {
			founded = true;

			break;
		}

	}
	if (founded == false) {
		cout << "\n\t\t there isn't garage id like that!! to enter id again press 1 , to go for main press 2";
		cout << " \n\t Your Decision is : "; cin >> action;
		switch (action)
		{
		case 1: find_garage_id();
			break;
		case 2:admin_view();
		default:exit;
			break;
		}
		return id;
	}
	else {
		cout << "\nfounded" << endl;
		return id;
	}

}

void admin::add_garage() {
	garage newgarage;

	get_garage_from_file();
	newgarage.set_garage_information();
	list_garages.push_back(newgarage);
	set_garages_to_file();

}


void admin::add_room() {

	showrooms newroom;

	get_rooms_from_file();
	newroom.set_room_informatin();

	list_showrooms.push_back(newroom);
	set_rooms_to_file();
}
void admin::show_all_rooms() {
	cout << "\n\t\t All showrooms\n .";
	cout << "\nshowroom id |  " << "showroom name | " << "showroom location |  " << "showroom phone |  " << endl;
	for (int i = 0; i < list_showrooms.size(); i++) {
		cout << list_showrooms[i].showrooms_id << "  " << list_showrooms[i].showrooms_name << "  " << list_showrooms[i].showrooms_location << "  " << list_showrooms[i].showrooms_phone << endl;
	}



}
void admin::add_car() {
	int room_id;
	room_id = find_room_id();
	for (int i = 0; i < list_showrooms.size(); i++) {
		if (room_id == list_showrooms[i].showrooms_id) {
			list_showrooms[i].add_car();
			break;
		}
	}
}
void admin::temp() {

	service s;
	cout << "\n\t\tEnter service  name : ";
	cin >> s.service_name;
	cout << "\n\t\tEnter service price : ";
	cin >> s.service_price;

	list_services_temp.push_back(s);

}
//void admin::add_service() {
//	temp();
//	get_garage_from_file();
//	bool flag = false;
//	bool flag2 = false;
//	int action;
//	while (flag == false) {
//		int id;
//		cout << "\n\t\tEnter garage id that you want to add service to";
//		cin >> id;
//		for (int i = 0; i < list_garages.size(); i++) {
//			if (id == list_garages[i].garage_id) {
//				flag2 = true;
//				list_services_temp.back().service_garage_id = id;
//				cout<<"\n----------------------------------------------------\n";
//				cout << "\n\t\t\tFounded" << endl;
//				cout << " \t\tpress 1 if you want to add one more garage id to this service" << endl;
//				cout << " \t\tpress 2 if you want to finish and return to main menu" << endl;
//				cout << " \t\tpress 3 if you want to  add one more service" << endl;
//				cout << " \t Your Decision is : "; cin >> action;
//				if (action == 1) {
//					list_services_temp.push_back(list_services_temp.back());
//					break;
//				}
//				else if (action == 2) {
//					get_service_info();
//					set_services_to_file();
//					cout << "\n\t\tAdded successfully" << endl;
//					flag = true;
//					break;
//				}
//				else if (action == 3) {
//					add_service();
//					break;
//				}
//			}
//		}
//		if (flag2 == false) {
//			cout << "\n\t\tWRONG  ID !!!" << endl;
//			cout << " \t\t Retry.." << endl;
//			continue;
//		}
//		else {
//			continue;
//		}
//		if (flag) {
//			break;
//		}
//	}
//}
void admin::add_service() {
	temp();
	get_garage_from_file();
	bool flag = false;
	bool flag2 = false;
	int action;
	while (flag == false) {
		int id;
		cout << "\n\t\tEnter garage id that you want to add service to";
		cin >> id;
		for (int i = 0; i < list_garages.size(); i++) {
			if (id == list_garages[i].garage_id) {
				flag2 = true;
				list_services_temp.back().service_garage_id = id;
				cout<<"\n----------------------------------------------------\n";
				cout << "\n\t\t\tFounded" << endl;
				cout << " \t\tpress 1 if you want to finish and return to main menu" << endl;
				cout << " \t\tpress 2 if you want to  add one more service" << endl;
				cout << " \t Your Decision is : "; cin >> action;

				if (action == 1) {
					get_service_info();
					set_services_to_file();
					cout << "\n\t\tAdded successfully" << endl;
					flag = true;
					break;
				}
				else if (action == 2) {
					add_service();
					break;
				}
			}
		}
		if (flag2 == false) {
			cout << "\n\t\tWRONG  ID !!!" << endl;
			cout << " \t\t Retry.." << endl;
			int x;
			cout << " 1. retry " << endl;
			cout << " 2. back to add service" << endl;
			cout << " 3. back to menu" << endl;
			cin >> x;
			if (x == 1) {
				continue;
			}
			else if (x == 2)
				add_service();
			else
				admin_view();
		}
		else {
			continue;
		}
		if (flag) {
			break;
		}
	}
}

void admin::update_car() {
	showrooms s;
	s.update_car();

}
void admin::update_room() {
	get_rooms_from_file();
	int id, action;
	bool found = false;
	cout << "\n\t\t>>>you are going to modify showroom<<<";
	cout << "\n\tEnter room id : ";
	cin >> id;
	for (int i = 0; i < list_showrooms.size(); i++) {
		if (id == list_showrooms[i].showrooms_id) {
			cout << "\n\t\tRoom id \t|\t Room Name \t|\t Room Location \t|\t Room Phone number";
			cout << "\n\t\told room inf :: " << list_showrooms[i].showrooms_id << "  " << list_showrooms[i].showrooms_name << ' ' << list_showrooms[i].showrooms_location << " " << list_showrooms[i].showrooms_phone;
			cout << "\n\tEnter new room name : ";
			cin >> list_showrooms[i].showrooms_name;
			cout << "\n\tEnter new room location : ";
			cin >> list_showrooms[i].showrooms_location;
			cout << "\n\tEnter new room phone : ";
			cin >> list_showrooms[i].showrooms_phone;
			found = true;
		}
	}
	if (found == false) {
		cout << "\n\t\tyou entered wrong id to enter id again press 1 to back for main press 2";
		cout << " \n\t Your Decision is : "; cin >> action;
		switch (action)
		{
		case 1:update_room();
			break;
		case 2:
			admin_view();
			break;
		default:exit;
			break;
		}
	}
	set_rooms_to_file();
	admin_view();
}

void admin::update_garage() {
	cout<<"\n----------------------------------------------------\n";
	int id, action;
	bool founded = false;
	get_garage_from_file();

	cout << "\n\t id \t| name \t| location \t| phone\n";
	for (int i = 0; i < list_garages.size(); i++) {
		cout << "\t" << list_garages[i].garage_id << "  " << list_garages[i].garage_name << "  " << list_garages[i].garage_location << "   " << list_garages[i].garage_phone << endl;
	}
	cout << "\n\t\tEnter garage id :";
	cin >> id;
	for (int i = 0; i < list_garages.size(); i++)
	{
		if (id == list_garages[i].garage_id) {
			founded = true;
			cout << "\n\tEnter new name : ";
			cin.ignore();
			getline(cin, list_garages[i].garage_name);
			cout << "\n\tEnter new location : ";
			getline(cin, list_garages[i].garage_location);
			cout << "\n\tEnter new phone  : ";
			cin >> list_garages[i].garage_phone;
			set_garages_to_file();
			cout << "\n\t\t>>>>updated successfully<<<<";
			admin_view();
			break;
		}
	}

	if (founded == false) {
		cout << "\n\t\tYou entered wrong id to enter again press 1 to back for menu press 2";
		cout << " \n\t Your Decision is : "; cin >> action;
		switch (action)
		{
		case 1:update_garage();
			break;
		case 2:admin_view();
			break;
		default:exit;
			break;
		}
	}



}
void admin::update_service() {
	get_garage_from_file();
	int id_tg, id_ts, action;
	int index = 0;//for temp list
	bool founded_garage = false;
	bool founded_service = false;
	cout << "\n\t\t>>> you are going to update service <<<";
	cout << "\n\t id \t| name \t| location \t| phone\n  ";
	for (int i = 0; i < list_garages.size(); i++) {
		cout << "\t" << list_garages[i].garage_id << "  " << list_garages[i].garage_name << "  " << list_garages[i].garage_location << "   " << list_garages[i].garage_phone << endl;
	}
	cout << "\n\t\t>>>>> you are going to update service <<<<\n";

	cout << "\n\tEnter garage id : ";
	cin >> id_tg;

	for (int i = 0; i < list_garages.size(); i++) {
		if (id_tg == list_garages[i].garage_id) {
			founded_garage = true;
			break;
		}
	}

	if (founded_garage == true) {
		cout<<"\n----------------------------------------------------\n";
		get_service_info();
		cout << "\n\rservice id " << " \t| " << "name " << " \t| " << "price \n";
		for (int i = 0; i < list_services.size(); i++) {
			if (id_tg == list_services[i].service_garage_id) {//show all services in that garage (id)
				cout << list_services[i].service_id << " \t " << list_services[i].service_name << " \t " << list_services[i].service_price << endl;

			}

		}
		cout << "\n\t Enter service id :";
		cin >> id_ts;
		for (int i = 0; i < list_services.size(); i++) {
			if (id_ts == list_services[i].service_id && id_tg == list_services[i].service_garage_id) {// اوعااا 3 عشان فروح الشقيه
				founded_service = true;
				cin.ignore();
				cout << "\n\t Enter new name : ";
				getline(cin, list_services[i].service_name);
				cout << "\n\t Enter new price : ";
				cin >> list_services[i].service_price;
				set_services_to_file();
				set_garages_to_file();
				break;
			}

		}
		if (founded_service == false) {
			cout << "\n\t\tYou entered wrong service id \n";
		}

	}
	else if (founded_garage == false) {
		cout << "\n\t\tYou entered wrong garage id to enter  again press 1 for back for main menu press 2 ";
		cout << " \n\t Your Decision is : "; cin >> action;
		switch (action)
		{
		case 1:update_service();
			break;
		case 2:admin_view();
			break;
		default:exit;
			break;
		}
	}
	admin_view();
}
//todo

admin::admin() {
	srand(time(0));
	admin_id = rand();
	admin_name = " ";
	admin_password = " ";
}

//todo