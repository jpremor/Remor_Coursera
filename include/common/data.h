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
 * @file data.h
 * @brief Basic data manipulation
 *
 * @author Jose Remor
 * @date June 26 2021
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#define ABS(a) ((a) < 0 ? -(a) : (a))

/**
 * @brief convert data from a standard integer type into an 
 * ASCII string 
 *
 * @param data - The number you wish to convert
 * @param ptr -  Index into pointer array to set value
 * @param base - support bases 2 to 16 by specifying the 
 * integer value of the base you wish to convert to (base)
 *
 * @return  length of the converted data (including a 
 * negative sign). Example my_itoa(ptr, 1234, 10) should 
 * return an ASCII string length of 5 (including the null 
 * terminator).
 *
 */
int8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
	
/**
 * @brief convert data back from an ASCII represented string 
 * into an integer type
 *
 * @param ptr - Character string to convert is passed in 
 * as a uint8_t * pointer (ptr)
 * @param digits - Number of digits in your character set is 
 * passed in as a uint8_t integer (digits).
 * @param base - support bases 2 to 16 by specifying the
 * integer value of the base you wish to convert to (base)
 *
 * @return converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
