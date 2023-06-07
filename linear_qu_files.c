#include<stdio.h>
int f,r,max,m;
int size;
f=-1;
r=-1;
FILE*fp1,*fp2,*fp3,*fp4,*fp5;
main()
{
   printf("enter the size of array\n");
   scanf("%d",&max);
   int a[max];
   printf("enter the size of queue\n");
   scanf("%d",&size);
   int queue[size];
   fp1=fopen("f1.txt","a");
   int i,j,y;
    for(i=0;i<max;i++)
    {
       a[i]=rand();
       fprintf(fp1,"%d  ",a[i]);
    }
    fclose(fp1);
   f=-1;
   r=-1;
   m=0;
   int ch;
   while(1)
   {
      printf("1.enqueue\n");
      printf("2.dequeue\n");
      printf("3.display\n");
      printf("4.exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
      switch(ch)
   {
       case 1: fp5=fopen("f5.txt","a");
                   fprintf(fp5,"enqueue\n");
                   m=y;
                   int p=a[m];
                   y=y+1;
                   enqueue(p,queue);
                   fclose(fp5);
                   break;
       case 2: fp5=fopen("f5.txt","a");
                   fprintf(fp5,"dequeue\n");
                   dequeue(queue);
                   fclose(fp5);
                   break;
       case 3: display(queue);
                break;
       case 4:exit(0);
                break;
       default:printf("invalid choice\n");
                break;
   }
   }
}
void enqueue(int p,int queue[])
{
    fp2=fopen("f2.txt","a");
    fp3=fopen("f3.txt","a");
    if(r==size-1)
    {
        printf("queue is full\n");
    }
    else
    {
        int x;

        if(f==-1&&r==-1)
        {
            r++;
            f++;
            queue[r]=p;
             fprintf(fp2,"%d  ", queue[r]);
             fprintf(fp3,"%d  ",queue[r]);
        }
        else
        {
            r++;
            queue[r]=p;
             fprintf(fp2,"%d  ", queue[r]);
             fprintf(fp3,"%d  ",queue[r]);
        }
    }
    fclose(fp2);
    fclose(fp3);
}
void dequeue(int queue[])
{
    fp4=fopen("f4.txt","a");
    if(f==-1&&r==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        if(f==r)
        {
            fprintf(fp4,"%d  ",queue[f]);
            f=-1;
            r=-1;
        }
        else
        {
            fprintf(fp4,"%d  ",queue[f]);
             f++;
        }

    }
    fclose(fp4);
}
void display(int queue[])
{
    if(f==-1&&r==-1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;
        for(i=r;i>=f;i--)
        {
            fscanf(fp3,"%d",&queue[i]);
            printf("%d ",queue[i]);
        }

    }
    printf("\n");

}

