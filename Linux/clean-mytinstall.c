#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

//Basic UI
char* ascii = "::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       \n+:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       \n+:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       \n+#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       \n+#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       \n#+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       \n###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########";

char* menu = "                                                   (Menu) \n_______________________________________________________________________________________________________________";


char* menuFeed =" 1 - Normal				[Download tracks one by one]\n\n 2 - Playlist				[Download entiere playlist]\n\n 3 - Custom				[Download in choosen folder]\n\n 4 - Browser				[Open Youtube-Music]\n\n 5 - Other				[Next side of Menu]"; 

char* menuQuestion = "\n Input the number option: ";

char* other = "                                                   (Other) \n_______________________________________________________________________________________________________________";

char* otherFeed =" 5 - Addons				[Useful fonctionalities]\n\n 6 - Settings				[Customize stuff from mytinstall]\n\n 7 - Readme!				[Just need to read this !]\n\n 8 - Back 				[Go back to menu]";

char* music ="                                            (Simple Download)\n_______________________________________________________________________________________________________________";

char* musicFeed =" Paste the link : ";

char* playlist="                                               (Playlist)\n_______________________________________________________________________________________________________________";

char* playlistFeed =" Give the name of your playlist : ";
char* playlistFeedBis =" Paste the link of the playlist : ";


char* custom="                                               (Custom)\n_______________________________________________________________________________________________________________";

char* customFeed =" Insert your desired Path : ";

char* customFeedBis =" Past the link : ";

char* browser="                                               (Browser)\n______________________________________________________________________________________________________________";

char* browserFeed =" Input the choosen browser number (1-Brave or 2-Firefox) : ";

char* addons="                                                (Addons)\n_______________________________________________________________________________________________________________";

char* addonsFeed ="";

char* settings ="                                                (Settings)\n_______________________________________________________________________________________________________________";

char* settingsFeed ="";

char* readme ="                                                (README)\n_______________________________________________________________________________________________________________";

char* readmeFeed ="";
//

//This function is to clear the current terminal
int cls(){
	printf("\033[2J\033[1;1H");
	//system("clear");
}
//Colors (reset and cyan)
int cRESET(){
	printf("\033[0m");
}

int cCYAN(){
	printf("\033[0;36m");
}
//

//Utilities variable 
int choice;
char ytlink[100];
char cmd[200];
char playlistName[10];
char cPATH[500];
char sBrowser;
//

int main(){
char * USER = getenv("USER");

//Directory initialization

char wPATH[100] = "/home/%s/Music";
char  PATH[100];
sprintf(PATH, wPATH, USER);
DIR* dir = opendir(PATH);
			if (dir) {
				//printf("It already exists\n");
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(PATH, 0700);		
			}
strcpy(wPATH, "/home/%s/Music/mytinstall");
sprintf(PATH, wPATH, USER);
	 dir = opendir(PATH);
			if (dir) {
				//printf("It already exists\n");
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(PATH, 0700);		
			}

strcpy(wPATH, "/home/%s/Music/mytinstall/Music");
sprintf(PATH, wPATH, USER);
	 dir = opendir(PATH);
			if (dir) {
				//printf("It already exists\n");
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(PATH, 0700);		
			}

strcpy(wPATH, "/home/%s/Music/mytinstall/Playlist");
sprintf(PATH, wPATH, USER);
	 dir = opendir(PATH);
			if (dir) {
				//printf("It already exists\n");
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(PATH, 0700);		
			}

strcpy(wPATH, "/home/%s/Music/mytinstall/SoundBoard");
sprintf(PATH, wPATH, USER);
	 dir = opendir(PATH);
			if (dir) {
				//printf("It already exists\n");
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(PATH, 0700);		
			}
// end of directory initialization

//Base working interface for downloading
MENU:
cls();
cCYAN();
printf("%s\n\n%s\n\n%s\n%s", ascii, menu,menuFeed,menuQuestion);
scanf("%d", &choice);
do {
	switch(choice){
		case 0:
		goto MENU;
		break;

//Music option
		case 1:
		cls();
		strcpy(wPATH, "/home/%s/Music/mytinstall/Music");
		sprintf(PATH, wPATH, USER);
		chdir(PATH);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, music, musicFeed);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		cls();
		break;

//Playlist option
		case 2:
		strcpy(wPATH, "/home/%s/Music/mytinstall/Playlist");
		sprintf(PATH, wPATH, USER);
		chdir(PATH);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, playlist, playlistFeed);
		scanf("%s", playlistName);
		DIR* dir = opendir(playlistName);
			if (dir) {
				printf("Playlist already exists\n");
				break;  
    		closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(playlistName, 0700);
			}
		chdir(playlistName);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, playlist, playlistFeedBis);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		cls();
		break;

//Custom option
		case 3:
	    cls();
		printf("%s\n\n%s\n\n%s", ascii, custom, customFeed);
		scanf("%s", cPATH);
		dir = opendir(cPATH);
			if (dir) {
				chdir(cPATH); 
    			closedir(dir);}
			else if (ENOENT == errno) {
				mkdir(cPATH, 0700);
				chdir(cPATH);
			}
		cls();
		printf("%s\n\n%s\n\n%s", ascii, custom, customFeedBis);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		cls();
		break;

//Browser option
		case 4:
		cls();
		printf("%s\n\n%s\n\n%s", ascii, browser, browserFeed);
		scanf("%c\n", &sBrowser);
		do {
			switch(sBrowser){
				case 1:
				system("/usr/bin/brave-browser https://music.youtube.youtube.com/");
				break;

				case 2:
				system("firefox https://music.youtube.youtube.com/");
				break;

				default:
				system("firefox https://music.youtube.youtube.com/");
				break;
			} 
		}while (sBrowser > 0);
		goto MENU;
		//cls();
		break;


		default:
		printf("ERROR             [Only use numbers and no other charachters] \n");
		cRESET();
		choice = 0;
		break;
	}} while (choice > 0);

	cRESET();
	return 0;
}

