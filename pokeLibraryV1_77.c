#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/5/2025 14:35 | Thaeron
	Version: 1.77
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana

	----- Changes -----
	- added function printCenteredText (pprint nya lang ng nakagitna hehe oc ako e)
	- changed various array sizes for better memory usage
	- reverted the array of structures to include colors
	- added a for loop in line 120 para uppercase na lahat ng iinput
	- Chart is finished and polished
	- added deletePokemon but only the pokedex number works palang
	- 

	---- RANDOM CODE NOTES ----
	- lagay nalang here mga need pa gawin or mga error na di naresolve
	- [thaeron] function 8 is still not done
	- 
    
    // ctrl + / to instantly comment out!
*/

const char *pokemonTypes[] = {"None", "\033[1;32mBug\033[0m", "\033[1;30mDark\033[0m", "\033[38;2;153;51;255mDragon\033[0m", "\033[1;33mElectric\033[0m",
                 			"\033[38;2;255;105;180mFairy\033[0m", "\033[38;2;220;20;60mFighting\033[0m", "\033[1;31mFire\033[0m", "\033[1;34mFlying\033[0m", "\033[1;37mGhost\033[0m",
                 			"\033[92mGrass\033[0m", "\033[38;2;139;69;19mGround\033[0m", "\033[1;96mIce\033[0m", "\033[1;90mNormal\033[0m", "\033[1;95mPoison\033[0m",
                			"\033[38;2;163;73;164mPhysic\033[0m", "\033[1;30mRock\033[0m", "\033[38;2;176;196;222mSteel\033[0m", "\033[1;94mWater\033[0m", "Unknown"};

#define MAX_POKEMON 100

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

// extern declares a variable or function na defined sa ibang files <33
pokeData myPokemons[MAX_POKEMON]; 

void printBorder() {
	printf("====================================================================================================\n");
}

void printCenteredText(const char *text, const char *plainText) {
	int width = 100;
	int padding = (width - strlen(plainText)) / 2;
	
	int i;
	for (i = 0; i < padding; i++)
		printf(" ");
		
	printf("%s\n", text);
}

//Function 1: Display Main Menu
void displayMainMenu() {
	printBorder();
    printCenteredText("\033[1;37mWelcome to the \033[1;34mPoke\e[1;93mDex!\033[0m", "Welcome to the PokeDex!");
    printBorder();
    printf("1. Show Pokemon Types\n");
    printf("2. Add New Pokemon Entry\n");
    printf("3. Display Complete Pokedex Chart\n");
    printf("4. Display Complete Pokedex Table\n");
    printf("5. Sort and Display Pokedex Table Based on Stats\n");
    printf("6. Search Pokemon\n");
    printf("7. Edit Pokemon\n");
    printf("8. Delete Pokemon\n");
    printf("9. Simulate Level Up\n");
    printf("10. Simulate Battle\n");
    printf("11. Display Battle Details\n");
    printf("12. Exit\n");
    printBorder();
}

// Function 2: Display Pokemon Types
void displayPokemonType() {
    printf("***********************************************************************\n");
    printf("*                            TYPE SELECTION                           *\n");
    printf("* 0: None       \033[1;32m1: Bug\033[0m        \033[1;30m2: Dark\033[0m      \033[38;2;153;51;255m3: Dragon\033[0m     \033[1;33m4: Electric\033[0m  *\n");
    printf("* \033[38;2;255;105;180m5: Fairy\033[0m      \033[38;2;220;20;60m6: Fighting\033[0m   \033[1;31m7: Fire\033[0m      \033[1;34m8: Flying\033[0m     \033[1;37m9: Ghost\033[0m     *\n");
    printf("* \033[92m10: Grass\033[0m    \033[38;2;139;69;19m11: Ground\033[0m    \033[1;96m12: Ice\033[0m      \033[1;90m13: Normal\033[0m    \033[1;95m14: Poison\033[0m    *\n");
    printf("* \033[38;2;163;73;164m15: Psychic\033[0m  \033[1;30m16: Rock\033[0m      \033[38;2;176;196;222m17: Steel\033[0m    \033[1;94m18: Water\033[0m    >19: Unknown   *\n");
    printf("***********************************************************************\n");
}

//Function 3: User Input
void inputPokemon(pokeData *myPokemons) {
	printBorder();
	printf("Add New Pokemon Entry: \n");
	printBorder();
	
    printf("Enter Pokedex Number: ");
    scanf("%d", &myPokemons->dexNum);
    
    while (getchar() != '\n');
    
    int i;
    
    printf("Enter Pokemon Name: ");
    fgets(myPokemons->pokeName, 30, stdin); //stdin is just standard input
    myPokemons->pokeName[strcspn(myPokemons->pokeName, "\n")] = '\0'; //remove trailing newline
    for (i = 0; myPokemons->pokeName[i] != '\0'; i++) 
    	myPokemons->pokeName[i] = toupper(myPokemons->pokeName[i]);
    
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
    
    printBorder();
    printf("Pokemon entered successfully.\n");
    printBorder();
}

