#include <stdio.h>
#include <stdlib.h>

int gcd (int a,int b)
{
    if(b==0)
       return 0;
    return gcd(b,a%b);

}
int main(){
    int a,b,ans;
    printf("\n read 2 number \n");
    scanf("%d%d",&a,&b);
    ans =gcd(a,b);
    printf("\n GCD od %d and %d is %d \n ",a,b,ans);
    return 0;
}
