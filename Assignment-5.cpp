//******************************************************* 
// 
// Homework: 5 (Chapter 8) 
// 
// Name: Bandana Kumar
// 
// Class: C Programming, Fall 2021 
// 
// Date: 10/10/21 
// 
// Description: Program which uses struct, arrays and function to determine gross 
// pay and outputs be sent to the console.  
// 
// 
//********************************************************

#include<stdio.h>  
#include <string.h> 
#include<stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5
#define SIZE 5 
struct employee 
    {
        int id_number;  /* or just int id_number; */
        float wage;
        float hours;
        
    };    

/* function declaration *
void payrollcalc(struct employee st);
void otpay(struct employee st2);
void nonotpay(struct employee st2);

// main program 
int main()
{
// struct employee st1;

struct employee  st1[SIZE];

 /* REPORT LAYOUT  */
  
printf("\n");
printf("----------------------------------------------------------------------\n");
printf("     Clock#  Wage  Hours     OT   Gross\n");
printf("----------------------------------------------------------------------\n");
for(int i=0;i<1;i++){
    
  payrollcalc(st1[i]);
}  // end of for loop
  return 0;
} // end of main program

// *******************************************
void payrollcalc(struct employee st)
{ 
struct employee  st2[5] ={98401, 10.60, 51.0, 526488,9.75,42.5,765349, 10.50, 37.0, 34645, 12.25,45.0,127615 ,8.35,0.0};

/* check over time */
for(int j=0;j<5;j++){

if (st2[j].hours > STD_HOURS) {

otpay(st2[j]);

}else{

nonotpay(st2[j]);  
 }
 
    
}

    
}
// Gross pay calculation with over time function 
void otpay(struct employee  st2) {
  
/*initialization of local variable   */    
float Over_time = 0.0;
float overtime_pay = 0.0;
float standard_pay = 0.0;
float gross = 0.0;

Over_time = st2.hours - STD_HOURS;
overtime_pay = st2.wage * SOT_PAY * Over_time;

standard_pay = st2.wage * STD_HOURS;
gross = overtime_pay + standard_pay ;

printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", st2.id_number , st2.wage, st2.hours, Over_time, gross);
printf("\n");
}

// over time calculation with zero over time function  
void nonotpay(struct employee  st2) {
float Over_time = 0.0;
float overtime_pay = 0.0;
float standard_pay = 0.0;
float gross = 0.0;   
 
standard_pay = st2.hours * st2.wage;
overtime_pay = (st2.wage * SOT_PAY * 0);
gross = overtime_pay + standard_pay;

printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", st2.id_number , st2.wage, st2.hours, Over_time, gross);
printf("\n");

}    
