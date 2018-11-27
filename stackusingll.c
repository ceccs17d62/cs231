#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
}*top,*newnode,*ptr;
void push();
void pop();
void display();
void exit();
int choice,stack[20];

void main()
{
	top=NULL;
	while(1)
	{
		printf("Enter the choice:");
		printf("\n\t1.push\n\t2.pop\n\t3.display\n\t4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
			default:printf("Wrong choice\n");	
			break;
		}
	}
}
void push()
{
	int a;
	printf("Enter the element:");
	scanf("%d",&a);
	newnode=(struct node*)malloc(sizeof(struct node*));
	newnode->data=a;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;

	}
}
void pop()
{
	int b;
	if(top==NULL)
	{
		printf("no elements\n");
	}
	else
	{
		ptr=top;
		top=top->next;
		free(ptr);
	}
}
void display()
{
	ptr=top;
	if(top==NULL)
	{
		printf("no elements");
	}
	else
	{
		printf("Element\t\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
