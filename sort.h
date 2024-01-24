#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_Sort(int array[], int lenght, int show) {
    int i, j, temp;

    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (j = 0; j != lenght; j++) {
        for (i = 0; i != lenght - j; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
    }
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void Selection_Sort(int array[], int lenght, int show) {
    int i, j, minj, temp;

    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (i = 0; i != lenght - 1; i++) {
        minj = i;
        for (j = i + 1; j != lenght; j++) {
        if (array[j] < array[minj])
        minj = j;
        }
        swap(&array[i], &array[minj]);
    }
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void Insertion_Sort(int array[], int lenght, int show) {
    int i, j, check, temp;

    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (i = 1; i != lenght; i++) {
        check = i;
        while (check > 0 && array[check - 1] > array[check]) {
            swap(&array[check - 1], &array[check]);
            check -= 1;
        }
    }
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void Counting_Sort(int array[], int lenght, int show) {
    int i, j, maximum, array_sort[lenght];

    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (i = 0; i < lenght; i++) {
        array_sort[i] = 0;
    }

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            array_sort[array[i]]++;
        }
        for (i = 0; i < lenght; i++) {
            j = 0;
            while (j < array_sort[i]) {
                printf("%i ", i);
                j++;
            }
        }
        printf("\n");
    }
    clock_t end = clock();

    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

int separation(int array[], int low, int high) {
    int support = array[low];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while (array[i] < support);
        
        do {
            j--;
        } while (array[j] > support);

        if (i >= j) {
            return j;
        }

        swap(&array[i], &array[j]);
    }
}

void sort(int array[], int low, int high) {
    if (low < high) {
        int support_index = separation(array, low, high);
        sort(array, low, support_index);
        sort(array, support_index + 1, high);
    }
}

void Quick_Sort(int array[], int lenght, int show) {
    int i;
    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    sort(array, 0, lenght - 1);
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void union_array(int array[], int array_help[], int low, int support, int high) {
    int i = low; 
    int j = support + 1;
    int k = low;
 
    while (i <= support && j <= high) {
        if (array[i] <= array[j]) {
            array_help[k] = array[i];
            k++;
            i++;
        }
        else {
            array_help[k] = array[j];
            k++;
            j++;
        }
    }
 
    while (i <= support) {
        array_help[k] = array[i];
        k++;
        i++;
    }
 
    for (i = low; i <= high; i++) {
        array[i] = array_help[i];
    }
}

void sort_helper(int array[], int array_help[], int low, int high) {
    if (low < high) {
        int support = (low + ((high - low) >> 1));
        sort_helper(array, array_help, low, support);
        sort_helper(array, array_help, support + 1, high);
        union_array(array, array_help, low, support, high);
    }
}

void Recursion_Merge_Sort(int array[], int lenght, int show) {
    int i, array_helper[lenght];
    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (i = 0; i < lenght; i++) {
        array_helper[i] = array[i];
    }
    sort_helper(array, array_helper, 0, lenght - 1);
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void merge(int array[], int array_helper[], int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int k = start;

    while (i <= middle && j <= end) {
        if (array[i] < array[j]) {
            array_helper[k] = array[i];
            k += 1;
            i += 1;
        }
        else {
            array_helper[k] = array[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= middle) {
        array_helper[k] = array[i];
        k += 1;
        i += 1;
    }
 
    for (i = start; i <= end; i++) {
        array[i] = array_helper[i];
    }
}

int minimum(int x, int y) {
    if (x < y) {
        return x;
    }
    else {
        return y;
    }
}

void interval(int array[], int array_helper[], int high) {
    int i, j;
    int start, middle, end;

    for (i = 1; i <= high; i = i * 2) {
        for (j = 0; j < high; j += i * 2) {
            start = j;
            middle = j - 1 + i;
            end = minimum(j - 1 + i * 2, high);

            merge(array, array_helper, start, middle, end);
        }
    }
}

void Iteration_Merge_Sort(int array[], int lenght, int show) {
    int i, array_helper[lenght];
    if (show == 1) {
        printf("Source Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
    }

    clock_t start = clock();
    for (i = 0; i < lenght; i++) {
        array_helper[i] = array[i];
    }
    interval(array, array_helper, lenght - 1);
    clock_t end = clock();

    if (show == 1) {
        printf("\nSorted Array\n");
        for (i = 0; i < lenght; i++) {
            printf("%i ", array[i]);
        }
        printf("\n");
    }
    printf("Algorithm execution time: %.3f", (float)(end - start) / CLOCKS_PER_SEC);
}

void HUD(int main_array[], int lenght) {
    printf("Choose your sorting option (Attention! Replace 'space' with '_'): \n");
    printf("1. Bubble Sort;\n");
    printf("2. Selection Sort;\n");
    printf("3. Insertion Sort;\n");
    printf("4. Counting Sort;\n");
    printf("5. Quick Sort;\n");
    printf("6. Recursion Merge Sort;\n");
    printf("7. Iterative Merge Sort;\n");
    printf("8. System Test;\n");

    int i;
    char choice[30];
    printf("Your choice: ");
    scanf("%s", choice);

    int show;
    char took[30];
    printf("Show the source array and the sorting result (Yes/No)? ");
    scanf("%s", took);

    if (!strcmp(took, "Yes")) {
        show = 1;
    }
    else if (!strcmp(took, "No")) {
        show = 0;
    }

    int array[lenght];
    for (i = 0; i < lenght; i++) {
        array[i] = main_array[i];
    }

    if (!strcmp(choice, "System_Test")) {
        printf("1. Bubble Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Bubble_Sort(array, lenght, show);

        printf("\n2. Selection Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Selection_Sort(array, lenght, show);

        printf("\n3. Insertion Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Insertion_Sort(array, lenght, show);

        printf("\n4. Counting Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Counting_Sort(array, lenght, show);

        printf("\n5. Quick Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Quick_Sort(array, lenght, show);

        printf("\n6. Recursion Merge Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Recursion_Merge_Sort(array, lenght, show);

        printf("\n7. Iterative Merge Sort;\n");
        for (i = 0; i < lenght; i++) {
            array[i] = main_array[i];
        }
        Iteration_Merge_Sort(array, lenght, show);
    }
    
    if (!strcmp(choice, "Bubble_Sort")) {
        Bubble_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Selection_Sort")) {
        Selection_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Insertion_Sort")) {
        Insertion_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Counting_Sort")) {
        Counting_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Quick_Sort")) {
        Quick_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Recursive_Merge_Sort")) {
        Recursion_Merge_Sort(array, lenght, show);
    }

    if (!strcmp(choice, "Iterative_Merge_Sort")) {
        Iteration_Merge_Sort(array, lenght, show);
    }
}