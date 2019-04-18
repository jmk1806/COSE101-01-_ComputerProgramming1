#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
	char name[30];
	char semi_ISBN[5]; /* 4 digits */
	int page;
};

int Menu(void);
void DisplayBooks(struct book[], int);
void AddBook(struct book[], int *);
void DeleteBook(struct book[], int *);
void SortBooks(struct book[], int);

int main(void)
{
	struct book books[100];
	int count = 0;

	while (1)
	{
		int input = Menu();

		switch (input)
		{
		case 1:
			DisplayBooks(books, count);
			break;
		case 2:
			AddBook(books, &count);
			break;
		case 3:
			DeleteBook(books, &count);
			break;
		case 4:
			SortBooks(books, count);
			break;
		case 5:
			return 0;
		}
	}
}

int Menu(void)
{
	int input;

	do
	{
		printf("\n-------- menu --------\n");
		printf("1. Display my book(s)\n");
		printf("2. Add a book\n");
		printf("3. Delete a book\n");
		printf("4. Sort my books\n");
		printf("5. Exit\n");
		printf("----------------------\n");
		printf("Choose a number : ");
		scanf_s("%d", &input);
	} while (input < 1 || input > 5);

	return input;
}

void DisplayBooks(struct book books[], int count)
{
	printf("\n%d book(s)\n", count);

	if (!count) return;

	for (int i = 0; i < count; i++)
		printf("%s (ISBN:%s), %d %s\n", books[i].name, books[i].semi_ISBN, books[i].page, books[i].page > 1 ? "pages" : "page");
	printf("\n");
}

void AddBook(struct book books[], int * count)
{
	char name[30];
	char isbn[5];
	int page;

	printf("\nPlease enter the name : ");
	rewind(stdin);
	gets_s(name, 30);
	printf("semi_ISBN : ");
	rewind(stdin);
	gets_s(isbn, 5);
	printf("The number of page : ");
	rewind(stdin);
	scanf_s("%d", &page);

	strcpy_s(books[*count].name, 30, name);
	strcpy_s(books[*count].semi_ISBN, 5, isbn);
	books[*count].page = page;
	(*count)++;
}

void DeleteBook(struct book books[], int * count)
{
	char name[30];
	int idx = -1;

	printf("\nPlease enter the book name to be removed : ");
	rewind(stdin);
	gets_s(name, 30);

	for (int i = 0; i < *count; i++)
		if (!strcmp(books[i].name, name))
			idx = i;

	if (idx == -1)
	{
		printf("\n%s is not in your bookshelf.\n\n", name);
		return;
	}

	for (int i = idx; i < *count - 1; i++)
		books[i] = books[i + 1];

	printf("\n%s is removed from your bookshelf.\n\n", name);
	(*count)--;
}

void SortBooks(struct book books[], int count)
{
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count - 1; j++)
			if (strcmp(books[j].name, books[j + 1].name) > 0)
			{
				struct book temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}

	printf("\nBookshelf is alphabetically ordered.\n\n");
}