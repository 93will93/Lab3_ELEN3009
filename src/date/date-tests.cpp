#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {
//    // make some prior memory allocations - which will be the case in a typical program
//    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
//    auto i2 = 1.0;
//
//    Date today;
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("Exception thrown for invalid day in Date initialization"){
    //This test verifies bigger than a month as well as not a leap year.
   CHECK_THROWS_AS(Date date(29, Month::February, 2001), InvalidDate);
}
TEST_CASE("Exception thrown for invalid year in Date initialization"){
    //This test verifies bigger than a month as well as not a leap year.
    CHECK_THROWS_AS(Date date(24, Month::February, -2001), InvalidDate);
}


// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.
TEST_CASE("Differnt days give different dates"){
    Date date_1(2, Month::February, 2000);
    Date date_2(1, Month::February, 2000);

    CHECK_FALSE( date_1 == date_2);
}
TEST_CASE("Different months give differnt dates"){
    Date date_1(2, Month::February, 2000);
    Date date_2(2, Month::March, 2000);
    CHECK_FALSE(date_1 == date_2);
}
TEST_CASE("Different years give differnt dates"){
    Date date_1(2, Month::February, 2000);
    Date date_2(2, Month::February, 2001);
    CHECK_FALSE(date_1 == date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("Incrementing a date gives the next day"){
    int day = 1;
    Date test_date(day, Month::March, 2000);
    test_date.nextDay();

    CHECK(test_date.day() == day+1);
}
TEST_CASE("Incrementing last day of the month"){
    Date test_date1(30, Month::September, 2000);
    Date test_date2(1, Month::October, 2000);
    test_date1.nextDay();

    CHECK(test_date1 == test_date2);
}
TEST_CASE("Incrementing last day of the year"){
    int year = 2000;
    Date test_date1(31, Month::December, year);
    Date test_date2(1, Month::January, year+1);
    test_date1.nextDay();

    CHECK(test_date1 == test_date2);
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
