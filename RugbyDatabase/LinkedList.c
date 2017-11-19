#include "LinkedList.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Adds Player
void addPlayer(struct node** head, int ifru) {
	struct node *temp;
	struct node *newNode;

	// if the list is empty then call function to add element at the start of the list
	if (*head == NULL)
		addPlayerAtStart(head, ifru);

	else {
		temp = *head;

		// Travel through the list until you get to the last node
		while (temp->NEXT != NULL)
			temp = temp->NEXT;	//Go to the next node

								//Create the new node
		newNode = (struct node*)malloc(sizeof(struct node));

		//Data input
		dataInput(newNode, ifru);

		//Link up the node after the last node in the list.
		newNode->NEXT = NULL;
		temp->NEXT = newNode;

	}//else

}//addPlayer()

//Adds Player at the start
void addPlayerAtStart(struct node** head, int ifru) {

	//Create new node and populate it with data
	struct node *newNode;

	newNode = (struct node*)malloc(sizeof(struct node));

	dataInput(newNode, ifru);

	//Connect up the node so that the new node is the headpointer
	newNode->NEXT = *head;
	*head = newNode;

}//addPlayerAtStart();

//Sorts by IFRU or height depending on variable choice, 1 - by IFRU ID, 2 - by height
void sort(struct node* head, int choice) {
	//Variables
	struct node* newNode;
	struct node* count;
	int temp;
	char temp2[35];
	int equation;

	newNode = head;

	for (; newNode->NEXT != NULL; newNode = newNode->NEXT) {
		for (count = newNode->NEXT; count != NULL; count = count->NEXT) {
			//Depending on choice variable, there will be different equation
			if(choice == 1)
				equation = newNode->ifru > count->ifru;	//ifru sort
			else
				equation = newNode->height > count->height;	//height sort
			if (equation == 1) {
				//Switching of all values
				temp = newNode->ifru;
				newNode->ifru = count->ifru;
				count->ifru = temp;

				strcpy(temp2, newNode->firstName);
				strcpy(newNode->firstName, count->firstName);
				strcpy(count->firstName, temp2);

				strcpy(temp2, newNode->secondName);
				strcpy(newNode->secondName, count->secondName);
				strcpy(count->secondName, temp2);

				temp = newNode->age;
				newNode->age = count->age;
				count->age = temp;

				temp = newNode->height;
				newNode->height = count->height;
				count->height = temp;

				temp = newNode->weight;
				newNode->weight = count->weight;
				count->weight = temp;

				strcpy(temp2, newNode->club);
				strcpy(newNode->club, count->club);
				strcpy(count->club, temp2);

				strcpy(temp2, newNode->email);
				strcpy(newNode->email, count->email);
				strcpy(count->email, temp2);

				strcpy(temp2, newNode->playerPosition);
				strcpy(newNode->playerPosition, count->playerPosition);
				strcpy(count->playerPosition, temp2);

				strcpy(temp2, newNode->tacklesMissed);
				strcpy(newNode->tacklesMissed, count->tacklesMissed);
				strcpy(count->tacklesMissed, temp2);

				strcpy(temp2, newNode->metres);
				strcpy(newNode->metres, count->metres);
				strcpy(count->metres, temp2);
			}//if
		}//for
	}//for
}//sort()

//Displays all players
void displayAllPlayers(struct node* head) {
	//Variables
	struct node *temp;

	temp = head;

	//If empty let user know
	if (temp == NULL)
		puts("\tPlayer Database is empty!");

	else {
		while (temp != NULL) {
			//Display the contents
			printPlayer(temp);
			temp = temp->NEXT;
		}//while
	}//else
	printf("\n");
}//displayAllPlayers()

