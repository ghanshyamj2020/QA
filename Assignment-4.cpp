//******************************************************* 
// 
// Homework: 4 (Chapter 7) 
// 
// Name: Bandana Kumar
// 
// Class: C Programming, Fall 2021 
// 
// Date: 10/03/21 
// 
// Description: Program which uses arrays and function to determine gross 
// pay and outputs be sent to the console.  
// 
// 
//********************************************************
#include<stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5
#define SIZE 5    // number of employees to process

/* function declaration */
void payrollcalc(int clockNumber , float hourlyWage, float workhourse);
void otpay(int clockNumber , float hourlyWage, float workhourse);
void nonotpay(int clockNumber , float hourlyWage, float workhourse);


int main()
{
 /* clock number for each employee */   
 int clockNumber  [] = {98401, 526488, 765349, 34645, 127615};
 /* hourly wage for each employee */
 float hourlyWage [] = {10.60, 9.75, 10.50, 12.25, 8.35};
 /* working hourse for each employee */
 float workhourse [] = {51.0, 42.5, 37.0, 45.0, 0.0};
/* REPORT LAYOUT  */
printf("\n");
printf("----------------------------------------------------------------------\n");
printf("    Clock#   Wage    Hours   OT   Gross\n");
printf("----------------------------------------------------------------------\n");
for( int i = 0; i < SIZE; ++i) {
/* Passing array element clockNumber ,hourlyWage , workhourse. */
    payrollcalc(clockNumber[i] , hourlyWage[i], workhourse[i]); 
}  // end of for loop
printf("\n");
return 0;
} // end of main function.
void payrollcalc(int clockNumber , float hourlyWage, float workhourse)
{
/* check over time */    
if (workhourse > STD_HOURS) {
    otpay(clockNumber , hourlyWage, workhourse);
}else{   
    nonotpay(clockNumber , hourlyWage, workhourse);
}
}
/* This function calculate over time and Gross pay using clockNumber, hourlyWage, workhourse */
void otpay(int clockNumber , float hourlyWage, float workhourse)
{
/*initialization of local variable   */    
float Over_time = 0.0;
float overtime_pay = 0.0;
float standard_pay = 0.0;
float gross = 0.0;

Over_time = workhourse - STD_HOURS;
overtime_pay = hourlyWage * SOT_PAY * Over_time;

standard_pay = hourlyWage * STD_HOURS;
gross = overtime_pay + standard_pay ;

printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", clockNumber , hourlyWage, workhourse, Over_time, gross);
printf("\n");
}
/* calculate and Gross pay and for zero over time */
void nonotpay(int clockNumber , float hourlyWage, float workhourse)
{
float Over_time = 0.0;
float overtime_pay = 0.0;
float standard_pay = 0.0;
float gross = 0.0;   
 
standard_pay = workhourse * hourlyWage;
overtime_pay = hourlyWage * SOT_PAY * Over_time;
gross = overtime_pay + standard_pay;
 
printf("    %06d  %5.2f   %5.1f  %5.1f  %6.2f", clockNumber , hourlyWage, workhourse, Over_time, gross);
printf("\n");
}