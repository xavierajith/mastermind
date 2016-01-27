#include <iostream>
#include <cstring>
#include <ctime>
#include <map>

class mm
{
    private:
	char code[10];
	int guessLeft;
	int predict(char *);
	int validColors(char *);
	int hits, onlist;
	int moves;
	std::map<char, int> colors = { 
		{'R',1}, {'G', 2},{'B',3}, {'Y',4}, {'V',5}, {'P',6},
		{'r',7}, {'g', 8},{'b',9}, {'y',10}, {'v',11}, {'p',12}};
	char vColors[6] = {'R','G','B','Y','V','P'};
    public:
	int play();
	int init();
	int help();
};
