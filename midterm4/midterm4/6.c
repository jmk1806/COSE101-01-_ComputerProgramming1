#include<stdio.h>
#pragma warning(disable : 4996)
#define NUM_ROW 128
#define NUM_COL 128



int count_summit(double h[NUM_ROW][NUM_COL],int nrow, int ncol) {
	int num_summit = 0; 
	for (int i = 1; i < nrow-1; i++) {
		for (int j = 1; j < ncol-1; j++) {
			if (h[i][j] > h[i - 1][j])
				if (h[i][j] > h[i - 1][j + 1])
					if (h[i][j] > h[i][j - 1])
						if (h[i][j] > h[i][j + 1])
							if (h[i][j] > h[i - 1][j - 1])
								if (h[i][j] > h[i - 1][j + 1])
									if (h[i][j] > h[i + 1][j - 1])
										if (h[i][j] > h[i + 1][j + 1])
											num_summit++;
		}
	}

	return num_summit;
}

void main() {
	double h[NUM_ROW][NUM_COL]
		= { { 1,2,3,4,1 },
	{ 3,4,3,1,1 },
	{ 1,2,3,4,1 },
	{ 1,5,3,3,1 },
	{ 1,2,3,3,1 } };
	int num_summit = count_summit(h, 5, 5);
	printf("%d summits exist.\n", num_summit);
}