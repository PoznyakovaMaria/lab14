#define _CRT_SECURE_NO_WARNINGS   
#define _USE_MATH_DEFINES 
#include <stdio.h>      
#include <locale.h>          
#include <math.h> 
#define N 100 

//функция для заполнения массива
double* full_elements(double* ptr_array, int n) {
    double sh = (4. - 2) / (n - 1);
    double x = 2.;

    for (int i = 0; i < n; i++) {
        double x = i;
        ptr_array[i] = pow(x, 3) + 3 * pow(x, 2) - 3;
        x += sh;
    }
    return ptr_array;
}
//функция печати элементов массива
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("array[%2d] = %lf\t", i, ptr_array[i]);
    }
    return 0;
}

//функция обработки элементов массива 
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0) {
            ptr_array[i] = 0;
        }
    }
    return ptr_array;
}

//функция вычитания суммы элементов массива
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}
//функция поиска элементов 
int find_element(double* ptr_array, int n, double element) {
    int i = 0;
    while (ptr_array[i] != element && i < n) {
        i++;
        if (ptr_array[i] == element) {
            return i;
        }
        else {
            return -1;
        }
    }

}
//функция определения индекса минимального элемента массива
int function(double* ptr_array, int n) {
    int min_index = 0;
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] < 0) {
            min_index = i;
        }
        return min_index;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    //1 
    double array[N];
    int size;
    printf("Введите размер массива (max %d) > ", N);
    scanf("%d", &size);
    full_elements(array, size);
    put_elements(array, size);

    //2 
    int a, b;
    double element;
    printf("\nВведите индекс начала массива: ");
    scanf("%d", &a);

    printf("\nВведите индекс конца массива: ");
    scanf("%d", &b);
    printf("\nСумма элементов массива:  %lf", sum_elements(array, a, b));

    double e;
    printf("\n\nВведите искомое значение:  ");
    scanf_s("%lf", &e);

    if (find_element(array, size, e)) {
        printf("\n\nНайдено значение под индексом %d", find_element(array, size, e));
    }
}