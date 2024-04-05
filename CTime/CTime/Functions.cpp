# include <iostream>
#include "Header.hpp"
CTime::CTime() {
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
}
CTime::CTime(int hour_, int minutes_, int seconds_)
{
	int hours = hour_;
	int minutes = minutes_;
	int seconds = seconds_;
}
CTime::CTime(const CTime& time)
{
	hours = time.hours;
	minutes = time.minutes;
	seconds = time.seconds;
}
Statys CTime::check(const CTime* time) {
	Statys state = SUCCESS;
	if (time->hours < 0 || time->hours > 23 || time->minutes < 0 || time->minutes > 59 || time->seconds < 0 || time->seconds > 59) state = ERROR;
	return state;
}
Statys CTime::input() {
	Statys state = SUCCESS;
	char colon;
	std::cin >> hours >> colon
		>> minutes >> colon
		>> seconds;
	state = check(this);
	
	return state;
}
Statys CTime::set_values(CTime* time, int hours, int minutes, int seconds) {
	Statys state = SUCCESS;
	time->hours = hours;
	time->minutes = minutes;
	time->seconds = seconds;
	return state;
}
Statys CTime::convert(CTime* time) {
	Statys state = SUCCESS;
	if (time->seconds >= 60) {
		time->minutes += 1;
		time->seconds = time->seconds - 60;
	}
	if (time->minutes >= 60) {
		time->hours += 1;
		time->minutes = time->minutes - 60;
	}
	if (time->hours >= 24) {
		time->hours = time->hours - 24;
		return WARNING;
	}
	return state;
}
Statys CTime::add_hours(int hours_, int hours) {
	Statys state = SUCCESS;
	hours += hours_;
	if (hours >= 23) {
		Statys state = WARNING;
		Statys convert(CTime * hours);
	}
	return state;
}
Statys CTime::add_minutes(int minutes_, int minutes) {
	Statys state = SUCCESS;
	minutes += minutes_;
	if (minutes >= 60) {
		Statys state = WARNING;
		Statys convert(CTime * minutes);
	}
	return state;
}
Statys CTime::add_seconds(int seconds_, int  seconds) {
	Statys state = SUCCESS;
	seconds += seconds_;
	if (seconds >= 60) {
		Statys state = WARNING;
		Statys convert(CTime * seconds);
	}
	return state;
}
Statys CTime::assign(CTime* time1, const CTime* time2) {
	Statys state = SUCCESS;
	if (time2 == nullptr) state = ERROR;
	else {
		this->hours = this->hours;
		this->minutes = this->minutes;
		this->seconds = this->seconds;
	}
	return state;
}
int CTime::compare(const CTime* time1, const CTime* time2) {
	Statys state = SUCCESS;
	if (time1->hours == time2->hours && time1->minutes == time2->minutes && time1->seconds == time2->seconds) return 0;

	// time1 > time2
	if (time1->hours > time2->hours) return 1;
	if (time1->minutes > time2->minutes && time2->hours <= time1->hours) return 1;
	if (time1->seconds > time2->seconds && time2->minutes <= time1->minutes && time2->hours <= time1->hours) return 1;

	// time1 < time2
	if (time2->hours > time1->hours) return -1;
	if (time2->minutes > time1->minutes && time1->hours <= time2->hours) return -1;
	if (time2->seconds > time1->seconds && time1->minutes <= time2->minutes && time1->hours <= time2->hours) return -1;
}
void PrintMassage(Statys state) {
	if (state == SUCCESS) std::cout << "\n" << "SUCCESS" << "\n";
	else if (state == WARNING) std::cout << "\n" << "WARNING" << "\n";
	else if (state == ERROR) std::cout << "\n" << "ERROR" << "\n";
}
void CTime::output() {
	std::cout << hours << ":"
		<< minutes << ":"
		<< seconds << std::endl;
}
