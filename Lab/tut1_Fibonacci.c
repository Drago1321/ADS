//Fibonacci series without recursion and with recursion.

#include<stdio.h>

void fibonacciwithoutrec(int num){
    int a=0, b=1, c;

    printf("0,1");
    for(int i = 0; i < num-2; i++)
    {
       c=a+b;
       a=b;
       b=c;
       printf(",%d", c); 
    }
    
};

void fibonaccirecursive(int num){
    static int a=0; 
    static int b=1;
    static int c;

    
    if(num>2){
        c=a+b;
        printf(",%d", c);
        a=b;
        b=c;
        
        fibonaccirecursive(num-1);
    }
}
int main(){
    int num;
    printf("Enter the number of fibonacci series\n");
    scanf("%d", &num);

    fibonacciwithoutrec(num);
    printf("\n");
    
    printf("0,1");
    fibonaccirecursive(num);
    return 0;
}