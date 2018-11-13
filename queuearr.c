#include <stdio.h>

int que[100], m=100, front=-1, rear=-1;

void enque() 
{
	int data;
	if (rear == m-1) 
	{
		printf("Failed: que full\n");
	} 
	else 
	{
		printf("Enter data to be entered : ");
		scanf("%d", &data);
		if (front == -1)
		{
			front = rear = 0;
		} 
		else
		{
			rear++;
		}
		que[rear] = data;
	}
}
void deque() {
	if (front == -1) {
		printf("Failed: Empty queue\n");
	} else {
		printf("Deleted element : %d\n", que[front]);
		if (front == rear) {
			front = rear = -1;
		} else {
			front++;
		}
	}
}
void printque() {
	int i=0;
	if (front == -1) {
		printf("Empty queue\n");
	} else {
		for (i=front; i<=rear; i++) {
			printf("%d\n", que[i]);
		}
	}
}
int main() {
	char choice;
	front = rear = -1;
	do {
		printf("\n\tque using array\n1.Enque\n2.Deque\n3.Display\n4.Exit\nEnter your choice : ");
		scanf(" %c", &choice);
		switch(choice) {
			case '1':
				enque();
				break;
			case '2':
				deque();
				break;
			case '3':
				printque();
				break;
		}
	} while(choice != '4');
}
