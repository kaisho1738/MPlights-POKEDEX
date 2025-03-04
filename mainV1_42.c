#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokelibraryV1_39.c"

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/4/2025 4:15 | Kim
	Version: 1.42
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana

	----- Changes -----
	- implemented fixed in colors sa pokemon types [permanent] ; also defined it as const since di na yan babaguhin
	-added display pokemon table
	- input function now stores into array allowing na makita sa table
	- table a

	---- RANDOM CODE NOTES ----
	- di pa malagay ibang cases kasi wala pang corresponding functions
	- implement index or count for pokemon count
	- [kim] input function working now storing properly
*/

int main() {
    int choice = 0;
	int size = 0;
    const char *pokemonTypes[] = {"None", "\033[1;32mBug\033[0m", "\033[1;30mDark\033[0m", "\033[38;2;153;51;255mDragon\033[0m", "\033[1;33mElectric\033[0m",
                   			"\033[38;2;255;105;180mFairy\033[0m", "\033[38;2;220;20;60mFighting\033[0m", "\033[1;31mFire\033[0m", "\033[1;34mFlying\033[0m", "\033[1;37mGhost\033[0m",
                   			"\033[92mGrass\033[0m", "\033[38;2;139;69;19mGround\033[0m", "\033[1;96mIce\033[0m", "\033[1;90mNormal\033[0m", "\033[1;95mPoison\033[0m",
                  			"\033[38;2;163;73;164mPhysic\033[0m", "\033[1;30mRock\033[0m", "\033[38;2;176;196;222mSteel\033[0m", "\033[1;94m18: WaterWater\033[0m", "Unknown"};
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
			
			//case 6: 
				
    		case 12: printf("Pokedex is now closing.");
					 return 0;
			
			default: printf("Invalid Input.");
					break;
		}
		
		system("pause");
	}
    
    return 0;
}