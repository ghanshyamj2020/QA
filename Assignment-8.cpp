//*******************
//
// Homework: 8 (Chapter 10)
//
// Name: Bandana Kumar
//
// Class: C Programming, Fall 2021
//
// Date: 07/11/21
//
// Description: Program which uses Link List Pointer struct, arrays and function to determine gross
// pay and outputs be sent to the console.
//
//
//********************

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5
#define SIZE 5

struct employee
    {
char *name;
int id_number;
float wage;
float hours;
float overtime;
float gross;
struct employee *next;
    };


//  function declaration

//void payrollcalc(struct employee *st3);
struct employee * otpay(struct employee *st2);

float overtime_pay = 0.0;
float standard_pay = 0.0;
int i=0, j;


int main()
{

struct employee *head, *h, *node, *strex, *strex1, *st4;

struct employee  st3[5] ={{"Connie Cobol ", 98401, 10.60, 51.0,0.0,0.0},
  {"Mary Apl     ",526488,9.75,42.5,0.0,0.0},
  {"Frank Fortran",765349,10.50, 37.0,0.0,0.0},
  {"Jeff Ada     ", 34645, 12.25,45.0,0.0,0.0},
  {"Anton Pascal ",127615 ,10.00,40.0,0.0,0.0}};

st4=st3;
node = (struct employee*) malloc(sizeof(struct employee));

head=node;
h=node;
while( i< SIZE)
{
    node->name = st4->name; 
    node->id_number =st4->id_number;
    node->wage = st4->wage ;
    node->hours = st4->hours;
    node->overtime = st4->overtime;
    node->gross = st4->gross ;
    node->next = (struct employee*) malloc(sizeof(struct employee));
    node=node->next;
    st4++;
    i++;
 }
node->next=NULL;
// REPORT LAYOUT Header detail

printf("----------------------------------------------------------------------\n");
printf("Name            Clock#  Wage    Hours    OT   Gross\n");
printf("----------------------------------------------------------------------\n");

/* check over time */
float total_ot=0.0;
float total_gross=0.0;
float total_wage=0.0;
float total_hours=0.0;

 
while( head->next !=NULL) {
    strex1 = (struct employee*) malloc(sizeof(struct employee));
    strex1 = otpay(head);
    total_wage  = total_wage + strex1->wage;
    total_hours = total_hours + strex1->hours;
    total_ot    = total_ot + strex1->overtime;
    total_gross = total_gross + strex1->gross;
    head =head->next;
   
}



printf("----------------------------------------------------------------------\n");
printf("\n");
printf("Total:                  %.2f %8.1f %5.1f %8.2f  \n",total_wage, total_hours, total_ot, total_gross);
printf("Average:                %.2f %8.1f %5.1f %8.2f \n", total_wage/SIZE, total_hours/ SIZE, total_ot/SIZE,
      total_gross/SIZE);

                  
 
}
// Gross pay calculation with over time function otpay started
struct employee * otpay(struct employee *st2) {

/*initialization of local variable   */

struct employee  *strex;

strex = (struct employee*) malloc(sizeof(struct employee));
if (st2->hours > STD_HOURS) {
    st2->overtime = st2->hours - STD_HOURS;
    overtime_pay = st2->wage * SOT_PAY * st2->overtime;
    standard_pay = st2->wage * STD_HOURS;
    st2->gross = overtime_pay + standard_pay;

    strex->wage     = st2->wage;
    strex->hours    = st2->hours;
    strex->overtime = st2->overtime;
    strex->gross    = st2->gross;
   //printf("111---------------------------------------------------------------------\n");

    printf("%s   %06d  %5.2f   %5.1f  %5.1f  %5.2f\n",st2->name, st2->id_number , st2->wage, st2->hours,

st2->overtime, st2->gross);


} else {

// over time calculation with zero over time
    standard_pay = st2->hours * st2->wage;
    overtime_pay = (st2->wage * SOT_PAY * 0);
    st2->gross = overtime_pay + standard_pay;

    strex->wage     = st2->wage;
    strex->hours    = st2->hours;
    strex->overtime = st2->overtime;
    strex->gross    = st2->gross;

   printf("%s   %06d  %5.2f   %5.1f  %5.1f  %5.2f \n",st2->name, st2->id_number , st2->wage, st2->hours,
  st2->overtime, st2->gross);



}
 return(st2++);

}
