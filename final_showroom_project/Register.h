#pragma once
#include "user.h"
#include "admin.h"
#include <string>
#include<vector>
#include <cstdlib>
#include <fstream>
class Register
{
public:

	vector<user> users_list;
	vector<admin> admins_list;
	int index_of_user;
	int user_id;
	fstream list;
	void get_admin_from_file();
	void get_users_from_file();
	void set_admin_to_file();
	void set_users_to_file();
	void signup();
	/*int return_user_id(int id);
	int return_user_index(int index);*/
	void signin();
	/*int signin2();*/
	void menuView();
	void login_admin();
	void user_view(int index_of_user);
	void search_view();
};

