#include <iostream>
#include <vector> // необходимо для работы с векторами

using namespace std;

vector<int> binarySearch(int arr[], int n, int x) {
    vector<int> result; // создаем вектор для хранения индексов найденного элемента
    int left = 0; // индекс левой границы
    int right = n - 1; // индекс правой границы
    int mid;
    while (left <= right) { // пока левая граница не станет больше правой
        mid = (left + right) / 2; // находим средний индекс
        if (arr[mid] == x) { // если элемент найден
            result.push_back(mid); // добавляем индекс в вектор
            int i = mid - 1;
            while (i >= 0 && arr[i] == x) { // ищем все предыдущие повторяющиеся элементы
                result.push_back(i); // добавляем индекс в вектор
                i--;
            }
            i = mid + 1;
            while (i < n && arr[i] == x) { // ищем все последующие повторяющиеся элементы
                result.push_back(i); // добавляем индекс в вектор
                i++;
            }
            return result; // возвращаем вектор с найденными индексами
        }
        else if (arr[mid] < x)
            left = mid + 1; // ищем в правой половине массива
        else
            right = mid - 1; // ищем в левой половине массива
    }
    return result; // возвращаем пустой вектор, если элемент не найден
}

int main() {
    int n;
    do {
        cout << "Введи размер массива: ";
        cin >> n;
    } while (n <= 0);

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    int x;
    cout << "Введи искомый элемент: ";
    cin >> x;

    sort(arr, arr + n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> result = binarySearch(arr, n, x);

    if (result.empty())
        cout << "Элемент не найден" << endl;
    else {
        cout << "Элемент найден под индексом";
        for (int i = 0; i < result.size(); i++)
            cout << " " << result[i];
        cout << endl;
    }

    return 0;
}
