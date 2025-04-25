#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declaration of helper functions
#define NUMSIGFIGS 10
enum operation {
    nothing, 
    add, 
    sub, 
    mult, 
    dvd
}; 

static inline int
isNumber(char *string); 
int get_equation(double* x, double* y, enum operation* op);
double do_equation(double* x, double* y, enum operation* op); 
//~~~ end decs

int main(int argc, char **argv)
{


    printf("Welcome to the calculator! Please input your equation:\n"); 
    double user_x; 
    double user_y; 
    enum operation user_op = nothing;  
    bool calc_open = get_equation(&user_x, &user_y, &user_op); 
     while (calc_open){
        double user_answer = 0; 
        user_answer = do_equation(&user_x, &user_y, &user_op);  
        

        //print answer
        printf("~~~ ");
        printf("%f\n", user_answer); 
        
        //allow for new input
        calc_open = get_equation(&user_x, &user_y, &user_op); 
    }

    //end
    printf("Thanks for using the calculator! Bye-bye!\n"); 

return 0; 
}//main 


//checks if the given value is a number or char
//source: UofM EECS 370
static inline int
isNumber(char *string)
{
    int num;
    char c;
    return((sscanf(string, "%d%c",&num, &c)) == 1);
} //isNumber

int get_equation(double* x, double* y, enum operation* op){
    char current_char = getchar(); 
     
    while (current_char != '='){
        //quit if needed
        if (current_char == 'q') return 0;
        //handle the characters 
         
        *x = current_char - 48;
         
        //get next
        current_char = getchar(); 
    }

    return 1; 

}// get_equation

double do_equation(double* x, double* y, enum operation* op){
    double db_x = *x; 
    double db_y = *y; 
    if (*op == add){
        return db_x + db_y;  
    } else {
        return db_x; 
    } 
}