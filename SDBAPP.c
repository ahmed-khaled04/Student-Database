#include <stdio.h>
#include "SDB.h"



//App Super Loop
void SDB_APP(){



    SDB_intialize();
    uint8 choice = 1;
    while(choice){

        printf("To Add Entry: Press 1\n");
        printf("To Get Used Size: Press 2\n");
        printf("To Read Student Data: Press 3\n");
        printf("To Get All Student IDs: Press 4\n");
        printf("To Check ID: Press 5\n");
        printf("To Delete Student: Press 6\n");
        printf("To Check If DB Is Full: Press 7\n");
        printf("To Exit: Press 0\n");

        scanf("%d" , &choice);

        SDB_action(choice);
        
    }



}

//That Calls WHat Function Get Done
void SDB_action(uint8 choice){


    uint8 count;
    uint32 list[10];
    uint32 id;
    switch(choice){
        case 1:
        SDB_AddEntry();
        break;
        
        case 2:
        printf("Size Is: %d\n", SDB_GetUsedSize());
        break;

        case 3:
        printf("Enter Student ID: \n");
        scanf("%d" , &id);
        SDB_ReadEntry(id);
        break;

        case 4:
        SDB_GetList(&count , list);
        break;


        case 5:
        printf("Enter Student ID: \n");
        scanf("%d" , &id);
        SDB_IsIdExist(id);
        break;

        case 6:
        printf("Enter Student ID: \n");
        scanf("%d" , &id);
        SDB_deleteEntry(id);
        break;

        case 7:
        if(SDB_isFull()){
            printf("DB Is Full\n");
        }
        else{
            printf("DB Is Not Full\n");
        }
        break;

        case 0:
        printf("Exited Program\n");
        break;

        default:
            printf("Invalid Input\n");
        break;
    }

}