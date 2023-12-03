#include <iostream>
using namespace std;

// Функція, що повертає індекс максимального елемента в стовпці двовимірного масиву
int max_index(int arr[][10], int rows, int col) {
    int max = arr[0][col]; // Припускаємо, що перший елемент стовпця є максимальним
    int index = 0; // Зберігаємо індекс максимального елемента
    for (int i = 1; i < rows; i++) { // Перебираємо всі елементи стовпця
        if (arr[i][col] > max) { // Якщо знайшли елемент, що більший за поточний максимум
            max = arr[i][col]; // Оновлюємо максимум
            index = i; // Оновлюємо індекс
        }
    }
    return index; // Повертаємо індекс максимального елемента
}

// Функція, що повертає індекс мінімального елемента в стовпці двовимірного масиву
int min_index(int arr[][10], int rows, int col) {
    int min = arr[0][col]; // Припускаємо, що перший елемент стовпця є мінімальним
    int index = 0; // Зберігаємо індекс мінімального елемента
    for (int i = 1; i < rows; i++) { // Перебираємо всі елементи стовпця
        if (arr[i][col] < min) { // Якщо знайшли елемент, що менший за поточний мінімум
            min = arr[i][col]; // Оновлюємо мінімум
            index = i; // Оновлюємо індекс
        }
    }
    return index; // Повертаємо індекс мінімального елемента
}

// Функція, що переставляє місцями максимальний і мінімальний елементи в кожному стовпці двовимірного масиву
void swap_max_min(int arr[][10], int rows, int cols) {
    for (int j = 0; j < cols; j++) { // Перебираємо всі стовпці масиву
        int max_i = max_index(arr, rows, j); // Знаходимо індекс максимального елемента в стовпці j
        int min_i = min_index(arr, rows, j); // Знаходимо індекс мінімального елемента в стовпці j
        int temp = arr[max_i][j]; // Зберігаємо максимальний елемент в змінній temp
        arr[max_i][j] = arr[min_i][j]; // Переставляємо місцями максимальний і мінімальний елементи
        arr[min_i][j] = temp; // Переставляємо місцями максимальний і мінімальний елементи
    }
}

// Функція, що виводить двовимірний масив на екран
void print_array(int arr[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) { // Перебираємо всі рядки масиву
        for (int j = 0; j < cols; j++) { // Перебираємо всі стовпці масиву
            cout << arr[i][j] << " "; // Виводимо елемент масиву
        }
        cout << endl; // Переходимо на новий рядок
    }
}

int main() {
    int arr[10][10]; // Створюємо двовимірний масив розміром 10 на 10
    int rows, cols; // Зберігаємо кількість рядків і стовпців масиву
    cout << "Введіть кількість рядків масиву: "; // Просимо користувача ввести кількість рядків
    cin >> rows; // Зчитуємо кількість рядків
    cout << "Введіть кількість стовпців масиву: "; // Просимо користувача ввести кількість стовпців
    cin >> cols; // Зчитуємо кількість стовпців
    cout << "Введіть елементи масиву: " << endl; // Просимо користувача ввести елементи масиву
    for (int i = 0; i < rows; i++) { // Перебираємо всі рядки масиву
        for (int j = 0; j < cols; j++) { // Перебираємо всі стовпці масиву
            cin >> arr[i][j]; // Зчитуємо елемент масиву
        }
    }
    cout << "Вихідний масив: " << endl; // Виводимо вихідний масив
    print_array(arr, rows, cols); // Викликаємо функцію для виводу масиву
    swap_max_min(arr, rows, cols); // Викликаємо функцію для перестановки максимальних і мінімальних елементів
    cout << "Масив після перестановки: " << endl; // Виводимо масив після перестановки
    print_array(arr, rows, cols); // Викликаємо функцію для виводу масиву
    return 0; // Завершуємо програму
}
