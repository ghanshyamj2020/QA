//******************************************************* 
// 
// Homework: 3 (Chapter 6) 
// 
// Name: Bandana Kumar
// 
// Class: C Programming, Fall 2021 
// 
// Date: 9/30/21 
// 
// Description: Program which uses arrays to determine gross 
// pay and outputs be sent to the console.  
// 
// 
//******************************************************** 

#include <stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5
#define SIZE 5    // number of employees to process
int main () {

   
   /* unique employee identifier */
   long int clockNumber [SIZE] = {98401, 526488, 765349, 34645, 127615};

   /* hourly wage for each employee */        
   float hourlyWage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35};
  
  /* working hourse for each employee */
  float workhourse [SIZE] = {51.0, 42.5, 37.0, 45.0, 0.0}; 

   float gross;           // total gross pay for the week
   float Over_time;       // calculate the over time
   float overtime_pay;    // over time pay
   float standard_pay;    // standard pay

   /* initial loop counter */    
   int counter = 0;

   printf("\n");
   printf("----------------------------------------------------------------------\n");
   printf("    Clock#  Wage     Hours    OT       Gross\n");
   printf("----------------------------------------------------------------------\n");
   while (counter < SIZE ) {       
          if (workhourse[counter] > STD_HOURS) {
   // calculate over time                
              Over_time = workhourse[counter] - STD_HOURS;
   // calculate standard pay
              standard_pay = hourlyWage[counter] * STD_HOURS ;  
   // calculate over time pay            
              overtime_pay = hourlyWage[counter] * SOT_PAY * Over_time;
   // calculate gross pay                  
              gross = overtime_pay + standard_pay ;  
                            
              printf("    %6d  %5.2f   %5.1f    %5.1f    %6.2f", clockNumber[counter], hourlyWage[counter], workhourse[counter], Over_time, gross);
              printf("\n");
                      
          }  else {
              
              Over_time = 0.0;
              
              standard_pay = workhourse[counter] * hourlyWage[counter];           
              overtime_pay = hourlyWage[counter] * SOT_PAY * Over_time;  
              
              gross = overtime_pay + standard_pay;
              printf("    %6d  %5.2f   %5.1f    %5.1f    %6.2f", clockNumber[counter], hourlyWage[counter], workhourse[counter], Over_time, gross);
              printf("\n");
              
          }       
       /* increment and go to next employee */ 
           ++counter ;
   }  // end while loop
       return (0);  // success
}   // end  main program  