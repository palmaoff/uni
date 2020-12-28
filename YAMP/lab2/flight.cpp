#include "flight.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 2020;
}

void Date::setD(int d)
{
	day = d;
}

void Date::setM(int m)
{
	month = m;
}

void Date::setY(int y)
{
	year = y;
}

void Date::setDate(Date d)
{
	day = d.getD();
	month = d.getM();
	year = d.getY();
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

int Date::read()
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

	return 1;
}

int	Date::read(const char *buff)
{
	int i = 0;

	setD(atoi(&buff[i]));
	i = nextCharacter(buff, i);

	setM(atoi(&buff[i]));
	i = nextCharacter(buff, i);

	setY(atoi(&buff[i]));

	if (!checkDate())
	 	return 0;
	return 1;
}

bool Date::checkDate()
{
	bool b = 1;
	int tmp;

	if (year <= 0 || month > 12 || month <= 0 || day <= 0 || day > 31)
		b = 0;
	if (month == 4 || month == 6 || month == 9 || month == 11 && day > 30)
		b = 0;
	if (month == 2 && isLeap(year) && day > 29)
		b = 0;
	if (month == 2 && !isLeap(year) && day > 28)
		b = 0;
	return b;
}

Flight::Flight()
{
	from = "";
	to = "";
}

int	Flight::setArrive(const char *buff)
{
	if (!arrive.read(buff))
		return 0;
	return 1;
}

int	Flight::setLeave(const char *buff)
{
	if (!leave.read(buff))
		return 0;
	return 1;
}

Date	Flight::getArrive()
{
	return arrive;
}

Date	Flight::getLeave()
{
	return leave;
}

string Flight::toString()
{
	return leave.toString() + "\n" + arrive.toString() + "\n" + "from: "
		+ from + "\n" + "to: " + to + "\n";
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

int nextCharacter(const char *buff, int i)
{
	while (buff[i] != ' ' && buff[i] != '\0')
		i++;
	while (buff[i] == ' ')
		i++;
	return i;
}

bool	isLeap(int y)
{
	return y % 400 == 0 || y % 100 != 0 && y % 4 == 0; 
}

