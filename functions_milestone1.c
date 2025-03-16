#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_POKEMON 100
#define MAX_TYPE_WIDTH 10 // max width type displayPokemonTable

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
 */

//array of pokemon types with embedded colors
const char *pokemonTypes[] = {"None",
							"\033[1;32mBug\033[0m",
							"\033[1;30mDark\033[0m",
							"\033[38;2;153;51;255mDragon\033[0m",
							"\033[1;33mElectric\033[0m",
                 			"\033[38;2;255;105;180mFairy\033[0m",
							"\033[38;2;220;20;60mFighting\033[0m",
							"\033[1;31mFire\033[0m",
							"\033[1;34mFlying\033[0m",
							"\033[1;37mGhost\033[0m",
                 			"\033[92mGrass\033[0m",
							"\033[38;2;139;69;19mGround\033[0m",
							"\033[1;96mIce\033[0m",
							"\033[1;90mNormal\033[0m",
							"\033[1;95mPoison\033[0m",
                			"\033[38;2;163;73;164mPsychic\033[0m",
							"\033[1;30mRock\033[0m",
							"\033[38;2;176;196;222mSteel\033[0m",
							"\033[1;94mWater\033[0m",
							"Unknown"};

//pokemon struct                          
typedef struct {
    int dexNum;
    char pokeName[30];
    int pokeType1;
    int pokeType2;
    int HP;
    int Atk;
    int Def;
    int Spd;
    int Sp;
    int evolvesFrom;
    int evolvesTo;
    char description[50];
} pokeData; // name of the struct

pokeData myPokemons[MAX_POKEMON]; 

//function 1: Responsible for printing borders
void printBorder() {
	puts("========================================================================================================================");
}

//function 2: 
void printCenteredText(const char *text, const char *plainText) {
	int width = 120;
	int padding = (width - strlen(plainText)) / 2;
	
	int i;
	for (i = 0; i < padding; i++)
		printf(" ");
		
	printf("%s\n", text);
}

//function 3:
int getVisibleLength(const char *str) { // basically kukunin nya lang kung ilan yung kinuha niyang space na visible then stores it in a variable
    int length = 0;
    int in_escape = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\033') {
            in_escape = 1; // Entering escape sequence
        } else if (in_escape && str[i] == 'm') {
            in_escape = 0; // Exiting escape sequence
        } else if (!in_escape) {
            length++; // Count only visible characters
        }
    }
    return length;
}

//function 4: 
void printPokemonType(const char *type) { // Function to print Pokémon type with proper alignment
    int visibleLength = getVisibleLength(type);
    int padding = MAX_TYPE_WIDTH - visibleLength;
    printf("%s%*s", type, padding, ""); // Adjust spacing dynamically, basically yung * para siyang pointer, and yun yung variable na "padding"
}

//Function 1: Display Main Menu
void displayMainMenu() {
	printBorder();
    printCenteredText("\033[1;37mWelcome to the \033[1;34mPoke\e[1;93mDex!\033[0m", "Welcome to the PokeDex!");
    printBorder();
    puts("1. Show Pokemon Types");
    puts("2. Add New Pokemon Entry");
    puts("3. Display Complete Pokedex Chart");
    puts("4. Display Complete Pokedex Table");
    puts("5. Sort and Display Pokedex Table Based on Stats");
    puts("6. Search Pokemon");
    puts("7. Edit Pokemon");
    puts("8. Delete Pokemon");
    puts("9. Simulate Level Up");
    puts("10. Simulate Battle");
    puts("11. Display Battle Details");
    puts("12. Exit");
    printBorder();
}

// Function 2: Display Pokemon Types
void displayPokemonType() {
    puts("***********************************************************************");
    puts("*                            TYPE SELECTION                           *");
    printf("* 0: None       \033[1;32m1: Bug\033[0m        \033[1;30m2: Dark\033[0m      \033[38;2;153;51;255m3: Dragon\033[0m     \033[1;33m4: Electric\033[0m  *\n");
    printf("* \033[38;2;255;105;180m5: Fairy\033[0m      \033[38;2;220;20;60m6: Fighting\033[0m   \033[1;31m7: Fire\033[0m      \033[1;34m8: Flying\033[0m     \033[1;37m9: Ghost\033[0m     *\n");
    printf("* \033[92m10: Grass\033[0m    \033[38;2;139;69;19m11: Ground\033[0m    \033[1;96m12: Ice\033[0m      \033[1;90m13: Normal\033[0m    \033[1;95m14: Poison\033[0m    *\n");
    printf("* \033[38;2;163;73;164m15: Psychic\033[0m  \033[1;30m16: Rock\033[0m      \033[38;2;176;196;222m17: Steel\033[0m    \033[1;94m18: Water\033[0m    >19: Unknown   *\n");
    puts("***********************************************************************");
}

