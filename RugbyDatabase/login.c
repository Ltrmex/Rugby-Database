#include "login.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Login search/ checks
int loginValidation(char username[], char password[]) {
	//Variables
	FILE * loginData;
	char user[7], pass[7];
	int result, found = -1;

	//Open file to read
	loginData = fopen("LoginData.txt", "r");

	//Check if file exists
	if (loginData == NULL) {
		puts("File cannot be opened!");	//let user know if file doesn't exist
	}//if

	//Else if file exists
	else {
		while (!feof(loginData)) {	//loop until reaches end of file
			result = fscanf(loginData, "%s%s", user, pass);	//result will determine if there's something in the file

			if (result > 0) {	//if file isn't empty go inside and compare file data with user input
				if ((strcmp(username, user) == 0) && (strcmp(password, pass) == 0))	//checks for a match
					++found;	//if match found increment found
			}//if
		}//while

		//Close file
		fclose(loginData);
	}//else

	//Will return 0 if data didn't match, or otherwise it will return incremented value of 1
	return found;
}//loginValidation()

//Login Input
void login() {
	//Variables
	char username[7], password[7], ch;
	int i, result;

	do {
		printf("Username: ");

		//The role of for loop is to only allow 6 clicks of keyboard
		for (i = 0; i < 6; i++) {
			ch = getch();
			username[i] = ch;	//gets each character
			printf("%c", ch);
		}//for

		username[i] = '\0';	//null terminator

		printf("\nPassword: ");

		//The role of for loop is to only allow 6 clicks of keyboard
		for (i = 0; i < 6; i++) {
			ch = getch();
			password[i] = ch;	//gets each character
			ch = '*';	//replaces character with a * symbol
			printf("%c", ch);	//this way password array retains it's value but doesn't get displayed on screen
		}//for

		password[i] = '\0';	//null terminator

		result = loginValidation(username, password);	//returns 0 if username and/or password don't match

		if (result != 0)
			puts("\n\tInvalid Username or Password!\n");	//let user know of invalid input
	} while (result != 0);	//keeps user in loop until valid login details are inputted

	puts("\n\tLogged In!");	//once logged in, let user know by outputting on screen message
}//login()