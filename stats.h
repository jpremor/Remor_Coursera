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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Given an array of data and a length, returns the maximum. 
 *  
 * @param array[] : pointer to the array
 * @param n : array size
 * 
 * @return Returns the maximum value in the array
 */
unsigned int find_maximum(unsigned char *array, unsigned int n);

/**
 * @brief Given an array of data and a length, returns the minimum.
 * 
 * @param array[] : pointer to the array
 * @param n : array size
 * 
 * @return Returns the maximum value in the array
*/
unsigned int find_maximum(unsigned char *array, unsigned int n);

/**
 * @brief  A function that prints the statistics of an array 
 *  including minimum, maximum, mean, and median.
 * 
 * @param array[] : pointer to the array
 * @param n : array size
 *          
 * @return Do not return information
*/
void print_statistics(unsigned char *array, unsigned int n);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * @param array[] : pointer to the array
 * @param n : array size
 *
 * @return Do not return information
*/
void print_array(unsigned char *array, unsigned int n);

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array[] : pointer to the array
 * @param n : array size
 *
 * @return Returns the medium value in the array
*/
unsigned int find_median(unsigned char *array, unsigned int n);

/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * @param array[] : pointer to the array
 * @param n : array size
 *
 * @return Returns the mean value in the array
*/
unsigned int find_mean(unsigned char *array, unsigned int n);


/**
 * @brief Sort array from max to min value
 *
 * Given an array of data and a length, sorts the array from largest
 * to smallest.  (The zeroth Element should be the largest value,
 * and the last element (n-1) should be the smallest value. )
 *
 * @param array[] : pointer to the array
 * @param n : array size
 * @param sorted_array[] : pointed to the resulting array
 *
 * @return Do not return value
 */
void sort_array(unsigned char *array, unsigned int n, unsigned char *sorted_array);


#endif /* __STATS_H__ */
