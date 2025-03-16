
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumberCheck(int ent, int rndn);
int enternumber(int n);
int NumberGenerate();

int main() {
	
	int number= NumberGenerate();

	int seeds = enternumber(0);

	int i = 1;
	while (i > 0) {

		int sum = NumberCheck(seeds, number);
		
		if (sum == 0) {
			
			if (i==1) {
		    	printf("Congrats you guessed it on your %dst try\n", i);
		    }
		    else if (i == 2) {
		    	printf("Congrats you guessed it on your %dnd try\n", i);
			}
			else if (i == 3) {
		    	printf("Congrats you guessed it on your %drd try\n", i);
			}
			else {
		    	printf("Congrats you guessed it on your %dth try\n", i);
			}
			int ans;

			printf("%s", "Play again (enter 1 for play again) : ");
			scanf_s("%d", &ans);

			if (ans == 1) {
				i = 1;
				number = NumberGenerate();
				seeds = enternumber(0);
				continue;
			}
			else {
				return(0);
			}

		}
		else if (sum == 1) {
			seeds = enternumber(1);
		}
		else if (sum == 2) {
			seeds = enternumber(2);
		}
		++i;
	}
}
int NumberCheck(int ent, int rndn) {
	if (ent == rndn) {
		return(0);
	}
	else if (ent < rndn) {
		return(1);
	}
	else if (ent > rndn) {
		return(2);
	}
}
int enternumber(int n) {
	switch (n) {
	case 0:
		printf("%s", "Enter a number [0-100] : ");
		break;
	case 1:
		printf("%s", "Enter a greater number [0-100] : ");
		break;
	case 2:
		printf("%s", "Enter a smaller number [0-100] : ");
		break;
	}
	int seed = 0;
	scanf_s("%d", &seed);
	return(seed);
}
int NumberGenerate() {
	system("cls");
	srand(time(0));
	int number;
	number =  rand() % 101;
	//printf("%d ", number);
	return(number);
}
