#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <io.h>

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

char* browserFeed =" Input the choosen browser first letter (b-Brave or f-Firefox or c-chrome or e-edge) : ";

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
	system("cls");
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
//char sBrowser = 0;
//

int main()
{
//Usefull variables but not constant this time
    char * USER = getenv("userprofile");

//Directory initialization
    char wPATH[100] = "%s\\Music";
    char  PATH[100];
    sprintf(PATH, wPATH, USER);
    const char* folder;
    folder = PATH;
    struct stat sb;
    if (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
    } else {
        _mkdir(PATH);
    }

    strcpy(wPATH, "%s\\Music\\mytinstall");
    sprintf(PATH, wPATH, USER);
    folder = PATH;
    //struct stat sb;
    if (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
    } else {
        _mkdir(PATH);
    }

    strcpy(wPATH, "%s\\Music\\mytinstall\\Music");
    sprintf(PATH, wPATH, USER);
    folder = PATH;
    //struct stat sb;
    if (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
    } else {
        _mkdir(PATH);
    }

    strcpy(wPATH, "%s\\Music\\mytinstall\\Playlist");
    sprintf(PATH, wPATH, USER);
    folder = PATH;
    //struct stat sb;
    if (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
    } else {
        _mkdir(PATH);
    }
// end of directory initialization


    //Base working interface for downloading
MENU:
cls();
cCYAN();
choice = 0;
printf("%s\n\n%s\n\n%s\n%s", ascii, menu,menuFeed,menuQuestion);
scanf("%d", &choice);
	switch(choice){
		case 0:
		goto MENU;
		break;

//Music option
		case 1:
		cls();
		strcpy(wPATH, "%s\\Music\\mytinstall\\Music");
		sprintf(PATH, wPATH, USER);
		_chdir(PATH);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, music, musicFeed);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-quality 0 --add-metadata --xattrs --embed-thumbnail --audio-format mp3 ");
		strcat(cmd, ytlink);
		system(cmd);
		//system("notify-send 'Mytinstall' 'The music as been installed'");
        goto MENU;
		break;

//Playlist option
		case 2:
		strcpy(wPATH, "%s\\Music\\mytinstall\\Playlist");
		sprintf(PATH, wPATH, USER);
		_chdir(PATH);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, playlist, playlistFeed);
		scanf("%s", playlistName);
        if (stat(playlistName, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
        } else {
        _mkdir(playlistName);
        }	
		_chdir(playlistName);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, playlist, playlistFeedBis);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		//system("notify-send 'Mytinstall' 'The playlist as been installed'");
		cls();
        goto MENU;
		break;

//Custom option
		case 3:
	    cls();
		printf("%s\n\n%s\n\n%s", ascii, custom, customFeed);
		scanf("%s", cPATH);
        if (stat(cPATH, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //printf("YES\n");
        } else {
        _mkdir(cPATH);
        }	
		_chdir(cPATH);
		cls();
		printf("%s\n\n%s\n\n%s", ascii, custom, customFeedBis);
		scanf("%s", ytlink);
		strcpy(cmd, "youtube-dl -q -o '%(title)s.%(ext)s' --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --embed-thumbnail ");
		strcat(cmd, ytlink);
		system(cmd);
		//system("notify-send 'Mytinstall' 'The music as been installed in your path'");
		cls();
        goto MENU;
		break;     

        case 4:
		cls();
		printf("%s\n\n%s\n\n%s", ascii, browser, browserFeed);
        char sBrowser = 0;
		scanf(" %c", &sBrowser);
		switch(sBrowser){

			case 'b':
			system("start brave https://music.youtube.com/ ");
            goto MENU;
			break;
        
			case 'f':
			system("start firefox.exe https://music.youtube.com/ ");
            goto MENU;
			break;   

            case 'c':
			system("start chrome https://music.youtube.com/ ");
            goto MENU;
			break;

            case 'e':
			system("start msedge https://music.youtube.com/ ");
            goto MENU;
			break;
        }


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
		break;

    }
 

    return 0;
}