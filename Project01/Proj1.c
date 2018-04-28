
#include <stdio.h>

//Define constant variables
const char starSymbol = '*';
const char hashSymbol = '#';
const int numOfRows = 15;
const int numOfcolumns = 30;


//Declare variables
int totalAmount = 0;
int totalSeats = 450;
int conformSeat = 0;
int q = 1;
char ticket[numOfRows][numOfcolumns];
double cost;

//Function prototypes
int displayMenu();
void displayChart();

//main method
int main()
{
	//Declare variables
	int x, y, rate;
	int res;
	const int num = 15;
	int cost[num];

	//Prompt and read input from the user
	printf("\tSeating capacity 15 rows, with 30 seats in each row.");

	for (int i = 0; i < numOfRows; i++)
	{
		printf("Enter the cost for row ", &(i + 1));
		printf(": ");
		scanf("%i", &cost[i]);

	}
	for (int j = 0; j < numOfRows; j++)
	{
		for (int k = 0; k < numOfcolumns; k++)
			ticket[j][k] = hashSymbol;
	}
	int choice;
	do
	{
		choice = displayMenu();
		switch (choice)
		{
		case 1:
			printf("View Seat Prices\n\n");

			for (int count = 0; count < numOfRows; count++)
			{
				printf("The price for row ", &(count + 1));
				printf(": ");
				scanf("%i", &cost[count]);
			}
			break;
		case 2:
			do
			{
				printf("Select the row: ");
				fgets(x, stdin);
				printf("Select the seat: ");
				fgets(y, stdin);
				if (ticket[x][y] == '*')
				{
					printf("Sorry that seat is sold-out, select an another seat.");
					printf("\n");
				}
				else
				{
					rate = cost[x] + 0;
					totalAmount = totalAmount + rate;
					printf("Ticket cost: %i", &rate);
					printf("Book the Ticket(1 = YES / 2 = NO)):");
					scanf("%i", res);
					totalSeats = totalSeats - res;
					conformSeat += res;

					if (res == 1)
					{
						printf("Your ticket purchase has been confirmed.");
						ticket[x][y] = starSymbol;
					}
					else if (res == 2)
					{
						printf("Would you continue for another seat? (YES=1 / NO=2)");
						printf("\n");
						scanf( "%i", q);
					}

					printf("Would you continue for another seat? (YES=1 / NO=2)");
					scanf("%i", &q);
				}
			} while (q == 1);

			break;
		case 3:
			printf("Available Seats displays # symobl, filled seats displays * symbol\n\n");
			displayChart();
			break;
		case 4:
			printf("Exit\n");
			break;
		default: printf("Error input\n");
		}
	} while (choice != 5);
	return 0;
}
//Method definition of displayMenu
int displayMenu()
{
	int MenuChoice;
	printf("\n\n");
	printf(" \t.......CHOICES.........\n");
	printf(" 1. Cost for seats.\n");
	printf(" 2. Buy a Ticket.\n");
	printf(" 3. Display Available Seats.\n");
	printf(" 4. Exit.\n");
	printf("_____________________\n\n");
	printf("Enter choice: ");
	scanf("%i", &MenuChoice);
	printf("\n\n");
	return MenuChoice;
}

//Method definition of displayChart
void displayChart()
{
	printf("\tSeats");
	printf("\n   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
	for (int i = 0; i <15; i++)
	{
		printf("\nRow %i", &(i + 1));
		for (int j = 0; j <30; j++)
		{
			printf(" %c", &ticket[i][j]);
		}
	}
	printf("\n");
}

