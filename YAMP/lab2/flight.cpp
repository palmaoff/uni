#include "flight.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2020;
}

int Date::setD(int d)
{
	if (d < 1 || d > 31)
		return 0;
	day = d;
	return 1;
}

int Date::setM(int m)
{
	if (m < 1 || m > 12)
		return 0;
	month = m;
	return 1;
}

int Date::setY(int y)
{
	year = y;
	return 1;
}

int Date::getD()
{
	return day;
}

int Date::getM()
{
	return month;
}

int Date::getY()
{
	return year;
}

bool Date::isLater(Date d)
{
	int a = 0;
	int b = 0;

	a = year * 360 + (month - 1) * 30 + day;
	b = d.getY() * 360 + (d.getM() - 1) * 30 + d.getD();
	if (a > b)
		return 1;
	return 0;
}

bool Date::isEqual(Date d)
{
	if (year == d.getY() && month == d.getM() && day == d.getD())
		return 1;
	return 0;
}

string Date::toString()
{
	return to_string(day) + " " + to_string(month) + " " + to_string(year);
}

void Date::read()
{
	int n;

	// day
	cin >> n;
	setD(n);

	// month
	cin >> n;
	setM(n);

	// year
	cin >> n;
	setY(n);
}

Flight::Flight()
{
	from = "";
	to = "";
}

string Flight::toString()
{
	return Date::toString() + "\n" + "from: " + from + "\n" + "to: " + to + "\n";
}

void Flight::setTo(string t)
{
	to = t;
}

void Flight::setFrom(string f)
{
	from = f;
}

string Flight::getFrom()
{
	return from;
}

string Flight::getTo()
{
	return to;
}
