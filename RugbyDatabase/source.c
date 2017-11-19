#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "login.h"
#include "LinkedList.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Main Functions
void menu();

void main() {

	//Variables
	int option, result, ifru;
	struct node* head, *chosenPositions;

	head = NULL;

	//Before user can do anything with database right login and password must be entered
	login();

	//Gets data from Rugby file
	retrieve(&head);

	//Sorts linked list if database isn't empty
	if(head != NULL)
		sort(head, 1);

	//Displays menu
	menu();

	do {

		printf("Option(-1 to exit or 9 for menu): ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			//Adding new player
			do {
				printf("\tEnter IFRU: ");
				scanf("%d", &ifru);

				result = searchIFRU(head, ifru);

				//Checks for duplicates, as IFRU must be unique
				if (result != 0)
					puts("\t\tDuplicate IFRU!");
			} while (result != 0);	//kept in while loop until unique IFRU is entered

			//After validation bit players gets added and populated with data
			addPlayer(&head, ifru);
			sort(head, 1);	//players get sorted straight after adding
			break;
		case 2:
			//Displays all players in the database
			displayAllPlayers(head);
			break;
		case 3:
			//Find player by IFRU or by Name and display player's details
			findPlayer(head, 1);	//1 represents that once player is found, user wants to display that players detail
			break;
		case 4:
			//Find player by IFRU or by Name and edit player's details
			findPlayer(head, 2);	//2 represents that once player is found, user wants to edit that players detail
			break;
		case 5:
			do {
				printf("\tEnter IFRU: ");
				scanf("%d", &ifru);

				result = searchIFRU(head, ifru);

				//error check for IFRU ID
				if (result == 0)
					puts("\t\tIFRU doesn't exist!");
			} while (result == 0);

			if (result == 1)
				deleteAtStart(&head);	//deletes at start
			else
				deletePlayer(&head, result);	//deletes at chosen location
			break;
		case 6:
			//Generates stats based on users input
			generateStats(head);
			break;
		case 7:
			//Outputs ONLY all player details to the Report file
			reportFile(head);
			break;
		case 8:
			//Second Row and Back Row players in order of height
			chosenPositions = NULL;
			findPositions(head, &chosenPositions);	//chosenPositions is a linked list where Second Row and Back Row players will be stored

			if (chosenPositions == NULL)
				puts("\tNo players with Second Row or Back Row in the database!\n");	//if none found let the user know
			else {
				sort(chosenPositions, 2);	//sort, number 2 represents that the function should order players by their height
				displayAllPlayers(chosenPositions);	//displays sorted players with Second Row and/or Back Row
			}	
			break;
		case 9:
			//Display menu again
			menu();
			break;
		//-1 for exit
		case -1:
			break;
		default:
			puts("\tOption doesn't exists!\n");	//if wrong input
		}//switch
	} while (option != -1);	//exit on -1

	//Update player database
	update(head);
	puts("\nSuccessfully Logged Out!");	//let user know that program has been closed

	getch();
}//main

//Different menu options
void menu() {
	puts("\n1 - Add player.");
	puts("2 - Display all players.");
	puts("3 - Display player details.");
	puts("4 - Update player's statistics.");
	puts("5 - Delete player.");
	puts("6 - Generate statistics.");
	puts("7 - Print player details into report.");
	puts("8 - Players in order of height.\n");
}//menu()


