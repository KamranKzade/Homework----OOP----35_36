#pragma once




class MyException : public exception
{
protected:
	string _message;
	const char* _source;
	const char* _time;
	int _line;

public:

	MyException(const char* message = "Empty Exception",
		const char* source = "",
		const char* time = "",
		const int line = 0) noexcept
		: exception(message)
	{
		_source = source;
		_time = time;
		_line = line;


		_message = "\nMessage:  " + (string)exception::what()
			+ "\nSource:   " + _source
			+ "\nTime:     " + _time
			+ "\nLine:     " + to_string(_line);
	}

	virtual const char* what() const override
	{
		return _message.c_str();
	}
};
