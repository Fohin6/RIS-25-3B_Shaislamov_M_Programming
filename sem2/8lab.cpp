#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
using namespace std;

struct auto_owner {
    string fio;
    int number = 0;
    int phonenumber = 0;
    int techpass = 0;
    void input() {
        cin.ignore();
        cout << "Введите ФИО: ";
        getline(cin, fio);
        cout << "Введите номер машины: ";
        cin >> number;
        cout << "Введите номер телефона: ";
        cin >> phonenumber;
        cout << "Введите номер техпаспорта: ";
        cin >> techpass;
    }
    void print() {
        cout << "ФИО: " << fio << endl;
        cout << "Номер машины: " << number << endl;
        cout << "Номер телефона: " << phonenumber << endl;
        cout << "Номер техпаспорта: " << techpass << endl;
        cout << "----------------------\n";
    }
    static void inputAll(auto_owner* arr, int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nВладелец " << i + 1 << endl;
            arr[i].input();
        }
    }
    static void printAll(auto_owner* arr, int n) {
        for (int i = 0; i < n; i++) {
            arr[i].print();
        }
    }
    static void removeByNumber(auto_owner*& arr, int& n, int delNumber) {
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i].number == delNumber) {
                index = i;
                break;
            }
        }

        if (index == -1) return;

        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    static void insertBeforeFio(auto_owner*& arr, int& n, string targetFio) {
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i].fio == targetFio) {
                index = i;
                break;
            }
        }

        if (index == -1) return;

        auto_owner* newArr = new auto_owner[n + 2];

        for (int i = 0; i < index; i++) {
            newArr[i] = arr[i];
        }

        cout << "Введите данные 1 владельца:\n";
        newArr[index].input();

        cout << "Введите данные 2 владельца:\n";
        newArr[index + 1].input();

        for (int i = index; i < n; i++) {
            newArr[i + 2] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        n += 2;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество владельцев: ";
    cin >> n;

    auto_owner* arr = new auto_owner[n];

    auto_owner::inputAll(arr, n);

    int delNumber;
    cout << "\nВведите номер машины для удаления: ";
    cin >> delNumber;
    auto_owner::removeByNumber(arr, n, delNumber);

    string targetFio;
    cout << "Введите ФИО, перед которым вставить 2 элемента: ";
    cin >> targetFio;
    auto_owner::insertBeforeFio(arr, n, targetFio);

    cout << "\nСписок владельцев:\n";
    auto_owner::printAll(arr, n);

    delete[] arr;
    return 0;
}
