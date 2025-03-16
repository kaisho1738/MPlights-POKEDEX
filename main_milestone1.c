#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "functions_milestone1.c"

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/16/2025 11:05 | kim
	Version: 2.4
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana
*/

int main() {
    SetConsoleOutputCP(65001); // Sets CMD to UTF-8 basta para makita yung ibang texts
	
	int choice = 0;

	int size = GetValues(myPokemons);
	int searchPokeChoice = 0;
	int searchPokeDex = 0;
	char searchPokeName[50];

    system(""); //enables ANSI support in windows CMD

	while (1) {
		printf("\033[2J\033[H"); // ansi escape code to cleat the terminal screen and move the cursor to top left corner
		size = GetValues(myPokemons);
		displayMainMenu();
    	printf("What do you want to do? Enter the number of your choice: ");
    	scanf("%d", &choice);
    	printf("\033[2J\033[H");
    
    	switch (choice) {
    		case 1: displayPokemonType();
					printf("%d", size);
    				break;
    			
    		case 2: printBorder();
					puts("Add New Pokemon Entry:");
					printBorder();
					inputPokemon(&myPokemons[size]);
					size++;
					break;

			case 3: printBorder();
					printCenteredText("PokeDex:", "PokeDex:");
					printBorder();
					displayPokemonChart(myPokemons, size, pokemonTypes);
					break;

			case 4: printBorder();
					printCenteredText("PokeDex:", "PokeDex:");
					printBorder();
					displayPokemonTable(myPokemons, size, pokemonTypes);
					break;
			
			case 6: searchPokemon(myPokemons, size);
					break;
			
			case 7: break;
			
			case 8: deletePokemon(myPokemons, &size);
					break;
					
			case 9: printBorder();
					puts("SIMULATE LEVEL UP");
					printBorder();
					simulateLevelUp(myPokemons, size);
					break;
				
			case 10: printBorder();
					 puts("SIMULATE BATTLE");
					 printBorder();
					 simulatePokeBattle(myPokemons, size);
					 break;
				
			case 11: break;
				
    		case 12: printf("Pokedex is now closing.");
					 return 0;
			
			default: printf("\nInvalid Input.\n");
					 while (getchar() != '\n');
					 break;
		}
		
		system("pause");
	}
    
    return 0;
}