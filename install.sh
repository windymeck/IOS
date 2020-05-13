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

cp Code/explanations/WelcomeLetter.txt Game/Home
cp Code/explanations/BackSign.txt Game/Home/WesternForest
cp Code/explanations/Sign.txt Game/Home/WesternForest
cp Code/explanations/HurryingStudent.txt Game/Home/WesternForest/SpellCastingAcademy
cp Code/explanations/Instructions.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy1.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy2.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy3.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy4.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/PracticeDummy5.txt Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom
cp Code/explanations/Professor.txt Game/Home/WesternForest/SpellCastingAcademy/Lessons

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

