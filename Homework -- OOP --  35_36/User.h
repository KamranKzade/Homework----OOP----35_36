#pragma once





class User
{
private:
	
	size_t _id = 0;
	string _username = "";
	string _password = "";
	string _name = "";
	string _surname = "";
	short _age = 0;

public:
	User() = default;

	User(size_t id, string username, string password, string name, string surname, short age)
	{
		_id = id;
		_username = username;
		_password = password;
		_name = name;
		_surname = surname;
	}

	const string getUsername() const { return _username; }
	const  string getPassword() const { return _password; }
	const string getName() const { return _name; }
	const  string getSurname() const { return _surname; }
	const size_t getId() const { return _id; }
	const short getAge() const { return _age; }

	void setId(size_t id)
	{
		_id = id;
	}
	void setName(string name)
	{
		if (name.length() < 3)
			throw InvalidArgumentException("name in uzunlugu 3den azdir ", __FILE__, __TIME__, __LINE__);

		_name = name;
	}
	void setSurname(string surname)
	{
		if (surname.length() < 4)
			throw InvalidArgumentException("surname in uzunlugu 4den azdir ", __FILE__, __TIME__, __LINE__);

		_surname = surname;
	}
	void setAge(short age)
	{
		if (age < 0)
			throw InvalidArgumentException("Yas 0 dan balaca ola bilmez ", __FILE__, __TIME__, __LINE__);

		_age = age;
	}
	void setUsername(string username)
	{
		if (username.length() < 6)
			throw InvalidArgumentException("username in uzunlugu 6dan azdir ", __FILE__, __TIME__, __LINE__);

		if (username[0] > 96 && _username[0] < 123)
			throw InvalidArgumentException("Ilk herf balacadi ", __FILE__, __TIME__, __LINE__);

		_username = username;
	}
	void setPassword(string password)
	{
		if (password.length() < 8)
			throw InvalidArgumentException("password un uzunlugu 8den azdir ", __FILE__, __TIME__, __LINE__);

		_password = password;
	}


	friend ostream& operator << (ostream& out, const User& user);
};


///////////////////////////////////////////////////////////////////////
//// Operator overloading ( cout )

ostream& operator << (ostream& out, const User& user)
{
	out << "\nId: " << user._id << endl
		<< "Name: " << user._name << endl
		<< "Surname: " << user._surname << endl
		<< "Age: " << user._age << endl
		<< "Username: " << user._username << endl
		<< "Password: " << user._password << endl;

	return out;
}