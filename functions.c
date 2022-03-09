/*
Clinic Managnment System
version 1.0
By: Hana Ashour
File: Functions
*/
#include "types.c"
#include "functions.h"
#include <string.h>
#include <stdlib.h>
#define MAX 256
s16 slots[5] = {-1, -1, -1, -1, -1};

typedef struct
{
    u64 ID;
    char name[MAX];
    u8 gender;
    u32 age;
} patient;

patient patients[20];
int number_total_patients = 0;
void fileReader()
{
    FILE *f;
    f = fopen("patients.txt", "r");
    if (f != NULL)
    {
        while (!feof(f))
        {
        }
    }
}

void fileWriter()
{
}
void view_record()
{
    u64 temp_ID;
    int flag = 1, i, x;

    printf("USER MODE\n");
    printf("------------------------------------------------------------------------------\n");

    if (number_total_patients != 0)
    {
        printf("Please enter the patient's ID to view\n");
        scanf("%lu", &temp_ID);

        for (i = 0; i < number_total_patients; i++)
        {
            if (temp_ID == patients[i].ID)
            {
                printf("------------------------------------------------------------------------------\n");
                printf("patient found\n");
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {

            printf("%lu\t%s\t%c\t%d\n", patients[i].ID, patients[i].name, patients[i].gender, patients[i].age);
            printf("------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("Patient not found!!\n");
        }
        userMode();
    }
    else
    {
        system("clear");
        printf("NO PATIENTS!!\n");
        userMode();
    }
}
void today_reservation()
{
    int flag = 0;
    printf("USER MODE\n");
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        if (slots[i] != -1)
        {
            flag = 1;
            printf("SLOT %d reserved by patient with ID %lu\n", i + 1, patients[slots[i]].ID);
        }
    }
    if (flag == 0)
    {
        printf("\n");
        printf("NO RESERVATIONS TODAY!!\n");
          printf("------------------------------------------------------------------------------\n");
    }
    userMode();
}
void userMode()
{
    u32 x;
    printf("USER MODE\n");
    printf("------------------------------------------------------------------------------\n");
    printf("To view your record press 1 \n");
    printf("To view today’s reservations press 2 \n");
    printf("To go back to main menu press 0\n");
    printf("------------------------------------------------------------------------------\n");
    scanf("%d", &x);
    switch (x)
    {
    case 0:
    system("clear");
        start();
        break;
    case 1:
    system("clear");
        view_record();
        break;
    case 2:
    system("clear");
        today_reservation();
        break;
    default:
    system("clear");
        printf("incorrect choice\n");
        userMode();
        break;
    }
    system("clear");
}
void slots_display()
{
    //, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm and 4:30pm to 5pm

    printf("ADMIN MODE\n");
    printf("------------------------------------------------------------------------------\n");
    printf("TIME SLOTS\n");
    printf("SLOT 1: 2 pm to 2:30 pm\n");
    printf("SLOT 2: 2:30 pm to 3 pm\n");
    printf("SLOT 3: 3 pm to 3:30 pm\n");
    printf("SLOT 4: 4 pm to 4:30 pm\n");
    printf("SLOT 5: 4:30 pm to 5 pm\n");
    printf("\n");
    printf("Available slots are:\n");
    for (int i = 0; i < 5; i++)
    {
        if (slots[i] == -1)
        {
            printf("SLOT %d\n", i + 1);
        }
    }
    printf("\n");
}
void add_new_patient()
{
    u64 temp_ID = 0;
    int flag = 1;
    //system("clear");
    printf("ADMIN MODE\n");
    printf("------------------------------------------------------------------------------\n");
    printf("Please enter valid 14-digit patient's ID for the new patient.\n");
    scanf("%lu", &temp_ID);

    while (temp_ID <= 9999999999999 || temp_ID >= 100000000000000)
    {
        printf("Incorrect ID!!!\n");
        printf("------------------------------------------------------------------------------\n");
        printf("Please re-enter valid 14-digit patient's ID for the new patient.\n");
        scanf("%lu", &temp_ID); // 14
    }
    if (number_total_patients != 0)
    {

        for (int i = 0; i < number_total_patients; i++)
        {
            if (temp_ID == patients[i].ID)
            {
                printf("Patient already exists!!\n");
                flag = 0;
                adminPage();
                break;
            }
        }
    }
    else
    {
        patients[number_total_patients].ID = temp_ID;
    }
    if (flag == 1)
    {
        patients[number_total_patients].ID = temp_ID;
        printf("Please enter the new patient's name\n");
        scanf("%s", patients[number_total_patients].name);
        printf("Please enter the new patient's gender(f or m)\n");
        scanf("%s", &patients[number_total_patients].gender);
        printf("Please enter the new patient's age\n");
        scanf("%d", &patients[number_total_patients].age);
        system("clear");
        printf("------------------------------------------------------------------------------\n");
        printf("ID: %lu\tName: %s\tGender: %c\tAge: %d\n", patients[number_total_patients].ID, patients[number_total_patients].name, patients[number_total_patients].gender, patients[number_total_patients].age);
        printf("------------------------------------------------------------------------------\n");
        number_total_patients++;
        adminPage();
    }
}
void edit_patient()
{
    u64 temp_ID;
    int flag = 1, i, x;

    if (number_total_patients != 0)
    {
        printf("Please enter the patient's ID to edit\n");
        scanf("%lu", &temp_ID);

        for (i = 0; i < number_total_patients; i++)
        {
            if (temp_ID == patients[i].ID)
            {
                printf("------------------------------------------------------------------------------\n");
                printf("patient found\n");
                printf("------------------------------------------------------------------------------\n");
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            printf("ID: %lu\tName: %s\tGender: %c\tAge: %d\n", patients[i].ID, patients[i].name, patients[i].gender, patients[i].age);
            printf("Enter the information to be edited\n");
            printf("To edit name press 1\n");
            printf("To edit age press 2\n");
            printf("To edit gender press 3\n");
            printf("to go back to admin page press 0\n");
            scanf("%d", &x);
            if (x == 1)
            {
                printf("enter new name\n");
                scanf("%s", patients[i].name);
                system("clear");
                printf("------------------------------------------------------------------------------\n");
                printf("ID: %lu\tName: %s\tGender: %c\tAge: %d\n", patients[i].ID, patients[i].name, patients[i].gender, patients[i].age);
                printf("------------------------------------------------------------------------------\n");
                adminPage();
            }
            else if (x == 2)
            {
                printf("enter new age\n");
                scanf("%d", &patients[i].age);
                     system("clear");
                     printf("------------------------------------------------------------------------------\n");
                printf("ID: %lu\tName: %s\tGender: %c\tAge: %d\n", patients[i].ID, patients[i].name, patients[i].gender, patients[i].age);
                printf("------------------------------------------------------------------------------\n");
                adminPage();
            }
            else if (x == 3)
            {
                printf("enter new gender(f or m)\n");
                scanf("%s", &patients[i].gender);
                     system("clear");
                     printf("------------------------------------------------------------------------------\n");
                printf("ID: %lu\tName: %s\tGender: %c\tAge: %d\n", patients[i].ID, patients[i].name, patients[i].gender, patients[i].age);
                printf("------------------------------------------------------------------------------\n");
                adminPage();
            }
            else if (x == 0)
            {
                system("clear");
                adminPage();
            }
        }
        else
        {
            system("clear");
            printf("Patient does not exist\n");
            printf("------------------------------------------------------------------------------\n");
            adminPage();
        }
    }
    else
    {
        system("clear");
        printf("\n");
        printf("NO PATIENTS!!\n");
        printf("------------------------------------------------------------------------------\n");
        adminPage();
    }
}
void reserve_slot()
{

    u64 temp_ID;
    int flag = 1, i, x;

    if (number_total_patients != 0)
    {
        printf("Please enter patient's ID to reserve a slot\n");
        scanf("%lu", &temp_ID);

        for (i = 0; i < number_total_patients; i++)
        {
            if (temp_ID == patients[i].ID)
            {
                printf("patient found\n");
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            slots_display();
            printf("------------------------------------------------------------------------------\n");
            printf("Please enter the wanted slot to be reserved by entering slot number\n");
            scanf("%d", &x);
            while (1)
            {
                if (x == 1)
                {
                    if (slots[0] == -1)
                    {
                        printf("SLOT 1: 2 pm to 2:30 pm is reserved by patient with ID = %lu \n", patients[i].ID);
                        slots[0] = i;
                    }
                    else
                    {
                        printf("Slot 1 is already reserved\n");
                        printf("\n");
                    }
                    break;
                }
                else if (x == 2)
                {
                    if (slots[1] == -1)
                    {
                        printf("SLOT 2: 2:30 pm to 3 pm is reserved by patient with ID = %lu \n", patients[i].ID);
                        slots[1] = i;
                    }
                    else
                    {
                        printf("Slot 2 is already reserved\n");
                        printf("\n");
                    }
                    break;
                }
                else if (x == 3)
                {
                    if (slots[2] == -1)
                    {
                        printf("SLOT 3: 3 pm to 3:30 pm is reserved by patient with ID = %lu \n", patients[i].ID);
                        slots[2] = i;
                    }
                    else
                    {
                        printf("Slot 3 is already reserved\n");
                        printf("\n");
                    }
                    break;
                }
                else if (x == 4)
                {
                    if (slots[3] == -1)
                    {
                        printf("SLOT 4: 4 pm to 4:30 pm is reserved by patient with ID = %lu \n", patients[i].ID);
                        slots[3] = i;
                    }
                    else
                    {
                        printf("Slot 4 is already reserved\n");
                        printf("\n");
                    }
                    break;
                }
                else if (x == 5)
                {
                    if (slots[4] == -1)
                    {
                        printf("SLOT 5: 4:30 pm to 5 pm is reserved by patient with ID = %lu \n", patients[i].ID);
                        slots[4] = i;
                    }
                    else
                    {
                        printf("Slot 5 is already reserved\n");
                        printf("\n");
                    }
                    break;
                }
                else
                {
                    printf("Invalid slot\n");
                    printf("Please enter the wanted slot to be reserved by entering slot number\n");
                    scanf("%d", &x);
                }
            }
            adminPage();
        }
        else
        {
            system("clear");
            printf("Patient does not exist\n\n");
             printf("------------------------------------------------------------------------------\n");
            adminPage();
        }
    }
    else
    {
        system("clear");
        printf("\n");
        printf("NO PATIENTS!!\n");
        printf("------------------------------------------------------------------------------\n");
        adminPage();
    }
}
void cancel_reservation()
{
    u64 temp_ID;
    int flag = 1, i, x = 1;

    if (number_total_patients != 0)
    {
        printf("Please enter patient's ID to cancel their slot\n");
        scanf("%lu", &temp_ID);

        for (i = 0; i < number_total_patients; i++)
        {
            if (temp_ID == patients[i].ID)
            {
                printf("patient found\n");
                flag = 0;
                break;
            }
        }
    }
    else
    {
        system("clear");
        printf("\n");
        printf("NO PATIENTS!!\n");
        adminPage();
    }
    if (flag == 0)
    {
        for (int j = 0; j < 5; j++)
        {
            if (slots[j] == i)
            {
                slots[j] = -1;
                printf("SLOT %d has been cancelled\n", j + 1);
                x = 0;
                break;
            }
        }
        if (x == 1)
        {
            printf("Patient has no previous reservations!\n\n");
        }
        adminPage();
    }
    else
    {
        system("clear");
        printf("Patient could not be found!\n\n");
        adminPage();
    }
}
void adminPage()
{
    int press;
    printf("ADMIN MODE\n");
    printf("------------------------------------------------------------------------------\n");
    printf("To add a new patient record press 1\n");
    printf("To edit a patient record press 2\n");
    printf("To reserve a slot with the a doctor press 3\n");
    printf("To cancel a reservation press 4\n");
    printf("To go back to main menu press 0\n");
    printf("------------------------------------------------------------------------------\n");
    scanf("%d", &press);
    while (1)
    {
        if (press == 1)
        {
            system("clear");
            add_new_patient();
            break;
        }
        else if (press == 2)
        {
            system("clear");
            edit_patient();
            break;
        }
        else if (press == 3)
        {
            system("clear");
            reserve_slot();
            break;
        }
        else if (press == 4)
        {
            system("clear");
            cancel_reservation();
            break;
        }
        else if (press == 0)
        {
            system("clear");
            start();
            break;
        }
        else
        {
            printf("\n");
            printf("ADMIN MODE\n");
            printf("Incorrect choice!!\n");
            printf("Please choose again\n");
            printf("------------------------------------------------------------------------------\n");
            printf("To add a new patient record press 1\n");
            printf("To edit a patient record press 2\n");
            printf("To reserve a slot with the a doctor press 3\n");
            printf("To cancel a reservation press 4\n");
            printf("To go back to main menu press 0\n");
            printf("------------------------------------------------------------------------------\n");
            scanf("%d", &press);
        }
    }
    
}

void adminMode()
{
    char password[5];
    int comp;
    printf("Please enter 4 digit password:\n");
    // for (int i = 0; i < 4; i++)
    // {
    //     scanf("\n%c", &password[i]);
    //     printf("\33[2K\r");
    //     for (int z = -1; z < i; z++)
    //     {
    //         printf("*");
    //     }
    // }
    // printf("\n");
    // password[4] = '\0';
    scanf("%s",password);
    comp = strcmp(password, "1234");
    if (comp == 0)
    {
        adminPage();
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Incorrect password, please enter password again:\n");
            // for (int j = 0; j < 4; j++)
            // {
            //     scanf("\n%c", &password[j]);
            //     printf("\33[2K\r");
            //     for (int z = -1; z < j; z++)
            //     {
            //         printf("*");
            //     }
            // }
            // printf("\n");
            // password[4] = '\0';
             scanf("%s",password);
            comp = strcmp(password, "1234");
            if (comp == 0)
            {
                adminPage();
                break;
            }
        }
        if (comp != 0)
        {
            system("clear");
            printf("\nsytstem is closed!!\n");
        }
    }
}
void start()
{
    int x;
    system("clear");
    printf("------------------------------------------------------------------------------\n");
    printf("                **WELCOME TO MEDBAY CLINIC MANAGNMENT SYSTEM**\n");
    printf("Please choose user mode:\n");
    printf("Admin mode press 1\n");
    printf("User Mode press 2\n");
    printf("To exit the clinic system press 0\n");
    printf("------------------------------------------------------------------------------\n");
    scanf("%d", &x);
    switch (x)
    {
    case 0:
        system("clear");
        exit(0);
    case 1:
        system("clear");
        adminMode();

        break;
    case 2:
        system("clear");
        userMode();

        break;
    default:
        system("clear");
        printf("INCORRECT CHOICE!!!\n");
        start();
        break;
    }
}
