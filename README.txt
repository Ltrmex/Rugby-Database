---------------------------------------------------- USER MANUAL ---------------------------------------------------- 
1. To use the database, user must login with one of three login data from login.txt.
	- use '111111' as username and '111111' as password
2. User will be present with 8 different option on menu.
	- extra options include '-1' to exit the program, and '9' to display menu again(keeps things more clean and easily readable)
3. Menu and on screen messages explain everything else.

---------------------------------------------------- THINGS TO NOTE ---------------------------------------------------- 
1. Rugby.txt , Report.txt , login.txt included with submittion.
	- all of these files are already populated with data for testing purposes only
2. Not all requirements were meet.
	- No email validation
	- IFRU is kept unique, however it doesn't force user to input and integer (no error checking)
	- When generating Report.txt, it ONLY populates the file with all players data
		- Player performance statistics aren't written to the file
3. Input of username and password doesn't allow deletion of characters.
	- This is due to allowing user only 6 character inputs

---------------------------------------------------- CODING DECISIONS ----------------------------------------------------
1. Login was done through array based approached instead of linked list, as there was only three logins to proccess.
2. Some of the functions were made in a way where variable 'choice' was passed, this is due to reducing the code further.
	- Use of this is explained in the code
3. Allowed for function called 'dataInput', as this input is required in a few different functions.
4. Sorting for height and IFRU ID were made into one function.
5. Allowed for 'menu function' (only displayed at the beggining of database) so the output of all other functions is easily readeable.
	- NOTE: user can still choose to diplay that menu again by choosing option number 9
6. Most of input validation is done through use of do while loops as the code will run at least once.
	- NOTE: on screen messages displayed for invalid option choice