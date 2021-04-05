#include "AnyType.h"

AnyType::AnyType(bool data_)
{
	data.bool_value = data_;
	data_type = DataType::bool_type;
}

AnyType::AnyType(int data_)
{
	data.int_value = data_;
	data_type = DataType::int_type;
}

AnyType::AnyType(long data_)
{
	data.long_value = data_;
	data_type = DataType::long_type;
}

AnyType::AnyType(double data_)
{
	data.double_value = data_;
	data_type = DataType::double_type;
}

AnyType::AnyType(long double data_)
{
	data.long_double_value = data_;
	data_type = DataType::long_double_type;
}

AnyType::AnyType(char data_)
{
	data.char_value = data_;
	data_type = DataType::char_type;
}

AnyType::AnyType(unsigned int data_)
{
	data.unsigned_int_value = data_;
	data_type = DataType::unsigned_int_type;
}

AnyType::AnyType(float data_)
{
	data.float_value = data_;
	data_type = DataType::float_type;
}

AnyType::AnyType(const AnyType& data_)
{
	this->data = data_.data;
	this->data_type = data_.data_type;
}

AnyType::AnyType(AnyType&& data_) noexcept
{
	this->data = std::move(data_.data);
	this->data_type = data_.data_type;
	data_.Destroy();
}

AnyType AnyType::operator= (bool data_)
{
	data.bool_value = data_;
	data_type = DataType::bool_type;
	return this;
}

AnyType AnyType::operator= (int data_)
{
	data.int_value = data_;
	data_type = DataType::int_type;
	return this;
}

AnyType AnyType::operator= (long data_)
{
	data.long_value = data_;
	data_type = DataType::long_type;
	return this;
}

AnyType AnyType::operator= (double data_)
{
	data.double_value = data_;
	data_type = DataType::double_type;
	return this;
}

AnyType AnyType::operator= (long double data_)
{
	data.long_double_value = data_;
	data_type = DataType::long_double_type;
	return this;
}

AnyType AnyType::operator= (char data_)
{
	data.char_value = data_;
	data_type = DataType::char_type;
	return this;
}

AnyType AnyType::operator= (unsigned int data_)
{
	data.unsigned_int_value = data_;
	data_type = DataType::unsigned_int_type;
	return this;
}

AnyType AnyType::operator= (float data_)
{
	data.float_value = data_;
	data_type = DataType::float_type;
	return this;
}

AnyType AnyType::operator= (AnyType data_)
{
	this->data = data_.data;
	this->data_type = data_.data_type;
	return this;
}

void AnyType::Swap(AnyType& data_)
{
	AnyType tmp(data_);
	data_.data = this->data;
	data_.data_type = this->data_type;
	this->data = tmp.data;
	this->data_type = tmp.data_type;
}

std::string AnyType::GetType()
{
	switch (this->data_type)
	{
	case DataType::bool_type: return "bool";
		break;
	case DataType::int_type: return "int";
		break;
	case DataType::long_type: return "long";
		break;
	case DataType::double_type: return "double";
		break;
	case DataType::long_double_type: return "long double";
		break;
	case DataType::char_type: return "char";
		break;
	case DataType::unsigned_int_type: return "unsighed int";
		break;
	case DataType::float_type: return "float";
		break;
	default: return "none";
		break;
	}
}

void AnyType::Destroy()
{
	data.int_value = NULL;
	data_type = DataType::none;
}

bool AnyType::ToBool()
{
	if (data_type != DataType::bool_type)
	{
		throw InvalidCast();
	}
	return data.bool_value;
}

int AnyType::ToInt()
{
	if (data_type != DataType::int_type)
	{
		throw InvalidCast();
	}
	return data.int_value;
}

long int AnyType::ToLong()
{
	if (data_type != DataType::long_type)
	{
		throw InvalidCast();
	}
	return data.long_value;
}

double AnyType::ToDouble()
{
	if (data_type != DataType::double_type)
	{
		throw InvalidCast();
	}
	return data.double_value;
}

long double AnyType::ToLongDouble()
{
	if (data_type != DataType::long_double_type)
	{
		throw InvalidCast();
	}
	return data.long_double_value;
}

char AnyType::ToChar()
{
	if (data_type != DataType::char_type)
	{
		throw InvalidCast();
	}
	return data.char_value;
}

unsigned int AnyType::ToUnsignedInt()
{
	if (data_type != DataType::unsigned_int_type)
	{
		throw InvalidCast();
	}
	return data.unsigned_int_value;
}

float AnyType::ToFloat()
{
	if (data_type != DataType::float_type)
	{
		throw InvalidCast();
	}
	return data.float_value;
}
