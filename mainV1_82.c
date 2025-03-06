#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "pokeLibraryV1_77.c"

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
	- Decluttered some stuff na nakalimutan ko na siguro mga comments and shits
	- changed system clear to print, less memory usage
	- Added other cases pero wala pang laman gaano
	- nilagay ko na array wt colors sa pokeLibrary

	---- RANDOM CODE NOTES ----
	- potentially implement error handling sa searchpokemon [sa pag choose ng pokemon index input or name]*
	- about to do this, in another time siguro mamaya maya [thaeron]
	- [thaeron] chart is now completely working
	- more rigid error detection nalang, tapos yung mga mahihirap sorting and shit 
	- oo nga pre nakakatamad gumawa ng patch notes pero sige pag may mga nakaligtaan ako msg mo nalang ako type shit
*/

int main() {
    SetConsoleOutputCP(65001); // Sets CMD to UTF-8 basta para makita yung ibang texts
	
	int choice = 0;
	int size = 0;
	int searchPokemonChoice = 0;
	int pokemonDexNum = 0;
	char pokemonName[50];

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
    			
    		case 2: inputPokemon(&myPokemons[size]);
					size++;
					break;

			case 3: displayPokemonChart(myPokemons, size, pokemonTypes);
					break;

			case 4: displayPokemonTable(myPokemons, size, pokemonTypes);
					break;
			
			case 6: printf("Search via [0]Pokedex Number or [1]PokeName?: ");
					scanf("%d",&searchPokemonChoice);
					while (getchar() != '\n');

					if(searchPokemonChoice == 0) {
						printf("Enter Pokedex Number: ");
						scanf("%d", &pokemonDexNum);
					} else if (searchPokemonChoice == 1) {
						printf("Enter Pokemon to Search: ");
						fgets(pokemonName, 50, stdin);
					}

    				pokemonName[strcspn(pokemonName, "\n")] = '\0'; 
					searchPokemon(myPokemons, size, pokemonName, pokemonDexNum);
					break;
			
			case 7: break;
			
			case 8: deletePokemon(myPokemons, &size);
					break;
					
			case 9: break;
				
			case 10: break;
				
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