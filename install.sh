#!/bin/bash

#create the game folders
echo "Creating game folders..."

mkdir Game
mkdir Game/Home
mkdir Game/Home/WesternForest
mkdir Game/Home/NorthernMeadow
mkdir Game/Home/WesternForest/SpellCastingAcademy
mkdir Game/Home/WesternForest/SpellCastingAcademy/Lessons
mkdir Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
mkdir Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom/Box
mkdir Game/Home/NorthernMeadow/EasternMountains
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/Staircase
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/SmallHole
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber

mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Marketplace
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/ArtisanShop
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/House
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/Paradise
#copy files to the folders
cp Code/explanations/WelcomeLetter Game/Home
cp Code/explanations/BackSign Game/Home/WesternForest
cp Code/explanations/Sign Game/Home/WesternForest
cp Code/explanations/HurryingStudent Game/Home/WesternForest/SpellCastingAcademy
cp Code/explanations/Instructions Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy1 Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy2 Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy3 Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy4 Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy5 Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/Professor Game/Home/WesternForest/SpellCastingAcademy/Lessons
cp Code/explanations/Pony Game/Home/NorthernMeadow/
cp Code/explanations/OldMan Game/Home/NorthernMeadow/EasternMountains
cp Code/explanations/OldManuscrips Game/Home/NorthernMeadow/EasternMountains 
cp Code/explanations/Sing2 Game/Home/NorthernMeadow/EasternMountains/Cave/Staircase/Sign
cp Code/explanations/Boulder Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom
cp Code/explanations/Rat Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel
cp Code/explanations/RandomCitizen1 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare
cp Code/explanations/RandomCitizen2 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare
cp Code/explanations/DistraughtLady Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare
cp Code/explanations/Vendor Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Marketplace
cp Code/explanations/rmSpell Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Marketplace 
cp Code/explanations/HistoryOfTerminus Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library 
cp Code/explanations/TotallyRadSpellbook Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library
cp Code/explanations/PaperbackRomance Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library
cp Code/explanations/InconspicuousLever Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library
cp Code/explanations/Grep Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
cp Code/explanations/Librarian Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
cp Code/explanations/PracticeBook Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
cp Code/explanations/LargeBoulder Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/
cp Code/explanations/EarOfCorn Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm
cp Code/explanations/Farmer Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm
cp Code/explanations/StrangeTrinket Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/ArtisanShop
cp Code/explanations/ClockworkDragon Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/ArtisanShop
cp Code/explanations/ThornyBrambles Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath
cp Code/explanations/UglyTroll Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls
cp Code/explanations/UglierTroll Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls
cp Code/explanations/AbsolutelyHideousTroll Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls
cp Code/explanations/Instructions2 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles
cp Code/explanations/A_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/B_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/C_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/D_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/F_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/G_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/H_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/I_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/J_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
cp Code/explanations/K_txt Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/MoreKernelFiles
#folder permissions
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/Paradise
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls  
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing  
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
chmod 444 Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel
chmod 444 Game/Home/NorthernMeadow



echo -ne '#####                     (33%)\r'
sleep 1
echo -ne '#############             (66%)\r'
sleep 1
echo -ne '#######################   (100%)\r'
echo -ne '\n'

echo "Game folders created succesfully."
#compile and create executables
echo ""
echo "Compiling code..."

mkdir Commands
gcc Code/myshell.c -o shell -w
gcc Code/shellServer.c -o server -w
gcc Code/less.c -o Commands/less -w
gcc Code/cp2.c -o Commands/cp -w
gcc Code/grep.c -o Commands/grep -w
gcc Code/man.c -o Commands/man -w
gcc Code/pwd.c -o Commands/pwd -w
gcc Code/touch.c -o Commands/touch -w
gcc Code/rm.c -o Commands/rm -w
gcc Code/mv.c -o Commands/mv -w
gcc Code/ls.c -o Commands/ls -w
gcc Code/sudo.c -o Commands/sudo -w

echo -ne '#####                     (33%)\r'
sleep 1
echo -ne '#############             (66%)\r'
sleep 1
echo -ne '#######################   (100%)\r'
echo -ne '\n'
echo "Code compiled successfully."
echo ""

echo "Copying man files..."
mkdir Commands/manfolder

cp Code/manpages/cd Commands/manfolder/
cp Code/manpages/cp Commands/manfolder/
cp Code/manpages/ls Commands/manfolder/
cp Code/manpages/less Commands/manfolder/
cp Code/manpages/touch Commands/manfolder/
cp Code/manpages/grep Commands/manfolder/
cp Code/manpages/man Commands/manfolder/
cp Code/manpages/pwd Commands/manfolder/
cp Code/manpages/mv Commands/manfolder/
cp Code/manpages/sudo Commands/manfolder/

echo -ne '#####                     (33%)\r'
sleep 1
echo -ne '#############             (66%)\r'
sleep 1
echo -ne '#######################   (100%)\r'
echo -ne '\n'

echo "done! :)"
read -p 'do you want to start playing?[y/n]' input
if [ $input != "y" ];
then 
	echo "bye!!"
	exit
else 
	echo "loading game..."
	./shell
fi
echo "To enter the game execute write './shell' and hit enter."