//Function 3: Asks for pokemon entries
// @param pokeData *myPokemons = struct to store user input
void inputPokemon(pokeData *myPokemons) {
	FILE *pokemons;
	pokemons = fopen("pokemons.txt", "a"); //opens the file "a" meaning append [to add]
	
	printf("Enter Pokedex Number: ");
    scanf("%d", &myPokemons->dexNum);
    while (getchar() != '\n'); //clears input buffer	
    
    printf("Enter Pokemon Name: ");
    fgets(myPokemons->pokeName, 30, stdin); //stdin is just standard input	
    myPokemons->pokeName[strcspn(myPokemons->pokeName, "\n")] = '\0'; //remove trailing newline
	
	displayPokemonType();

    printf("Enter Type 1: ");
    scanf("%d", &myPokemons->pokeType1);	

    printf("Enter Type 2: ");
    scanf("%d", &myPokemons->pokeType2);	
    
    printf("Enter HP: ");
    scanf("%d", &myPokemons->HP);	
    
    printf("Enter Attack: ");
    scanf("%d", &myPokemons->Atk);	

    printf("Enter Defense: ");
    scanf("%d", &myPokemons->Def);	

    printf("Enter Speed: ");
    scanf("%d", &myPokemons->Spd);	


    printf("Enter Special: ");
    scanf("%d", &myPokemons->Sp);

    printf("Evolves from (Enter 0 for N/A): ");
    scanf("%d", &myPokemons->evolvesFrom);

    printf("Evolves to (Enter 0 for N/A): ");
    scanf("%d", &myPokemons->evolvesTo);

	while (getchar() != '\n'); // consumes leftover newline, clears input buffer

    printf("Enter Description: ");
    fgets(myPokemons->description, 50, stdin); 
    myPokemons->description[strcspn(myPokemons->description, "\n")] = '\0'; 
    
    fprintf(pokemons, "%d %s %d %d %d %d %d %d %d %d %d %s \n",
    myPokemons->dexNum,
    myPokemons->pokeName,
    myPokemons->pokeType1,
    myPokemons->pokeType2,
    myPokemons->HP,
    myPokemons->Atk,
    myPokemons->Def,
    myPokemons->Spd,
    myPokemons->Sp,
    myPokemons->evolvesFrom,
    myPokemons->evolvesTo,
    myPokemons->description); //prints the following into the txt file
    
    fclose(pokemons); //closes the file access
    printBorder();
    puts("Pokemon entered successfully.");
    printBorder();
}

/* Function 4: Display Pokemon Chart
@param pokeData myPokemons[] = struct array that cotains all the pokemons
@param int size = indicates the number of pokemons
@param const char *pokemonTypes[] = array that contains all the pokemon types
*/
void displayPokemonChart(pokeData myPokemons[], int size, const char *pokemonTypes[]) {
	int i, j;
	int temp1, temp2; 

	if (size == 0) {
        printf("There are currently no Pokémons to display.\n");
        return;	
    }
	
	for (i = 0; i < size; i++) {
		temp1 = myPokemons[i].pokeType1;
		temp2 = myPokemons[i].pokeType2;
		
		printf("\nPokedex Number: %d, Name: %s, Type One: %s, Type Two: %s\n",
		myPokemons[i].dexNum, myPokemons[i].pokeName, pokemonTypes[temp1], pokemonTypes[temp2]);
	
		printf("HP:      ");
		printf("\033[1;34m"); 
		for (j = 0; j < myPokemons[i].HP / 2; j++) //loop responsible for printing the bars
			if (j < myPokemons[i].HP) printf("█");
		printf(" (%d)\033[0m\n", myPokemons[i].HP);
		
		printf("Attack:  ");
		printf("\033[1;32m");
		for (j = 0; j < myPokemons[i].Atk / 2; j++)
			if (j < myPokemons[i].Atk) printf("█");
		printf(" (%d)\033[0m\n", myPokemons[i].Atk);
		
		printf("Defense: ");
		printf("\033[1;31m");
		for (j = 0; j < myPokemons[i].Def / 2; j++)
			if (j < myPokemons[i].Def) printf("█");
		printf(" (%d)\033[0m\n", myPokemons[i].Def);
		
		printf("Speed:   ");
		printf("\033[1;33m");
		for (j = 0; j < myPokemons[i].Spd / 2; j++)
			if (j < myPokemons[i].Spd) printf("█");
		printf(" (%d)\033[0m\n", myPokemons[i].Spd);
		
		printf("Special: ");
		printf("\033[0;35m");
		for (j = 0; j < myPokemons[i].Sp / 2; j++)
			if (j < myPokemons[i].Sp) printf("█");
		printf(" (%d)\033[0m\n", myPokemons[i].Sp);

		printf("Pokedex Entry: %s\n\n", myPokemons[i].description);	
		
		printBorder();
	}
	
} 

