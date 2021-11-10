//******************************************************* 
// 
// Homework: 7 (Chapter 10) 
// 
// Name: Bandana Kumar
// 
// Class: C Programming, Fall 2021 
// 
// Date: 07/11/21 
// 
// Description: Program which uses Pointer struct, arrays and function to determine gross 
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
        char  name [20];
        int id_number;  
        float wage;
        float hours;
        float overtime;
        float gross;
    };    

//  function declaration 

void payrollcalc(struct employee *st);
struct employee *otpay(struct employee *st2);

// main program 
int main()
{

// struct employee st1;

struct employee  st1;

 // REPORT LAYOUT Header detail  
  
printf("----------------------------------------------------------------------\n");
printf("Name            Clock#  Wage    Hours    OT   Gross\n");
printf("----------------------------------------------------------------------\n");

// call the function
payrollcalc(&st1);    

 return 0;
} // end of main program

// function payrollcalc started 
void payrollcalc(struct employee *st)
{ 
struct employee  st2[5] ={"Connie Cobol ", 98401, 10.60, 51.0,0.0,0.0,
                          "Mary Apl     ",526488,9.75,42.5,0.0,0.0,
                          "Frank Fortran",765349,10.50, 37.0,0.0,0.0,
                          "Jeff Ada     ", 34645, 12.25,45.0,0.0,0.0,
                          "Anton Pascal ",127615 ,10.00,40.0,0.0,0.0};
struct employee *strex;

float total_ot;
float total_gross;
float total_wage;
float total_hours;

/* check over time */
for(int j=0; j < 5; j++) { 
     
   *strex = *otpay(&st2[j]);
   
    total_wage  = total_wage + strex->wage;
    total_hours = total_hours + strex->hours;
    total_ot    = total_ot + strex->overtime;
    total_gross = total_gross + strex->gross;
   strex++;   
}
  
printf("----------------------------------------------------------------------\n");
printf("\n");
printf("Total:                  %.2f %8.1f %5.1f %8.2f  \n",total_wage, total_hours, total_ot, total_gross);
printf("Average:                %.2f %8.1f %5.1f %8.2f \n", total_wage/SIZE, total_hours/ SIZE, total_ot/SIZE,
                                                                                              total_gross/SIZE);
} // function payrollcalc ended

// Gross pay calculation with over time function otpay started 
struct employee *otpay(struct employee  *st2) {
  
/*initialization of local variable   */    

struct employee  strex;
float overtime_pay = 0.0;
float standard_pay = 0.0;

if (st2->hours > STD_HOURS) {
    st2->overtime = st2->hours - STD_HOURS;
    overtime_pay = st2->wage * SOT_PAY * st2->overtime;
    standard_pay = st2->wage * STD_HOURS;
    st2->gross = overtime_pay + standard_pay;
    
    strex.wage     = st2->wage;
    strex.hours    = st2->hours;
    strex.overtime = st2->overtime;
    strex.gross    = st2->gross;
    
    
    printf("%s   %06d  %5.2f   %5.1f  %5.1f  %5.2f\n",st2->name, st2->id_number , st2->wage, st2->hours,

                                                                                 st2->overtime, st2->gross);

    
} else {

// over time calculation with zero over time  

    standard_pay = st2->hours * st2->wage;
    overtime_pay = (st2->wage * SOT_PAY * 0);
    st2->gross = overtime_pay + standard_pay;

    strex.wage     = st2->wage;
    strex.hours    = st2->hours;
    strex.overtime = st2->overtime;
    strex.gross    = st2->gross;
    
   printf("%s   %06d  %5.2f   %5.1f  %5.1f  %5.2f \n",st2->name, st2->id_number , st2->wage, st2->hours, 
                                  st2->overtime, st2->gross);
    
}
return(st2++);

} 