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
Statys CTime::check() {
	Statys state = SUCCESS;
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) state = ERROR;
	return state;
}
Statys CTime::input() {
	Statys state = SUCCESS;
	char colon;
	std::cin >> hours >> colon
		>> minutes >> colon
		>> seconds;
	state = check();
	
	return state;
}
Statys CTime::set_values( int hours_, int minutes_, int seconds_) {
	Statys state = SUCCESS;
	hours = hours;
	minutes = minutes;
	seconds = seconds;
	return state;
}
Statys CTime::convert() {
	Statys state = SUCCESS;
	if (seconds >= 60) {
		minutes += 1;
		seconds = seconds - 60;
	}
	if (minutes >= 60) {
		hours += 1;
		minutes = minutes - 60;
	}
	if (hours >= 24) {
		hours = hours - 24;
		return WARNING;
	}
	return state;
}
Statys CTime::add_hours(int hours_) {
	Statys state = SUCCESS;
	hours += hours_;
	if (hours >= 23) {
		Statys state = WARNING;
		Statys convert(CTime * hours);
	}
	return state;
}
Statys CTime::add_minutes(int minutes_) {
	Statys state = SUCCESS;
	minutes += minutes_;
	if (minutes >= 60) {
		Statys state = WARNING;
		Statys convert(CTime * minutes);
	}
	return state;
}
Statys CTime::add_seconds(int seconds_) {
	Statys state = SUCCESS;
	seconds += seconds_;
	if (seconds >= 60) {
		Statys state = WARNING;
		Statys convert(CTime * seconds);
	}
	return state;
}
Statys CTime::assign(CTime& time) {
	Statys state = SUCCESS;
	 
		time.hours = hours;
		time.minutes = minutes;
		time.seconds = seconds;
	
	return state;
}
int CTime::compare(const CTime& time) {
	if (hours == time.hours && minutes == time.minutes && seconds == time.seconds) return 0;

	// time1 > time2
	if (hours > time.hours) return 1;
	if (minutes > time.minutes && time.hours <= hours) return 1;
	if (seconds > time.seconds && time.minutes <= minutes && time.hours <= hours) return 1;

	// time1 < time2
	if (time.hours > hours) return -1;
	if (time.minutes > minutes && hours <= time.hours) return -1;
	if (time.seconds > seconds && minutes <= time.minutes && hours <= time.hours) return -1;
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