/*Function: 4.5
Responsible for reading the pokemons inside the file
@param pokeData myPokemons[] = struct array that cotains all the pokemons
return lines as number of pokemons
*/
int GetValues(pokeData *myPokemons){
	int lines = 0;
	FILE *pokemons; 
	pokemons = fopen("pokemons.txt", "r"); //opens the file "r" for read [no modifying]

	for(int i = 0; i < 100; i++)
	myPokemons[i].dexNum = -1; //initializing vacant pokemon slots

	while (fscanf(pokemons, "%d %s %d %d %d %d %d %d %d %d %d %50[^\n]",
		&myPokemons[lines].dexNum,
		myPokemons[lines].pokeName, //cannot handle spaces [to fix]
		&myPokemons[lines].pokeType1,
		&myPokemons[lines].pokeType2,
		&myPokemons[lines].HP,
		&myPokemons[lines].Atk,
		&myPokemons[lines].Def,
		&myPokemons[lines].Spd,
		&myPokemons[lines].Sp,
		&myPokemons[lines].evolvesFrom,
		&myPokemons[lines].evolvesTo,
		myPokemons[lines].description) == 12) //reads up the printed values in the txt file
{
lines++; // Move to the next Pokémon
}

fclose(pokemons);
return lines;
}

/* Function 5: Display Pokemon Table
@param pokeData myPokemons[] = struct array that cotains all the pokemons
@param int size = indicates the number of pokemons
@param const char *pokemonTypes[] = array that contains all the pokemon types
*/
void displayPokemonTable(pokeData myPokemons[], int size, const char *pokemonTypes[]) {
    char evolvesTo[50];
    char evolvesFrom[50];

    if (size == 0) {
        printf("There are currently no Pokémons to display.\n");
        return;	
    }
    
    puts("+--------+-------------------+------------+------------+-----+-----+-----+-----+-----+-----------------+---------------+");
    printf("| No.    | Name              | Type One   | Type Two   | \033[32mHP\033[0m  | \033[31mAtk\033[0m | \033[34mDfs\033[0m | \033[33mSpd\033[0m | \033[35mSp\033[0m  | Evolves From    | Evolves To    |\n");
    puts("+--------+-------------------+------------+------------+-----+-----+-----+-----+-----+-----------------+---------------+");

    for (int i = 0; i < size && myPokemons[i].dexNum != -1; i++) {
        strcpy(evolvesFrom, "N/A");
        strcpy(evolvesTo, "N/A");

        // Find evolution names
        for (int j = 0; j < size; j++) {
            if (myPokemons[i].evolvesFrom == myPokemons[j].dexNum)
                strcpy(evolvesFrom, myPokemons[j].pokeName);
            if (myPokemons[i].evolvesTo == myPokemons[j].dexNum)
                strcpy(evolvesTo, myPokemons[j].pokeName);
        }

        printf("| %-6d | %-17s | ", myPokemons[i].dexNum, myPokemons[i].pokeName);
        printPokemonType(pokemonTypes[myPokemons[i].pokeType1]);
        printf(" | ");
        printPokemonType(pokemonTypes[myPokemons[i].pokeType2]);
        printf(" | %-3d | %-3d | %-3d | %-3d | %-3d | %-15s | %-13s |\n",
               myPokemons[i].HP, myPokemons[i].Atk, myPokemons[i].Def,
               myPokemons[i].Spd, myPokemons[i].Sp, evolvesFrom, evolvesTo);
               
        puts("+--------+-------------------+------------+------------+-----+-----+-----+-----+-----+-----------------+---------------+");
    }
}

//to add: sorted table function

