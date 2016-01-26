#include "mm.h"

using namespace std;

int mm::help()
{
    cout << "\tWelcome to Master mind" << endl;
    cout << "Rules\n1. Valid Colors" << endl;
    cout << "R - Red\t\t G - Green\t B - Blue\n"
	"Y - yellow\t V - Violet\t P - Pink" << endl << endl;
    cout << "2. You can input only 4 valid colors" << endl;
    cout << "NOTE:: Any any point type help to display this menu" << endl << endl;
}

int mm::init()
{
    int i = 0;

    /*Choosing a random code*/
    srand((int)time(0));
    for (i = 0 ; i < 4; i++) {
	code[i] = colors[rand() % 6];
    }
    code [4] = '\0';

    cout << "Generated code : " << code << endl;

    guessLeft = 7;
    moves = 0;
}

int mm::predict(char* guess)
{
    int map[4] = {0, 0, 0, 0}, i = 0, j = 0;
    onlist = 0;
    hits = 0;

    guessLeft--;
    moves++;

    if (!strcmp(code,guess)) {
	cout << "You won in " << moves << " moves" << endl;
	return 1;
    }
    else {
	if (!guessLeft) {
	    cout << "You lost. Out of moves!!!" << endl;
	    return 1;
	}
	else {
	    for (i = 0; i < 4; i++) {
		if ( code[i] == toupper(guess[i])) {
		    hits++;
		    map[i] = 1;
		}
	    }
	    if (hits == 4) {
		cout << "You won in " << moves << " moves" << endl;
		return 1;
	    }

	    for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
		    if (!map[j]) {
		        if (guess[i] == toupper(code[j])) {
		    	    onlist++;
			    map[j] = 1;
			}
		    }			
		}    
	    }
	    cout << "Hits : " << hits << " Onlist : " << onlist << endl;
	    cout << "Gusess Left " << guessLeft << endl << endl;
	}
    }
    return 0;
}

int mm::play()
{
    char guess[10];

    while (1) {
        cout << "Guess : ";
        cin >> guess;

	if (!strcmp(guess, "help") || !strcmp(guess, "HELP")) {
	    help();
	    continue;
	}
	if (strlen(guess) != 4) {
	    cout << "Invalid Input!!!" << endl;
	    continue;
        }

        if (predict(guess))
	    break;
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
