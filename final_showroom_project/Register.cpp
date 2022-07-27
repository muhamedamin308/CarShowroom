#include "Register.h"
#include <iostream>

using namespace std;

void Register::get_admin_from_file() {
	string s;
	admin temp;
	admins_list.clear();
	list.open("adminsinformation.txt", ios::in);
	while (!list.eof()) {

		getline(list, s, '|');

		temp.admin_id = atoi(s.c_str());

		getline(list, s, '|');

		temp.admin_name = s;
		getline(list, s);

		temp.admin_password = s;
		/*cout << temp.admin_name;
		cout << temp.admin_id<<endl;*/

		admins_list.push_back(temp);
	}
	list.close();
	//admins_list.pop_back();
//	cout <<">>>>>>>>" << admins_list.size();

}
void Register::get_users_from_file() {
	string s;
	user temp;

	users_list.clear();//to not dublicate data in vector
	list.open("usersinformation.txt", ios::in);
	while (!list.eof()) {
		//cout << "###";
		getline(list, s, '|');

		temp.id = atoi(s.c_str());

		getline(list, s, '|');

		temp.name = s;
		getline(list, s);

		temp.password = s;
		users_list.push_back(temp);
	}
	users_list.pop_back();//becouse there is un decleard user at last of vector 0|0|0

	list.close();
}
void Register::set_admin_to_file() {
	list.open("adminsinformation.txt", ios::out);
	list.clear();
	for (int i = 0; i < admins_list.size(); i++) {
		list << admins_list[i].admin_id << '|' << admins_list[i].admin_name << '|' << admins_list[i].admin_password << endl;
	}
	list.close();

}
void Register::set_users_to_file() {

	list.open("usersinformation.txt", ios::out);
	list.clear();
	for (int i = 0; i < users_list.size(); i++) {
		list << users_list[i].id << '|' << users_list[i].name << '|' << users_list[i].password << endl;
	}
	list.close();
}
void Register::signup()
{

	get_users_from_file();

	user newuser;

	newuser.get_information();

	users_list.push_back(newuser);
	set_users_to_file();


}

void Register::signin() {

	bool founded = false;
	int action;
	int index_of_user;
	cout<<"\n----------------------------------------------------\n";
	string pass, name;
	cout << "\n Enter your name :";
	cin >> name;
	cout << "\n Enter your password :";
	cin >> pass;
	get_users_from_file();
	for (int i = 0; i < users_list.size(); i++) {
		if ((name == users_list[i].name) && (pass == users_list[i].password)) {
			index_of_user = i;
			founded = true;
			cout<<"\n----------------------------------------------------\n";
			user_view(index_of_user);


		}
	}
	if (founded == false) {
		cout << "\n !!!Wrong password or name to sign in again press 1 to back to main menu press 2  :";
		cin >> action;
		switch (action)
		{
		case 1:signin();
			break;
		case 2:menuView();
			break;
		default:exit;
			break;
		}
	}

}


void Register::menuView() {
	int choice = 4;
	int index_of_user;
	cout << "press Number from 1 to 3 " << endl;
	cout << "........................................." << endl;
	cout << "1-Login as Admin.." << endl;
	cout << "2-Login as a User.." << endl;
	cout << "3-Signup as user.." << endl;
	cout << "4-Exist.." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:login_admin();
		break;
	case 2: signin();

		break;
	case 3:signup();
		cout<<"\n----------------------------------------------------\n";
		menuView();
		break;
	case 4:cout << ">>>>>>i will exit<<<<<<<<<<";
		_Exit(10);
		break;
	default:cout<<"\n----------------------------------------------------\n";
		cout << "\nSorry wrong choice ";
		menuView();
		break;
	}
}
void Register::login_admin() {
	cout<<"\n----------------------------------------------------\n";
	string pass, name;
	bool founded = false;
	int action, index;

	cout << "\n Enter your name :";
	cin >> name;
	cout << "\n Enter your password :";
	cin >> pass;

	get_admin_from_file();

	//cout << admins_list.size();
	for (int i = 0; i < admins_list.size(); i++) {
		//cout << name << "  = " << admins_list[i].admin_name << "  " << pass << "=" << admins_list[i].admin_password<<endl;
		if ((name == admins_list[i].admin_name) && (pass == admins_list[i].admin_password)) {
			founded = true;
			index = i;
			break;

		}
	}
	if (!founded) {
		cout << "\n !!!Wrong password or name to sign in again press 1 to back to main menu press 2  :";
		cin >> action;
		switch (action)
		{
		case 1:signin();
			break;
		case 2:menuView();
			break;
		default:exit;
			break;
		}
	}
	else {
		cout << "\n\t\t Successful login";
		admins_list[index].admin_view();
	}
}
void Register::user_view(int index_of_user) {
	int index;
	int action;
	user u;

	cout << "press 1 , 2 , 3 , 4 or 5 " << endl;
	cout << "\t\t 1. Buy a car" << endl; //done
	cout << "\t\t 2. Rent a car" << endl; // done
	cout << "\t\t 3. For search" << endl;
	cout << "\t\t 4. View garage" << endl;
	cout << "\t\t 5. View showroom" << endl;
	cout << "\t\t 6. For services" << endl;
	cout << "\t\t 7. For your history " << endl;
	cout << "\t\t 8. Log out " << endl;
	cout << "\n\tYour decision is : "; cin >> action;
	switch (action)
	{
	case 1:
		u.buy_car(index_of_user);
		break;
	case 2:
		u.rent_car(index_of_user);
		break;
	case 3:
		search_view();
		break;
	case 4:
		u.view_garage();
		break;
	case 5:
		u.view_showrooms();
		break;
	case 6:
		u.use_service(index_of_user);
		break;
	case 7:
		u.history(index_of_user);
		break;
	case 8:cout<<"\n----------------------------------------------------\n";
		menuView();
		break;
	default:exit;
		break;
	}
	user_view(index_of_user);
}
void Register::search_view() {
	cout<<"\n----------------------------------------------------\n";
	user user;
	int action;
	cout << "\t\t 1. Search for car" << endl;
	cout << "\t\t 2. Search for showroom" << endl;
	cout << "\t\t 3. Search for garage" << endl;
	cout << "\t\t 4. Search for service" << endl;
	cout << "\n\tYour decision is : \t"; cin >> action;
	switch (action)
	{
	case 1: user.search_about_car(index_of_user);
		break;
	case 2: user.search_about_showroom(index_of_user);
		break;
	case 3: user.search_about_garage(index_of_user);
		break;
	case 4: user.search_about_service(index_of_user);
		break;
	default:exit;
		break;
	}

}

