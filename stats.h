
/******************************************************************************
 *  * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *  *
 *  * Redistribution, modification or use of this software in source or binary
 *  * forms is permitted as long as the files maintain this copyright. Users are 
 *  * permitted to modify this and use it to learn about the field of embedded
 *  * software. Alex Fosdick and the University of Colorado are not liable for any
 *  * misuse of this material. 
 *  *
 *  * @file stats.h 
 *  * @brief The header file of stats.c where it includes all the definitions.
 *  *  
 *  * @author Wu Wei Ng
 *  * @date 19 Aug 2023
 * ****************************************************************************/
#ifndef __STATS_H__
#define __STATS_H__

// CONSTANT - START
#define TRUE (1)
#define FALSE (0)
// CONSTANT - END

// TYPE DEFINITION - START
typedef signed char int8_t;
typedef unsigned char uint8_t;
// TYPE DEFINITION - END

// FUNCTION PROTOTYPE - START
/******************************************************************************
* Function: print_statistics
* Description:
*  
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return: void
******************************************************************************/
void print_statistics(uint8_t median, uint8_t mean, uint8_t max, uint8_t min);
/******************************************************************************
* Function: print_array
* Description:
*  
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return: void
******************************************************************************/
void print_array(uint8_t* arr, uint8_t arrLen);
/******************************************************************************
* Function: find_median
* Description:
*     Given an sorted array of data and a length, returns the median value
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return: uint8_t - Median of the array
******************************************************************************/
uint8_t find_median(uint8_t* arr, uint8_t arrLen);
/******************************************************************************
* Function: find_mean
* Description:
*     Given an array of data and a length, returns the mean
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return:
******************************************************************************/
uint8_t find_mean(uint8_t* arr, uint8_t arrLen);
/******************************************************************************
* Function: find_maximum
* Description:
*     Given an ascending sorted array of data and a length, returns the maximum
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return:
******************************************************************************/
uint8_t find_maximum(uint8_t* arr, uint8_t arrLen);
/******************************************************************************
* Function: find_minimum
* Description:
*     Given an ascending sorted array of data and a length, returns the minimum
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return:
******************************************************************************/
uint8_t find_minimum(uint8_t* arr, uint8_t arrLen);
/******************************************************************************
* Function: sort_array
* Description: 
*     Given an array of data and a length, sorts the array from 
*     largest to smallest.
* Parameters:
*     uint8_t *  arr: Pointer to a unsigned char data set
*     uint8_t arrLen: size of the data set
* Return: void
******************************************************************************/
void sort_array(uint8_t* arr, uint8_t arrLen);
// FUNCTION PROTOTYPE - END
#endif /* __STATS_H__ */
