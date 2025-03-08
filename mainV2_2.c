#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "pokeLibraryV2_2.c"

/*
	--THIS HEADER FILE CONTAINS ALL FUNCTION DEFINITIONS & DECLARATIONS --
	note: d2 na lahat ng declarations and definitions, wag na mag .h complicated
	masyado isang oras ko ginawa napikon lang ako

	Last modified: 3/7/2025 22:36 | Thaeron
	Version: 2.2
	++ 0.01 when making small adjustments
	++ 0.1 when finishing a function
	++ 1.0 when making super major changes/may prototype na na gumagana

	----- Changes -----
	- Transferred the searchPokemon scanf sa loob na mismo ng function searchPokemon
	- placed the headers within the switch case para mas flexible ang paggamit ng functions

	---- RANDOM CODE NOTES ----
	- 
	- [thaeron] chart is now completely working
	- more rigid error detection nalang, tapos yung mga mahihirap sorting and shit 
	- oo nga pre nakakatamad gumawa ng patch notes pero sige pag may mga nakaligtaan ako msg mo nalang ako type shit
*/

int main() {
    SetConsoleOutputCP(65001); // Sets CMD to UTF-8 basta para makita yung ibang texts
	
	int choice = 0;
	int size = 0;
	
	int searchPokeChoice = 0;
	int searchPokeDex = 0;
	char searchPokeName[50];

    //system(""); //enables ANSI support in windows CMD

	for(int i = 0; i < 100; i++)
		myPokemons[i].dexNum = -1;

	while (1) {
		printf("\033[2J\033[H"); // ansi escape code to cleat the terminal screen and move the cursor to top left corner
		
		displayMainMenu();
    	printf("What do you want to do? Enter the number of your choice: ");
    	scanf("%d", &choice);
    	printf("\033[2J\033[H");
    
    	switch (choice) {
    		case 1: displayPokemonType();
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