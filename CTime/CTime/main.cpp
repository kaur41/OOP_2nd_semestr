/*#include <iostream>

// Список функций:
// input - ввод времени
// output - вывод времени
// printMassage - вывод состояния
// check - проверка времени на правильность
// convert - преобразование времени
// set_values - изменение времени
// assign - присваивание одного времени другому
// add_hours - добавление часов
// add_minutes - добавление минут
// add_seconds - добавление секунд
// compare - сравнение времени

enum Status { SUCCESS, ERROR, WARNING };

struct Time {
	int hours;
	int minutes;
	int seconds;
};

Status check(const Time* time) {
	Status state = SUCCESS;
	if (time->hours < 0 || time->hours > 23 || time->minutes < 0 || time->minutes > 59 || time->seconds < 0 || time->seconds > 59) state = ERROR;
	return state;
}

Status input(Time* time) {
	Status state = SUCCESS;
	char colon;
	std::cin >> time->hours >> colon
		>> time->minutes >> colon
		>> time->seconds;
	state = check(time);
	if (state == ERROR) time = nullptr;
	return state;
}

Status set_values(Time* time, int hours, int minutes, int seconds) {
	Status state = SUCCESS;
	time->hours = hours;
	time->minutes = minutes;
	time->seconds = seconds;
	return state;
}

Status convert(Time* time) {
	Status state = SUCCESS;
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

 {
	Status state = SUCCESS;
	time->hours += hours;
	if (time->hours > 23) state = convert(time);
	return state;
}

Status add_minutes(Time* time, int minutes) {
	Status state = SUCCESS;
	time->minutes += minutes;
	if (time->minutes >= 60) state = convert(time);
	return state;
}

Status add_seconds(Time* time, int seconds) {
	Status state = SUCCESS;
	time->seconds += seconds;
	if (time->seconds >= 60) state = convert(time);
	return state;
}

int compare(const Time* time1, const Time* time2) {
	// time1 == time2
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

Status assign(Time* time1, const Time* time2) {
	Status state = SUCCESS;
	if (time2 == nullptr) state = ERROR;
	else {
		time1->hours = time2->hours;
		time1->minutes = time2->minutes;
		time1->seconds = time2->seconds;
	}
	return state;
}

Status output(const Time* time) {
	Status state = SUCCESS;
	if (time == nullptr) state = ERROR;
	else {
		std::cout << time->hours << ":"
			<< time->minutes << ":"
			<< time->seconds << "\n";
	}
	return state;
}

void printMassege(Status state) {
	if (state == SUCCESS) std::cout << "\n" << "SUCCESS" << "\n";
	else if (state == WARNING) std::cout << "\n" << "WARNING" << "\n";
	else if (state == ERROR) std::cout << "\n" << "ERROR" << "\n";
}

int main() {
	Time time1 = { 0, 0, 0 };
	// код
	return 0;
}*/
#include "Header.hpp"
#include <iostream>
int main() {
	int compare;
	CTime t1, t4;
	CTime t2(12, 56, 17);
	CTime t3(t2);
	t2.output();
	t3.output();
	t1.input();
	t1.assign(t4);
	t4.output();
	t2.set_values(20, 4, 3);
	t2.output();
	t2.add_hours(6);
	t2.output();
	compare = t3.compare(t2);
	std::cout << compare << std::endl;
}