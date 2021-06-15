:menu
mode con:cols=113 lines=20
echo off
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                                   (Menu) 
echo _______________________________________________________________________________________________________________
color B        
echo 1: Simple Download                   [Download tracks one by one] & echo.2: Playlist Download                 [Download entier Playlist] & echo.3: Custom Download                   [Download tracks in the choosed folder] & echo.4: Youtube-Music reserach            [Reseach Music on Youtube-Music] & echo.5: Other                             [The rest of the menu]
echo.
echo Select the option number: 
choice /c 12345 /n
if errorlevel 5 goto autre
if errorlevel 4 goto mytinstall-s
if errorlevel 3 goto mytinstall-c
if errorlevel 2 goto mytinstall-p
if errorlevel 1 goto mytinstall-n



:autre
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                                   (Autre)
echo _______________________________________________________________________________________________________________
color B     
echo 1: Gaming-Menu                       [A menu with Gamer features] & echo.2: Option                            [Readme!, Licence, Uninstall] & echo.3: Menu                              [Go back to main menu]
echo.
echo Select the option number: 
choice /c 123 /n
if errorlevel 3 goto menu 
if errorlevel 2 goto option-menu
if errorlevel 1 goto mytinstall-gamingmenu

:option-menu
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                                   (Autre)
echo _______________________________________________________________________________________________________________
echo 1: README!                           [To read for not being surprised] & echo 2: Licence                           [Who made this tool ?] & echo 3: Uninstall                         [Uninstall mytinstall] & echo 4: Menu                              [Go back to main menu]
echo.
echo Select the option number:
choice /c 1234 /n
if errorlevel 4 goto menu
if errorlevel 3 goto mytinstall-uninstall
if errorlevel 2 goto mytinstall-licence
if errorlevel 1 goto mytinstall-readme!


:mytinstall-n
cls
if exist C:\Users\%UserProfile%\Music\mytinstall.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music 
mkdir mytinstall
)
if exist C:\Users\%UserProfile%\Music\mytinstall\Music.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music
cd mytinstall
mkdir Music
)
cd /
cd %UserProfile%\Music\mytinstall\Music
cls
:loop-mytinstall-n
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                            (Simple Download)
echo _______________________________________________________________________________________________________________
echo.
echo Paste the link of the chosen Music:
set /p lien=
youtube-dl -o "%%(title)s.%%(ext)s" --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata %lien%
cls
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, 'Mytinstall', 'The Music has been downloaded !', [System.Windows.Forms.ToolTipIcon]::None)}"
goto loop-mytinstall-n
exit



:mytinstall-p
cls
if exist C:\Users\%UserProfile%\Music\mytinstall.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music 
mkdir mytinstall
)
if exist C:\Users\%UserProfile%\Music\mytinstall\Playlist.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music
cd mytinstall
mkdir Playlist
)
cd /
cd %UserProfile%\Music\mytinstall\Playlist
cls
echo Which name would you give to this playlist ?:
set /p nomdeplaylist=
mkdir "%nomdeplaylist%"
cd "%nomdeplaylist%"
cls
:loop-mytinstall-p
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                            (Playlist Download)
echo _______________________________________________________________________________________________________________
echo.
echo Paste the link of the chosen Playlist:
set /p lien=
youtube-dl -o "%%(title)s.%%(ext)s" --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --yes-playlist -i %lien%
cls
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, 'Mytinstall', 'The Playlist has been downloaded !', [System.Windows.Forms.ToolTipIcon]::None)}"
goto loop-mytinstall-p
exit


:mytinstall-s
echo off 
set error=It seems that this Navigator is not installed. If this is the case, check to have written it in lowercase!
color B
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                          (Youtube-Music Launcher)
echo _______________________________________________________________________________________________________________
echo.
set url="https://music.youtube.com/"
echo Which browser would you choose ? (chrome/firefox/iexplorer/edge):
set /p browser=
if %browser%== menu (goto menu)
if %browser%==chrome (start chrome %url% || if %errorlevel% == 0 cls && echo %error% && pause && goto mytinstall-s)
if %browser%==firefox (start firefox.exe %url% || if %errorlevel% == 0 cls && echo %error% && pause && goto mytinstall-s)
if %browser%==iexplorer (start iexplore.exe %url% || if %errorlevel% == 0 cls && echo %error% && pause && goto mytinstall-s)
if %browser%==edge (start msedge %url% || if %errorlevel% == 0 cls && echo %error% && pause && goto mytinstall-s)
goto menu
exit



:mytinstall-c 
color B
echo off
cls
echo Choose the folder where the tracks will be downloaded...
setlocal
set "psCommand="(new-object -COM 'Shell.Application')^
.BrowseForFolder(0,'Please choose a folder.',0,0).self.path""
for /f "usebackq delims=" %%I in (`powershell %psCommand%`) do set "folder=%%I" 
:loop-mytinstall-c
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                            (Custom Download)
echo _______________________________________________________________________________________________________________
echo.
echo Paste the link of the chosen Music:
cd %folder%
set /p lien=
youtube-dl -o "%%(title)s.%%(ext)s" --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata %lien%
cls
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, 'Mytinstall', 'The Music has been downloaded !', [System.Windows.Forms.ToolTipIcon]::None)}"
goto loop-mytinstall-c

exit

