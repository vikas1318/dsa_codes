#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE *fp1,*fp2;
    char a[100],b[100],c[100];
    fp1=fopen("vikas.txt","r");
    fp2=fopen("v2.txt","w");

    printf("Enter the word to be replaced:\n");
    scanf("%s",a);

    printf("word replacing it");
    scanf("%s",b);


    while(!feof(fp1))
    {
        fscanf(fp1,"%s",c);
        if(strcmp(c,a)==0)
        {
            fprintf(fp2,"%s ",b);
        }
        else
        {
            fprintf(fp2,"%s ",c);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
