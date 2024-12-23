#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

//������� ��� ��������� ��������� �����
void random_elements(int* start, int* end) {
    for (int* ptr = start; ptr < end; ptr++) {
        *ptr = rand() % 100 - 50; //��������� ��������� ����� �� -50 �� 49
    }
}
//������� ��� ������������ ������ ������ ������������� ��������� �������
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
    //����� ������
    for (int i = last_negative; i > 0; i--) {
        if (arr[i - 1] < 0) {
            arr[i] = arr[i - 1];
        }
    }
    arr[0] = -1; //������������� ������ ������� � -1 
}
//������� ��� ������ �������
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); //������������� ���������� ��������� �����
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));

    //��������� ��������� �����
    random_elements(arr, arr + size);
    printf("��������������� ������:\n");
    print_array(arr, size);

    //���������� ������������ ������ ������ ������������� ���������
    negative_elements(arr, size);
    printf("������ ����� ������������ ������ ������ ������������� ���������:\n");
    print_array(arr, size);

    //������������ ������
    free(arr);
    return 0;
}