#pragma once
#include <algorithm>
#include <string>
#include <exception>
#include <iostream>

/*Custom exception for incorrect call of method To{Type}()*/
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

	enum class DataType
	{
		bool_type,
		int_type,
		long_type,
		double_type,
		long_double_type,
		char_type,
		unsigned_int_type,
		float_type,
		none
	}data_type;


public:
	AnyType(bool data_);
	AnyType(int data_);
	AnyType(long data_);
	AnyType(double data_);
	AnyType(long double data_);
	AnyType(char data_);
	AnyType(unsigned int data_);
	AnyType(float data_);

	AnyType(const AnyType& data_);
	AnyType(AnyType&& data_) noexcept;

	AnyType operator= (bool data_);
	AnyType operator= (int data_);
	AnyType operator= (long data_);
	AnyType operator= (double data_);
	AnyType operator= (long double data_);
	AnyType operator= (char data_);
	AnyType operator= (unsigned int data_);
	AnyType operator= (float data_);
	AnyType operator= (AnyType data_);

	/*Swaps value and type between two AnyType objects*/
	void Swap(AnyType& data_);
	std::string GetType();
	/*Sets unions value to NULL and type to none*/
	void Destroy();

	/*Type-safe access to boolean value*/
	bool ToBool();
	/*Type-safe access to integer value*/
	int ToInt();
	/*Type-safe access to long value*/
	long ToLong();
	/*Type-safe access to double value*/
	double ToDouble();
	/*Type-safe access to long double value*/
	long double ToLongDouble();
	/*Type-safe access to char value*/
	char ToChar();
	/*Type-safe access to unsigned integer value*/
	unsigned int ToUnsignedInt();
	/*Type-safe access to float value*/
	float ToFloat();
};

