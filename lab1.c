#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
struct stack{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;
void push (STACK *s, char item)
{
   s->data[++(s->top)]=item;
}
void pop(STACK *s){

return s->data[(s->top)--];
}
int preced( char symbol){
switch(symbol){
case '^': return 5;
case '*':
case '/': return 3;
case '+':
case '-':return 1;
}
}
void infixtopostfix(STACK*s, char infix[20])
{ int i=0,j=0;
char symbol,postfix[20],temp;
for (i=0;infix[i]!='\0';i++)
{
    if(isalnum(symbol))
        postfix[j++]=symbol;
    else
    {
        switch(symbol)
        {
        case '(': push(s,symbol);
        break;
        case ')':temp=pop(s);
        while(temp !='c'){
            postfix[j++]=temp;
            temp=pop(s);
        }
        break;
         case '+':
         case '-':
         case '*':
         case '/':
         case '^': if(s->top == -1::s->data[s->top]=='c')
                   push (s,symbol);
                   else{
                    while(preced (s->data[s->top])>=preced(symbol)&&s->top!=-1&&s->data[s->top]!='c')
                        postfix[j++]=pop(s);
                        push(s,symbol);

                   }
                   break;
        }
    }
}
while (s->top !=-1)
    postfix[j++]=pop(s);
postfix[j]='\0';
printf("\n postfix expression is %s",postfix);
}
int main()
{
 char infix[20];
 STACK s;
 s.top=-1;
 printf("read infix expression\n");
 scanf("%s",infix);
 infixtopostfix(&s, infix);

    return 0;
}
