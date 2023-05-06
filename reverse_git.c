#include<stdio.h>
void display(int a[], int n);
void reverse(int a[],int n,int, int );
FILE*fp;
main()
{
    int a[20];
    int n,i;
    fp=fopen("s.txt","r");
    fscanf(fp,"%d",&n);
    printf("%d",n);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&(a[i]));
    }
    reverse(a,n,0,n-1);
    display(a,n);
    fclose(fp);

}
void display(int a[],int n)
{
    int i;
    fp=fopen("s.txt","w");
    for(i=0;i<n;i++)
    {

        fprintf(fp,"%d ",a[i]);
        printf("%d\t",a[i]);
    }
    fclose(fp);
}
void reverse(int a[],int n,int l,int u)
{
    int i=l;
    int j=u;
    int temp;
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }


}
