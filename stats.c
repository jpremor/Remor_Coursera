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
  /* Statistics and Printing Functions Go Here */
}

/* Given an array of data and a length, returns the maximum */
unsigned int find_maximum(unsigned char *array, unsigned int n) {
}

/* Given an array of data and a length, returns the minimum */
unsigned int find_minimum(unsigned char *array, unsigned int n) {
}

/* A function that prints the statistics of an array including minimum, 
 * maximum, mean, and median. */
void print_statistics(unsigned char *array, unsigned int n) {
}

/* Given an array of data and a length, prints the array to the screen */
void print_array(unsigned char *array, unsigned int n) {
}

/* Given an array of data and a length, returns the median value */
unsigned int find_median(unsigned char *array, unsigned int n) {
}

/* Given an array of data and a length, returns the mean */
unsigned int find_mean(unsigned char *array, unsigned int n) {
}


/* Given an array of data and a length, sorts the array from largest 
 * to smallest.  (The zeroth Element should be the largest value, 
 * and the last element (n-1) should be the smallest value. ) */
void sort_array(unsigned char *array, unsigned int n, unsigned char *sorted_array) {
}







	
