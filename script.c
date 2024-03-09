
#include <stdio.h>
#include <stdlib.h>

// Counter Struct
typedef struct counter {
    int num;
    int count;
} counter;

// prints array of ints
void print_count_array(counter* arr, int length, int is_bubble) {

    int total = 0;
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", arr[i].num, arr[i].count);
        total += arr[i].count;
    }
    if (is_bubble == 1) total /= 2;
    printf("%d\n", total);
}


// Selection Sort
counter* selection_sort(int* arr, int length) {

    // Allocate Array
    counter* res_arr = (counter*)malloc(sizeof(counter) * length);
    for (int i = 0; i < length; i++) {
        res_arr[i].num = arr[i];
        res_arr[i].count = 0;
    }
    
    // For i in array
    for (int i = 0; i < length; i++) {

        int index_smallest = -1;
        counter smallest;
        
        // for sublist in array
        for (int j = i; j < length; j++) {
            
            // if found smallest, record new
            if (index_smallest == -1 || smallest.num > res_arr[j].num) {
                smallest = res_arr[j];
                index_smallest = j;
            }
        }
        if(index_smallest == i) continue;
        // swap
        counter temp = res_arr[i];
        res_arr[i] = smallest;
        res_arr[index_smallest] = temp;

        // increase count
        res_arr[index_smallest].count++;
        res_arr[i].count++;
    }

    return res_arr;
}

// Bubble Sort
counter* bubble_sort(int* arr, int length) {

    // Allocate Array
    counter* res_arr = (counter*)malloc(sizeof(counter) * length);
    for (int i = 0; i < length; i++) {
        res_arr[i].num = arr[i];
        res_arr[i].count = 0;
    }
    
    // Do Bubble Sort
    for (int i = length - 1; i >= 0; i--) {
    
        // Loop remaining unsorted
        for (int j = 0; j < i; j++) {
        
            // if less than, SWAP!!
            if (res_arr[j].num > res_arr[j+1].num) {
                
                // Swap
                counter temp = res_arr[j];
                res_arr[j] = res_arr[j+1];
                res_arr[j+1] = temp;

                // Increase Counters
                res_arr[j].count++;
                res_arr[j+1].count++;
            }
        }
    }

    return res_arr;
}

int main(int argc, char *argv[])
{

    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr_length = 9;

    // Selection Sort Array 1
    counter* res1s = selection_sort(arr1, arr_length); 
    print_count_array(res1s, arr_length, 0); 
    free(res1s);
    printf("\n");

    // Selection Sort Array 2
    counter* res2s = selection_sort(arr2, arr_length); 
    print_count_array(res2s, arr_length, 0); 
    free(res1s);
    printf("\n");
    
    // Bubble Sort Array 1
    counter* res1b = bubble_sort(arr1, arr_length); 
    print_count_array(res1b, arr_length, 1); 
    free(res1b);
    printf("\n");

    // Bubble Sort Array 1
    counter* res2b = bubble_sort(arr2, arr_length); 
    print_count_array(res2b, arr_length, 1); 
    free(res2b);
    printf("\n");

    return 0;
}
















































