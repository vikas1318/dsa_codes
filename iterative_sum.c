#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
int createsll(struct node *head)
{
    struct node*newnode,*temp;
     newnode=(struct node*)malloc(sizeof(struct node));
     printf("enetr the data\n");
     scanf("%d",&newnode->data);
    return newnode;
}

int insertend(struct node *head)
{
    struct node *newnode,*temp;
    newnode=createsll(head);
    if(head==NULL)
    {
        head=temp=newnode;
        temp->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
      printf("%d",temp->data);
}

 void sum(struct node *head)
 {
     int sum=0;
     struct node *temp;
     temp=head ;

     while(temp->next!=NULL)
     {
         sum=sum+temp->data;
         temp=temp->next;
     }
     printf("%d",sum);
 }

int main()
{
    struct node *head;int i;
    head=NULL;
     for(i=0;i<5;i++)
     {
         head=insertend(head);
     }

     display(head);
     printf("\n");
     printf("sum is\n");
     sum(head);
}
