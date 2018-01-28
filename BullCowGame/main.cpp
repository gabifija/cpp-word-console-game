/*
	This is the console executable, that makes use of The BullCow class
	This acts as the view in a MVC pattern, and is responsible for all
	user interaction. For game logic see the FBullCowGame class.
*/

#include "stdafx.h"
#include "BullCowGame.h"
#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	constexpr int32 WORLD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

}


FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}