// Function 4: Display Pokemon Chart
void displayPokemonChart(pokeData myPokemons[], int size, const char *pokemonTypes[]) {
	printBorder();
	printCenteredText("PokeDex", "PokeDex");
	printBorder();
	
	int i, j;
	int temp1, temp2; 
	
	for (i = 0; i < size; i++) {
		temp1 = myPokemons[i].pokeType1;
		temp2 = myPokemons[i].pokeType2;
		
		printf("\nPokedex Number: %d, Name: %s, Type One: %s, Type Two: %s\n",
		myPokemons[i].dexNum, myPokemons[i].pokeName, pokemonTypes[temp1], pokemonTypes[temp1]);
	
		printf("HP:      ");
		printf("\033[1;34m");
		for (j = 0; j < myPokemons[i].HP / 2; j++)
			if (j < myPokemons[i].HP) printf("█"); // divided by 2 dahil masyadong malaki yung block
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

// Function 5: TABULAR FORM
void displayPokemonTable(pokeData myPokemons[], int size, const char *pokemonTypes[]) {
    char evolvesTo[50];
    char evolvesFrom[50];
    int type1PlaceHolder;
    int type2PlaceHolder;
	if (size == 0) {
		printf("There are currently no Pokemons to display.\n");
		return;	
	}
    printf("+-----------------+------------------+---------------+---------------+---------------+----------------+----------------+--------------+----------------+----------------+--------------+\n");
	printf("Pokedex           |Name              |Type 1         |Type 2         |\033[32mHP\033[0m             |\033[31mAttack\033[0m          |\033[34mDefense\033[0m         |\033[33mSpeed\033[0m         |\033[35mSpecial\033[0m         |Evolves From    |Evolves To     ");
	printf("\n+-----------------+------------------+---------------+---------------+---------------+----------------+----------------+--------------+----------------+----------------+--------------+\n");
		
	for(int i = 0; i < 100; i++){
		if(myPokemons[i].dexNum == -1) {
		break; // bawal daw gumamit ng break not unless naka-switch
	}
	
    strcpy(evolvesFrom, "N/A");
    strcpy(evolvesTo, "N/A");

    type1PlaceHolder = myPokemons[i].pokeType1;
    type2PlaceHolder = myPokemons[i].pokeType2;

    
    if(myPokemons[i].pokeType1 == 0 || myPokemons[i].pokeType2 == 0) {
        type1PlaceHolder = 0;
        type2PlaceHolder = 0;
    }

    for(int j = 0; j < size; j++){ //loop for finding evolve from and to
        if(myPokemons[i].evolvesFrom == myPokemons[j].dexNum) {
            strcpy(evolvesFrom, myPokemons[j].pokeName);
        }

        if(myPokemons[i].evolvesTo == myPokemons[j].dexNum) {
            strcpy(evolvesTo, myPokemons[j].pokeName);
        } 
    }
    
                                                            //hp        atk         def         spd        special
    printf("|%-9d        |%-9s         |%-9s      |%-9s      |\033[32m%-9d\033[0m      |\033[31m%-9d\033[0m       |\033[34m%-9d\033[0m       |\033[33m%-9d\033[0m     |\033[35m%-9d\033[0m       |%-9s       | %-9s     |\n", 
        myPokemons[i].dexNum, myPokemons[i].pokeName, pokemonTypes[type1PlaceHolder], pokemonTypes[type2PlaceHolder],
        myPokemons[i].HP, myPokemons[i].Atk, myPokemons[i].Def, 
        myPokemons[i].Spd, myPokemons[i].Sp, evolvesFrom, evolvesTo);	

	}
    
	printf("+-----------------+------------------+---------------+---------------+---------------+----------------+----------------+--------------+----------------+----------------+--------------+\n");
}


// Function 5:



//Function 6:
//should have the option to show through chart/table
void searchPokemon(pokeData myPokemons[], int size, char *pokemonName, int pokemonDexNum) {
	int i, flag = 0;
	
	printBorder();
    printf("Searching Pokemon...\n");
	printBorder();
	
	for (i = 0; i < size; i++) {
		if (strcmp(myPokemons[i].pokeName, pokemonName) == 0 || myPokemons[i].dexNum == pokemonDexNum) {
			printBorder();
			printf("\nPokemon is Found!\n");
			printBorder();
			displayPokemonTable(&myPokemons[i],size, pokemonTypes);
			flag = 1;
		}
	} 
	
	if (!flag) {
		printBorder();
		printf("\nThe Pokemon you are looking for is not in the Pokedex.\n");
		printBorder();
	}
}

// Function 7

// Function 8:

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

void deletePokemon (pokeData myPokemons[], int *size) { // nakapointer si size para mammodify siya sa main file
	printBorder();
	printf("Delete Pokemon Entry\n");
	printBorder();
	
	int choice, found, i;
	int dtemp1;
	char ctemp2;
	
	printf("Delete by:\n");
	printf("1. Pokedex Number\n");
	printf("2. Name\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	switch (choice) {
		case 1: printf("Enter Pokedex Number: ");
				scanf("%d", dtemp1);
				
				for (i = 0; i < *size - 1; i++) {
					if (dtemp1 == myPokemons[i].dexNum) {
						myPokemons[i] = myPokemons[i + 1]; // shifts all the details to the right hanggang lumagpas sa size
						found = 1;
					}	
				}
				
				printBorder();
				
				if (found) {
					printf("Pokemon deleted successfully!\n");
					(*size)--; // decrements the amount of pokemon
				} else printf("Pokemon not found!\n");
				
				printBorder();
				break;
				
		case 2: printf("Enter Pokemon Name: ");	
				break;
	}
}