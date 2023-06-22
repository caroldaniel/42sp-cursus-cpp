#!/bin/bash

red='\033[31m'
green='\033[32m'
reset='\033[0m'

# Tests ex00

echo ./megaphone \"shhhhh... I think the students are asleep...\"
result=$(./megaphone "shhhhh... I think the students are asleep...")
if [ "$result" = "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." ]
then
	echo -e "${green}OK${reset}"
else
	echo -e "${red}KO${reset}"
fi

echo ./megaphone Damnit \" ! \" \"Sorry students, I thought this thing was off.\"
result=$(./megaphone Damnit " ! " "Sorry students, I thought this thing was off.")
if [ "$result" = "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." ]
then
	echo -e "${green}OK${reset}"
else
	echo -e "${red}KO${reset}"
fi

echo ./megaphone
result=$(./megaphone)
if [ "$result" = "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ]
then
	echo -e "${green}OK${reset}"
else
	echo -e "${red}KO${reset}"
fi