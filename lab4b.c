#include <stdio.h>
#include <stdlib.h>
void TOH(int n,char source,char dest,char temp)
{
    if(n>1)
    {
        TOH(n-1,source,temp,dest);
        printf("\n move %d disc from %c to%c",n,source,dest );
        TOH(n-1,temp,dest,source);
    }
    else
        printf("\n move %d disc from %c to %c ",n,source,dest);

}
int main()
{
    int n;
    printf("\n read no discs:");
    scanf("%d",&n);
    TOH(n, 's','d','t');
    return 0;

}
