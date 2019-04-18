#include <stdlib.h> // malloc
#include <stdio.h>
#include <string.h> // strdup, strcmp
#pragma warning(disable : 4996)
// User structure type definition
typedef struct
{
	char	*token;
	int		freq;
} tTOKEN;

////////////////////////////////////////////////////////////////////////////////
// LIST type definition
typedef struct node
{
	tTOKEN		*dataPtr;
	struct node	*link;
} NODE;

typedef struct
{
	int		count;
	NODE	*pos;
	NODE	*head;
	NODE	*rear;
} LIST;

////////////////////////////////////////////////////////////////////////////////
// Prototype declarations

/* Allocates dynamic memory for a list head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
LIST *createList(void);

/* Deletes all data in list and recycles memory
	return	NULL head pointer
*/
LIST *destroyList(LIST *pList);

/* Inserts data into list
	return	-1 if overflow
			0 if successful
			1 if duplicated key
*/
int addNode(LIST *pList, tTOKEN *dataInPtr);

/* Removes data from list
	return	0 not found
			1 deleted
*/
int removeNode(LIST *pList, char *keyPtr, tTOKEN **dataOut);

/* interface to search function
	Argu	key being sought
	dataOut	contains found data
	return	1 successful
			0 not found
*/
int searchList(LIST *pList, char *pArgu, tTOKEN **pDataOut);

/* returns number of nodes in list
*/
int listCount(LIST *pList);

/* returns	1 empty
			0 list has data
*/
int emptyList(LIST *pList);

//int fullList( LIST *pList);

/* prints data from list
*/
void printList(LIST *pList);

/* internal insert function
	inserts data into a new node
	return	1 if successful
			0 if memory overflow
*/
static int _insert(LIST *pList, NODE *pPre, tTOKEN *dataInPtr);

/* internal delete function
	deletes data from a list and saves the (deleted) data to dataOut
*/
static void _delete(LIST *pList, NODE *pPre, NODE *pLoc, tTOKEN **dataOutPtr);

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
static int _search(LIST *pList, NODE **pPre, NODE **pLoc, char *pArgu);

/* Allocates dynamic memory for a token structure, initialize fields(token, freq) and returns its address to caller
	return	token structure pointer
			NULL if overflow
*/
tTOKEN *createToken(char *str);

/* Deletes all data in token structure and recycles memory
	return	NULL head pointer
*/
tTOKEN *destroyToken(tTOKEN *pToken);

////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	LIST *list;
	char str[1024];
	tTOKEN *pToken;
	int ret;

	// creates a null list
	list = createList();
	if (!list)
	{
		printf("Cannot create list\n");
		return 100;
	}

	while (scanf("%s", str) == 1)
	{
		pToken = createToken(str);

		// insert function call
		ret = addNode(list, pToken);

		if (ret == 1) // duplicated 
			destroyToken(pToken);
	}
	// print function call
	printList(list);

	destroyList(list);

	return 0;
}

LIST *createList(void) {
	LIST* list = (LIST*)malloc(sizeof(LIST));
	if (!list) return NULL;

	list->head = (NODE*)malloc(sizeof(NODE)); // try to avoid exception
	list->head->link = NULL;
	list->rear = NULL;
	list->count = 0;
	return list;
}

LIST *destroyList(LIST *pList) {
	pList->pos = pList->head->link;
	while (pList->pos != NULL) {
		pList->rear = pList->pos;
		pList->pos = pList->pos->link;
		destroyToken(pList->rear->dataPtr);
		free(pList->rear);
	}
	free(pList->pos);
	free(pList->head);
	free(pList);
	return NULL;
}

int addNode(LIST *pList, tTOKEN *dataInPtr) {
	tTOKEN **pdataout = NULL;
	NODE* newNode = NULL;
	pList->pos = pList->head;

	while (pList->pos->link != NULL) {
		if (searchList(pList, dataInPtr->token, pdataout)) {
			(pList->pos->dataPtr->freq)++;
			destroyToken(dataInPtr);
			return 1;
		}
	}
	newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode) return -1;
	newNode->link = NULL;

	if (pList->head->link == NULL) {
		pList->head->link = newNode;
	}
	else {
		pList->pos = pList->head;
		while (pList->pos->link != NULL && strcmp(dataInPtr->token, pList->pos->link->dataPtr->token) > 0) {
			pList->pos = pList->pos->link;
		}
		newNode->link = pList->pos->link;
		pList->pos->link = newNode;
	}
	newNode->dataPtr = dataInPtr;
	(pList->count)++;
	return 0;
}

int searchList(LIST *pList, char *pArgu, tTOKEN **pDataOut) {
	if (emptyList(pList)) return 0;

	pList->pos = pList->head->link;
	while (pList->pos->link != NULL) {
		if (strcmp(pList->pos->dataPtr->token, pArgu) == 0) {
			return 1;
		}
		pList->pos = pList->pos->link;
	}
	return 0;
}

int listCount(LIST *pList) {
	return pList->count;
}

int emptyList(LIST *pList) {
	if (pList->head->link == NULL) return 1;
	else return 0;
}

void printList(LIST *pList) {
	if (!emptyList(pList)) {
		pList->pos = pList->head->link;
		printf("%s\t %d\n\n", pList->pos->dataPtr->token, pList->pos->dataPtr->freq);
		while (pList->pos->link != NULL) {
			pList->pos = pList->pos->link;
			printf("%s\t %d\n\n", pList->pos->dataPtr->token, pList->pos->dataPtr->freq);
		}
	}
}

tTOKEN *createToken(char *str) {
	tTOKEN *newToken = (tTOKEN*)malloc(sizeof(tTOKEN));
	if (!newToken) return NULL;
	newToken->token = strdup(str);
	newToken->freq = 1;
	return newToken;
}

tTOKEN *destroyToken(tTOKEN *pToken) {
	free(pToken->token);
	free(pToken);
	return NULL;
}