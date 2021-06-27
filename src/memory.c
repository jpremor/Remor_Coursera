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
 * @file memory.c
 * @brief Functions to do memory movements and memory manipulation
 *
 * @author Jose Remor
 * @date June 26 2021
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/**
 * @brief Takes two byte pointers (one source and one destination) and
 * a length of bytes to move from the source location to the
 * destination.
 *
 * @param src - Pointer to data array
 * @param dst - Destination address
 * @param length - Memory address size
 *
 * @return Return a pointer to the destination (dst).
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  // create temporary array
  uint8_t * vector = (uint8_t *) malloc(length * sizeof(uint8_t));	
  size_t i;

  for (i = 0; i < length; i++) {
    *(vector + i) = *(src + i);
  }
  for(i = 0; i < length; i++){
    *(dst + i) = *(vector + i);
  }
  free(vector);
  return dst;
}

/**
 * @brief Takes two byte pointers (one source and one destination) and a
 * length of bytes to copy from the source location to the destination.
 *
 * @param src - Pointer to data array
 * @param dst - Destination address
 * @param length - Memory address size
 *
 * @return Return a pointer to the destination (dst).
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  size_t i;

  for (i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }

  return dst;
}

/**
 * @brief Take a pointer to a source memory location, a length in
 * bytes and set all locations of that memory to a given value
 *
 * @param src - Pointer to data array
 * @param length - Memory address size
 * @param value - Value to set the memory with
 *
 * @return Return a pointer to the ource(src).
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  size_t i;

  for (i = 0; i < length; i++) {
    *(src + i) = value;
  }

  return src;
}

/**
 * @brief Take a pointer to a memory location, a length in bytes and
 * zero out all of the memory
 *
 * @param src - Pointer to data array
 * @param Length - memory address size
 * @param value - Value to set the memory with
 *
 * @return Return a pointer to the source (src).
 */
uint8_t * my_memzero(uint8_t * src, size_t length) {
  size_t i;

  for (i = 0; i < length; i++) {
    *(src + i) = 0;
  }

  return src;
}

/**
 * @brief Take a pointer to a memory location and a length in bytes
 * and reverse the order of all of the bytes
 *
 * @param src - Pointer to data array
 * @param length - Memory address size
 *
 * @return Return a pointer to the source (src).
 */
uint8_t * my_reverse(uint8_t * src, size_t length) {
  size_t i;
  uint8_t x=0;

  for(i = 0; i <= (length-1)/2; i++){
    x = *(src + i);
    *(src + i) = *(src + (length-1-i));
    *(src + (length-1-i)) = x;
  }

  return src;
}

/**
 * @brief Take ake number of words to allocate in dynamic memory
 *
 * @param length - Memory address size
 *
 * @return Return a pointer to memory if successful, or a Null
 * Pointer if not successful
 *
 */
int32_t * reserve_words(size_t length) {
  return (int32_t *) malloc(sizeof(int32_t) * length);
}

/**
 * @brief Free a dynamic memory allocation by providing the
 * pointer src to the function
 *
 * @param src - Pointer to data arra
 *
 * @return Return a pointer to memory if successful, or a Null
 * Pointer if not successful
 *
 */
void free_words(int32_t * src) {
  free(src);
}


