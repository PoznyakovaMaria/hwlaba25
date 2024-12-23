#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

//Функция для генерации случайных чисел
void random_elements(int* start, int* end) {
    for (int* ptr = start; ptr < end; ptr++) {
        *ptr = rand() % 100 - 50; //Генерация случайных чисел от -50 до 49
    }
}
//Функция для циклического сдвига вправо отрицательных элементов массива
void negative_elements(int* arr, int n) {
    int last_negative = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            last_negative = i;
        }
    }
    if (last_negative == -1) {
        return;
    }
    //Сдвиг вправо
    for (int i = last_negative; i > 0; i--) {
        if (arr[i - 1] < 0) {
            arr[i] = arr[i - 1];
        }
    }
    arr[0] = -1; //Устанавливаем первый элемент в -1 
}
//Функция для вывода массива
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); //Инициализация генератора случайных чисел
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));

    //Генерация случайных чисел
    random_elements(arr, arr + size);
    printf("Сгенерированный массив:\n");
    print_array(arr, size);

    //Выполнение циклического сдвига вправо отрицательных элементов
    negative_elements(arr, size);
    printf("Массив после циклического сдвига вправо отрицательных элементов:\n");
    print_array(arr, size);

    //Освобождение памяти
    free(arr);
    return 0;
}