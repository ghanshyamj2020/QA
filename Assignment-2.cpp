//******************************************************* 
// 
// Homework: 2 (Chapter 6) 
// 
// Name: Bandana Kumar
// 
// Class: C Programming, Fall 2021 
// 
// Date: 9/23/21 
// 
// Description: Program which determine gross 
// pay and over time outputs be sent to the console.  
// 
// 
//******************************************************** 

#include <stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5

int main () {

   
   int num;               // number of employees to process
   int counter;           // loop counter
   int clock;             // clock number for employee
   float wage;            // hourly wage
   float hours;           // hours worked in a week
   float gross;           // total gross pay for the week
   float OT;              // calculate the over time
   float overtime_pay;    // over time pay
   float standard_pay;    // standard pay

   /* initial loop counter */    
   counter = 1;

   printf("\n");
   printf("***Pay Calculator***\n");
   printf("\n");
   printf("Enter number of employees to process:  ");
   scanf("%d", &num);
   while (counter <= num ) {
          printf("\n");
          printf("Enter Employee's Clock #: ");
          scanf("%d", &clock);
          printf("Enter hourly wage: ");
          scanf("%f", &wage);
          printf("Enter number of hours worked: ");
          scanf("%f", &hours);
          printf("\n");
          printf("-----------------------------------------\n");
          printf("Clock# Wage  Hours OT  Gross\n");
          printf("-----------------------------------------\n");
          
          if (hours > STD_HOURS) {
          // calculate over time                
              OT = hours - STD_HOURS;
          // calculate standard pay
              standard_pay = wage * STD_HOURS ;  
          // calculate over time pay            
              overtime_pay = wage * SOT_PAY * OT;
          // calculate gross pay                  
              gross = overtime_pay + standard_pay ;  
                            
              printf("%06d %.2f %.1f %.1f %.2f", clock, wage, hours, OT, gross);
              printf("\n");
              printf("\n");
          
          }  else {
              
              OT = 0.0;
              
              standard_pay = hours * wage;           
              overtime_pay = wage * SOT_PAY * OT;  
              
              gross = overtime_pay + standard_pay;
              printf("%06d %.2f %.1f %.1f %.2f", clock, wage, hours, OT, gross);
              printf("\n");
              printf("\n");
          }       
       /* increment and go to next employee */ 
          counter = counter + 1;
   }  // end while loop
       return (0);  // success
}   // end  main program  
