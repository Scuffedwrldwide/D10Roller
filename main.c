/* D10Roller - A simple D10 dice roller - Scuffedwrldwide */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "d10.h"

void invalidBreak(){
    printf(INVALID_MSG);
    exit(1);
}

void printDice(int size, int *dice, int isHunger){
    int i = 0;
    for (i = 0; i < size; i++){
        printf("  _____   ");
    }
    putchar('\n');
    for (i = 0; i < size; i++){
        printf(" / / \\ \\  ");
    }
    putchar('\n');
    for (i = 0; i < size; i++){
        if (dice[i] <= FAIL && isHunger) printf("|_/ 0 \\_| ");
        else if (dice[i] >= CRIT) printf("|_/⋆☥⋆\\_| ");
        else if (dice[i] >= SUCESS) printf("|_/ ☥ \\_| ");
        else printf("|_/   \\_| ");
        
    }
    putchar('\n');
    for (i = 0; i < size; i++){
        printf("  - _ -   ");
    }
    putchar('\n');
}

void printRoll(int number, int* dice, int isHunger){
    int lines, final, i = 0;
    lines = number / 5;
    final = number % 5;
    for (i = 0; i < lines; i++){
        printDice(5, &dice[i*5], isHunger);
    }
    if (final > 0) printDice(final, &dice[lines*5], isHunger);
}

int* rollDice(int number){
    int i = 0;
    int* dice = malloc(sizeof(int) * number);
    for (i = 0; i < number; i++){
        dice[i] = rand() % 10 + 1;
    }
    return dice;
}

void roll(int regular, int hunger, int diff){
    int i = 0, d = 0, success = 0, rCrits = 0, hCrits = 0, bestial = 0;
    int* dice = NULL;

    if (regular != -1){
        d = regular-hunger;
        dice = rollDice(d);
        printRoll(d, dice, 0);
        putchar('\n');
        for(i = 0; i < d; i++){
            if (dice[i] >= SUCESS) success++;
            if (dice[i] >= CRIT) rCrits++;
        }
        free(dice);
    }
    if (hunger != -1){
        dice = rollDice(hunger);
        printf("\033[1;31m");
        printRoll(hunger, dice, 1);
        putchar('\n');
        printf("\033[1;0m");
        for(i = 0; i < hunger; i++){
            if (dice[i] >= SUCESS) success++;
            if (dice[i] >= CRIT) hCrits++;
            if (dice[i] == FAIL) bestial = 1;
        }
        free(dice);
    }
    success += ((hCrits + rCrits) / 2) * 3;
    printf("%d %d\n", success, diff);
    if (diff > 0){
        if (success > diff){
            printf(SUCCESS_MSG" %d\n", abs(success - diff));
            if ((hCrits % 2) != 0) printf(CRITICAL_MSG);
        }
        else if (success < diff){
            printf(FAILIURE_MSG" %d\n", abs(success - diff));
            if(bestial) printf(BESTIAL_MSG);
        }
        else printf(TIE_MSG);
    }
    else if (diff < 0){
        printf(SUCESSES_MSG" %d\n", success);
        if ((hCrits % 2) != 0) printf(CRITICAL_MSG);
    }

}

int main(int argc, char* argv[]){   
    int hunger = -1, pool = -1, diff = -1;

    srand(time(0));
    if (argc < 2){
        printf(HELP_MSG);
    }
    else if (argc == 2){
        if (strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--help") == 0)
            printf(HELP_MSG);

        else printf(INVALID_MSG);
    }
    else if (argc > 2)
    {
        if (strcmp(argv[1], "--r") == 0 || strcmp(argv[1], "--roll") == 0){
            pool = atoi(argv[2]);
            if (pool == 0) invalidBreak();
            if (argc > 4){
                if (strcmp(argv[3], "-h") || strcmp(argv[3], "-hunger")){
                    hunger = atoi(argv[4]);
                    if (hunger == 0) invalidBreak();
                }
                else if (strcmp(argv[3], "-d") || strcmp(argv[3], "-difficulty")){
                    diff = atoi(argv[4]);
                    if (diff == 0) invalidBreak();
                }
                if (argc == 7){
                    if (strcmp(argv[5], "-d") || strcmp(argv[5], "-difficulty")){
                        diff = atoi(argv[6]);
                        if (diff == 0) invalidBreak();
                    }
                    else if (strcmp(argv[5], "-h") || strcmp(argv[5], "-hunger")){
                        hunger = atoi(argv[6]);
                        if (hunger == 0) invalidBreak();
                    }
                }

            }
            roll(pool, hunger, diff);
        }
        else if (strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--help") == 0)
            printf(HELP_MSG);
        else if (strcmp(argv[1], "--r") == 0) printf("ROUSE");
        else printf(INVALID_MSG);
    }
    else printf(INVALID_MSG);

    return 0;
}


