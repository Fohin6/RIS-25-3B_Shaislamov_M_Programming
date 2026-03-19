#include <iostream>
#include <clocale>
#include <algorithm>

using namespace std;

bool makeIncreasingDiagonal(int** arr, int n) {
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int col = n - 1 - i;
        int minIndex = -1;
        int minValue = 1000000;
        for (int row = i; row < n; row++) {
            if (arr[row][col] > prev && arr[row][col] < minValue) {
                minValue = arr[row][col];
                minIndex = row;
            }
        }
        if (minIndex == -1)
            return false;
        int temp = arr[i][col];
        arr[i][col] = arr[minIndex][col];
        arr[minIndex][col] = temp;
        prev = arr[i][col];
    }
    return true;
}
void elements() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int** arr = new int* [n];
    //Выделяем память под массив
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    //Заполняем массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    if (makeIncreasingDiagonal(arr, n)) {
        cout << "Можно сделать возрастающую побочную диагональ\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else{
        cout << "Нельзя сделать возрастающую побочную диагональ\n";
    }

}
int main() {
    setlocale(LC_ALL, "ru_RU");
    elements();
    return 0;
}
