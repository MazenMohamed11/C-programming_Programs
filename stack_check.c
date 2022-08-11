#include<stdio.h>

#define STACK_SIZE 15
#define EXPRESSION_SIZE 15
#define STACK_IS_FULL 1
#define INITIAL_TOP -1
#define STACK_IS_EMPTY 0
#define STACK_SUFFICIENT 2
#define BALANCED 100
#define NOT_BALANCED 200

#pragma warning(disable : 4996)

typedef struct stack { int elements[STACK_SIZE]; int top; }ST_stack;
ST_stack store_string;

/*function to set stack embty
*INPUT: pointer to struct of stack 
*RETURN: void
*/
void createEmptyStack(ST_stack* stack)
{
	stack->top = INITIAL_TOP;
}

/*function to push data into stack
*INPUT: pointer to struct of stack , the data
*RETURN: state error
*/
int push(ST_stack *stack, int data)
{
	int status;
	if (stack->top < (STACK_SIZE - 1))
	{
		stack->top++;
		stack->elements[stack->top] = data;
		status = STACK_SUFFICIENT;
	}
	else
	{
		status = STACK_IS_FULL;
	}
	return status;
}

/*function to set pop data from stack
*INPUT: pointer to struct of stack , pointer to integer of data
*RETURN: state error
*/
int pop(ST_stack *stack, int *data)
{
	int status;
	if (stack->top != INITIAL_TOP)
	{
		*data = stack->elements[stack->top];
		stack->top--;
		status = STACK_SUFFICIENT;
	}
	else
	{
		status = STACK_IS_EMPTY;
	}
	return status;
}

/*function to chaeck expression valid or not
*INPUT: void
*RETURN: state of expression
*/
int expression_Check(void)

{
	int first_Char, last_Char;
	int status,flag;
	status = pop(&store_string, &last_Char);
	store_string.top = 0;                       // to pop the first character
	status = pop(&store_string, &first_Char);
	if ((first_Char+1) == last_Char || (first_Char + 2) == last_Char)   // equation from ascii table
	{
		flag = BALANCED;
	}
	else
	{
		flag = NOT_BALANCED;
	}
	return flag;
}
int main()
{
    char arr_String1[EXPRESSION_SIZE];
	int i, status1, j = -1;
	int status2;
	while (1)
	{
		createEmptyStack(&store_string);
		printf("Start Write\n");
		gets(arr_String1);
		for (i = 0; i < EXPRESSION_SIZE; i++)
		{
			if (arr_String1[i] != NULL)
			{
				status1 = push(&store_string, arr_String1[i]);
				if (status1 == STACK_IS_FULL)
				{
					printf("stack does not have vacancies");
				}
				else
				{
				}
			}
			else
			{
				break;
			}
		}
		status2 = expression_Check();
		if (status2 == BALANCED)
		{
			printf("The Expression is Balanced\n");
		}
		else
		{
			printf("Erorr,The Expression is not Balanced\n");
		}
	}
}
