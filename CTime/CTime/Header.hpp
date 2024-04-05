#pragma once 
enum Statys { ERROR = 0, SUCCESS, WARNING };
class CTime {
	int hours, minutes, seconds;
public:

	CTime();
	CTime(int hour_, int minutes_, int seconds_);
	CTime(const CTime& time);
	Statys check();
	Statys input();
	Statys set_values(int hours_, int minutes_, int seconds_);
	Statys convert();
	Statys add_hours(int hours_);
	Statys add_minutes( int minutes_);
	Statys add_seconds( int seconds_);
	Statys assign(CTime&time);
	int compare(const CTime& time);
	void PrintMassage(Statys state);
	void output();
};