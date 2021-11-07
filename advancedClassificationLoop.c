#include "NumClass.h"
#include <math.h>

int numOfDigit(int x){
    int num=0;
    while(x!=0 ){
        num++;
        x=x/10;
   }
   return num;
}
//turn the number 
int reverse(int n){
     int  a = 0;
     int r;
    while (n != 0) 
    {
        r = n % 10;
        a = a * 10 + r;
        n =n/ 10;
    }
    return a;
}

int isPalindrome(int x){
int num=reverse(x);
    while(x>0){
    if(x%10 !=num%10){
         return 0;
    }
         x=x/10;
         num=num/10;
    }
  return 1;
}
int isArmstrong(int x) {
    int num1=x;
    int num=numOfDigit(x);
      int c=0;

      while(x>0){
         c=c + (pow(x%10, num));
         x=x/10;
         
      }
    if(c == num1)
        return 1;
   return 0;
}
   

