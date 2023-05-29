#include <stdio.h>
struct stack
{
    int a[50];
    int top;
};
void init(struct stack *s)
{
    s->top=0;
}
int isempty(struct stack *s)
{
    if(s->a[s->top]==0)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct stack *s,int v)
{
        s->a[s->top]=v;
        s->top++;
}
int pop(struct stack *s)
{
   int p=s->a[s->top];
    s->top--;
    return p;
}
int main()
{
    struct stack s;
    init(&s);
    FILE *fp1;
    int s1[50],i,n;
    fp1=fopen("v1.txt","w");
    printf("enetr n\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
        push(&s,s1[i]);
          fprintf(fp1,"%d  ",s1[i]);
    }



}

