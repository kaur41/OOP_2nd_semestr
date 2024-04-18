#pragma once 
enum Status { ERROR = 0, SUCCESS, WARNING };
class CData {
	int day, month, year;
public:
	CData();
	CData(int day_, int month_, int year_);
	CData(const CData&data);
	Status check();
	Status input();
	Status set_values(int day_, int month_, int year_);
	Status assign(CData&data);
	Status add_year(int year_);
	Status add_month(int month_);
	Status add_day(int day_);
	int compare(const CData& data);
	Status convert();
	void output();
	~CData();
};