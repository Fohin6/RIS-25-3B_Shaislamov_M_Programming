#include <iostream>
#include <clocale>
#include <string>
#include <map>
#include <sstream>
#include <Windows.h>
using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ru");
    std::string text;
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);
    std::map<std::string, int> wordCount;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word) {
        wordCount[word]++;
    }
    std::string mostFrequent;
    int maxCount = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    std::cout << "Самое частое слово: " << mostFrequent << std::endl;
    std::cout << "Количество повторений: " << maxCount << std::endl;
    return 0;
    return 0;
}
