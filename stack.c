#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push();
void pop();
int checkStackFull();
int checkStackEmpty();
void display();

struct StackArray{
	int top, array[SIZE];
}ptr;

int main(void)
{
	int choice, contin;

	ptr.top = -1;
	do
	{
		printf("Enter\n 1 -Push \n2 -Pop \n3 -Display\n 4 -EXit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: exit(0); break;
			default: printf("Enter a valid choice\n");
		}
		printf("Enter 1 to continue and 0 to stop the program\n");
		scanf("%d", &contin);	
	}while(contin == 1);
	return(0);
}

void push()
{
	int flag = checkStackFull(); 
	if (flag == 1)
	{
		int value;
		printf("Enter value to push into stack\n");
		scanf("%d", &value);
		ptr.top += 1;
		ptr.array[ptr.top] = value;	
	}
	else
	{
		printf("Stack is Full\n");
	}
}

void pop()
{
	int flag = checkStackEmpty();
	if (flag == 1)
	{
		printf("The popped value is %d\n", ptr.array[ptr.top]);
		ptr.top -= 1;
	}
	else
	{
		printf("Stack is Empty\n");
	}
}

void display()
{
	int i, flag = checkStackEmpty();

	if (flag == 1)
	{
		for (i = ptr.top; i > -1; i--)
	        {
       		         printf("%d\n", ptr.array[i]);
        	}
	        printf("\n");
	}
	else
	{
		printf("Stack is empty\n");
	}
}

int checkStackFull()
{
	if (ptr.top != SIZE)
		return (1);
	else
		return (0);
}

int checkStackEmpty()
{
	if (ptr.top == -1)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
