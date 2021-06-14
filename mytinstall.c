#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


//This function is to clear the current terminal
int cls(){
	printf("\e[1;1H\e[2J");
}


//The main ascii art of mytinstall
char* ascii = "::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       \n+:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       \n+:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       \n+#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       \n+#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       \n#+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       \n###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########";


int main(){
// Initialising basic directories
//
// 
struct stat st = {0};

if(stat("/home/sean64/Musique/mytinstall", &st) == -1) {
    mkdir("/home/sean64/Musique/mytinstall", 0700);
}
if(stat("/home/sean64/Musique/mytinstall/Music", &st) == -1) {
    mkdir("/home/sean64/Musique/mytinstall/Music", 0700);
}
if(stat("/home/sean64/Musique/mytinstall/Playlist", &st) == -1) {
    mkdir("/home/sean64/Musique/mytinstall/Playlist", 0700);
}
if(stat("/home/sean64/Musique/mytinstall/SoundBoard", &st) == -1) {
    mkdir("/home/sean64/Musique/mytinstall/SoundBoard", 0700);
}
// End of initialisation
//MENU:

char* menu = "                                                   (Menu) \n_______________________________________________________________________________________________________________";

char* feed = "1: Simple Download                   [Download tracks one by one]\n2: Playlist Download                 [Download entier Playlist]\n3: Custom Download                   [Download tracks in the choosed folder]\n4: Youtube-Music reserach            [Reseach Music on Youtube-Music]\n5: Other                             [The rest of the menu]"; 

cls();
printf("%s\n%s\n\n%s\n", ascii, menu,feed);


}
