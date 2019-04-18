#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#pragma warning(disable : 4996)
struct TreeNode {
	struct TreeNode *leftPtr;
	char *token;
	struct TreeNode *rightPtr;
};
typedef struct TreeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, char *tokenPtr);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void) {
	TreeNodePtr rootPtr = NULL; /* points to the tree root */
	char sentence[100]; /* text from user */
	char *tokenPtr; /* pointer to current token */

	printf("Enter a sentence:\n");
	gets_s(sentence,sizeof(sentence));

	tokenPtr = strtok(sentence, " ");

	while (tokenPtr) {
		insertNode(&rootPtr, tokenPtr);
		tokenPtr = strtok(NULL, " ");

	}
	/* traverse the tree preorder */
	printf("\nThe preorder traversal is:\n");
	preOrder(rootPtr);

	/* traverse the tree inorder */
	printf("\n\nThe inorder traversal is:\n");
	inOrder(rootPtr);

	/* traverse the tree postorder */
	printf("\n\nThe postorder traversal is:\n");
	postOrder(rootPtr);
	
	printf("\n\n");
	return 0;
}
void insertNode(TreeNodePtr *treePtr, char *tokenPtr) {
	if (*treePtr == NULL) {
		*treePtr = (TreeNodePtr)malloc(sizeof(TreeNode));
		(*treePtr)->token = tokenPtr;
		(*treePtr)->leftPtr = NULL;
		(*treePtr)->rightPtr = NULL;

	}
	else {
		if (strcmp((*treePtr)->token, tokenPtr) > 0) {
			insertNode(&((*treePtr)->leftPtr), tokenPtr);
		}
		else if (strcmp((*treePtr)->token, tokenPtr) < 0) {
			insertNode(&((*treePtr)->rightPtr), tokenPtr);
		}
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr) {
		inOrder(treePtr->leftPtr);
		printf("%s ", treePtr->token);
		inOrder(treePtr->rightPtr);
	}
}
void preOrder(TreeNodePtr treePtr) {
	if (treePtr) {
		printf("%s ", treePtr->token);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}
void postOrder(TreeNodePtr treePtr) {
	if (treePtr) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%s ", treePtr->token);
	}
}