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
        float overtime;
        float gross;
    };    

/* function declaration */
void payrollcalc(struct employee st);
void otpay(struct employee st2);
void nonotpay(struct employee st2);

// main program 
int main()
{
// struct employee st1;

struct employee  st1;

 /* REPORT LAYOUT  */
  
printf("\n");
printf("----------------------------------------------------------------------\n");
printf("     Clock#  Wage  Hours     OT   Gross\n");
printf("----------------------------------------------------------------------\n");

payrollcalc(st1);    // call the function

 return 0;
} // end of main program

// function payrollcalc started 
void payrollcalc(struct employee st)
{ 
struct employee  st2[5] ={98401, 10.60, 51.0,0.0,0.0, 526488,9.75,42.5,0.0,0.0,765349, 
    10.50, 37.0,0.0,0.0, 34645, 12.25,45.0,0.0,0.0,127615 ,8.35,0.0,0.0,0.0,};

/* check over time */
for(int j=0;j<SIZE;j++){

if (st2[j].hours > STD_HOURS) {

otpay(st2[j]);

}else{

nonotpay(st2[j]);  
 }
 
}

} // function payrollcalc ended

// Gross pay calculation with over time function otpay started 
void otpay(struct employee  st2) {
  
/*initialization of local variable   */    

float overtime_pay = 0.0;
float standard_pay = 0.0;


st2.overtime = st2.hours - STD_HOURS;
overtime_pay = st2.wage * SOT_PAY * st2.overtime;

standard_pay = st2.wage * STD_HOURS;
st2.gross = overtime_pay + standard_pay ;

printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", st2.id_number , st2.wage, st2.hours, st2.overtime, st2.gross);
printf("\n");
} // Gross pay calculation with over time function otpay ended

// over time calculation with zero over time function nonotpay started 
void nonotpay(struct employee  st2) {

float overtime_pay = 0.0;
float standard_pay = 0.0;

standard_pay = st2.hours * st2.wage;
overtime_pay = (st2.wage * SOT_PAY * 0);
st2.gross = overtime_pay + standard_pay;

printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", st2.id_number , st2.wage, st2.hours, st2.overtime, st2.gross);
printf("\n");

} // over time calculation with zero over time function nonotpay ended   
