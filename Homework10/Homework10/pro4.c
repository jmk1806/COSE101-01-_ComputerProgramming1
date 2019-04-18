#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr); 
int isEmpty(StackNodePtr topPtr);

void main() {
	StackNodePtr stackPtr = NULL;
	char text[100];
	int i = 0;
	printf("Enter a line of text: ");
	fgets(text, 100, stdin);
	text[strlen(text) - 1] = '\0';

	while (text[i]) {
		push(&stackPtr, text[i]);
		i++;
	}
	i = 0;
	printf("\nThe reversed line is: ");
	
	while (text[i]) {
		if (!isEmpty(stackPtr)) 
			printf("%c", pop(&stackPtr));
		
		else break;
	}
	printf("\n\n");
}

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void push(StackNodePtr* topPtr, int info) {
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));
	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
}

int pop(StackNodePtr* topPtr) {
	StackNodePtr tempPtr;
	int popValue;
	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}