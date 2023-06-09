#ifndef _D10_H_
#define _D10_H_

#define HELP_MSG "\033[1;31mRegular Rolls:\033[1;0m\n    --roll [dice pool]\n\n    Optional:\n        -hunger [hunger level]\n        -difficulty [level]\n\n\033[1;31mRouse Check:\033[1;0m\n    --rouse\n\nUse --help, --h for help.\nNote: all arguments may be abbreviated to their initial, except for --rouse.\n"
#define INVALID_MSG "Invalid command or insufficient arguments. Use --help, -h for help.\n"
#define SUCCESS_MSG "Success! Margin:"
#define SUCCESSES_MSG "Sucesses: "
#define FAILIURE_MSG "Failiure. Margin:"
#define BESTIAL_MSG "\033[1;31m  BESTIAL FAILIURE \033[1;0m\n"
#define CRITICAL_MSG "\033[1;31m MESSY CRITICAL \033[1;0m\n"
#define TIE_MSG "Tie goes to the active Kindred.\n"
#define ROUSE_MSG "You call upon the powers of your Blood.\n"
#define HUNGER_ROUSE_MSG "\033[1;31m AND YOU GET HUNGRIER.. \033[1;0m\n"

#define FAIL_ICON "0"
#define WIN_ICON "☥"
#define CRIT_ICON "⋆☥⋆"

#define MIN_H 1
#define MAX_H 5
#define CRIT 10
#define SUCESS 6
#define FAIL 1

#endif
