#include <iostream>
#include <clocale>
using namespace std;

struct Time{
    int hours;
    int minutes;
};
int hourstomins(int hours, int minutes) {
    hours *= 60;
    hours += minutes;
    return hours;
}
Time minstohours(double minutes) {
    Time result;
    result.hours = (int)(minutes / 60);  
    result.minutes = (int)minutes % 60;   
    return result;
}
int main()
{
    setlocale(LC_ALL, "Ru");
    int h;
    int m;
    cout << "Введите часы: ";
    cin >> h;
    cout << "Введите минуты: ";
    cin >> m;
    cout << "Часы и минуты в минуты\n";
    cout << hourstomins(h, m) << " минут\n";
    cout << "Минуты в часы в минуты\n";
    Time t = minstohours(m);
    cout << t.hours <<" часов " << t.minutes << " минут\n";

}