/*Function 6: Search Pokemon: Allows the user to search a pokemon through name or index number via table or chart.
@param pokeData myPokemons[] = struct array that cotains all the pokemons
@param int size = indicates the number of pokemons
*/
void searchPokemon(pokeData myPokemons[], int size) {
	//to add: evolves to and from 
	//to add: searching via type
	printBorder();
    puts("Search Pokemon:");
	printBorder();
	
	int i, j, flag = 0;
	int viewOption;
	
	int searchPokeChoice = 0;
	int searchPokeDex = 0;
	char searchPokeName[50];
	
	char ctemp1[50] = {0}; // stores lowercase pokemon namne from myPokemons
	char ctemp2[50] = {0}; // stores lowercase pokemon name from searchPokeName
	
	puts("How would you like to SEARCH?");
	puts("1. Pokedex Number");
	puts("2. Pokemon Name");
	printf("Enter the number of your choice: ");
	scanf("%d", &searchPokeChoice);
	while (getchar() != '\n');
	
	switch (searchPokeChoice) {
		case 1: printf("Enter Pokedex Number: ");
				scanf("%d", &searchPokeDex);
				break;
		
		case 2: printf("Enter Pokemon to Search: ");
				fgets(searchPokeName, 50, stdin);
				searchPokeName[strcspn(searchPokeName, "\n")] = '\0';
				break;
				
		default: printf("Invalid Input.\n");
				 break;
	}
	
	for (i = 0; i < size; i++) {
        for (j = 0; myPokemons[i].pokeName[j] != '\0'; j++) {
            ctemp1[j] = tolower(myPokemons[i].pokeName[j]);
        }
        ctemp1[strlen(myPokemons[i].pokeName)] = '\0';
    
        for (j = 0; searchPokeName[j] != '\0'; j++) {
            ctemp2[j] = tolower(searchPokeName[j]);
        }
        ctemp2[strlen(searchPokeName)] = '\0';
        
        if ((searchPokeChoice == 1 && myPokemons[i].dexNum == searchPokeDex) || 
            (searchPokeChoice == 2 && strcmp(ctemp1, ctemp2) == 0)) {
            
            flag = 1;
            printf("\033[2J\033[H");
            printBorder();
            puts("SEARCH RESULTS");
            printBorder();
            
            displayPokemonChart(&myPokemons[i], 1, pokemonTypes);
        }
    }
    if (!flag) printf("\nThe Pokemon you are looking for is not in the Pokedex.\n");
}	
// Function 7: Edit Pokemon
void EditPokemon(pokeData myPokemons[], int size, char *pokeName){
	//implement search pokemon and  input pokemon
	
}

// Function 8:



void deletePokemon (pokeData myPokemons[], int *size) { // nakapointer si size para mammodify siya sa main file
	printBorder();
	puts("Delete Pokemon Entry");
	printBorder();
	
	int choice, found = 0, i;
	int dtemp1;
	char ctemp2[50] = {0};
	int ctemp2Length, ctemp2Length2;
	char toLower1[50], toLower2[50];

	puts("Delete by:");
	puts("1. Pokedex Number");
	puts("2. Pokemon Name");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	while (getchar() != '\n');

	switch (choice) {
		case 1: printf("Enter Pokedex Number: ");
				scanf("%d", &dtemp1);
				
				for (i = 0; i < *size; i++) {
					if (dtemp1 == myPokemons[i].dexNum) {
						myPokemons[i] = myPokemons[i + 1]; // shifts all the details to the right hanggang lumagpas sa size
						found = 1;
					}	
				}
				
				printBorder();
				
				if (found) {
					puts("Pokemon deleted successfully!");
					(*size)--; // decrements the amount of pokemon
				} else puts("Pokemon not found!");
				
				printBorder();
				break;
				
		case 2: printf("Enter Pokemon Name: ");	
				fgets(ctemp2, 50, stdin);
				ctemp2[strcspn(ctemp2, "\n")] = '\0';
				
				for(i = 0; i < *size; i++){
					ctemp2Length = strlen(ctemp2);
					ctemp2Length2 = strlen(myPokemons[i].pokeName);

					for(int k = 0; k < ctemp2Length; k++){ //to handle case insensitivity
						toLower1[k] = tolower(ctemp2[k]);
					}
					toLower1[ctemp2Length] = '\0';
					
					for(int j = 0; j < ctemp2Length2; j++){ //to handle case insensitivity
						toLower2[j] = tolower(myPokemons[i].pokeName[j]);
					}
					toLower2[ctemp2Length2] = '\0';

					if(strcmp(toLower1, toLower2) == 0){
						puts("Pokemon deleted successfully!");
						(*size)--;
					} else puts("Pokemon not found!");
				}
				
				printBorder();
				break;
	}
}

