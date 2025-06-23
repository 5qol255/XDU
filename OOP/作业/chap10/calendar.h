#ifndef CALENDAR_H
#define CALENDAR_H
#pragma once

#include <ctime>
#include <string>

class calendar
{
private:
    std::time_t time_;

public:
    /* constructors */
    calendar(time_t t = std::time(nullptr));                  // 无参构造默认调用当前时间
    calendar(const int year, const int month, const int day); // 年月日，时间默认0点
    calendar(const int year, const int month, const int day,  // 年月日时分秒
             const int hour, const int minute, const int second);
    /* methods */
    void tick() { ++time_; };
    void tick(const int seconds) { time_ += seconds; };
    /* getters */
    int get_year() const;
    int get_month() const;
    int get_day() const;
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    std::string format_time(const std::string &fmt) const; // 可选参数%Y,%m,%d,%H,%M,%S
    std::string get_date() const;                          // %Y-%m-%d
    std::string get_time() const;                          // %H:%M:%S
    std::string get_datetime() const;                      // %Y-%m-%d %H:%M:%S
    /* setters */
    void set_year(int year);
    void set_month(int month);
    void set_day(int day);
    void set_hour(int hour);
    void set_minute(int minute);
    void set_second(int second);
    void set_date(const int year, const int month, const int day);
    void set_time(const int hour, const int minute, const int second);
    void set_datetime(const int year, const int month, const int day,
                      const int hour, const int minute, const int second);
};

#endif // CALENDAR_H