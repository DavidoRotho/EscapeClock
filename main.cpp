#include <iostream>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "header.h"

using namespace std;

int main(int argc, char** argv)
{
	int tf;
	char* ascii[11];
	ascii[0] = "\033[9A    █████\033[1B\033[8D  ██   ██\033[1B\033[9D ██     ██\033[1B\033[10D ██     ██\033[1B\033[10D ██     ██\033[1B\033[10D  ██   ██\033[1B\033[8D  █████ ";
	ascii[1] = "\033[9A    ██\033[1B\033[5D ████\033[1B\033[4D  ██\033[1B\033[3D ██\033[1B\033[3D ██ \033[1B\033[4D ██\033[1B\033[5D █████";
	ascii[2] = "\033[9A    ███████\033[1B\033[9D ██     ██\033[1B\033[3D ██\033[1B\033[9D ███████\033[1B\033[9D ██\033[1B\033[3D ██\033[1B\033[3D █████████ ";
	ascii[3] = "\033[9A    ███████\033[1B\033[9D ██     ██\033[1B\033[3D ██\033[1B\033[9D ███████\033[1B\033[2D ██\033[1B\033[10D ██     ██\033[1B\033[9D ███████";
	ascii[4] = "\033[9A    ██\033[1B\033[3D ██    ██\033[1B\033[9D ██    ██\033[1B\033[9D ██    ██\033[1B\033[9D █████████\033[1B\033[4D ██\033[1B\033[3D ██";
	ascii[5] = "\033[9A    ████████\033[1B\033[9D ██\033[1B\033[3D ██ \033[1B\033[4D ███████\033[1B\033[2D ██\033[1B\033[9D ██    ██\033[1B\033[8D ██████";
	ascii[6] = "\033[9A    ███████\033[1B\033[9D ██     ██\033[1B\033[10D ██\033[1B\033[3D ████████\033[1B\033[9D ██     ██\033[1B\033[10D ██     ██\033[1B\033[9D ███████";
	ascii[7] = "\033[9A    ████████\033[1B\033[9D ██    ██\033[1B\033[5D ██\033[1B\033[4D ██\033[1B\033[4D ██\033[1B\033[3D ██\033[1B\033[3D ██";
	ascii[8] = "\033[9A    ███████\033[1B\033[9D ██     ██\033[1B\033[10D ██     ██\033[1B\033[9D ███████\033[1B\033[9D ██     ██\033[1B\033[10D ██     ██\033[1B\033[9D ███████";
	ascii[9] = "\033[9A    ███████\033[1B\033[9D ██     ██\033[1B\033[10D ██     ██\033[1B\033[9D ████████\033[1B\033[4D  ██\033[1B\033[10D ██     ██\033[1B\033[9D ███████";
	ascii[10] = "\033[9A\033[1B      |     \033[4B\033[7D |";
	cock(ascii, tf);
	return 0;
}

int cock(char** ascii, int tf)
{
	while(1)
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		printf("\033[2J\033[1;1H");
		char buf[256];
		sprintf(buf, "%02d:%02d:%02d", ltm->tm_hour > 12 && !tf ? ltm->tm_hour-12 : ltm->tm_hour,\
					       ltm->tm_min,\
					       ltm->tm_sec);
		for (int i = 0; buf[i] != '\0' && i < 8; i++)
		{
			if (buf[i] == ':')
			{
				cout << ascii[10];
			}
			else
			{
				int index = buf[i] - '0';
				printf("%s",ascii[index]);
			}
		}
		printf("\033[1B\033[99D");
		fflush(stdout);
		sleep(1);
	}
}
