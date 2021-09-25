#include <stdio.h>
#define STD_HOURS 40.0
#define SOT_PAY  1.5


void main () {

   /* Variables    */
   int num, counter = 1, Clock; 
   float wage , hours1, gross, OT, overtime_pay, standard_pay;
   printf("\n");
   printf("***Pay Calculator***\n");
   printf("\n");
   printf("Enter number of employees to process:  ");
   scanf("%d", &num);
   while (counter <= num ) {
          printf("\n");
          printf("Enter Employee's Clock #: ");
          scanf("%d", &Clock);
          printf("Enter hourly wage: ");
          scanf("%f", &wage);
          printf("Enter number of hours worked: ");
          scanf("%f", &hours1);
          printf("\n");
          printf("-----------------------------------------\n");
          printf("Clock# Wage  Hours OT  Gross\n");
          printf("-----------------------------------------\n");
          
          if (hours1 > STD_HOURS) {
             
              OT = hours1 - STD_HOURS;
              
              standard_pay = STD_HOURS * wage;  
                      
              overtime_pay = wage * SOT_PAY * OT;
                            
              gross = overtime_pay + standard_pay ;  
                            
              printf("%06d %.2f %.1f %.1f %.2f", Clock, wage, hours1, OT, gross);
              printf("\n");
              printf("\n");
          
          }  else {
              OT = 0.0;
              
              standard_pay = hours1 * wage;           
              overtime_pay = wage * SOT_PAY * OT;  
              
              gross = overtime_pay + standard_pay;
              printf("%06d %.2f %.1f %.1f %.2f", Clock, wage, hours1, OT, gross);
              printf("\n");
              printf("\n");
          }       
           
          counter = counter + 1;
   }

}   