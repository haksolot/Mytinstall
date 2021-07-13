#include <stdio.h>
#include <stdlib.h>

char * ascii = "  ____  _  _  ___  ____   __    __    __      __   ____  ____  _____  _  _       \n (_  _)( /( )/ __)(_  _) /__/  (  )  (  )    /__/ (_  _)(_  _)(  _  )( /( )      \n  _)(_  )  ( /__ /  )(  /(__)/  )(__  )(__  /(__)/  )(   _)(_  )(_)(  )  (       \n(____)(_)/_)(___/ (__)(__)(__)(____)(____)(__)(__)(__) (____)(_____)(_)/_)()()()";
//This function is to clear the current terminal
int cls(){
	//printf("\033[2J\033[1;1H");
	system("clear");
}
//Colors (reset and cyan)
int cRESET(){
	printf("\033[0m");
}

int cCYAN(){
	printf("\033[0;36m");
}
//


int main(){
    cCYAN();
    printf("%s\n", ascii);
    system("pacman -S youtube-dl");
    system("pacman -S ffmpeg");
    system("cp mytinstall /usr/bin");
    cls();

    return 0;
}