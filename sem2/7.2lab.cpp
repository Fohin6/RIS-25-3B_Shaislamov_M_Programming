#include <iostream>
#include <Windows.h>
#include <clocale>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>
#include <locale.h>
#include <cstdlib>

using namespace std;

std::time_t stringToTime(const std::string& date_str) {
    std::tm tm = {};
    std::istringstream ss(date_str);
    ss >> std::get_time(&tm, "%d-%m-%y");
    return std::mktime(&tm);
}
int daysBetween(const std::string& date1, const std::string& date2) {
    std::tm tm1 = {}, tm2 = {};
    std::istringstream ss1(date1), ss2(date2);
    ss1 >> std::get_time(&tm1, "%d.%m.%y");
    ss2 >> std::get_time(&tm2, "%d.%m.%y");
    tm1.tm_hour = tm1.tm_min = tm1.tm_sec = 0;
    tm2.tm_hour = tm2.tm_min = tm2.tm_sec = 0;
    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);
    double diff = std::difftime(time2, time1) / (60 * 60 * 24);
    return static_cast<int>(std::round(diff));
}
int days(int count, ...) {
    if (count < 2) {
        cerr << "Ошибка: нужно минимум 2 параметра (даты)" << endl;
        return 0;
    }

    va_list args;
    va_start(args, count);

    cout << "\n=== Вызов days с " << count << " параметрами ===" << endl;
    const char* date1_str = va_arg(args, const char*);
    string date1(date1_str);
    cout << "Дата 1: " << date1 << endl;
    const char* date2_str = va_arg(args, const char*);
    string date2(date2_str);
    cout << "Дата 2: " << date2 << endl;
    string comment = "";
    int excludeWeekends = 0;
    double multiplier = 1.0;
    string dateFormat = "dd.mm.yy";
    int includeStartDay = 0;
    string notes = "";
    if (count >= 3) {
        comment = va_arg(args, const char*);
        cout << "Комментарий: " << comment << endl;
    }
    if (count >= 4) {
        excludeWeekends = va_arg(args, int);
        cout << "Исключать выходные: " << (excludeWeekends ? "да" : "нет") << endl;
    }
    if (count >= 5) {
        multiplier = va_arg(args, double);
        cout << "Множитель: " << multiplier << endl;
    }
    if (count >= 6) {
        dateFormat = va_arg(args, const char*);
        cout << "Формат даты: " << dateFormat << endl;
    }
    if (count >= 7) {
        includeStartDay = va_arg(args, int);
        cout << "Включать первый день: " << (includeStartDay ? "да" : "нет") << endl;
    }
    if (count >= 8) {
        notes = va_arg(args, const char*);
        cout << "Примечания: " << notes << endl;
    }
    va_end(args);
    int result = daysBetween(date1, date2);
    cout << "Базовая разница: " << result << " дней" << endl;
    if (excludeWeekends) {
        int weekends = result * 2 / 7;
        result -= weekends;
        cout << "После исключения выходных: " << result << " дней" << endl;
    }
    if (includeStartDay) {
        result += 1;
        cout << "После включения первого дня: " << result << " дней" << endl;
    }
    if (multiplier != 1.0) {
        result = static_cast<int>(round(result * multiplier));
        cout << "После применения множителя: " << result << " дней" << endl;
    }

    return abs(result);
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int result1 = days(3,
        "01.01.24",
        "15.01.24",
        "Первая половина января");
    cout << "РЕЗУЛЬТАТ 1 (3 параметра): " << result1 << " дней" << endl;
    int result2 = days(5,
        "01.02.24",
        "01.03.24",
        "Февраль 2024",
        1,      
        2.0);   
    cout << "РЕЗУЛЬТАТ 2 (5 параметров): " << result2 << " дней" << endl;
    int result3 = days(8,
        "01.12.23",
        "31.12.23",
        "Декабрь 2023",
        0,                
        1.5,                 
        "dd.mm.yy",           
        1,                   
        "Тестовый период"); 
    cout << "РЕЗУЛЬТАТ 3 (8 параметров): " << result3 << " дней" << endl
  }
