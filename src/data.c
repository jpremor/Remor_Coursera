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
 * @file data.c
 * @brief Basic data manipulation
 *
 * @author Jose Remor
 * @date June 26 2021
 *
 */
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
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
int8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t i = 0;
  int32_t rem = data % base;

  // In case data = zero
  if (data == 0) {
    ptr[i++] = '0';
    ptr[i] = '\0';
    return i;
  }
  // if not zero, is it positive?
  else if (data > 0) {
    while (data != 0) {
      ptr[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
      data = data/base;
    }
  }
  // not zero nor positive, its negative
  else {
    while (data != 0) {
      ptr[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
      data = data/base;
    }
    data = -data;
    ptr[i++] = '-';
  }

  // Reverse the string until the null termination
  my_reverse(ptr, i);

  ptr[i] = '\0'; // Append string terminator

  return i;
}


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
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t out = 0;
  uint8_t i;

  for (i=1; i < digits; i++) {
      out = out*base + ptr[i] - '0';
  }
  if (prt[0] == '-') { 
    out = -out;
  }

  return out;
}














