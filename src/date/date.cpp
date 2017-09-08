// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date(int day, Month month, int year):
	_day{day},
	_month{month},
	_year{year}

{
	if( day > daysInMonth() || year < 0) throw InvalidDate();
}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}
bool Date::operator==(const Date& rhs)const{
	auto equalCounter = 0;
	if (_day == rhs.day())
		equalCounter++;
	if (_month ==rhs.month())
		equalCounter++;
	if(_year == rhs.year())
		equalCounter++;

	if (equalCounter != 3)
		return false;

	return true;
}

void Date::nextDay(){
	_day++;
	if (_day > daysInMonth()){
		_day = 1;
		auto currentMonth = static_cast<int>(_month);
		currentMonth++;
		if(currentMonth == 13) {
			currentMonth = 1;
			_year++;
		}
		_month = static_cast<Month>(currentMonth);
	}
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

