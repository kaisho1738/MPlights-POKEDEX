#include "functions.c"
//version 2.0
//4:01pm march 3

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
    } else if(choice == 2){
        system("cls");
        inputPokemon(&p);
        //printf("%d, %d, %d, %s", p->atk,p->def,p->def, p->pokename);
    }
}