// int dexNum;
//    char pokeName[30];
//    int pokeType1;
//    int pokeType2;
//    int HP;
//    int Atk;
//    int Def;
//    int Spd;
//    int Sp;
//    int evolvesFrom;
//    int evolvesTo;
//    char description[50];

// Function 9: SimulateLevelUp
void simulateLevelUp(pokeData myPokemons[], int size) {
	int searchPokeDex;
	int levelUp;
	int found = 0;
	int i;
	
	printf("Enter Pokedex Number of the Pokemon to level up: ");
	scanf("%d", &searchPokeDex);
	
	for (i = 0; i < size; i++) {
		if (myPokemons[i].dexNum == searchPokeDex) {
			found = 1;
			printf("Enter level-up value: ");
			scanf("%d", &levelUp);
			
			int HP = (int)(myPokemons[i].HP + (myPokemons[i].HP * 0.10 * levelUp));
			int Atk = (int)(myPokemons[i].Atk + (myPokemons[i].Atk * 0.10 * levelUp));
			int Def = (int)(myPokemons[i].Def + (myPokemons[i].Def * 0.10 * levelUp));
			int Spd = (int)(myPokemons[i].Spd + (myPokemons[i].Spd * 0.10 * levelUp));
			int Sp = (int)(myPokemons[i].Sp + (myPokemons[i].Sp * 0.10 * levelUp));
			
			puts("************************************************************************************************************************");
			printf("\nSimulated Level-Up stats for %s (Level up by %d):\n", myPokemons[i].pokeName, levelUp);
			printf("HP:      ");
			printf("\033[1;34m");
			for (i = 0; i < HP / 2; i++) printf("█"); // divided by 2 dahil masyadong malaki yung block
			printf(" (%d)\033[0m\n", HP);
			
			printf("Attack:  ");
			printf("\033[1;32m");
			for (i = 0; i < Atk / 2; i++) printf("█");
			printf(" (%d)\033[0m\n", Atk);
			
			printf("Defense: ");
			printf("\033[1;31m");
			for (i = 0; i < Def / 2; i++) printf("█");
			printf(" (%d)\033[0m\n", Def);
			
			printf("Speed:   ");
			printf("\033[1;33m");
			for (i = 0; i < Spd / 2; i++) printf("█");
			printf(" (%d)\033[0m\n", Spd);
			
			printf("Special: ");
			printf("\033[0;35m");
			for (i = 0; i < Sp / 2; i++) printf("█");
			printf(" (%d)\033[0m\n", Sp);
			
			puts("************************************************************************************************************************");
		}
	}
	if (!found) printf("\nThe pokemon you are looking for is not in the PokeDex.\n");
}

