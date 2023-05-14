#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int v[6],source=5,size=6,dist[6],path[6];
int a[6][6]={{0,15,10,INT_MAX/2,45,INT_MAX/2},
             {INT_MAX/2,0,15,INT_MAX/2,20,INT_MAX/2},
             {20,INT_MAX/2,0,20,INT_MAX/2,INT_MAX/2},
             {INT_MAX/2,10,INT_MAX/2,0,35,INT_MAX/2},
             {INT_MAX/2,INT_MAX/2,INT_MAX/2,30,0,INT_MAX/2},
             {INT_MAX/2,INT_MAX/2,INT_MAX/2,4,INT_MAX/2,0}};
int next_source(int dist[],int v[])
{
    int min,j,i;
    min=INT_MAX/2;
    for(i=0;i<size;i++){
        if(v[i]!=-1)
        {
           if(dist[i]<min)
           {
               min=dist[i];
               j=i;
           }
        }
    }
    return j;
}
int check(int m[])
{
    int flag=1,i;
    for(i=0;i<size;i++){
        if(m[i]!=-1)
        {
          flag=0;
          break;
        }
    }
    if(flag==1)
        return 0;
    else
        return 1;

}
void dijkstras(int path[],int dist[])
{
    int u,i;
   v[source]=-1;
   while(check(v))
   {
       u=next_source(dist,v);
       v[u]=-1;
       for(i=0;i<size;i++){
         if(v[i]!=-1)
         {
             if(dist[i]>(dist[u]+a[u][i]))
             {
                 dist[i]=dist[u]+a[u][i];
                 path[i]=u;
             }
         }
      }
    }
}
void shortest_path(int source,int dest)
{
    int b[size-1],k=1,i;
    b[0]=dest;
    i=dest;
    while(path[i]!=source)
    {
        b[k]=path[i];
        i=path[i];
        k++;

    }
    b[k]=source;
    k++;
    printf("from %d to %d\n",source,dest);
    for(i=k-1;i>=0;i--){
        printf("%d->",b[i]);
    }
}
int main()
{
   int i;
   for(i=0;i<size;i++){
       path[i]=source;
       dist[i]=a[source][i];
       v[i]=i;
   }
    dijkstras(path,dist);
    printf("dist\tpath\n");
    for(i=0;i<size;i++){
      printf("%d\t%d\n",dist[i],path[i]);
   }
   for(i=0;i<size;i++)
   {
       if(i!=source)
       {
        shortest_path(source,i);
        printf("\ncost=%d\n\n",dist[i]);
       }
   }

}
