#include<stdio.h>
#define SIZE 5
struct que
{
    int E[SIZE];
    int r;
    int f;
};
void init(struct que*qu)
{
    qu->f=0;
    qu->r=-1;
}
int isempty(struct que*qu)
{
    if(qu->f>qu->r)
    {
        return 1;
    }
    else
        return 0;
}
int isfull(struct que*qu)
{
    if(qu->r==SIZE-1)
        return 1;
    else
        return 0;
}
void enq(struct que*qu)
{
    char ch;
     printf("enter the data\n");
     scanf("%c",&ch);
    qu->r++;
    qu->E[qu->r]=ch;
}
int deq(struct que*qu)
{
    int e;
    e=qu->E[qu->f];
    qu->f++;
    return e;
}

void display(struct que*qu)
{
    int i;char f;
    for(i=qu->f;i<=qu->r;i++)
    {
        if(qu->E[i]=='F')
        {
            f=deq(&qu);
            printf("%c",f);
        }
    }
    for(i=qu->f;i<=qu->r;i++)
    {
        printf("%c",qu->E[i]);
    }
}

int main()
{
    struct que qu;
    init(&qu);
    int n;
    int e;
    printf("enetr N");
    scanf("%d",&n);int i;
    for(i=0;i<=n;i++)
      {
    if(isfull(&qu))
       {
        printf("overflow\n");
       }
    else
      {

        enq(&qu);
      }
      }
    if(isempty(&qu))
      {
        printf("underflow\n");
      }
    else
      {
       display(&qu);

      }
}

