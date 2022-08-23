#pragma once





class Registration
{
private:
	Database _database;

public:

	Registration(const Database& database)
	{
		_database = database;
	}

	void signIn(string username, string password)
	{
		if (_database.getUserByUsername(username))
			if (_database.getUserByPassword(password))
				cout << " XOS GELMISIZ!!!!!!!!";

	}

	void signUp(User& user)
	{
		string name, surname, username, password;
		short age;
		size_t id;

		id = user.getId();
		id++;
		user.setId(id);


		cout << "Name: ";
		getline(cin, name);
		user.setName(name);

		cout << "Surname: ";
		getline(cin, surname);
		user.setSurname(surname);

		cout << "Age: ";
		cin >> age;
		user.setAge(age);

		cin.ignore();

		cout << "Username: ";
		getline(cin, username);
		user.setUsername(username);

		cout << "Password: ";
		getline(cin, password);
		user.setPassword(password);


		if (_database.getSize() > 1)
		{
			for (size_t i = 0; i < _database.getSize(); i++)
				if (_database[i]->getUsername() == user.getUsername())
					throw DatabaseException("Bu username istifade olunub", __FILE__, __TIME__, __LINE__);
		}

		cout << endl;
		_database.addUser(user);
	}


	size_t getSize() { return _database.getSize(); }
	
	User*& operator[](const size_t& index)
	{
		return _database[index];
	}
};