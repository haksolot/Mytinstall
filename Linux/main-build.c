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

char* otherFeed =" 6 - Addons				[Useful fonctionalities]\n\n 7 - Settings				[Customize stuff from mytinstall]\n\n 8 - Readme!				[Just need to read this !]\n\n 9 - Back 				[Go back to menu]";

char* music ="                                            (Simple Download)\n_______________________________________________________________________________________________________________";

char* musicFeed =" Paste the link : ";

char* playlist="                                               (Playlist)\n_______________________________________________________________________________________________________________";

char* playlistFeed =" Give the name of your playlist : ";

char* playlistFeedBis =" Paste the link of the playlist : ";

char* custom="                                               (Custom)\n_______________________________________________________________________________________________________________";

char* customFeed =" Insert your desired Path : ";

char* customFeedBis =" Past the link : ";

char* browser="                                               (Browser)\n______________________________________________________________________________________________________________";

char* browserFeed =" Input the choosen browser first letter (b-Brave or f-Firefox) : ";

char* addons="                                                (Addons)\n_______________________________________________________________________________________________________________";

char* addonsFeed ="";

char* settings ="                                                (Settings)\n_______________________________________________________________________________________________________________";

char* settingsFeed ="";

char* readme ="                                                (README)\n_______________________________________________________________________________________________________________";

char* readmeFeed ="   This tool is principaly made of Youtube-dl and ffmpeg.\n   So the respect for this project should belong to the creators of these.\n\n   As a consequence the supported website link are:\n   - youtube.com\n   - music.youtube.com\n   - and other compatible links with youtube-dl... \n     (to find on https://ytdl-org.github.io/youtube-dl/supportedsites.html )\n\n   It is open source so you can modify it.\n   It is stored in C:/Program Files/mytinstall-files on your windows pc\n\n   The tracks downloaded are stored in C:/Users/#your-username#/Music/mytinstall\n   There are different folders like Music or Playlist inside it so you won't be messed up ;)\n\n   And finnaly it is added to the path so you can start it by the CMD (Command Prompt)\n   with the command mytinstall\n------------------------------------------------------------------------------------------";

char* readmeFeedBis =" Press 'Enter' to go back : ";
//

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

//Utilities variables
int choice;
int otherChoice;
char ytlink[100];
char cmd[200];
char playlistName[10];
char cPATH[500];
int sBrowser;
//

int main(){

//Usefull variables but not constant this time
char * USER = getenv("USER");
//

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
choice = 0;
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
		system("notify-send 'Mytinstall' 'The music as been installed'");
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
		system("notify-send 'Mytinstall' 'The playlist as been installed'");
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
		system("notify-send 'Mytinstall' 'The music as been installed in your path'");
		cls();
		break;

//Browser option
		case 4:
		cls();
		printf("%s\n\n%s\n\n%s", ascii, browser, browserFeed);
		scanf("%lc", &sBrowser);
		switch((char)sBrowser){

			case 'b':
			system("/usr/bin/brave-browser https://music.youtube.com/ ");
			goto MENU;
			break;

			case 'f':
			system("firefox https://music.youtube.com/ ");
			goto MENU;
			break;

		}
		break;

		case 5:
		OTHER:
		cls();
		printf("%s\n\n%s\n\n%s\n%s", ascii, other,otherFeed,menuQuestion);
		scanf("%d", &otherChoice);
		switch(otherChoice){

			case 6:
			cls();
			printf(" Not yet available!\n");
			printf("\n%s", readmeFeedBis);
			int f = getchar();
			getchar();
			goto OTHER;
			break;

			case 7:
			cls();
			printf(" Not yet available!\n");
			printf("\n%s", readmeFeedBis);
			int u = getchar();
			getchar();
			goto OTHER;
			break;

	//README option
			case 8:
			cls();
			printf("%s\n\n%s\n\n%s", ascii, readme, readmeFeed);
			printf("\n%s", readmeFeedBis);
			int c = getchar();
			getchar();
			goto OTHER;
			break;

			case 9:
			goto MENU;
			break;






		}
		


		default:
		printf("ERROR             [Only use numbers and no other charachters] \n");
		cRESET();
		choice = 0;
		break;
	}} while (choice > 0);

	cRESET();
	return 0;
}