//Data Input and validation of players details
void dataInput(struct node* newNode, int ifru) {
	//Variables
	int option, result;
	char position[7][25] = { "Prop", "Hooker", "Second Row", "Back Row", "Half Back", "Centres", "Wingers/Full Back" };	//makes sure user can choose only from this list
	char tackles[4][25] = { "Never", "Less than three", "Less than five", "More than five" };	//makes sure user can choose only from this list
	char metersTravelled[4][25] = { "None", "Less than 10", "Less than 20", "More than 20" };	//makes sure user can choose only from this list

	//Populate the new node's data
	newNode->ifru = ifru;	//put validated ifru into the node

	//User input of the rest of the data
	printf("\tEnter First Name: ");
	scanf("%s", newNode->firstName);

	printf("\tEnter Second Name: ");
	scanf("%s", newNode->secondName);

	printf("\tEnter Age: ");
	scanf("%d", &newNode->age);

	printf("\tEnter Height: ");
	scanf("%d", &newNode->height);

	printf("\tEnter Weight: ");
	scanf("%d", &newNode->weight);

	printf("\tEnter Club: ");
	scanf("%s", newNode->club);

	printf("\tEnter Email Address: ");
	scanf("%s", newNode->email);

	//Let user choose from different positions
	printf("\tChoose Player's Position: \n");
	puts("\t\t1 - Prop");
	puts("\t\t2 - Hooker");
	puts("\t\t3 - Second Row");
	puts("\t\t4 - Back Row");
	puts("\t\t5 - Half Back");
	puts("\t\t6 - Centres");
	puts("\t\t7 - Wingers");
	do {
		printf("\t\t\tChoose: ");
		scanf("%d", &option);

		if (option > 7 && option < 1)
			printf("Option %d doesn't exist!", option);
	} while (option > 7 && option < 1);	//keep user inside loop until right postion range gets chosen

	strcpy(newNode->playerPosition, position[option - 1]);	//copy chosen position into the node

	//Let user choose from different options
	printf("\tHow Many Tackles Missed per Match?\n");
	puts("\t\t1 - Never");
	puts("\t\t2 - Less than three");
	puts("\t\t3 - Less than five");
	puts("\t\t4 - More than five");
	do {
		printf("\t\t\tChoose: ");
		scanf("%d", &option);

		if (option > 4 && option < 1)
			printf("Option %d doesn't exist!", option);
	} while (option > 4 && option < 1);	//keep user inside loop until right range gets chosen

	strcpy(newNode->tacklesMissed, tackles[option - 1]);	//copy chosen data into the node

	//Let user choose from different options
	printf("\tHow Many Metres Does The Player Make In A Game?\n");
	puts("\t\t1 - None");
	puts("\t\t2 - Less than 10");
	puts("\t\t3 - Less than 20");
	puts("\t\t4 - More than 20");
	do {
		printf("\t\t\tChoose: ");
		scanf("%d", &option);

		if (option > 4 && option < 1)
			printf("Option %d doesn't exist!", option);
	} while (option > 4 && option < 1);	//keep user inside loop until right range gets chosen

	strcpy(newNode->metres, metersTravelled[option - 1]);	//copy chosen data into the node
	printf("\n");
}//dataInput()

//Seaches for IFRU and returns found position
int searchIFRU(struct node* head, int ifru) {
	//Variables
	struct node *temp;
	int found = 0, count = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	//Loops throught whole linked list
	while (temp != NULL) {
		//keeps count
		++count;
		if (temp->ifru == ifru) {
			found = count;	//once ifru id is found let variable foun equal to count
		}//if				//NOTE: only one function required to find location and check if ifru exists

		if (found > 0)
			break;

		else
			temp = temp->NEXT;	//go to next node
	}//while

	return(found);	//return location

}//searchNode()

