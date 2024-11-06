



#include <iostream>
using namespace std;

// домашнє завдання 1





int findMax(int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}





int findMin(int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}





double findAvg(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}





double Action(int* arrA, int sizeA, int* arrB, int sizeB, double (*func)(int*, int)) {
    return func(arrA, sizeA);
}















// домашнє завдання 2





int stringLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

// завдання 1




void removeCharAt(char* str, int index) {
    int len = stringLength(str);
    if (index >= 0 && index < len) {
        for (int i = index; i < len - 1; ++i) {
            str[i] = str[i + 1];
        }
        str[len - 1] = '\0';
    }
}








// завдання 2


void removeAllOccurrences(char* str, char ch) {
    int len = stringLength(str);
    int pos = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] != ch) {
            str[pos++] = str[i];
        }
    }
    str[pos] = '\0';
}




// завдання 3








void insertCharAt(char* str, int index, char ch) {
    int len = stringLength(str);
    if (index >= 0 && index <= len) {
        for (int i = len; i >= index; --i) {
            str[i + 1] = str[i];
        }
        str[index] = ch;
        str[len + 1] = '\0';
    }
}






// завдання 4


void replaceDots(char* str) {
    int len = stringLength(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}










// завдання 5




int countOccurrences(const char* str, char ch) {
    int count = 0;
    int len = stringLength(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] == ch) {
            ++count;
        }
    }
    return count;
}







// завдання 6
void countCharacters(const char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    int len = stringLength(str);
    for (int i = 0; i < len; ++i) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            ++letters;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            ++digits;
        }
        else {
            ++others;
        }
    }
}











int main() {
    
    int arrA[] = { 1, 2, 3, 4, 5 };
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);

    char choice;
    cout << "Оберіть функцію для масиву (m - max, n - min, a - avg): ";
    cin >> choice;

    double result;
    switch (choice) {
    case 'm':
        result = Action(arrA, sizeA, nullptr, 0, findMax);
        break;
    case 'n':
        result = Action(arrA, sizeA, nullptr, 0, findMin);
        break;
    case 'a':
        result = Action(arrA, sizeA, nullptr, 0, findAvg);
        break;
    default:
        cout << "Неправильний вибір!" << endl;
        return 1;
    }

    cout << "Результат: " << result << endl;

 


    char str[100];
    cout << "Введіть рядок: ";
    cin.ignore();
    cin.getline(str, 100);









    // завдання 1
    int index;
    cout << "Введіть індекс символа для видалення: ";
    cin >> index;
    removeCharAt(str, index);
    cout << "Рядок після видалення символа: " << str << endl;





    // завдання 2
    char ch;
    cout << "Введіть символ для видалення з рядка: ";
    cin >> ch;
    removeAllOccurrences(str, ch);
    cout << "Рядок після видалення символів: " << str << endl;






    // завдання 3
    cout << "Введіть індекс для вставки символа: ";
    cin >> index;
    cout << "Введіть символ для вставки: ";
    cin >> ch;
    insertCharAt(str, index, ch);
    cout << "Рядок після вставки символа: " << str << endl;

    // завдання 4
    replaceDots(str);
    cout << "Рядок після заміни точок на знаки оклику: " << str << endl;

    // завдання 5
    cout << "Введіть символ для підрахунку входжень: ";
    cin >> ch;
    int occurrences = countOccurrences(str, ch);
    cout << "Кількість входжень символа '" << ch << "': " << occurrences << endl;

    // завдання 6
    int letters, digits, others;
    countCharacters(str, letters, digits, others);
    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших символів: " << others << endl;

}
