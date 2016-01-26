#include <iostream>
#include <cstring>
#include <ctime>

class mm
{
    private:
	char code[10];
	int guessLeft;
	int predict(char *);
	int hits, miss, onlist;
	int moves;
	char colors[6] = {'R', 'G', 'B', 'Y', 'V', 'P'};
    public:
	int play();
	int init();
	int help();
};
