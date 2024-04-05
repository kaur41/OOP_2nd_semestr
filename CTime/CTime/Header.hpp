#pragma once 
enum Statys { ERROR = 0, SUCCESS, WARNING };
class CTime {
	int hours, minutes, seconds;
public:

	CTime();
	CTime(int hour_, int minutes_, int seconds_);
	CTime(const CTime& time);
	Statys check(const CTime* time);
	Statys input();
	Statys set_values(CTime* time, int hours, int minutes, int seconds);
	Statys convert(CTime* time);
	Statys add_hours(int hours, int hours_);
	Statys add_minutes(int minutes, int minutes_);
	Statys add_seconds(int seconds, int seconds_);
	Statys assign(CTime* time1, const CTime* time2);
	int compare(const CTime* time1, const CTime* time2);
	void PrintMassage(Statys state);
	void output();
};