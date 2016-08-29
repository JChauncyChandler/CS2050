#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

static char prec(char operator)
{
	switch(operator)
	{
		case '*':
			return 5;
			break;
		case '/':
			return 4;
			break;
		case '%':
			return 3;
			break;
		case '+':
			return 2;
			break;
		case '-':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

static int isNumeric(char *num) 
{
	if(isdigit(*num))
		return 1;
	else
		return 0;
}

char* to_postfix(char* infix)
{
        char* postfix = malloc(sizeof(infix));
        stack* s = create_stack();
        int i=0, j=0;
	for(i=0; infix[i]!='\0'; i++)
    	{
	        if(isdigit(infix[i]))
                {
	                postfix[j]=infix[i];
                        j++;                }
                else if(infix[i]=='(')
	        {
	               push(s,(char)infix[i]);
	        }
	        else if(infix[i]==')')
                {                                                               			postfix[j]=' ';
                       j++;
                       while(!isEmpty(s) && top(s)!='(')
                       {
				postfix[j]=(char)top(s);
                                j++;
                                pop(s);
                       }
                       pop(s);
                }
                else
		{
			postfix[j++]=' ';
                        if(isEmpty(s))
                        {
	                        push(s,(char)infix[i]);
                        }
                        else
			{	
				while(!isEmpty(s) && prec((char)top(s)) && prec(infix[i]))
                                {
	                                postfix[j++]=' ';
                                        postfix[j++]=(char)top(s);
                                        pop(s);
                                }
                                push(s,(char)infix[i]);
                        }
                }
	}
	while(!isEmpty(s))
        {
		postfix[j++]= (char)top(s);
                pop(s);
        }
        postfix[j]='\0';
        free(s);
        return postfix;
}

int eval(char* postfix) 
{
    stack *s = create_stack();
    int result;

    char* token = strtok(postfix, " \n");
    while(token != NULL) {
        if (isNumeric(token)) {
            push(s, atoi(token));
        } else {
            int x = top(s);
            pop(s);
            int y = top(s);
            pop(s);

            switch(token[0]) {
                case '*':
                    result = y * x;
                    break;
                case '/':
                    result = y / x;
                    break;
                case '%':
                    result = y % x;
                    break;
                case '+':
                    result = y + x;
                    break;
                case '-':
                    result = y - x;
                    break;
            }

            push(s, result);
        }

        token = strtok(NULL, " \n");
    }

    result = top(s);
    pop(s);
    free(s);

    return result;
}
