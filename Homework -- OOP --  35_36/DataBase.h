#pragma once





class Database
{
private:
	vector<User*> users;
	size_t Dbsize = 0;

public:

	size_t getSize() const { return Dbsize; }

	void addUser(User& user) 
	{
		Dbsize += 1 ;
		users.push_back(&user); 
	}
	User*& getUserByUsername(string username)
	{
		for (size_t i = 0; i < Dbsize; i++)
			if (users[i]->getUsername() == username)
				return users[i];
			else
				throw DatabaseException("Bele username tapilmadi", __FILE__, __TIME__, __LINE__);
	}
	User*& getUserByPassword(string password)
	{
		for (size_t i = 0; i < Dbsize; i++)
			if (users[i]->getPassword() == password)
				return users[i];
			else
				throw DatabaseException("Bele password tapilmadi", __FILE__, __TIME__, __LINE__);
	}
	void updateUser(User*& olduser, User*& newuser)
	{
		for (size_t i = 0; i < Dbsize; i++)
			if (users[i] == olduser)
			{
				delete[] users[i];
				users[i] = nullptr;
				users[i] = newuser;
			}
			else
				throw DatabaseException("Bele old user tapilmadi", __FILE__, __TIME__, __LINE__);
	}
	void deleteUserById(const int& id)
	{
		for (size_t i = 0; i < Dbsize; i++)
			if (users[i]->getId() == id)
				delete users[i];
			else
				throw InvalidArgumentException("Bele id movcud deyil", __FILE__, __TIME__, __LINE__);
	}


	User*& operator[](const size_t& index)
	{
		return users[index];
	}
};