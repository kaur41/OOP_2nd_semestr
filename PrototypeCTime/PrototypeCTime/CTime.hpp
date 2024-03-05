#pragma once 
#include <string>

class CTime {
	int hours, minutes, seconds;
public:
	CTime();
	CTime(int hours, int minutes, int seconds);
	CTime(const CTime& time);
	CTime(std::string time);
};