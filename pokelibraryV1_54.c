#include <stdio.h>
#include <string.h>

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/4/2025 10:05 | Kim
	Version: 1.54
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana

	----- Changes -----
	-debugged 1st function from *p -> *myPokemons
    -user inputs are now being stored in the array mypokemon[]
	-implemented fgets
    -pokemon tabular form working [to implement colors]
    -implemented searchpokemon via pokedexnum or name: to add option to display using bar graph

	---- RANDOM CODE NOTES ----
	- lagay nalang here mga need pa gawin or mga error na di naresolve
	- Function 6:
		- di pa kayang gawin dahil need pa pala iimplement yung evolution before and after kinemerut
	- ito pala gagamitin sa stats �������������� ANGAS ����������������
    - nasisira alignment ng table because of color sa pokemon types
    - IF THERES ANYTHING I MISSED OUT/BUGS/NALILITO SA CHANGES KO LMK LANG POGI (feel ko kasi may iba akong di nalalagay sa patch notes)
*/

const char *pokemonTypes[] = {"None", "Bug", "Dark", "Dragon", "Electric",
    "Fairy", "Fighting", "Fire", "Flying", "Ghost",
    "Grass", "Ground", "Ice", "Normal", "Poison",
    "Psychic", "Rock", "Steel", "Water", "Unknown"};

#define MAX_POKEMON 152

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
    char description[100];
} pokeData; // name of the struct

// extern declares a variable or function na defined sa ibang files <33
pokeData myPokemons[MAX_POKEMON]; 

void printBorder() {
	printf("====================================================================================================\n");
}

//Function 1: Display Main Menu
void displayMainMenu() {
	printBorder();
    printf("=                                     \033[1;37mWelcome to the Pokedex!\033[0m                                      =\n");
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

// Function 2: Pokemon Display Menu
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
    
    printf("Enter Pokemon Name: ");
    fgets(myPokemons->pokeName, 100, stdin); //stdin is just standard input
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
    fgets(myPokemons->description, 100, stdin); 
    myPokemons->description[strcspn(myPokemons->description, "\n")] = '\0'; 
    
    printBorder();
    printf("Pokemon entered successfully.\n");
    printBorder();
}

// Function 4: TABULAR FORM
void displayPokemonTable (pokeData myPokemons[], int size, const char *pokemonTypes[]) {
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
		if(myPokemons[i].dexNum == -1){
		break;
	}
	
    strcpy(evolvesFrom, "N/A");
    strcpy(evolvesTo, "N/A");

    type1PlaceHolder = myPokemons[i].pokeType1;
    type2PlaceHolder = myPokemons[i].pokeType2;

    
    if(myPokemons[i].pokeType1 == 0 || myPokemons[i].pokeType2 == 0){
        type1PlaceHolder = 0;
        type2PlaceHolder = 0;
    }

    for(int j = 0; j < size; j++){ //loop for finding evolve from and to
        if(myPokemons[i].evolvesFrom == myPokemons[j].dexNum){
            strcpy(evolvesFrom, myPokemons[j].pokeName);
        }

        if(myPokemons[i].evolvesTo == myPokemons[j].dexNum){
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
void searchPokemon(pokeData mypokemons[], int size, char *pokemonName, int pokemonDexNum) {
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
