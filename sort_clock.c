#include<stdio.h>
#include<time.h>
void sort(int a[],int);
FILE*fp1,*fp2;
main()
{
    int a[10000];
    fp1=fopen("f1.txt","w");
    fp2=fopen("f2.txt","w");
   int i,j,temp;
   double time;
   clock_t begin,end;
    for(i=0;i<5000;i++)
    {
       a[i]=rand();
       fprintf(fp1,"%d  ",a[i]);
    }
     fclose(fp1);
     begin=clock();
      sort(a,5000);
      end=clock();
      time=(double)(end-begin);
      printf("time delay=%lf\n",time);
      fprintf(fp2,"time delay=%lf\n",time);
    for(i=0;i<5000;i++)
    {
        printf("%d  ",a[i]);
      fprintf(fp2,"%d  ",a[i]);
    }

    fclose(fp2);
}
void sort(int a[10000],int n)
{

   int i,j,temp;

   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if(a[j]>a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
}
