 #include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
}*start,*ptr,*newnode,*preptr;
void addbg();
void addend();
void display();
void search();
void dlbg();
void dlend();
void dlaftnode();
int option;
void main()
{
start=NULL;
while(1)
{
printf("enter a opiton \n");
printf("1.addbg\n2.addend\n3.display\n4.search the list\n5.delete at begining\n6.delete at end\n7.delete after a node\n8.exit\n");
scanf("%d",&option);
switch(option)
{
case 1:addbg();
break;
case 2:addend();
break;
case 3:display();
break;
case 4:search();
break;
case 5:dlbg();
break;
case 6:dlend();
break;
case 7:dlaftnode();
break;
case 8:exit(0);
break;
default:printf("wrong choice\n");
}
}
}
void dlaftnode()
{
int value;
if(start==NULL)
{
printf("no elements\n");
}
else
{
ptr=start;
preptr=ptr;
printf("enter a node value\n");
scanf("%d",&value);
if(preptr->data==value)
{
ptr=ptr->next;
preptr->next=ptr->next;
free(ptr);
}
else
{
while(preptr->data!=value)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=ptr->next;
free(ptr);
}
}
}
void dlend()
{
if(start==NULL)
{
printf("no elements\n");
}
else
{
while(ptr->next!=NULL)
{
ptr=start;
preptr=ptr;
ptr=ptr->next;
}
preptr->next=NULL;
free(ptr);
}
}
void addbg()
{
int num;
printf("enter a element\n");
scanf("%d",&num);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
if(start==NULL)
{
newnode->data=num;
newnode->next=NULL;
start=newnode;
printf(" added at begin \n");
}
else
{
newnode->data=num;
newnode->next=start;
start=newnode;
printf(" added at begin \n");
}
}
void addend()
{
int num;
printf("enter a data\n");
scanf("%d",&num);
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
newnode->data=num;
newnode->next=NULL;
if(start==NULL)
{
start=newnode;
}
else
{
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=newnode;
}
}
void display()
{
ptr=start;
if(ptr==NULL)
{
printf("empty list\n");
}
else
{
printf("array elements are:\n");
while(ptr!=NULL)
{
printf("%d \n",ptr->data);
ptr=ptr->next;
}
}
}
void search()
{
int value,count=0;
if(start==NULL)
{
printf("list is empty\n");
}
else
{
ptr=start;
printf("enter a search data\n");
scanf("%d",&value);
while(ptr!=NULL)
{
if(ptr->data==value)
{
count++;
}
ptr=ptr->next;
}
if(count==0)
{
printf("no nodes found\n");
}
else
{
printf("value repeated %d times\n",count++);
}
}
}
void dlbg()
{
if(start==NULL)
{
printf("no elements\n");
}
else
{
ptr=start;
start=start->next;
free(ptr);
printf("deleted node at begining \n");
}
}
