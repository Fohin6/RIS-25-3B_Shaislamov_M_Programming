#include <iostream>
#include <clocale>
#include <cstring>
#include <windows.h>

using namespace std;

void minWords() {
    SetConsoleCP(1251);     
    SetConsoleOutputCP(1251);
    int n;
    int maxLenght = 100;
    cout << "Введите кол-во слов: ";
    cin >> n;
    cin.ignore();
    char **words = new char*[n];
    for (int i = 0; i < n; ++i) { // ввыделение памяти под каждое слово
        words[i] = new char[maxLenght];
    }
    cout << "\nНапишите слова: \n";
    for (int i = 0; i < n; i++) {
        cin.getline(words[i], maxLenght);
    }
    cout << "Ваши слова: ";
    for (int i = 0; i < n; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    cout << "Минимальные слова: " << "\n";
    //Поиск минимального слова
    int minLength = 0;
    while (words[0][minLength] != '\0') {
        minLength++;
    }
    for (int i = 1; i < n; i++) {
        int currentLength = 0;
        while (words[i][currentLength] != '\0') {
            currentLength++;
        }
        if (currentLength < minLength) {
            minLength = currentLength;
        }
    }
    cout << "Удаление коротких слов \n";
    //Удаление коротких слов
    int i = 0;
    while (i < n) {
        int currentLength = 0;
        while (words[i][currentLength] != '\0') {
            currentLength++;
        }
        if (currentLength == minLength) {
            cout << words[i] << endl;
            delete[] words[i];
            for (int j = i; j < n - 1; j++) {
                words[j] = words[j + 1];
            }
            n--; 
        }
        else {
            i++;
        }
    }
    cout << "\nРезультат после удаления:" << endl;
    if (n == 0) {
        cout << "Минимальных слов нет" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << words[i] << endl;
        }
    }
    //Очитска памяти
    for (int i = 0; i < n; i++) {
        delete[] words[i];
    }
    delete[] words;

}
int main() {
    setlocale(LC_ALL, "ru_RU");
    minWords();
    return 0;
}
