#include "functions.c"

int main(){
    int choice = 0;
    char *pokemonTypes[] = {"None", "Bug", "Dark", "Dragon", "Electric",
                   "Fairy", "Fighting", "Fairy", "Flying", "Ghost",
                   "Grass", "Ground", "Ice", "Normal", "Poison",
                  "Physic", "Rock", "Steel", "Water", "Unknown"};

    //system(""); //enables ANSI support in windows CMD

    displayMainMenu();

    printf("What do you want to do? Enter the number of your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1){
    system("cls");
    displayPokemonType();
    system("pause");
    }
}