//Finds player based on IFRU or Name and depending on choice it allows 1 - to diplay found players details, 2 - edit players details
void findPlayer(struct node* head, int choice) {
	//Variables
	struct node *temp;
	char name[20] = "";
	int ifru = 0, option, newIfru, result;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	//Check if database if empty
	if (temp == NULL)
		puts("\tPlayer Database is empty!\n");

	else {
		//Let user choose by what they would like to find player
		printf("\t1 for Player's IFRU ID, 2 for Player's Name: ");
		scanf("%d", &option);
		do {
			//If search by ifru
			if (option == 1) {
				printf("\tEnter IFRU: ");
				scanf("%d", &ifru);
			}//if

			//if search by name
			else if (option == 2) {
				printf("\tEnter First Name: ");
				scanf("%s", name);
			}//else if

			//Wrong input causes display of message below
			else
				printf("\n\tOption %d doesn't exist!\n", option);
		} while (option > 2 && option < 1);

		//Loops until reaches end of linked list
		while (temp != NULL) {
			if (temp->ifru == ifru || strcmp(temp->firstName, name) == 0) {	//checks if any of them match
				//for choice one display found players detail
				if (choice == 1) {
					puts("\t------Player Details------");
					printPlayer(temp);
					printf("\n");
				}//if

				//for choice two let user edit found players details
				else {
					do {
						//Check for duplicate IFRU
						printf("\tEnter New IFRU: ");
						scanf("%d", &newIfru);

						result = searchIFRU(head, newIfru);

						if (result != 0)
							puts("\t\tDuplicate IFRU!");	//on screen message
					} while (result != 0);

					dataInput(temp, newIfru);	//data input
					sort(temp, 1);	//sort by ifru

					puts("\tPlayer Information successfully updated!\n");	//let user know that players data was updated
				}//else
			}//if

			//go to next node
			temp = temp->NEXT;

		}//while
	}//else
}//displayPlayerDetails()

//Prints one player
void printPlayer(struct node* temp) {
	printf("\n\tIFRU: %d", temp->ifru);
	printf("\n\tFirst Name: %s", temp->firstName);
	printf("\n\tSecond Name: %s", temp->secondName);
	printf("\n\tAge: %d", temp->age);
	printf("\n\tHeight: %d", temp->height);
	printf("\n\tWeight: %d", temp->weight);
	printf("\n\tClub: %s", temp->club);
	printf("\n\tEmail Address: %s", temp->email);
	printf("\n\tPosition: %s", temp->playerPosition);
	printf("\n\tTackles Missed per Match: %s", temp->tacklesMissed);
	printf("\n\tMeters Travelled in Game: %s\n", temp->metres);
}//printPlayer()

//Deletes Player based on IFRU 
void deletePlayer(struct node** head, int location) {
	int i;
	struct node* temp;

	temp = *head;

	//Find previous node of the node to be deleted
	for (i = 1; temp != NULL && i < location - 1; i++)
		temp = temp->NEXT;

	//Store pointer to the next of node to be deleted
	struct node *next = temp->NEXT->NEXT;

	//Unlink the node from linked list
	free(temp->NEXT);

	//Unlink the deleted node from list
	temp->NEXT = next;

	puts("\tPlayer has been deleted\n");
}//deleteAtLocation()

//Deletes from start
void deleteAtStart(struct node** head) {
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));

	temp = *head;
	*head = temp->NEXT;

	//Free temp
	free(temp);

	//Let user know that the item has been deleted
	puts("\tPlayer has been deleted!\n");
}//deleteAtStart()

//Writes ONLY all players details into Report file
void reportFile(struct node* head) {
	//Variables
	struct node *temp;
	FILE * playerData;

	temp = head;

	//open file to write
	playerData = fopen("Report.txt", "w");

	//check if file exists
	if (playerData == NULL)
		printf("\tCan not open the file to write");

	//check if database is empty
	if (temp == NULL)
		puts("\tPlayer Database is empty!");

	else {
		while (temp != NULL) {
			//Display the contents
			fprintf(playerData, "----------- Player Details -----------");
			fprintf(playerData, "\n\tIFRU: %d", temp->ifru);
			fprintf(playerData, "\n\tFirst Name: %s", temp->firstName);
			fprintf(playerData, "\n\tSecond Name: %s", temp->secondName);
			fprintf(playerData, "\n\tAge: %d", temp->age);
			fprintf(playerData, "\n\tHeight: %d", temp->height);
			fprintf(playerData, "\n\tWeight: %d", temp->weight);
			fprintf(playerData, "\n\tClub: %s", temp->club);
			fprintf(playerData, "\n\tEmail Address: %s", temp->email);
			fprintf(playerData, "\n\tPosition: %s", temp->playerPosition);
			fprintf(playerData, "\n\tTackles Missed per Match: %s", temp->tacklesMissed);
			fprintf(playerData, "\n\tMeters Travelled in Game: %s\n", temp->metres);
			temp = temp->NEXT;
		}//while
	}//else
	fclose(playerData);
	puts("\tPlayers added to Report.txt!\n");
}//reportFile()

