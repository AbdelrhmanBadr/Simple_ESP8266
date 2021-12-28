/** @file Std_DataType.h
*
* @brief This file is used to define standarded data types in AVR (unsigned and signed) integers and floats.
* @layer Service
* @note	THIS FILE MUST BE INCLUDED IN ALL SOURCE FILES
* @author Abdelrhman Badr
* @last update 27-sep-21
*/

#ifndef  STD_DATATYPES_H_
#define STD_DATATYPES_H_

/*Define null*/
#define NULL	0
/*Re-define volatile dataType*/
#define __IO__    volatile
#define __I__     volatile
#define __O__     volatile

/*unsigned datatypes*/
typedef unsigned char 		uint8t;
typedef unsigned short 		uint16t;
typedef unsigned long 		uint32t;
typedef unsigned long long 	uint64t;

/*signed datatypes*/
typedef signed char 		 int8t;
typedef signed short 		 int16t;
typedef signed long 		 int32t;
typedef signed long long     int64t;

/*float datatypes*/
typedef float 	float32t;
typedef double 	float64t;

#endif /*STD_DATATYPES_H_*/
