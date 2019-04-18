#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void* dataPtr;
	struct node* link;
} NODE;

NODE* createNode(void* itemPtr) {
	NODE* nodePtr;
	nodePtr = (NODE*)malloc(sizeof(NODE));
	nodePtr->dataPtr = itemPtr;
	nodePtr->link = NULL;
	return nodePtr;
}

int main() {

	int* newData;
	int* nodeData;
	NODE* node;

	int num = 0;
	printf("숫자 하나를 입력하세요 : ");
	scanf_s("%d", &num);

	newData = (int*)malloc(sizeof(int));
	*newData = num;

	node = createNode(newData);
	nodeData = (int*)node->dataPtr;
	printf("Data from node : %d\n", *nodeData);
	system("pause");
	return 0;
}
