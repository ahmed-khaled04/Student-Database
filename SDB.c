#include "SDB.h"
#include <stdio.h>


//Checks If DB is full or not
//if true then its full otherwise false
boolean SDB_isFull(){

    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID == 0){
            return FALSE;
        }
    }
    return TRUE;

}
//DONE


//Returns number of students in DB
uint8 SDB_GetUsedSize(){

    uint8 size = 0;
    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID > 0)
            size++;
    }
    return size;

}
//DONE

//Add entry in DB
boolean SDB_AddEntry(){

    uint32 id;
    uint32 year;
    uint32 id1;
    uint32 grade1;
    uint32 id2;
    uint32 grade2;
    uint32 id3;
    uint32 grade3;


    if(!SDB_isFull()){
        printf("Student ID: \n");
        scanf("%d" , &id);
        printf("Student Year: \n");
        scanf("%d" , &year);
        printf("Course One ID: \n");
        scanf("%d" , &id1);
        printf("Course One Grade: \n");
        scanf("%d" , &grade1);
        printf("Course Two ID: \n");
        scanf("%d" , &id2);
        printf("Course Two Grade: \n");
        scanf("%d" , &grade2);
        printf("Course Three ID: \n");
        scanf("%d" , &id3);
        printf("Course Three Grade: \n");
        scanf("%d" , &grade3);

        if(id <= 0 || id1 <= 0 || id2 <= 0 || id3 <= 0 || grade1 < 0 || grade2 < 0 || grade3 < 0){
            printf("Data is Invalid.\nTry Again\n");
            return FALSE;
        }
        if(SDB_IsIdExist(id)){
            printf("ID Already Exists. Try Another ID \n");
            return FALSE;
        }

        for(int i = 0; i < 10; i++){
            if(students[i].Student_ID == 0){


                students[i].Student_ID = id;
                students[i].Student_year = year;
                students[i].Course1_ID = id1;
                students[i].Course1_grade = grade1;
                students[i].Course2_ID = id2;
                students[i].Course2_grade = grade2;
                students[i].Course3_ID = id3;
                students[i].Course3_grade = grade3;\
                //Value Added

                printf("Student Added Successfully\n");

                return TRUE;


            }
        }

    }
    else{
        printf("Size Full\n");
        return FALSE;
    }



}
//DONE

//Delete entry based onthe ID
void SDB_deleteEntry(uint32 id){

    if(SDB_GetUsedSize() <= 3)
    {
        printf("Minimum amount is reached cannot delete\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID == id){

            students[i].Student_ID = 0;
            students[i].Student_year = 0;
            students[i].Course1_ID = 0;
            students[i].Course1_grade = 0;
            students[i].Course2_ID = 0;
            students[i].Course2_grade = 0;
            students[i].Course3_ID = 0;
            students[i].Course3_grade = 0;


            printf("Student Deleted\n");
            return ;
        }
        
    }

    printf("Student Not Found\n");

}
//DONE

//Prints Data if student if exists
//Returns 1 if exists otherwise 0
boolean SDB_ReadEntry (uint32 id){
    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID == id){
            printf("ID: %d\nYear: %d\nFirst Course ID: %d\nFirst Course Grade: %d\n" , students[i].Student_ID , students[i].Student_year , students[i].Course1_ID , students[i].Course1_grade);
            printf("Second Course ID: %d\nSecond Course Grade: %d\nThird Course ID: %d\nThird Course Grade: %d\n" , students[i].Course2_ID , students[i].Course2_grade , students[i].Course3_ID , students[i].Course3_grade);
            return TRUE;
        }
    }
    printf("Student Not Found\n");
    return FALSE;
}
//DONE


//Prints All IDs
void SDB_GetList (uint8 * count, uint32 * list){

    *count = SDB_GetUsedSize();
    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID > 0)
            list[i] = students[i].Student_ID;
    }

    for(int i = 0; i < *count ;i++){
        printf("ID: %d\n" , list[i]);
    }

}

//Checks if The Id Exists
boolean SDB_IsIdExist (uint32 id){

    for(int i = 0; i < 10; i++){
        if(students[i].Student_ID == id){
            printf("ID Exists\n");
            return TRUE;
        }
    }
    printf("ID Does not Exist\n");
    return FALSE;

}


//intialize Database with zeroes
void SDB_intialize(){

    for(int i = 0; i < 10; i++){
        students[i].Student_ID = 0;
        students[i].Student_year = 0;
        students[i].Course1_ID = 0;
        students[i].Course1_grade = 0;
        students[i].Course2_ID = 0;
        students[i].Course2_grade = 0;
        students[i].Course3_ID = 0;
        students[i].Course3_grade = 0;
    }

}
