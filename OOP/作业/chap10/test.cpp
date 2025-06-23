/*
请运用教材第10章的知识，定义并实现一个表示日历时间的类，其类名、接口自行定义，但该类的所有实例/对象应（至少）具有以下能力1~6：
(１) 能计时，时间精度至少为1秒。
　　［注１］ 为简化实现，可设计一个接口操作，如 tick()，由调用者调用该操作实现时间递增1秒。
　　［注２］若你了解或学习了多线程编程，也可以采用该机制实现时间的自动递增。但应支持多个时间对象同时计时。
(２) 允许调用者(通过接口操作)调整时间。
　　［注３］一旦调时，则时间对象应从调用者指定的时刻开始继续计时。
　　［注４］可设计多个不同接口函数，分别调整不同的时间成分。
(３) 可为调用者提供年、月、日、时、分、秒等六个时间成分。
　　［注５］你应提供多个不同的接口操作，分别向调用者返回时间成分的不同组合。
　　［注６］返回时间成分的具体方式请自行定义，如可以是函数返回值，也可以是函数的引用型参数。
(４)  以字符串形式向调用者提供格式化的时间。你应定义若干不同接口操作，分别产生不同格式的时间字符串。
(５)  对于(4)中定义的某一个函数，应支持调用者指定格式化描述串，就像 printf(...) 的第一个参数那样。
　　［注７］格式化描述串的具体规格由你自己定义。但你应在注释中解释说明。
(６)  每个对象应具备自我初始化能力。你应定义若干构造函数，按调用者指定的具体方式（不同参数列表）完成初始化。
－－－下面是程序编制要求－－－
(７) 应按多个源文件组织你的程序，具体文件名自定义，但应恰当合理。如 ccc.hpp 用于存放类定义，ccc.cpp 存放类型的实现，test.cpp 存放测试源程序等。
(８) 应对你实现的类进行完整测试，并将最终版程序测试的输出文本整理到一个测试文件中（最一般的文本文件即可）。
(９) 程序中应添加必要的注释说明——不要让老师猜测各个名字的意图和功用。
*/
#include "calendar.h"

#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
     // 重定向到output.txt
     freopen("output.txt", "w", stdout);
     // 测试构造函数
     calendar c1 = calendar();
     calendar c2 = calendar(2025, 1, 2);
     calendar c3 = calendar(2025, 1, 2, 12, 30, 45);
     // 测试getters
     cout << "c1: " << c1.get_year() << "-" << c1.get_month() << "-" << c1.get_day() << ' '
          << c1.get_hour() << ":" << c1.get_minute() << ":" << c1.get_second() << endl;
     cout << "c2: " << c2.get_year() << "-" << c2.get_month() << "-" << c2.get_day() << ' '
          << c2.get_hour() << ":" << c2.get_minute() << ":" << c2.get_second() << endl;
     cout << "c3: " << c3.get_year() << "-" << c3.get_month() << "-" << c3.get_day() << ' '
          << c3.get_hour() << ":" << c3.get_minute() << ":" << c3.get_second() << endl;
     cout << "c1.get_time()=" << c1.get_time() << endl
          << "c2.get_time()=" << c2.get_time() << endl
          << "c3.get_time()=" << c3.get_time() << endl;
     cout << "c1.get_date()=" << c1.get_date() << endl
          << "c2.get_date()=" << c2.get_date() << endl
          << "c3.get_date()=" << c3.get_date() << endl;
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl
          << "c2.get_datetime()=" << c2.get_datetime() << endl
          << "c3.get_datetime()=" << c3.get_datetime() << endl;
     cout << "c1.format_time()=" << c1.format_time("%Y-%m %H:%M") << endl
          << "c2.format_time()=" << c2.format_time("%Y %%") << endl
          << "c3.format_time()=" << c3.format_time("%Y %M:%S") << endl;
     // 测试tick
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.tick();
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.tick(1e3);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.tick(1e5);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     // 测试setters
     c1.set_year(2020);
     c1.set_month(12);
     c1.set_day(31);
     c1.set_hour(23);
     c1.set_minute(59);
     c1.set_second(59);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.set_datetime(2021, 1, 1, 0, 0, 0);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.set_date(2022, 2, 2);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     c1.set_time(12, 30, 45);
     cout << "c1.get_datetime()=" << c1.get_datetime() << endl;
     return 0;
}