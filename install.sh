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
mkdir Game/Home/NorthernMeadow/Cave
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
gcc Code/less.c -o Commands/less -w
gcc Code/cp.c -o Commands/cp -w
gcc Code/grep.c -o Commands/grep -w
gcc Code/man.c -o Commands/man -w
gcc Code/pwd.c -o Commands/pwd -w
gcc Code/touch.c -o Commands/touch -w

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

cp Code/cd Commands/manfolder/
cp Code/cp Commands/manfolder/
cp Code/ls Commands/manfolder/
cp Code/less Commands/manfolder/
cp Code/touch Commands/manfolder/
cp Code/grep Commands/manfolder/
cp Code/man Commands/manfolder/
cp Code/pwd Commands/manfolder/

echo -ne '#####                     (33%)\r'
sleep 1
echo -ne '#############             (66%)\r'
sleep 1
echo -ne '#######################   (100%)\r'
echo -ne '\n'

echo "done! :)"
echo "To enter the game execute write './shell' and hit enter."

