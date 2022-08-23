#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

//// Exceptions 

#include "MyException.h"
#include "DatabaseException.h"
#include "InvalidArgumentException.h"


#include "User.h"
#include "DataBase.h"
#include "Registration.h"








// class StartUp {
// public:
// 	static void Start() {
// 		Database db;
// 		Registration twitter(db);
// 
// 		// twitter.getDatabase().addUser(user);
// 
// 		//mainde yazilacaq her shey burda yazilsin.
// 	}
// 
// 
// 
// 
// };



void main()
{
	Database db;
	Registration twitter(db);

	try
	{
		User user;

		twitter.signUp(user);

		db.addUser(user);

		system("cls");

		string username, password;
		cout << "Enter Username: ";
		getline(cin, username);

		cout << "Enter Password: ";
		getline(cin, password);


		twitter.signIn(username, password);
		cout << endl;
		Sleep(3000);
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
	cout << endl;
	system("pause");
}