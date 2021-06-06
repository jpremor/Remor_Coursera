/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Week 1 assignment
 *
 * Provides statistics on a vector of 40 chars.
 *
 * @author Jose P Remor
 * @date 6/4/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char sorted[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  /* Statistics and Printing Functions Go Here */
  printf("Printing the original array.\n");
  print_array(test, SIZE);
  printf("\nPrinting statistics.\n");
  print_statistics(test, SIZE);
  sort_array(test, SIZE, sorted);
  printf("\nNow printing the sorted array.\n");
  print_array(sorted, SIZE);
}



/* Given an array of data and a length, returns the maximum */
unsigned int find_maximum(unsigned char *array, unsigned int n) {
  unsigned int i = 0;
  unsigned int output = 0;

  for (i=0 ; i<n ; i++) {
    if (*array > output) output = *array;
    array++;
  }
  return(output);
}

/* Given an array of data and a length, returns the minimum */
unsigned int find_minimum(unsigned char *array, unsigned int n) {
  unsigned int i = 0;
  unsigned int output = find_maximum(array,n);

  for (i=0 ; i<n ; i++) {
    if (*array < output) output = *array;
    array++;
  }
  return(output);
}

/* A function that prints the statistics of an array including minimum, 
 * maximum, mean, and median. */
void print_statistics(unsigned char *array, unsigned int n) {
  printf("Minimum value is %d \n", find_minimum(array,n));
  printf("Maximum value is %d \n", find_maximum(array,n));
  printf("Mean value is %d \n", find_mean(array,n));
  printf("Mediam value is %d \n\n", find_median(array,n)); 
}

/* Given an array of data and a length, prints the array to the screen */
void print_array(unsigned char *array, unsigned int n) {
  unsigned int i;
  printf("This is the array: ");
  for (i=0 ; i<n ; i++) {
    printf("%d, " , *array);
    array++;
  }
  printf("\n");
}

/* Given an array of data and a length, returns the median value */
unsigned int find_median(unsigned char *array, unsigned int n) {
  unsigned int i = 0;
  unsigned int output = 0;
  
  output = (find_minimum(array,n) + find_maximum(array,n))/2;
  return(output);
}

/* Given an array of data and a length, returns the mean */
unsigned int find_mean(unsigned char *array, unsigned int n) {
  unsigned int i = 0;
  unsigned int output = 0;

  for (i=0 ; i<n ; i++) {
    output += *array;
    array++;
  }
  return(output / n);
}


/* Given an array of data and a length, sorts the array from largest 
 * to smallest.  (The zeroth Element should be the largest value, 
 * and the last element (n-1) should be the smallest value. ) */
void sort_array(unsigned char *array, unsigned int n, unsigned char *sorted_array) {
  unsigned int i;
  unsigned int j;
  unsigned int highest = 255;
  unsigned int next_lowest;
  unsigned char *array_start;
  unsigned char repeat_count;
  unsigned char break_point=0;

  for (i=0 ; i<n ; i++) {

    array = array_start;
    next_lowest = 0;
    for (j=0 ; j<n ; j++) {
      
      if ((*array < highest) & 
	  (*array > next_lowest)) {
       next_lowest = *array;
      }
      if (*array == next_lowest) { // found repeated
        repeat_count++;
      }
      array++;
    }

    highest = next_lowest;
    *sorted_array = next_lowest;
    sorted_array++;

    // find repeats
    array = array_start;
    repeat_count = 0;
    for (j=0; j<n; j++) {
      if (*array == next_lowest) repeat_count++; // count repeats
      array++;
    }
    // add repeats to the output array
    for (j=1; j<repeat_count; j++) {
      *sorted_array = next_lowest;
      sorted_array++;
    }
    
    break_point += repeat_count;
    if (break_point == n) break;
  }
}







	
