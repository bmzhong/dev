#ifndef _atoi
#define _atoi

#include <string>

namespace my_atoi
{

enum Classify
{
	Oct = 8,
	Dec = 10,
	Hex = 16,
	Error = 0
};

long long decimal(const char *str);

long long octonary(const char *str);

long long hex(const char *str);

std::string tranform(const char *str, int *symbol);

Classify classify(const char *str);

long long fetch_power(std::string string1, int pos);

long long handle_error(const char *str);

int atoi(const char *str);

} // namespace my_atoi

#endif