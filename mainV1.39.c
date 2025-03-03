#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokelibrary.c"

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/3/2025 7:04 | Thaeron
	Version: 1.39
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana

	----- Changes -----
	- added mini-tracker description and organized notes
	- revised the version incrementation 
	- changed the choice function into a switch case para maangas
	- generally fixed formatting din para maangas

	---- RANDOM CODE NOTES ----
	- di pa malagay ibang cases kasi wala pang corresponding functions
	- implement index or count for pokemon count
*/

int main() {
    int choice = 0;
    char *pokemonTypes[] = {"None", "Bug", "Dark", "Dragon", "Electric",
                   			"Fairy", "Fighting", "Fairy", "Flying", "Ghost",
                   			"Grass", "Ground", "Ice", "Normal", "Poison",
                  			"Physic", "Rock", "Steel", "Water", "Unknown"};

    //system(""); //enables ANSI support in windows CMD

	while (1) {
		system("cls");
		displayMainMenu();
    	printf("What do you want to do? Enter the number of your choice: ");
    	scanf("%d", &choice);
    
    	switch (choice) {
    		case 1: displayPokemonType();
    				break;
    			
    		case 2: inputPokemon(&myPokemons[0]);
    				break;
    		
			case 6: 
				
    		case 12: printf("Pokedex is now closing.");
					 return 0;
			
			default: printf("Invalid Input.");
					break;
		}
		
		system("pause");
	}
    
    return 0;
}