// Function 10: Simulate Battle
void simulatePokeBattle (pokeData myPokemons[], int size) {
	puts("+--------------+---------------------------------------------------+---------------------------------------------------+");
	puts("|                                                     TYPE EFFECTS                                                     |");
	puts("+--------------+---------------------------------------------------+---------------------------------------------------+");
    puts("| \033[1;32mBug\033[0m          | \033[92mGrass\033[0m, \033[38;2;163;73;164mPsychic\033[0m, \033[1;30mDark\033[0m                              | \033[1;31mFire\033[0m, \033[1;34mFlying\033[0m, \033[1;30mRock\033[0m                                |");
    puts("| \033[1;30mDark\033[0m         | \033[38;2;163;73;164mPsychic\033[0m, \033[1;37mGhost\033[0m                                    | \033[38;2;220;20;60mFighting\033[0m, \033[1;32mBug\033[0m, \033[38;2;255;105;180mFairy\033[0m                              |");
    puts("| \033[38;2;153;51;255mDragon\033[0m       | \033[38;2;153;51;255mDragon\033[0m                                            | \033[1;96mIce\033[0m, \033[38;2;153;51;255mDragon\033[0m, \033[38;2;255;105;180mFairy\033[0m                                |");
    puts("| \033[1;33mElectric\033[0m     | \033[1;94mWater\033[0m, \033[1;34mFlying\033[0m                                     | \033[38;2;139;69;19mGround\033[0m                                            |");
    puts("| \033[38;2;255;105;180mFairy\033[0m        | \033[38;2;220;20;60mFighting\033[0m, \033[38;2;153;51;255mDragon\033[0m, \033[1;30mDark\033[0m                            | \033[1;95mPoison\033[0m, \033[38;2;176;196;222mSteel\033[0m                                     |");
    puts("| \033[38;2;220;20;60mFighting\033[0m     | \033[1;90mNormal\033[0m, \033[1;96mIce\033[0m, \033[1;30mRock\033[0m, \033[1;30mDark\033[0m, \033[38;2;176;196;222mSteel\033[0m                    | \033[1;34mFlying\033[0m, \033[38;2;163;73;164mPsychic\033[0m, \033[38;2;255;105;180mFairy\033[0m                            |");
    puts("| \033[1;31mFire\033[0m         | \033[92mGrass\033[0m, \033[1;96mIce\033[0m, \033[1;32mBug\033[0m, \033[38;2;176;196;222mSteel\033[0m                            | \033[1;94mWater\033[0m, \033[1;30mRock\033[0m, \033[38;2;139;69;19mGround\033[0m                               |");
    puts("| \033[1;34mFlying\033[0m       | \033[92mGrass\033[0m, \033[38;2;220;20;60mFighting\033[0m, \033[1;32mBug\033[0m                              | \033[1;33mElectric\033[0m, \033[1;96mIce\033[0m, \033[1;30mRock\033[0m                               |");
    puts("| \033[1;37mGhost\033[0m        | \033[38;2;163;73;164mPsychic\033[0m, \033[1;37mGhost\033[0m                                    | \033[1;37mGhost\033[0m, \033[1;30mDark\033[0m                                       |");
    puts("| \033[92mGrass\033[0m        | \033[1;94mWater\033[0m, \033[38;2;139;69;19mGround\033[0m, \033[1;30mRock\033[0m                               | \033[1;31mFire\033[0m, \033[1;96mIce\033[0m, \033[1;95mPoison\033[0m, \033[1;34mFlying\033[0m, \033[1;32mBug\033[0m                    |");
    puts("| \033[38;2;139;69;19mGround\033[0m       | \033[1;31mFire\033[0m, \033[1;33mElectric\033[0m, \033[1;95mPoison\033[0m, \033[1;30mRock\033[0m, \033[38;2;176;196;222mSteel\033[0m               | \033[1;94mWater\033[0m, \033[92mGrass\033[0m, \033[1;96mIce\033[0m                                 |");
    puts("| \033[1;96mIce\033[0m          | \033[92mGrass\033[0m, \033[38;2;139;69;19mGround\033[0m, \033[1;34mFlying\033[0m, \033[38;2;153;51;255mDragon\033[0m                     | \033[1;31mFire\033[0m, \033[38;2;220;20;60mFighting\033[0m, \033[1;30mRock\033[0m, \033[38;2;176;196;222mSteel\033[0m                       |");
    puts("| \033[1;90mNormal\033[0m       | None                                              | \033[38;2;220;20;60mFighting\033[0m                                          |");
    puts("| \033[1;95mPoison\033[0m       | \033[92mGrass\033[0m, \033[38;2;255;105;180mFairy\033[0m                                      | \033[38;2;139;69;19mGround\033[0m, \033[38;2;163;73;164mPsychic\033[0m                                   |");
    puts("| \033[38;2;163;73;164mPsychic\033[0m      | \033[38;2;220;20;60mFighting\033[0m, \033[1;95mPoison\033[0m                                  | \033[1;32mBug\033[0m, \033[1;37mGhost\033[0m, \033[1;30mDark\033[0m                                  |");
    puts("| \033[1;30mRock\033[0m         | \033[1;31mFire\033[0m, \033[1;96mIce\033[0m, \033[1;34mFlying\033[0m, \033[1;32mBug\033[0m                            | \033[1;94mWater\033[0m, \033[92mGrass\033[0m, \033[38;2;220;20;60mFighting\033[0m, \033[38;2;139;69;19mGround\033[0m, \033[38;2;176;196;222mSteel\033[0m             |");
    puts("| \033[38;2;176;196;222mSteel\033[0m        | \033[1;96mIce\033[0m, \033[1;30mRock\033[0m, \033[38;2;255;105;180mFairy\033[0m                                  | \033[1;31mFire\033[0m, \033[38;2;220;20;60mFighting\033[0m, \033[38;2;139;69;19mGround\033[0m                            |");
    puts("+--------------+---------------------------------------------------+---------------------------------------------------+");
    
    int PokeBattle1;
    int PokeBattle2;
    
    printf("Enter Pokedex Number of the FIRST Pokemon: ");
    scanf("%d", &PokeBattle1);
	printf("Enter Pokedex Number of the SECOND Pokemon: ");
    scanf("%d", &PokeBattle2);
	//todo simulate
}
