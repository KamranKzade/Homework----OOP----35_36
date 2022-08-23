#pragma once


#pragma once





class InvalidArgumentException : public MyException
{
public:
	InvalidArgumentException(const char* message = "InvalidArgument Exception",
		const char* source = "",
		const char* time = "",
		const int line = 0) noexcept
		: MyException(message)
	{
		_source = source;
		_time = time;
		_line = line;

		_message = "\nMessage:  " + (string)exception::what()
			+ "\nSource:   " + _source
			+ "\nTime:     " + _time
			+ "\nLine:     " + to_string(_line);
	}


	virtual virtual const char* what() const override
	{
		return _message.c_str();
	}
};