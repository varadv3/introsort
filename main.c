#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sort.h"

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    clock_t begin, end;

    size_t size = (size_t)1e8;

    int* original_arr = malloc(sizeof(int) * size);
    int* arr = malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {
        original_arr[i] = rand();
    }

    printf("Executing the In-built sort: ");
    memcpy(arr, original_arr, sizeof(int) * size);
    begin = clock();
    qsort(arr, size, sizeof(int), cmp);
    end = clock();
    printf("TIME = %ld\n", (end - begin));

    // printf("Sorted array: ");
    // for(int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    printf("Executing the Mixed Sort: ");
    // memcpy(arr, original_arr, sizeof(int) * size);
    begin = clock();
    sort(original_arr, size);
    end = clock();
    printf("TIME = %ld\n", (end - begin));

    // printf("Sorted array: ");
    // for(int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    printf("Checking correctness: ");
    for(int i = 0; i < size; i++) {
        if (original_arr[i] != arr[i]) {
            printf("NOT CORRECT\n");
            break;
        }
    }
    printf("CORRECT\n");
    free(original_arr);
    free(arr);
    return 0;
}