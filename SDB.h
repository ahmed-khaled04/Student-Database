#ifndef _SDB_H
#define _SDB_H


/*
defining some types with known size (bits)
u ==> unsigned
number if bits is the numbers beside the data type
*/

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;

// defining boolean value false: 0 true: 1
typedef enum {FALSE , TRUE} boolean;


//For defining every student with these exact data
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
}student;

//Function definition


boolean SDB_isFull();
uint8 SDB_GetUsedSize();
boolean SDB_AddEntry();
void SDB_deleteEntry(uint32 id);
boolean SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list);
boolean SDB_IsIdExist (uint32 id);
void swap(student *s1 , student *s2);
void SDB_intialize();

extern student students[10];

#endif