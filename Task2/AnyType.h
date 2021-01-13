#pragma once
#include <algorithm>
#include <string>
#include <exception>
#include <iostream>


struct InvalidCast : public std::exception
{
	const char* what() const throw ()
	{
		return "Invalid cast";
	}
};

class AnyType
{
	union
	{
		bool bool_value;
		int int_value;
		long long_value;
		double double_value;
		long double long_double_value;
		char char_value;
		unsigned int unsigned_int_value;
		float float_value;
	}data;

	enum DataType { bool_type, int_type, long_type, double_type, long_double_type, char_type, unsigned_int_type, float_type}data_type;


public:
	AnyType(bool data_);
	AnyType(int data_);
	AnyType(long data_);
	AnyType(double data_);
	AnyType(long double data_);
	AnyType(char data_);
	AnyType(unsigned int data_);
	AnyType(float data_);

	AnyType operator= (bool data_);
	AnyType operator= (int data_);
	AnyType operator= (long data_);
	AnyType operator= (double data_);
	AnyType operator= (long double data_);
	AnyType operator= (char data_);
	AnyType operator= (unsigned int data_);
	AnyType operator= (float data_);
	AnyType operator= (AnyType data_);

	void Swap(AnyType& data_);
	std::string GetType();

	bool ToBool();
	int ToInt();
	long ToLong();
	double ToDouble();
	long double ToLongDouble();
	char ToChar();
	unsigned int ToUnsignedInt();
	float ToFloat();
};

