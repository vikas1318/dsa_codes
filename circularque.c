#include<stdio.h>
#define N 5
struct que
{
    int E[N];
    int rear;
    int front;
};
void init(struct que*q)
{
    q->front=-1;
    q->rear=-1;
}
int isempty(struct que*q)
{
    if(q->rear==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isfull(struct que*q)
{
    if((q->rear+1)%N==q->front)
        return 1;
    else
        return 0;
}
void enq(struct que*q,int e)
{
    q->rear=(q->rear+1)%N;
    q->E[q->rear]=e;
    if(q->front==-1)
        q->front=0;
}
int deq(struct que*q)
{
    int f;
    f=q->E[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else
       q->front=(q->front+1)%N;
       return f;
}
int main()

{
    struct que q;
    init(&q);
    int v,e;
    if(isfull(&q))
    {
        printf("overflow\n");
    }
    else
    {
        printf("enetr the data\n");
        scanf("%d",&v);
        enq(&q,v);
    }
    if(isempty(&q))
    {
        printf("underflow\n");
    }
    else
    {
       e=deq(&q);
       printf("%d",e);
    }
}





