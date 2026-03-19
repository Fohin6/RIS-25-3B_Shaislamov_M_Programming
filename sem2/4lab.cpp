#include <iostream>
#include <clocale>

using namespace std;

void fifo() {
    int n;
    cout << "Введите размер массива\n";
    cin >> n;
    int* arr = new int[n];
    cout << "Введите очередь\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Ваш массив: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << "Извлечение:\n";
    int temp = n;
    for (int j = 0; j <= temp; j++) {
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
            cout << arr[i] << " ";
        }
        n--;
        cout << "\n";
    }
    temp--;
    delete[] arr;
}
int main() {
    setlocale(LC_ALL, "ru_RU");
    fifo();
    return 0;
}
