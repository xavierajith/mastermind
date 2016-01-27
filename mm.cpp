#include "mm.h"

using namespace std;

int mm::help()
{
    cout << "***************************************************************" << endl;
    cout << "\t\tWelcome to Master mind" << endl;
    cout << "Rules\n1. Valid Color Code (case insensitive)" << endl;
    cout << "R - Red\t\t G - Green\t B - Blue\n"
	"Y - yellow\t V - Violet\t P - Pink" << endl << endl;
    cout << "2. Computer makes the code with any of the 4 color code above." << endl << endl;
    cout << "3. You try and break the code within 10 moves" << endl << endl;
    cout << "4. Computer provies feedback on each guess." 
	"\n\t-white - Number of correct color in correct position"
	"\n\t-dark  - Number of correct color in wrong position" << endl << endl;
    cout << "NOTE:: Any any point type help to display this menu" << endl << endl;
    cout << "***************************************************************" << endl;
}

/*Returns 1 if the guess contains invalid colors. guess
is checked through the colors maps to see if it is a 
valid color*/
int mm::validColors(char* guess)
{
    int i;
    
    for (i = 0; i < 4; i++) {
	if (colors.find(guess[i]) != colors.end())
	    continue;
	else
    	    return 0;
    }
    return 1;
}

/*Called before start of every game to generate random
code and state initializations*/
int mm::init()
{
    int i = 0;

    /*Choosing a random code*/
    srand((int)time(0));
    for (i = 0 ; i < 4; i++) {
	code[i] = vColors[rand() % 6];
    }
    code [4] = '\0';

    guessLeft = 10;
    moves = 0;
}

/*Checks if the guessed code is correct or not.
Returns 1 if the game is won*/
int mm::predict(char* guess)
{
    int i, j;
    onlist = 0;
    hits = 0;

    guessLeft--;
    moves++;

    for (i = 0; i < 4; i++) {
	hitmap[i] = 0;
	map[i] = 0;
    }

    /*Check for direct hits*/
    for (i = 0; i < 4; i++) {
	if (code[i] == toupper(guess[i])) {
	    hits++;
	    hitmap[i] = 1;
	    map[i] = 1;
	}
    }
    /*Player wins if 4 hits*/
    if (hits == 4) {
	return 1;
    }

    /*Calculates the correctness of guess*/
    for (i = 0; i < 4; i++) {
	if (!hitmap[i]) {
	    for (j = 0; j < 4; j++) {
	    	if (!map[j]) {
		    if (toupper(guess[i]) == code[j]) {
		    	onlist++;
		    	map[j] = 1;
		    }
		}
	    }			
	}    
    }

    return 0;
}

/*Manages the state of the game.*/
int mm::play()
{
    char guess[10];
    int p;

    while (1) {
        cout << "Guess : ";
        cin >> guess;

	if (!strcmp(guess, "help") || !strcmp(guess, "HELP")) {
	    help();
	    continue;
	}
	if (strlen(guess) != 4) {
	    cout << "Invalid Input!!! - Can't exceed/less than 4 input." << endl;
	    continue;
        }

	if (!validColors(guess)) {
	    cout << "Invalid Input!!! - Check the colors entered" << endl;
	    continue;
        }

	if (predict(guess)) {
	    cout << "You won in " << moves << " moves" << endl;
	    break;
	}

	if (!guessLeft) {
	    cout << "You lost!!! Out of moves" << endl;
	    cout << "Real Code " << code << endl;
	    break;
	}
	cout << "White: " << hits << " Dark : " << onlist << endl;
	cout << "Gusess Left " << guessLeft << endl << endl;
    }

    return 0;
}

int main()
{
    char option;
    mm game;

    game.help();

    while(1) {
        game.init();
        game.play();

	cout << "Do you want to play again (y/n)? ";
	cin  >> option;

	if (option == 'y' || option == 'Y')
	    continue;
	else
	    break;
    }

    return 0;
}
