#pragma once

#include<string>

using namespace std;

enum Classify
{
	Oct = 8,
	Dec = 10,
	Hex = 16,
	Error = 0
};

int decimal(const char* str);

int octonary(const char* str);

int hex(const char* str);

const char* tranform(const char* str, int* symbol);

Classify classify(const char* str);

int fetch_power(string string1, int pos);

int handle_error(const char* str);