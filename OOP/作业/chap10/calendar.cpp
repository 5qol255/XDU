#include "calendar.h"

#include <ctime>
#include <string>

calendar::calendar(time_t t) : time_(t)
{
}

calendar::calendar(const int year, const int month, const int day) : calendar(year, month, day, 0, 0, 0)
{
}

calendar::calendar(const int year, const int month, const int day,
                   const int hour, const int minute, const int second)
{
    std::tm temp;
    temp.tm_year = year - 1900;
    temp.tm_mon = month - 1;
    temp.tm_mday = day;
    temp.tm_hour = hour;
    temp.tm_min = minute;
    temp.tm_sec = second;
    time_ = std::mktime(&temp);
}

int calendar::get_year() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_year + 1900;
}

int calendar::get_month() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_mon + 1;
}

int calendar::get_day() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_mday;
}

int calendar::get_hour() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_hour;
}

int calendar::get_minute() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_min;
}

int calendar::get_second() const
{
    std::tm *temp = std::localtime(&time_);
    return temp->tm_sec;
}

std::string calendar::format_time(const std::string &fmt) const
{
    std::tm *temp = std::localtime(&time_);
    char buffer[100];
    std::strftime(buffer, 100, fmt.c_str(), temp);
    return buffer;
}

std::string calendar::get_date() const
{
    return format_time("%Y-%m-%d");
}

std::string calendar::get_time() const
{
    return format_time("%H:%M:%S");
}

std::string calendar::get_datetime() const
{
    return format_time("%Y-%m-%d %H:%M:%S");
}

void calendar::set_year(const int year)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_year = year - 1900;
    time_ = std::mktime(temp);
}

void calendar::set_month(const int month)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_mon = month - 1;
    time_ = std::mktime(temp);
}

void calendar::set_day(const int day)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_mday = day;
    time_ = std::mktime(temp);
}

void calendar::set_hour(const int hour)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_hour = hour;
    time_ = std::mktime(temp);
}

void calendar::set_minute(const int minute)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_min = minute;
    time_ = std::mktime(temp);
}

void calendar::set_second(const int second)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_sec = second;
    time_ = std::mktime(temp);
}

void calendar::set_date(const int year, const int month, const int day)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_year = year - 1900;
    temp->tm_mon = month - 1;
    temp->tm_mday = day;
    time_ = std::mktime(temp);
}

void calendar::set_time(const int hour, const int minute, const int second)
{
    std::tm *temp = std::localtime(&time_);
    temp->tm_hour = hour;
    temp->tm_min = minute;
    temp->tm_sec = second;
    time_ = std::mktime(temp);
}

void calendar::set_datetime(const int year, const int month, const int day,
                            const int hour, const int minute, const int second)
{
    std::tm temp;
    temp.tm_year = year - 1900;
    temp.tm_mon = month - 1;
    temp.tm_mday = day;
    temp.tm_hour = hour;
    temp.tm_min = minute;
    temp.tm_sec = second;
    time_ = std::mktime(&temp);
}