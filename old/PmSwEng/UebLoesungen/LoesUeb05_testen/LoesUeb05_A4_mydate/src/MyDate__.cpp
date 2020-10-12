#include "MyDate.h"

MyDate::MyDate(void) :
	_day(0), _month(0), _year(0), _isValid(false) {
}

MyDate::MyDate(int day, int month, int year) :
	_day(day), _month(month), _year(year), _isValid(true) {
	if (day <= 0 || month <= 0 || month > 12 || year < 1 || day
			> getLastDayOfMonth()) {
		_isValid = false;
		_day = _month = _year = 0;
	}
}

MyDate::MyDate(const MyDate & x) :
	_day(x._day), _month(x._month), _year(x._year), _isValid(x._isValid) {
}

int MyDate::getLastDayOfMonth(void) const {
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
			30, 31 };
	int days = daysInMonth[_month - 1];
	if (_month == 2 && isLeapYear())
		++days;
	return days;
}

int MyDate::daysTil(const MyDate & til) const {
	return til.daysSince1() - this->daysSince1();
}

MyDate MyDate::addDays(int n) const {
	if (isValid())
		return MyDate::dateFromDays(daysSince1() + n);
	return MyDate();
}

MyDate & MyDate::operator=(const MyDate & x) {
	if (this != &x) {
		_day = x._day;
		_month = x._month;
		_year = x._year;
		_isValid = x._isValid;
	}
	return *this;
}

bool MyDate::isLeapYear(void) const {
	return _year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0);
}

bool MyDate::isValid(void) const {
	return _isValid;
}

bool MyDate::operator==(const MyDate & other) const {
	if (!this->isValid() && !other.isValid())
		return true;
	return _day == other._day && _month == other._month && _year == other._year;
}

bool MyDate::operator!=(const MyDate & other) const {
	return !(*this == other);
}

bool MyDate::operator<(const MyDate & other) const {
	if (!this->isValid() || !other.isValid())
		return false;
	if (_year < other._year)
		return true;
	if (_year > other._year)
		return false;
	if (_month < other._month)
		return true;
	if (_month > other._month)
		return false;
	return _day < other._day;
}

bool MyDate::operator<=(const MyDate & other) const {
	return *this < other || *this == other;
}

bool MyDate::operator>(const MyDate & other) const {
	return other < *this;
}

bool MyDate::operator>=(const MyDate & other) const {
	return other <= *this;
}

int MyDate::getDay() const {
	return _day;
}

int MyDate::getMonth() const {
	return _month;
}

int MyDate::getYear() const {
	return _year;
}

int MyDate::daysSinceStartOfYear(void) const
{
	int days = _day - 1;
	switch (_month) { // fall through, adding all previous months ...
	case 12:
		days += 30;
	case 11:
		days += 31;
	case 10:
		days += 30;
	case 9:
		days += 31;
	case 8:
		days += 31;
	case 7:
		days += 30;
	case 6:
		days += 31;
	case 5:
		days += 30;
	case 4:
		days += 31;
	case 3:
		if (isLeapYear())
			days += 29;
		else
			days += 28;
	case 2:
		days += 31;
	case 1:
		;
	}
	return days;
}

int MyDate::daysInPreviousYears(void) const
{
	int years = _year - 1;
	return years*365 + years/4 - years/100 + years/400;
}

int MyDate::daysSince1(void) const {
	if (_isValid)
		return daysSinceStartOfYear() + daysInPreviousYears();
	return -1;
}

MyDate MyDate::dateFromDays(int days)
{
	if (days < 0)
		return MyDate();

	int years, daysInNextMonth;
	years = (days+1)*400/146097; // <=> days/365.2425 (365 + 1/4 - 1/100 + 1/400)
	MyDate date(1, 1, years+1);
	days -= years*365 + years/4 - years/100 + years/400;

	for (;;) {
		daysInNextMonth = date.getLastDayOfMonth();
		if (days < daysInNextMonth)
			break;
		++date._month;
		days -= daysInNextMonth;
	}

	date._day = days+1;
	return date;
}
