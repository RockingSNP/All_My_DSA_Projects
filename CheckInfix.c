#include<stdio.h>
#include<string.h>
#define N 100

char str[N];
char stack[100];
int top = -1;


// Push Function.
void push(int *top, char stack[],char x)
{
       stack[++*top] = x;
    }

// Pop function
void pop(int *top)
{    
        --*top;
   }
   

int main(){
printf("Welcome to DSA DAY 3\n");
//printf("Chose What to enter:");
printf("Enter Your Expression:\t");
scanf("%s",str);
int length = strlen(str);
	for(int i=0; str[i] != '\0';i++){
		if(str[i]= '('||'{'||'['){
			push(&top, stack ,str[i]);
		}else if(str[i] =')'||'}'||']'){
			if(str[i]==str[0])
			pop(&top);
		}else{continue;}

	}

	if(top == (-1)){
	printf("The expression is accurate");
	return 0;
	}else{return -1;}


	for(int i=0; i<=2;i++){
	printf("%c\t",stack[i]);
	}

}
