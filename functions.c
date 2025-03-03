#include <stdio.h>
//version 1.0 change

//Pokemon Struct
typedef struct pokemon{
    int pokedexNumber;
    char pokename[30];
    int pokemonType1;
    int pokemonType2;
    int hp;
    int atk;
    int def;
    int spd;
    int sp;
    int evolvesFrom;
    int evolvesTo;
    char description[100];
} pokemon;

pokemon p[100];

//Function 1: Display Main Menu
void displayMainMenu(){
    printf("****************************************************************************************************\n");
    printf("*                                  \033[1;37mWelcome to the Pokedex!\033[0m                                        *\n");
    printf("****************************************************************************************************\n");
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
    printf("****************************************************************************************************\n");
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

//Function 3:
void inputPokemon(pokemon *p){
    printf("Enter Pokedex Number: ");
    
    printf("Enter Pokename: ");

    printf("Enter Type 1: ");

    printf("Enter Type 2: ");
    
    printf("Enter HP: ");

    printf("Enter Attack: ");

    printf("Enter")
}
