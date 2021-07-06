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


char* menuFeed =" 1 - Normal				[Download tracks one by one]\n\n 2 - Playlist				[Download entiere playlist]\n\n 3 - Custom				[Download in choosen folder]\n\n 4 - Other				[Next side of Menu]"; 

char* menuQuestion = "\n Input the number option: ";

char* other = "                                                   (Other) \n_______________________________________________________________________________________________________________";

char* otherFeed =" 5 - Addons				[Useful fonctionalities]\n\n 6 - Settings				[Customize stuff from mytinstall]\n\n 7 - Readme!				[Just need to read this !]\n\n 8 - Back 				[Go back to menu]";

char* music ="                                            (Simple Download)\n_______________________________________________________________________________________________________________";

char* musicFeed =" Paste the link : ";

char* playlist="                                               (Playlist)\n_______________________________________________________________________________________________________________";

char* playlistFeed =" Give the name of your playlist : ";
char* playlistFeedBis =" Paste the link of the playlist : ";


char* custom="                                               (Custom)\n_______________________________________________________________________________________________________________";

char* customFeed ="";

char* addons="                                                (Addons)\n_______________________________________________________________________________________________________________";

char* addonsFeed ="";

char* settings ="                                                (Settings)\n_______________________________________________________________________________________________________________";

char* settingsFeed ="";

char* readme ="                                                (README)\n_______________________________________________________________________________________________________________";

char* readmeFeed ="";
//

//This function is to clear the current terminal
int cls(){
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

//Utilities variable 
int choice;
char ytlink[100];
char cmd[200];
char playlistName[10];
//

int main(){
char * USER = getenv("USER");

//Directory initialization

char wPATH[100] = "/home/%s/Music";
char * PATH;
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

		case 1:
		strcpy(wPATH, "/home/%s/Musique/mytinstall/Music");
		sprintf(PATH, wPATH, USER);
		chdir(PATH);
		//cls();
		printf("%s\n\n%s\n\n%s", ascii, music, musicFeed);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		cls();
		break;

		case 2:
		strcpy(wPATH, "/home/%s/Musique/mytinstall/Playlist");
		sprintf(PATH, wPATH, USER);
		chdir(PATH);
		//cls();
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

		default:
		printf("ERROR             [Only use numbers and no other charachters] \n");
		cRESET();
		choice = 0;
		break;
	}} while (choice > 0);

	cRESET();
	return 0;
}

