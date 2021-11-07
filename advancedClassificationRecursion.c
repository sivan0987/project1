#include <stdio.h>
#include <math.h>
#include "NumClass.h"

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
int numOfDigit(int x){
    int num=0;
    while(x!=0 ){
        num++;
        x=x/10;
   }
   return num;
}

int isArmstrong1(int num,int sum,int n)
{
if(num<10)
return sum+pow(num,n);
else
{
    sum=sum+(pow((num%10),n));
    num=num/10;
    return isArmstrong1(num,sum,n);
}
}

int isArmstrong(int num)
{
int n=dig(num);
int sumArm=isArmstrong1(num,0,n);
if(sumArm==num)
return 1;
return 0;
}

int isPalindrome1(int x, int num){
    
    if(x%10!=num%10)
            return 0;
    if(x==0 && num==0)
        return 1;
    return isPalindrome1(x/10 , num/10);
}
int isPalindrome(int x){
    int num=reverse(x);
    return isPalindrome1(x,num);

}
