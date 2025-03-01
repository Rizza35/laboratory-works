#include <stdio.h>
#include <math.h>

// Функция для вычисления факториала числа
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    double x;
    int N;

    // Ввод значений x и N
    printf("Введите значение x: ");
    scanf("%lf", &x);
    printf("Введите количество элементов N: ");
    scanf("%d", &N);

    double sum = 0.0;

    // Вычисление суммы первых N элементов ряда
    for (int i = 0; i < N; i++) {
        sum += (pow(x, i) / factorial(i));
    }

    // Вывод результата
    printf("Сумма первых %d элементов ряда: %.5f\n", N, sum);

    return 0;
}