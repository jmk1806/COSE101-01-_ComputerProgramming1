#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct treeNode {
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void levelOrder(TreeNodePtr treePtr);

struct queueNode {
	TreeNodePtr data;
	struct queueNode *nextPtr;
};
typedef struct queueNode QueueNode;
typedef QueueNode* QueueNodePtr;

int isEmpty(QueueNodePtr headPtr);
void enqueue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr, TreeNodePtr);
TreeNodePtr dequeue(QueueNodePtr* headPtr, QueueNodePtr* tailPtr);

int main() {
	int i, item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));
	printf("The numbers being placed in the tree are:\n");

	for (i = 1; i <= 10; i++) {
		item = 1 + rand() % 20;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}
	printf("\n\nThe level-order traversal is: \n");
	levelOrder(rootPtr);
	printf("\n");

	return 0;
}
void insertNode(TreeNodePtr *treePtr, int value) {

	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		if (*treePtr) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else {
			printf("%d not inserted. No memory available.\n", value);
		}
	}
	else {
		if (value < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else if (value >(*treePtr)->data) {
			insertNode(&((*treePtr)->rightPtr), value);
		}
		else {
			printf("dup");
		}
	}
}
int isEmpty(QueueNodePtr headPtr) {
	return headPtr == NULL;
}
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNodePtr node) {
	QueueNodePtr newPtr;

	newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL) {
		newPtr->data = node;
		newPtr->nextPtr = NULL;

		if (isEmpty(*headPtr)) {
			*headPtr = newPtr;
		}
		else {
			(*tailPtr)->nextPtr = newPtr;
		}
		*tailPtr = newPtr;
	}
	else {
		printf("Node not inserted \n");
	}
}
TreeNodePtr dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	TreeNodePtr node;
	QueueNodePtr tempPtr;

	node = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
		*tailPtr = NULL;

	free(tempPtr);

	return node;
}
void levelOrder(TreeNodePtr treePtr) {
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	TreeNodePtr node;
	
	enqueue(&headPtr, &tailPtr, treePtr);

	while (!isEmpty(headPtr)) {
		node = dequeue(&headPtr, &tailPtr);
		printf("%3d", node->data);
		if (node->leftPtr != NULL) enqueue(&headPtr, &tailPtr, node->leftPtr);
		if (node->rightPtr != NULL) enqueue(&headPtr, &tailPtr, node->rightPtr);
	}
}