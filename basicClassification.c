#include <stdio.h>

//check the factorial of the number 
int calc(int x){
    int sum =1;
    while(x!=0){
        sum=sum*x;
        x--;

    }
return sum;
}

int isPrime(int x){
    if(x==1)
    return 1;
    int i;
    for(i=2; i< x ; i++)
  {
      if(x %i ==0)
      return 0;
  }
  return 1;
  }
  
int isStrong(int x) {
    int t=x;
    int sum=0;
    while(x>0){
        sum =sum+ calc(x%10);
        x=x/10;
    }
    if(sum==t)
        return 1;
   return 0;
}


 

