#ifndef LINKEDLIST
	#define LINKEDLIST
	struct node {
		int ifru;
		char firstName[20];
		char secondName[20];
		int age;
		int height;
		int weight;
		char club[15];
		char email[30];
		char playerPosition[35];
		char tacklesMissed[35];
		char metres[35];
		struct node * NEXT;
	};

	void addPlayer(struct node** head, int ifru);	//adds player
	void addPlayerAtStart(struct node** head, int ifru);	//adds player at start/if linked list is empty
	void sort(struct node* head, int choice);	//sorts player linked list
	void displayAllPlayers(struct node* head);	//displayes all players onto screen
	void dataInput(struct node* newNode, int ifru);	//input of player details - reduces amount of code that requires to be written
	int searchIFRU(struct node* head, int ifru);	//searches for IFRU ID and returns location found at
	void findPlayer(struct node* head, int choice);	//finds player, and depending on variable choice: 1 - displays player details, 2 - edit player details
	void printPlayer(struct node* temp);	//prints found player
	void deletePlayer(struct node** head, int location);	//deletes player based on IFRU ID
	void deleteAtStart(struct node** head);	//deletes from start
	void generateStats(struct node* head);	//generates stats based on user input
	void retrieve(struct node** head);	//gets data from Rugby file
	void reportFile(struct node* head);	//prints ONLY all players detail to Report file
	void findPositions(struct node* head, struct node** chosenPositions);	//checks for Second Row and Back Row players in player database
	void update(struct node* head);	//updates Rugby file
#endif
