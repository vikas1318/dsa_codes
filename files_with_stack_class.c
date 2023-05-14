#include<stdio.h>
#include <stdio.h>
struct stack
{
    int a[50];
    int top;
};
void init(struct stack *s)
{
    s->top=-1;
}
int isempty(struct stack *s)
{
    if(s->a[s->top]==-1)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct stack *s,int v)
{
        s->top++;
        s->a[s->top]=v;

}
int pop(struct stack *s)
{
   int p=s->a[s->top];
    s->top--;
    return p;
}
main()
{
    struct stack s;int b[5];int x,n;
    time_t t;
    srand((unsigned)time(&t));
    init(&s);
    FILE*fp1,*fp2,*fp3,*fp4;
    int a[5];
    fp1=fopen("v1.txt","w");
    fp2=fopen("v2.txt","w");
    fp3=fopen("v3.txt","w");
    fp4=fopen("v4.txt","w");
   int i,j,temp;
   printf("enter number of random numbers\n");
   scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       a[i]=rand();
       fprintf(fp1,"%d  ",a[i]);
       printf("\n1 for push,2 for pop\n");
       scanf("%d",&x);
       if(x==1)
       {
           push(&s,a[i]);
           fprintf(fp3,"%d  ",a[i]);
           fprintf(fp4,"push()\n");
       }
       else  if(x==2)
       {
           b[i]=pop(&s);
           fprintf(fp2,"%d  ",b[i]);
           fprintf(fp4,"pop()\n");

       }

    }
    fclose(fp1);
    fclose(fp2);
}

