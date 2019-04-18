#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;
void insert(ListNodePtr *sPtr, char value);
void printList(ListNodePtr ptr);
ListNodePtr merge(ListNodePtr *ptr1, ListNodePtr *ptr2);

void main() {
	ListNodePtr startPtr1 = NULL;
	ListNodePtr startPtr2 = NULL;
	ListNodePtr first = NULL;
	int item;
	printf("List 1 is: ");
	for (int i = 0; i < 5; i++) {
		item = 2 * (i + 1);
		printf("%d ", item);
		insert(&startPtr1, item);
	}
	printf("*\n");

	printf("\nList 2 is: ");
	for (int i = 0; i < 5; i++) {
		item = 2 * (i + 1) - 1;
		printf("%d ", item);
		insert(&startPtr2, item);
	}
	printf("*\n");

	printf("\nThe merged list is: ");
	first = merge(&startPtr1, &startPtr2);
	printList(first);
	printf("\n\n");
	return;
}

void printList(ListNodePtr headPtr) {
	ListNodePtr nodePtr;
	if (headPtr) 
		for (nodePtr = headPtr; nodePtr != NULL; nodePtr = nodePtr->nextPtr) 
			printf("%d ", nodePtr->data);
	printf("*");
}

void insert(ListNodePtr *sPtr, char value) {
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	newPtr = malloc(sizeof(ListNode));
	if (newPtr) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;

		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}

}

ListNodePtr merge(ListNodePtr *ptr1, ListNodePtr *ptr2) {
	ListNodePtr ptr3 = NULL;
	ListNodePtr newPtr = NULL;

	ListNodePtr nodePtr1 = *ptr1;
	ListNodePtr nodePtr2 = *ptr2;
	ListNodePtr nodePtr3 = ptr3;

	while ((nodePtr1 != NULL) || (nodePtr2 != NULL)) {
		if (!nodePtr1) {
			insert(&ptr3, nodePtr2->data);
			nodePtr2 = nodePtr2->nextPtr;
		}
		else if (!nodePtr2) {
			insert(&ptr3, nodePtr1->data);
			nodePtr1 = nodePtr1->nextPtr;
		}
		else {
			if ((nodePtr1->data) > (nodePtr2->data)) {
				insert(&ptr3, nodePtr2->data);
				nodePtr2 = nodePtr2->nextPtr;
			}
			else {
				insert(&ptr3, nodePtr1->data);
				nodePtr1 = nodePtr1->nextPtr;
			}
		}
	}
	return ptr3;
}