//Finds Second Row and Back Row position players
void findPositions(struct node* head, struct node** chosenPositions) {	//reminder that chosenPositions is a linked list created to store Second Row and Back Row players
	//Variables
	struct node *temp;
	temp = head;
	
	while (temp != NULL) {	//loops through linked list until end is reached
		if (((strcmp(temp->playerPosition, "Second Row")) == 0) || ((strcmp(temp->playerPosition, "Back Row")) == 0)) {	//checks for positions match
			//new node created for storing found player data
			struct node *newNode;
			newNode = (struct node*)malloc(sizeof(struct node));
			
			//initilize data to found data
			newNode->ifru = temp->ifru;
			strcpy(newNode->firstName, temp->firstName);
			strcpy(newNode->secondName, temp->secondName);
			newNode->age = temp->age;
			newNode->height = temp->height;
			newNode->weight = temp->weight;
			strcpy(newNode->club, temp->club);
			strcpy(newNode->email, temp->email);
			strcpy(newNode->playerPosition, temp->playerPosition);
			strcpy(newNode->tacklesMissed, temp->tacklesMissed);
			strcpy(newNode->metres, temp->metres);
			
			//Link data
			newNode->NEXT = *chosenPositions;
			*chosenPositions = newNode;
		}//if

		//Move to next element
		temp = temp->NEXT;
	}//while
}//findPositions()

//Gets player data from Rugby File
void retrieve(struct node** head) {
	//Variables
	FILE * playerData;

	//open file to read
	playerData = fopen("Rugby.txt", "r");

	//check if file exists
	if (playerData == NULL) {
		puts("\tFile cannot be opened!");
	}//if

	else {
		//Variables
		int ifru, result;
		char firstName[30], secondName[30];
		int age, height, weight;
		char club[30], email[30], playerPosition[30], tacklesMissed[30], metres[30];

		while (!feof(playerData)) {
			//Initial read to check if file isn't empty
			result = fscanf(playerData, "%d \n%s \n%s \n%d %d %d \n%s \n%s %[^\n] %[^\n] \n%[^\n]", 
				&ifru, firstName, secondName, &age, &height, &weight, club,
				email, playerPosition, tacklesMissed, metres);

			if (result > 0) {//if result bigger than 0 populate linked list
				//Struct node for storing data
				struct node *temp;
				temp = (struct node*)malloc(sizeof(struct node));

				temp->ifru = ifru;
				strcpy(temp->firstName, firstName);
				strcpy(temp->secondName, secondName);
				temp->age = age;
				temp->height = height;
				temp->weight = weight;
				strcpy(temp->club, club);
				strcpy(temp->email, email);
				strcpy(temp->playerPosition, playerPosition);
				strcpy(temp->tacklesMissed, tacklesMissed);
				strcpy(temp->metres, metres);

				//Link data up
				temp->NEXT = *head;
				*head = temp;
			}//if

			else{
				puts("\tDatabase is empty!");	//let user know if database is empty
			}
			
		}//while
		
	}//else

	//close file 
	fclose(playerData);
}//retrieve()

//Updates player data to Rugby File
void update(struct node* head) {
	//Variables
	FILE * playerData;
	struct node *temp;

	temp = head;

	//open file to write
	playerData = fopen("Rugby.txt", "w");

	//check if file exists
	if (playerData == NULL) {
		puts("\tCan not open the file to write!");
	}//if

	else {
		//check if database is empty
		if (temp == NULL)
			puts("\tPlayer Database is empty!");

		while (temp != NULL) {
			//put data into Rugby file
			fprintf(playerData, "%d\n%s\n%s\n%d %d %d\n%s\n%s\n%s\n%s\n%s\n", temp->ifru, temp->firstName, temp->secondName, temp->age, temp->height, temp->weight, temp->club,
				temp->email, temp->playerPosition, temp->tacklesMissed, temp->metres);

			//move to next element
			temp = temp->NEXT;
		}//while
	}//else

	//close file
	fclose(playerData);
}//update()

