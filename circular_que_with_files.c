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
   printf("enter the size of qu\n");
   scanf("%d",&size);
   int qu[size];
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
      printf("1.enq\n");
      printf("2.dq\n");
      printf("3.display\n");
      printf("4.exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
      switch(ch)
   {
       case 1: fp5=fopen("f5.txt","a");
                   fprintf(fp5,"enq\n");
                   m=y;
                   int p=a[m];
                   y=y+1;
                   enq(p,qu);
                   fclose(fp5);
                   break;
       case 2: fp5=fopen("f5.txt","a");
                   fprintf(fp5,"dq\n");
                   dq(qu);
                   fclose(fp5);
                   break;
       case 3: display(qu);
                break;
       case 4:exit(0);
                break;
       default:printf("invalid choice\n");
                break;
   }
   }
}
void enq(int p,int qu[])
{
    fp2=fopen("f2.txt","a");
    fp3=fopen("f3.txt","a");
    if((r+1)%size==f)
    {
        printf("qu is full\n");
    }
    else
    {
        if(f==-1&&r==-1)
        {
            r=(r+1)%size;
            f=(f+1)%size;
            qu[r]=p;
            fprintf(fp2,"%d  ", qu[r]);
            fprintf(fp3,"%d  ",qu[r]);
        }
        else
        {
            r=(r+1)%size;
            qu[r]=p;
            fprintf(fp2,"%d  ", qu[r]);
            fprintf(fp3,"%d  ",qu[r]);
        }
    }
    fclose(fp2);
    fclose(fp3);
}
void dq(int qu[])
{
    fp4=fopen("f4.txt","a");
    if(f==-1&&r==-1)
    {
        printf("qu is empty\n");
    }
    else
    {
        if(f==r)
        {
            fprintf(fp4,"%d  ",qu[f]);
            f=-1;
            r=-1;
        }
        else
        {
            fprintf(fp4,"%d  ",qu[f]);
            f=(f+1)%size;
        }

    }
    fclose(fp4);
}
void display(int qu[])
{
    if(f==-1&&r==-1)
    {
        printf("qu is empty\n");
    }
    else
    {
        int i;
        for(i=f;i!=r;i=(i+1)%size)
        {
            fscanf(fp3,"%d",&qu[i]);
            printf("%d ",qu[i]);
        }
        printf("%d",qu[i]);

    }
    printf("\n");

}
