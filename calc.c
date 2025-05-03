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
    neg, 
    add, 
    sub,
    holderrrrrrrrrrrrrrr,  
    mult, 
    dvd, 
    exp, 
    percent,
    log
}; 

static inline int
isNumber(char *string); 
int get_equation(int* x, int* y, enum operation* op);
int do_equation(int* x, int* y, enum operation* op); 
bool calc_open = true; 
//functions
int negate (int x); 
int divide (int x, int y); 

//~~~ end decs

int main(int argc, char **argv)
{


    printf("Welcome to the calculator! Please input your equation:\n");
    printf("The format should be 'x y operation_number'\n"); 
     
    int user_x; 
    int user_y; 
    enum operation user_op = nothing;   
     while (calc_open){
        get_equation(&user_x, &user_y, &user_op);
        int user_answer = 0; 
        user_answer = do_equation(&user_x, &user_y, &user_op);  
        

        //print answer
        printf("~~~ ");
        printf("%d\n", user_answer); 
        
        
        //allow for new input
        //printf("do another? [y/n]\n"); 
        //char* quit; 
        //scanf("%c", &quit); 
        //if (*quit == 'n') calc_open = false; 
         
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

int get_equation(int* x, int* y, enum operation* op){
    char* this; 
    scanf("%d %d %d", x, y, op);
    //if (*this == 'q') calc_open = false; 
    return 1; 

}// get_equation

int do_equation(int* x, int* y, enum operation* op){
    int db_x = *x; 
    int db_y = *y; 
    if (*op == neg){
        //done
        negate(db_x);  
    } else if (*op == add){
        return db_x + db_y;  
    } else if (*op == sub){
       int temp = negate(db_y); 
        return db_x + temp; 
    } else if (*op == mult){
        //placeholder 
        return db_x * db_y; 
    } else if (*op == dvd){
        return divide (db_x, db_y); 
    } else if (*op == percent){
        return divide (db_x, 100); 
    } else {
        return db_x; 
    } 
}

int negate (int x){
    int temp = x; 
    temp = ~(temp | temp);
    temp += 1;  
    return temp;
}

int divide (int x, int y){
    //placeholder
    return x / y; 
}

//1 1 0 0
//0 0 1 1 

//0 0 1 1 //divide by 4 add one (3)

//0 0 1 1

int multiply (int x, int y){
    // bit left by the closest 2^x and add remainder
    
    //ex 12 * 3
    // 12 << 2, add 12
}

//returns the most significant bit of a number
int find_most_sig_bit (int x){
    int checker = 0; 
    for (int i  = 0; i < NUMSIGFIGS; )

    if (x & checker == 1){
        return NUMSIGFIGS - i; 
    }
}