//Generates player details based on user input
void generateStats(struct node* head) {
	//Variables
	struct node *temp;
	char position[35] = "";
	int weight = 999, option, count = 0;
	char positions[7][25] = { "Prop", "Hooker", "Second Row", "Back Row", "Half Back", "Centres", "Wingers/Full Back" };
	float stats[8] = { 0,0,0,0,0,0,0 };

	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;

	//check if database is empty
	if (temp == NULL)
		puts("\tPlayer Database is empty!\n");

	else {
		//User can choose to display players stats by position or weight
		printf("\t1 for Player's Position, 2 for Player's Weight: ");
		scanf("%d", &option);
		do {
			if (option == 1) {
				//Let user choose from options to make sure input is correct
				printf("\tChoose Player's Position: \n");
				puts("\t\t1 - Prop");
				puts("\t\t2 - Hooker");
				puts("\t\t3 - Second Row");
				puts("\t\t4 - Back Row");
				puts("\t\t5 - Half Back");
				puts("\t\t6 - Centres");
				puts("\t\t7 - Wingers");
				do {
					printf("\t\t\tChoose: ");
					scanf("%d", &option);

					if (option > 7 && option < 1)
						printf("Option %d doesn't exist!", option);	//let user know that choosen option doesn't exits
				} while (option > 7 && option < 1);	//make sure option user chooses is within range

				strcpy(position, positions[option - 1]);	//copy choosen data into variable position
			}//if

			//if user chooses to display stats by weight
			else if (option == 2) {
				printf("\tEnter Above Weight: ");
				scanf("%d", &weight);
			}//else if

			//else if option doesn't exists
			else
				printf("\n\tOption %d doesn't exist!\n", option);	//on screen message for wrong input
		} while (option > 2 && option < 1);	//keep it withing range

		while (temp != NULL) {	//loop throught whole linked list
			if (temp->weight > weight || strcmp(temp->playerPosition, position) == 0) {	//check for a match
				//% of	players who	miss	no	tackles
				if(strcmp(temp->tacklesMissed, "Never") == 0)
					++stats[0];	//increments amount of players for this option

				//%	of	players who	miss	less	than	3	tackles	per	match
				else if (strcmp(temp->tacklesMissed, "Less than three") == 0)
					++stats[1];	//increments amount of players for this option

				//%	of	players who	miss	less	than	5	tackles	per	match
				else if (strcmp(temp->tacklesMissed, "Less than five") == 0)
					++stats[2];	//increments amount of players for this option

				//%	of	players who	miss	more	than	5	tackles	per	match
				else if (strcmp(temp->tacklesMissed, "More than five") == 0)
					++stats[3];	//increments amount of players for this option

				//%	of	players who	make	no	metres	in	a	game
				if (strcmp(temp->metres, "None") == 0)
					++stats[4];	//increments amount of players for this option

				//%	of	players who	make	less	than	10	metres	in	a	game
				else if (strcmp(temp->metres, "Less than 10") == 0)
					++stats[5];	//increments amount of players for this option

				//%	of	players who	make	less	than	20	metres	in	a	game
				else if (strcmp(temp->metres, "Less than 20") == 0)
					++stats[6];	//increments amount of players for this option

				//%	of	players who	make	more	than	20	metres	in	a	game
				else if (strcmp(temp->metres, "More than 20") == 0)
					++stats[7];	//increments amount of players for this option
				
			}//if
			
			//move to next element
			temp = temp->NEXT;
			++count;	//keep count of all players
		}//while
	}//else

	//print all players stats to screen
	puts("\t----------Player Stats----------");
	puts("\t---Tackles Missed---");
	printf("\t\tNever: %.2f%%", ((stats[0]/count)*100));
	printf("\n\t\tLess than three: %.2f%%", ((stats[1] / count) * 100));
	printf("\n\t\tLess than five: %.2f%%", ((stats[2] / count) * 100));
	printf("\n\t\tMore than five: %.2f%%", ((stats[3] / count) * 100));
	puts("\n\t---Metres Travelled---");
	printf("\t\tNone: %.2f%%", ((stats[4] / count) * 100));
	printf("\n\t\tLess than 10: %.2f%%", ((stats[5] / count) * 100));
	printf("\n\t\tLess than 20: %.2f%%", ((stats[6] / count) * 100));
	printf("\n\t\tMore than 20: %.2f%%\n\n", ((stats[7] / count) * 100));
}//displayPlayerDetails()


