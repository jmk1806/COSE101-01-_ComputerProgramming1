#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)

typedef struct book {
	char name[30];
	char semi_ISBN[5];
	int page;
}Book;

int main() {
	int cmd = 0;
	int count = 0;
	int check = 0;
	int num = 0;
	char search[30];
	char temp[30];
	Book arr[100];
	for (int i = 0; i < 100; i++) {
		strcpy(arr[i].name, " ");
		strcpy(arr[i].semi_ISBN, " ");
		arr[i].page = 0;
	}
	strcpy(arr[0].name, "Let's do it.");
	strcpy(arr[0].semi_ISBN, "4456");
	arr[0].page = 36;
	count++;
	
	do {
		printf("--------- menu ---------\n");
		printf("1. Display my book(s)\n");
		printf("2. Add a book\n");
		printf("3. Delete a book\n");
		printf("4. Sort my books\n");
		printf("5. Exit\n");
		printf("-------------------------\n");
		printf("Choose a number : ");
		rewind(stdin);
		scanf("%d", &cmd);
		switch (cmd) {
		case 1 : 
			printf("\nThere is %d book(s)", count);
			printf("\n");
			for (int i = 0; i < count; i++) {
				printf("%s (ISBN: %s), %d pages\n", arr[i].name, arr[i].semi_ISBN, arr[i].page);
			}
			printf("\n");
			break;

		case 2 :
			printf("\nPlease enter the name : ");
			rewind(stdin);
			fgets(temp, 30, stdin);
			temp[strlen(temp) - 1] = '\0';
			strcpy(arr[count].name, temp);
			printf("semi_ISBN : ");
			rewind(stdin);
			fgets(temp, 30, stdin);
			temp[strlen(temp) - 1] = '\0';
			strcpy(arr[count].semi_ISBN, temp);
			printf("The number of page : ");
			rewind(stdin);
			scanf("%d", &num);
			arr[count].page = num;
			count++;
			printf("\n");
			break;

		case 3 : 
			printf("\nPlease enter the book name to be removed : ");
			check = -1;
			rewind(stdin);
			fgets(search, 30, stdin);
			search[strlen(search) - 1] = '\0';
			for (int i = 0; i < count; i++) {
				if (!strcmp(arr[i].name, search)) 
					check = i;
			}

			if (check == -1) {
				printf("\n%s is not in your bookshelf.\n\n",search);
			}
			else {
				for (int i = check; i < count - 1; i++) {
					arr[i] = arr[i + 1];
				}
				printf("\n%s is removed from your bookshelf.\n\n", search);
				count--;
			}
			break;

		case 4 : 
			for (int i = 0; temp[i]; i++) {
				temp[i] = '0';
			}
			for (int i = 0; i < count; i++) {
				for (int j = 0; j < count -1; j++) {
					if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
						Book temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			printf("\nBookshelf is a alphabetically ordered.\n\n");
			break;
		}
	} while (cmd != 5);
}