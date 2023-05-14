#include<stdio.h>
int fa(int j)
{
    int i;
    for(i=1;1<j;j--)
    {
        i=i*j;
    }
    return i;
}
int pascal(int n,int r)
{
    return fa(n)/(fa(n-r)*fa(r));
}
int main()
{
    int row;
    int i,j;
    printf("enetr the rows\n");
    scanf("%d",&row);
    for(i=0;i<=row;i++)
    {
        for(j=0;j<=row-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%3d",pascal(i,j));
        }
        printf("\n");
    }
    return 0;
}
