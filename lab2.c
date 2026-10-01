#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#define SIZE 20
struct STACK{
int top;
float data[SIZE];
};
typedef struct STACK STACK;
void push(STACK*s,float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK*s)
{
    return s->data[(s->top)--];
}
float compute(float oper1,char symbol,float oper2)
{
    switch(symbol)
    {
        case'+':return oper1+oper2;
        case'-':return oper1-oper2;
        case'*':return oper1*oper2;
        case'/':return oper1/oper2;
        case'^':return pow(oper1,oper2);
    }
}
float eval_postfix(STACK*s,char postfix[15])
{
    char symbol;
    int i;
    float oper1,oper2,res;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(s,symbol-'0');
        else
        {
            oper2=pop(s);
            oper1=pop(s);
            res = compute(oper1,symbol,oper2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[50];
    float Res;
    STACK s;
    s.top=-1;
    printf("\n read postfix expression:\n");
    scanf("%s",postfix);
    Res=eval_postfix(&s,postfix);
    printf("\n the final answer is%f",Res);
    return 0;
}
