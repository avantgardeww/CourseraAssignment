/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 * @file stats.c
 * @brief This is a program that can analyze an array of unsigned char data
 *        items and report analytics on the dataset for its:
 *        - maximum
 *        - minimum
 *        - mean
 *        - median
 *
 * @author Wu Wei Ng
 * @date 19 Aug 2023
 *
***************************************************************************/

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  static uint8_t test[SIZE] = { 
                                34, 201, 190, 154,   8, 194,   2,   6,
                               114, 88,   45,  76, 123,  87,  25,  23,
                               200, 122, 150, 90,   92,  87, 177, 244,
                               201,   6,  12,  60,   8,   2,   5,  67,
                                 7,  87, 250, 230,  99,   3, 100,  90
                              };
  uint8_t median = 0, mean = 0, max = 0, min = 0;
  printf("Before:\n\n");
  print_array(test, SIZE);
  sort_array(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  max = find_maximum(test, SIZE);
  min = find_minimum(test, SIZE);
  printf("After:\n\n");
  print_array(test, SIZE);
  print_statistics(median, mean, max, min);
}

void print_statistics(uint8_t median, uint8_t mean, uint8_t max, uint8_t min){
    printf("Median = %d\n", median);
    printf("Mean = %d\n", mean);
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
}

void print_array(uint8_t* arr, uint8_t arrLen){
    printf("Array = \n{\n");
    for (int i = 0; i < arrLen; i++){
        printf("%d", arr[i]);
        if (i!=(arrLen-1))
            printf(", ");
        if ((i+1)%8 ==0)
            printf("\n");
    }
    printf("}\n\n");
}

uint8_t find_median(uint8_t* arr, uint8_t arrLen){
    if (arrLen%2 == 0){
        uint8_t medianIsAnInt = ((arr[arrLen/2]+arr[arrLen/2-1])%2 == 0) ? TRUE : FALSE;
        if (medianIsAnInt){
            return ((arr[arrLen/2]+arr[arrLen/2-1])/2);
        }
        else{
            return ((arr[arrLen/2]+arr[arrLen/2-1])/2+1);
        }
    }
    else{
        return (arr[arrLen/2+1]);
    }
}

uint8_t find_mean(uint8_t* arr, uint8_t arrLen){
    int total = 0;
    uint8_t mean = 0;
    for (int i = 0; i < arrLen; i++)
    {
        total += arr[i];
    }
    mean = total/arrLen;
    if (total%arrLen >= arrLen/2){
        return (total/arrLen+1);
    }
    else{
        return (total/arrLen);
    }
}

uint8_t find_maximum(uint8_t* arr, uint8_t arrLen){
    return arr[arrLen-1];
}

uint8_t find_minimum(uint8_t* arr, uint8_t arrLen){
    return arr[0];
}

void sort_array(uint8_t* arr, uint8_t arrLen){
    uint8_t currentLowest = 0, temp = 0;
    for (int i = 0; i < (arrLen-1); i++){
        currentLowest = arr[i];
        for (int j = i+1; j < arrLen; j++){
            if (currentLowest > arr[j]){
                currentLowest = arr[j];
                /*Swap - START*/
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                /*Swap - END*/
            }
        }
    }
}
