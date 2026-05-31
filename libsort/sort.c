#include <stdio.h>
#include <string.h>

#include "sort.h"

void insertion_sort(int in[], size_t size);
void merge_sort(int in[], int start, int end);
void merge_sorted_arr(int in[], int start, int mid, int end);

void sort(int in[], size_t size) {
    // Use the merge sort
    merge_sort(in, 0, size - 1);
}

void merge_sort(int in[], int start, int end) {
    size_t size = end - start + 1;
    if(size <= 16) {
        insertion_sort(in + start, size);
        return;
    }

    int mid = start + (size >> 1);

    merge_sort(in, start, mid);
    merge_sort(in, mid + 1, end);
    merge_sorted_arr(in, start, mid, end);
}

void merge_sorted_arr(int in[], int start, int mid, int end) {
    // Calculated size of the halves.
    int left_size = mid - start + 1;
    int right_size = end - mid;

    // Allocate the resources.
    int* left_arr = malloc(sizeof(int) * left_size);
    int* right_arr = malloc(sizeof(int) * right_size);

    // Copy the data.
    memcpy(left_arr, in + start, sizeof(int) * left_size);
    memcpy(right_arr, in + mid + 1, sizeof(int) * right_size);

    // Initiate pointers.
    int *in_ptr = in + start;
    int i = 0;
    int j = 0;

    // Merge in to the original array.
    while(i < left_size && j < right_size) {
        if(left_arr[i] < right_arr[j]) {
            *in_ptr = left_arr[i++];
        } else {
            *in_ptr = right_arr[j++];
        }
        in_ptr++;
    }
    while(i < left_size) {
        *in_ptr = left_arr[i++];
        in_ptr++;
    }
    while(j < right_size) {
        *in_ptr = right_arr[j++];
        in_ptr++;
    }
    
    // Frer the resources.
    free(left_arr);
    free(right_arr);
}

void insertion_sort(int in[], size_t size) {
    // Assume first element to be sorted. 
    for(int i = 1; i < size; i++) {
        int tmp = in[i];
        int j = i - 1;

        // Shift till we get larger number.
        while(j >= 0 && tmp < in[j]) {
            in[j + 1] = in[j];
            j--;
        }
        in[j + 1] = tmp;
    }
}
