#include <stdlib.h> // malloc
#include <stdio.h>
#include <string.h> // strdup, strcmp
#include <ctype.h> // toupper

#define QUIT			1
#define FORWARD_PRINT	2
#define BACKWARD_PRINT	3
#define DELETE			4

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
	struct node	*llink;
	struct node	*rlink;
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

/* prints data from list (forward)
*/
void printList(LIST *pList);

/* prints data from list (backward)
*/
void printListR(LIST *pList);

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

/* gets user's input
*/
int get_action()
{
	char ch;
	scanf("%c", &ch);
	ch = toupper(ch);
	switch (ch)
	{
	case 'Q':
		return QUIT;
	case 'F':
		return FORWARD_PRINT;
	case 'B':
		return BACKWARD_PRINT;
	case 'D':
		return DELETE;
	}
	return 0; // undefined action
}

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
	LIST *list;
	char str[1024];
	tTOKEN *pToken;
	int ret;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "usage: %s FILE\n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "rt");
	if (!fp)
	{
		fprintf(stderr, "Error: cannot open file [%s]\n", argv[1]);
		return 2;
	}

	// creates a null list
	list = createList();
	if (!list)
	{
		printf("Cannot create list\n");
		return 100;
	}

	while (fscanf(fp, "%s", str) == 1)
	{
		pToken = createToken(str);

		// insert function call
		ret = addNode(list, pToken);

		if (ret == 1) // duplicated 
			destroyToken(pToken);
	}

	fclose(fp);

	fprintf(stdout, "Select Q)uit, F)orward print, B)ackward print, D)elete: ");

	while (1)
	{
		int action = get_action();

		switch (action)
		{
		case QUIT:
			destroyList(list);
			return 0;

		case FORWARD_PRINT:
			printList(list);
			break;

		case BACKWARD_PRINT:
			printListR(list);
			break;

		case DELETE:
			fprintf(stdout, "Input a string to delete: ");
			fscanf(stdin, "%s", str);
			int ret = removeNode(list, str, &pToken);
			if (ret)
			{
				fprintf(stdout, "%s deleted\n", pToken->token);
				destroyToken(pToken);
			}
			else fprintf(stdout, "%s not found\n", str);
			break;
		}

		if (action) fprintf(stdout, "Select Q)uit, F)orward print, B)ackward print, D)elete: ");
	}
	return 0;
}

LIST *createList(void) {
	LIST* list = (LIST*)malloc(sizeof(LIST));
	if (!list) return NULL;

	list->head = (NODE*)malloc(sizeof(NODE));
	list->rear = (NODE*)malloc(sizeof(NODE));
	list->head->rlink = list->rear;
	list->head->llink = list->head;
	list->count = 0;
	return list;
}

LIST *destroyList(LIST *pList) {
	tTOKEN *dataout = NULL;
	while(!emptyList(pList)) {
		removeNode(pList, pList->head->rlink->dataPtr->token, &dataout);
		printf("%s", dataout);
		destroyToken(dataout);
	}
	free(pList->head);
	free(pList->rear);
	free(pList);
	return NULL;
}


int addNode(LIST *pList, tTOKEN *dataInPtr) {
	tTOKEN *pdataout = NULL;
	NODE* newNode = NULL;
	NODE* pPre = pList->head;
	NODE* pLoc = pList->head;
	pList->pos = pList->head;
	if (_search(pList, &pPre, &pLoc, dataInPtr->token)) {
		(pList->pos->dataPtr->freq)++;
		return 1;
	}

	newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode) return -1;

	newNode->rlink = pPre->rlink;
	newNode->llink = pPre;

	pPre->rlink = newNode;
	newNode->rlink->llink = newNode;

	newNode->dataPtr = dataInPtr;
	(pList->count)++;
	return 0;
}

int removeNode(LIST *pList, char *keyPtr, tTOKEN **dataOut) {
	if (emptyList(pList)) return 0;
	NODE *pPre = NULL;
	NODE *pLoc = NULL;

	if (_search(pList, &pPre, &pLoc, keyPtr)) {
		*dataOut = pList->pos->dataPtr;
		pPre->rlink = pLoc->rlink;
		pLoc->rlink->llink = pPre;
		free(pLoc);
		(pList->count)--;
		return 1;
	}
	return 0;
}


/*int searchList(LIST *pList, char *pArgu, tTOKEN **pDataOut) {
	if (emptyList(pList)) return 0;

	pList->pos = pList->head->rlink;
	while (pList->pos != NULL) {
		if (strcmp(pList->pos->dataPtr->token, pArgu) == 0) {
			*pDataOut = pList->pos->dataPtr;
			return 1;
		}
		if (pList->pos->rlink == NULL) return 0;
		pList->pos = pList->pos->rlink;
	}
	return 0;
}
*/
/* returns number of nodes in list
*/
int listCount(LIST *pList) {
	return pList->count;
}


int emptyList(LIST *pList) {
	if (listCount(pList) == 0) return 1;
	return 0;
}


/* prints data from list (forward)
*/
void printList(LIST *pList) {
	if (!emptyList(pList)) {
		pList->pos = pList->head;
		for (int i = 0; i < listCount(pList); i++) {
			pList->pos = pList->pos->rlink;
			printf("%s\t %d\n", pList->pos->dataPtr->token, pList->pos->dataPtr->freq);
		}
	}
}

/* prints data from list (backward)
*/
void printListR(LIST *pList) {
	if (!emptyList(pList)) {
		pList->pos = pList->rear;
		for (int i = 0; i < listCount(pList); i++) {
			pList->pos = pList->pos->llink;
			printf("%s\t %d\n", pList->pos->dataPtr->token, pList->pos->dataPtr->freq);
		}
	}
}

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
static int _search(LIST *pList, NODE **pPre, NODE **pLoc, char *pArgu) {

	if (emptyList(pList)) return 0;

	pList->pos = pList->head;
	for (int i = 0; i <= listCount(pList); i++) {
		pList->pos = pList->pos->rlink;
		if (i == listCount(pList))
		{
			*pLoc = pList->pos;
			*pPre = (*pLoc)->llink;
			return 0;
		}
		if (strcmp(pArgu, pList->pos->dataPtr->token) <= 0) {
			break;
		}
	}
	*pLoc = pList->pos;
	*pPre = (*pLoc)->llink;
	if (!strcmp(pArgu, (*pLoc)->dataPtr->token)) return 1;
	return 0;
}

/* Allocates dynamic memory for a token structure, initialize fields(token, freq) and returns its address to caller
	return	token structure pointer
			NULL if overflow
*/
tTOKEN *createToken(char *str) {
	tTOKEN *newToken = (tTOKEN*)malloc(sizeof(tTOKEN));
	if (!newToken) return NULL;
	newToken->token = strdup(str);
	newToken->freq = 1;
	return newToken;
}


/* Deletes all data in token structure and recycles memory
	return	NULL head pointer
*/
tTOKEN *destroyToken(tTOKEN *pToken) {
	free(pToken->token);
	free(pToken);
	return NULL;
}
