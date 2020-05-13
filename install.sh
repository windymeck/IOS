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
mkdir Game/Home/NorthernMeadow/EasternMountains
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/Staircase
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/SmallHole
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber

mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/Marketplace
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/Library
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/ArtisanShop
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/House
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls
mkdir Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DankRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide
#folder permissions
chmod 444 Game/Home/NorthernMeadow

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

