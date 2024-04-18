#include <iostream>
#include "Header.hpp"
CData::CData() {
	int year = 0;
	int month = 0;
	int day = 0;
}
CData::CData(int year_, int month_, int day_)
{
	year = year_;
	month = month_;
	day = day_;
}
CData::CData(const CData& data)
{
	year = data.year;
	month = data.month;
	day = data.day;
}
Status CData::check() {
	Status state = SUCCESS;
	if (year < 0 || year > 23 || month < 0 || month > 59 || day < 0 || day > 59) state = ERROR;
	return state;
}
Status CData::input() {
	Status state = SUCCESS;
	char colon;
	std::cin >> year >> colon
		>> month >> colon
		>> day;
	state = check();

	return state;
}
Status CData::set_values(int year_, int month_, int day_) {
	Status state = SUCCESS;
	year = year;
	month = month;
	day = day;
	return state;
}
Status CData::convert() {
	Status state = SUCCESS;
	if (day > 28) {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			month += 1;
			day = day - 30;
		}
		else if (month == 2) {
			month += 1;
			day = day - 28;
			if ((year % 4 == 0) && day < 30) { day--; }
		}
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
			month += 1;
			day = day - 31;
		}
	}
	if (month > 12) {
		year += 1;
		month = month - 12;
	}
	if (day < 1) {
		month -= 1;
		day = day + 31;
	}
	if (month < 1) {
		year -= 1;
		month = month + 12;
	}
	if (year < 0) {
		state = WARNING;
	}
	if (day > 31 || month > 12 || day < 1 || month < 1) {
		state = ERROR;
	}
	return state;
}
Status CData::add_year(int year_) {
	Status state = SUCCESS;
	year += year_;
	if (year >= 23) {
		Status state = WARNING;
		Status convert(CData * year);
	}
	return state;
}
Status CData::add_month(int month_) {
	Status state = SUCCESS;
	month += month_;
	if (month >= 60) {
		Status state = WARNING;
		Status convert(CData * month);
	}
	return state;
}
Status CData::add_day(int day_) {
	Status state = SUCCESS;
	day += day_;
	if (day >= 60) {
		Status state = WARNING;
		Status convert(CData * day);
	}
	return state;
}
Status CData::assign(CData& data) {
	Status state = SUCCESS;

	data.year = year;
	data.month = month;
	data.day = day;

	return state;
}
int CData::compare(const CData& data) {
	if (year == data.year && month == data.month && day == data.day) return 0;

	// data1 > data2
	if (year > data.year) return 1;
	if (month > data.month && data.year <= year) return 1;
	if (day > data.day && data.month <= month && data.year <= year) return 1;

	// data1 < data2
	if (data.year > year) return -1;
	if (data.month > month && year <= data.year) return -1;
	if (data.day > day && month <= data.month && year <= data.year) return -1;
}

//void PrintMassage(Statys state) {
//	if (state == SUCCESS) std::cout << "\n" << "SUCCESS" << "\n";
//	else if (state == WARNING) std::cout << "\n" << "WARNING" << "\n";
//	else if (state == ERROR) std::cout << "\n" << "ERROR" << "\n";
//}
void CData::output() {
	std::cout << year << ":"
		<< month << ":"
		<< day << std::endl;
}
CData::~CData() {}