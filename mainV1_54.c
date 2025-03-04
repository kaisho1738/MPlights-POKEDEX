#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokelibraryV1_54.c"

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
	- implemented fixed in colors sa pokemon types [permanent] ; also defined it as const since di na yan babaguhin
	-added display pokemon table
	- input function now stores into array allowing na makita sa table
	- commented color coded pokemontypes
	- added color sa table [ATK,HP,SPD,SP,DEF]
	- moved const char pokemontypes outside of main para avail to access for all functions [MOVED TO FUNCTIONS FILE]
	- implemented search pokemon

	---- RANDOM CODE NOTES ----
	- di pa malagay ibang cases kasi wala pang corresponding functions
	- implement index or count for pokemon count [idk wat u mean]
	- [kim] input function working now storing properly
	- tinangal ko muna color codes sa pokemontypes kasi nasisira formatting ng table
	- potentially implement error handling sa searchpokemon [sa pag choose ng pokemon index input or name]
*/

int main() {
    int choice = 0;
	int searchPokemonChoice = 0;
	int size = 0;
	char pokemonName[50];
	int pokemonDexNum = 0;
    //const char *pokemonTypes[] = {"None", "\033[1;32mBug\033[0m", "\033[1;30mDark\033[0m", "\033[38;2;153;51;255mDragon\033[0m", "\033[1;33mElectric\033[0m",
    //              			"\033[38;2;255;105;180mFairy\033[0m", "\033[38;2;220;20;60mFighting\033[0m", "\033[1;31mFire\033[0m", "\033[1;34mFlying\033[0m", "\033[1;37mGhost\033[0m",
    //              			"\033[92mGrass\033[0m", "\033[38;2;139;69;19mGround\033[0m", "\033[1;96mIce\033[0m", "\033[1;90mNormal\033[0m", "\033[1;95mPoison\033[0m",
    //             			"\033[38;2;163;73;164mPhysic\033[0m", "\033[1;30mRock\033[0m", "\033[38;2;176;196;222mSteel\033[0m", "\033[1;94m18: WaterWater\033[0m", "Unknown"};


	//^^index of this is the pokemon type

    //system(""); //enables ANSI support in windows CMD

	for(int i = 0; i<100;i++){
		myPokemons[i].dexNum = -1;
	}

	while (1) {
		system("cls");
		displayMainMenu();
    	printf("What do you want to do? Enter the number of your choice: ");
    	scanf("%d", &choice);
    
    	switch (choice) {
    		case 1: displayPokemonType();
    				break;
    			
    		case 2: inputPokemon(&myPokemons[size]);
					size++;
					break;

			case 4: displayPokemonTable(myPokemons, size, pokemonTypes);
			break;
			
			case 6:
			printf("Search via [0]Pokedex Number or [1]PokeName?: ");
			scanf("%d",&searchPokemonChoice);
			while (getchar() != '\n');

			if(searchPokemonChoice == 0){
				printf("Enter Pokedex Number: ");
				scanf("%d", &pokemonDexNum);
			} else if(searchPokemonChoice == 1){
				printf("Enter Pokemon to Search: ");
				fgets(pokemonName, 50, stdin);
			}

    		pokemonName[strcspn(pokemonName, "\n")] = '\0'; 
			searchPokemon(myPokemons,size, pokemonName, pokemonDexNum);
			break;
				
    		case 12: printf("Pokedex is now closing.");
					 return 0;
			
			default: printf("Invalid Input.");
					break;
		}
		
		system("pause");
	}
    
    return 0;
}