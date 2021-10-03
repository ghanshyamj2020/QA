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

void payrollcalc(int a, float b, float c);

int main()
{
     float Over_time = 0.0 ;
    /* unique employee identifier */
  long int clockNumber [] = {98401, 526488, 765349, 34645, 127615};

   /* hourly wage for each employee */        
   float hourlyWage [] = {10.60, 9.75, 10.50, 12.25, 8.35};
  
  /* working hourse for each employee */
  float workhourse [] = {51.0, 42.5, 37.0, 45.0, 0.0}; 
   printf("\n");
   printf("----------------------------------------------------------------------\n");
   printf("    Clock#   Wage     Hours     OT    Gross\n");
   printf("----------------------------------------------------------------------\n");
   
   for( int i = 0; i < SIZE; ++i) {  
       //Passing array element clockNumber ,hourlyWage , workhourse.
       payrollcalc(clockNumber[i],hourlyWage[i], workhourse[i]);  
               
        } // end of for loop
   return 0;
}

// function to calculate the Gross pay
void payrollcalc(int a, float b, float c)
   {   
    /*initialization of  */ 
    float Over_time = 0.0;
    float overtime_pay = 0.0;
    float gross = 0.0;
    float standard_pay = 0.0;

    if (c > STD_HOURS) {
   // calculate over time                
        Over_time = c - STD_HOURS;
   // calculate standard pay
        standard_pay = b * STD_HOURS ;  
   // calculate over time pay            
        overtime_pay = b * SOT_PAY * Over_time;
   // calculate gross pay                  
        gross = overtime_pay + standard_pay ;  
                            
        printf("    %06d  %5.2f   %5.1f    %5.1f    %6.2f", a, b, c, Over_time, gross);
        printf("\n");
                      
          }  else {
              
        Over_time = 0.0;
              
        standard_pay = c * b;           
        overtime_pay = b * SOT_PAY * Over_time;  
              
        gross = overtime_pay + standard_pay;
        printf("    %06d  %5.2f   %5.1f    %5.1f    %6.2f", a, b, c, Over_time, gross);
        printf("\n");

     }
}