:mytinstall-licence
@echo off
color B
cls
echo KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKXKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK0KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKOdl:,'''''',,,;cok0KKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKKKKKKK0d;.                .,o0KKKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKKKKKOc.    ...'',,,,,,''..   ;OKKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKKKOl.   .',,;;;;;;;;;;;;,,'.  ;OKKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKK0c     .........'',,;;;;;;,.  :0KKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKKx;.                 ..,;;;;;.  .oKKKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKOc. .,coxkkOOOkddo:...  .';;,;,.  ;0KKKKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKO; .;xKWWWMWWWNX0O0Ol,'.  .,;;;,.  'x00KKKKKKKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKK0c  :O0000000O0O0O0Od:''.  .';;;,.   ..',:lx0KKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKK0,  'loddddxxxxxxdol;,,,.  .,;;;,'.   ...  .l0KKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKK0c   .'',,,,,,,,,,,,,''.   .,;;;,'.  .,;,'  .kXKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKO:.   ....'','''''...   ..,;;;;,..  .',,'.  lKKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKK0;         ....      ..',;;;;,'..   .....  :0KKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKc  .''..........'',,,;;;;;;;,'..   .....  ,OKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKK:  .;;,;;;;;;;;;;;;;;,,;;;;;,...   .....  'kKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKK0:  .,;;;;;;;;;;;;;;;;;;;;;;,'...   .....  .xKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKK0:  .';;;;;;;;;;;;;;,;;;;;;;'....   .....  .dKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKK:  ..,;,;;,;;;;;;;;;;;;;;;'.....   .....  .dKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKc  ..'',;;;;;;;;;;;;;;;;,'......   .....  .dKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKl   ....',,,,,,,,,,,,,''........   .....  'kKKKKKKKKKKKKKKK
echo KKKKKKKKKKKKKKKKKKKKKd.  ............................   .....  :0KKKKKKKKKKKKKKK
echo Mytinstall
echo.
echo Made by Sean.64
echo.
echo Based on "Youtube-Dl" and "ffmpeg"
set/p<nul =&pause>nul
goto menu
exit 

:mytinstall-readme!
echo off
color b
cls
echo   -----------------------------Only compatible with windows !----------------------------
echo.
echo   This tool is principaly made of Youtube-dl and ffmpeg.
echo   So the respect for this project should belong to the creators of these.
echo.
echo   As a consequence the supported website link are:
echo   - youtube.com
echo   - music.youtube.com
echo   - and other compatible links with youtube-dl... 
echo     (to find on https://ytdl-org.github.io/youtube-dl/supportedsites.html )
echo.
echo   It is open source so you can modify it.
echo   It is stored in C:\Program Files\mytinstall-files on your windows pc
echo.
echo   The tracks downloaded are stored in C:\Users\#your-username#\Music\mytinstall
echo   There are different folders like Music or Playlist inside it so you won't be messed up ;)
echo.
echo   And finnaly it is added to the path so you can start it by the CMD (Command Prompt)
echo   with the command "mytinstall"
echo.
set/p<nul =&pause>nul
goto menu

:mytinstall-gamingmenu
cls
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                                 (Gaming-Menu)
echo _______________________________________________________________________________________________________________
color B     
echo 1: GTA5 sync                         [Sync your Music folder to the CustomRadio in GTA5] & echo.2: SoundBoard                        [Create a Soundboard just to troll ;)] & echo.3: Menu                              [Go back to main menu]
echo.
echo Inserez le chiffre de l'action souhaite: 
choice /c 123 /n
if errorlevel 3 goto menu
if errorlevel 2 goto mytinstall-sdbd
if errorlevel 1 goto mytinstall-gta5sync




:mytinstall-sdbd
color B
if exist C:\Users\%UserProfile%\Music\mytinstall.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music 
mkdir mytinstall
)
if exist C:\Users\%UserProfile%\Music\mytinstall\SoundBoard.ext (echo  ) else (
cd Users
cd %UserProfile%
cd Music
cd mytinstall
mkdir SoundBoard
)
cd /
cd %UserProfile%\Music\mytinstall\SoundBoard
cls
echo off
:loop-mytinstall-sdbd
echo ::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       
echo +:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       
echo +:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       
echo +#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       
echo +#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       
echo #+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       
echo ###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########
echo                                               (SoundBoard)
echo _______________________________________________________________________________________________________________
echo.
echo Paste the link of the chosen art-piece:
set /p lien=
youtube-dl -o "%%(title)s.%%(ext)s" --format bestaudio --extract-audio --audio-format mp3 --audio-quality 0 --add-metadata --yes-playlist -i %lien%
cls
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, 'Mytinstall', 'The Sound has been downloaded !', [System.Windows.Forms.ToolTipIcon]::None)}"
goto loop-mytinstall-sdbd


:mytinstall-gta5sync
echo off
cls
color B
cd %userprofile%\Music\mytinstall
copy "Music" "%userprofile%\Documents\Rockstar Games\GTA V\User Music"
powershell -Command "& {Add-Type -AssemblyName System.Windows.Forms; Add-Type -AssemblyName System.Drawing; $notify = New-Object System.Windows.Forms.NotifyIcon; $notify.Icon = [System.Drawing.SystemIcons]::Information; $notify.Visible = $true; $notify.ShowBalloonTip(0, 'Mytinstall', 'GTA5 custom radio has been synced !', [System.Windows.Forms.ToolTipIcon]::None)}"
goto menu

:mytinstall-uninstall
mytinstall-uninstall
