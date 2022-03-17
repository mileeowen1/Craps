/*
Name: Milee Owen
Class: CPSC 121, Spring 2019
Date: February 19, 2019
Programming Assignment: PA4
Description: Create a program to play the dice game "Craps" using nested loops.
*/
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	// assign variables with data types
	char userPick;
	double bankBalance = 0;
	double initialBalance = 0;
	double wager = 0;
	double sumWager = 0;
	int diceRoll1 = 0;
	int diceRoll2 = 0;
	int sumDiceRoll1 = 0;
	int sumDiceRoll2 = 0;
	int numRolls = 0;
	int gameWins = 0;
	int gameLoses = 0;
	string temp;
	bool noMoney = false;
	// explain the rules of the game
	cout << "Let's play a game called ""Craps""! "<< endl << "The rules are simple!" << endl << "1. A player (you) will have an initial bank balance of choice." << endl << "2. You will place an initial wager." << endl << "3. You will roll two dice." << endl << "4. Each die has six faces." << endl << "5. These faces contain 1, 2, 3, 4, 5, and 6 spots." << endl << "6. After the dice have come to rest, the sum of the spots on the two upward faces is calculated." << endl << "7. If the sum is 7 or 11 on the first throw, you win." << endl << "8. If the sum is 2, 3, or 12 on the first throw, you lose." << endl << "9. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes your ""point.""" << endl << "10. After each roll, you can place another wager that will be added to your initial." << endl << "11. To win, you must continue rolling the dice until you ""make your point.""" << endl << "12. If you roll a 7 before making the point, you lose the game." << endl << endl;
	// prompt player if he wants to play or not
	cout << "Do you want to play a game of Craps? y/n: ";
	cin >> userPick;
	// prompt player for initial balance if he chooses to play and make sure input is valid
	if (userPick == 'y' && noMoney == false) {
		cout << "\nWhat is your initial bank balance: $";
		cin >> bankBalance;
		while (bankBalance <= 0) {
			cout << "You cannot play without any money." << endl << "Please enter a positive inital bank balance number: $";
			cin >> bankBalance;
		}
	}
	else {
		cout << "\nSee you next time:)" << endl;
	}
	initialBalance = bankBalance;
	// seed random generator
	srand(time(0));
	// game begins
	while (userPick == 'y' && noMoney == false) {
		if (bankBalance <= 0) {
			cout << "You got no more money to loose and cannot continue playing! Come back again when you've become rich!" << endl;
			return 0;
		}
		else if (bankBalance >= initialBalance * 4) {
			cout << "Right on! You've got more than you brought!" << endl;
		}
		else if (bankBalance <= initialBalance / 4) {
			cout << "Luck is not on your side:( Play at your own risk. Who knows? Maybe the tables with turn in your favor." << endl;
		}
		// outputs how much money you have and prompts player to enter a wager
		cout << "\nCurrent bank balance: $" << bankBalance << endl;
		cout << "Please enter your initial wager: $";
		cin >> wager;
		// makes sure player doesn't bet nothing or more than they have
		while (wager > bankBalance || wager <= 0) {
			cout << "That is not a valid wager." << endl << "Please enter your initial wager: $";
			cin >> wager;
		}	
		// sums up the amount of money player wages and subtracts wager from bank account
		sumWager += wager;
		bankBalance -= wager;
		// random dice rolls and sums it up
		diceRoll1 = rand() % 6 + 1;
		diceRoll2 = rand() % 6 + 1;
		numRolls++;
		sumDiceRoll1 = diceRoll1 + diceRoll2;
		cout << "Sum: " << sumDiceRoll1 << " (Die1: " << diceRoll1 << "; Die2: " << diceRoll2 << ")" << endl;
		// first sum wins
		if (sumDiceRoll1 == 7 || sumDiceRoll1 == 11) {
			numRolls = 0;
			if (gameWins == 5) {
				cout << "You're on fire!" << endl << endl;
			}
			else {
				cout << "Booyeahhh! Winnah winnah chicken dinnah!" << endl << endl;
			}
			gameWins++;
			bankBalance += sumWager * 2;
			cout << "Current bank balance: $" << bankBalance << endl;
			sumDiceRoll1 = 0;
			sumWager = 0;
			cout << "Would you like to play another round? y/n: ";
			cin >> userPick;
				if (userPick == 'n') {
					cout << "Looks like you're not the 'risk it all' type." << endl;
				}
		}
		// first sum loses
		else if (sumDiceRoll1 == 2 || sumDiceRoll1 == 3 || sumDiceRoll1 == 12) {
			numRolls = 0;
			if (gameLoses == 5) {
				cout << "You're going out in flames." << endl << endl;
			}
			else {
				cout << "Ooofff. Sorry, you lost." << endl << endl;
			}
			gameLoses++;
			cout << "Current bank balance: $" << bankBalance << endl; 
			sumDiceRoll1 = 0;
			sumWager = 0;
			cout << "Would you like to play another round? y/n: ";
			cin >> userPick;
				if (userPick == 'n') {
					cout << "Looks like you're not the 'risk it all' type." << endl;
				}
		}
		// make your point
		else {
			cout << "You need to roll to make your point (" << sumDiceRoll1 << ")..." << endl;
			getline(cin, temp);
			cout << "Press enter to continue." << endl << endl;
			getline(cin, temp);
			while (userPick == 'y' && noMoney == false) {
				cout << "Total wager so far: $" << sumWager << endl;
				cout << "Available bank balance: $" << bankBalance << endl;
				cout << "Please enter your wager: $";
				cin >> wager;
				while (wager > bankBalance) {
					cout << "That is not a valid wager." << endl << endl;
					cout << "Total wager so far: $" << sumWager << endl;
					cout << "Available bank balance: $" << bankBalance << endl;
					cout << "Please enter your wager: $";
					cin >> wager;
				}
				// sums sequential wagers and subtracts from balance
				sumWager += wager;
				bankBalance -= wager;
				// sequential rolls
				diceRoll1 = rand() % 6 + 1;
				diceRoll2 = rand() % 6 + 1;
				numRolls++;
				sumDiceRoll2 = diceRoll1 + diceRoll2;
				if (numRolls == 7) {
					cout << "Come on roll lucky number seven!" << endl;
				}
				else if (numRolls > 7) {
					cout << "Any moment now!" << endl;
				}
				cout << "Sum: " << sumDiceRoll2 << " (Die1: " << diceRoll1 << "; Die2: " << diceRoll2 << ")" << endl;
				// sequential roll wins
				if (sumDiceRoll2 == sumDiceRoll1) {
				numRolls = 0;
					cout << "Congrats, you made your point (" << sumDiceRoll1 << ")!" << endl;
					getline(cin, temp);
					cout << "Press enter to continue." << endl << endl;
					getline(cin, temp);
					bankBalance += sumWager * 2;
					cout << "Current bank balance: $" << bankBalance << endl;
					sumDiceRoll1 = 0;
					sumDiceRoll2 = 0;
					sumWager = 0;
					cout << "Would you like to play another round? y/n: ";
					cin >> userPick;
						if (userPick == 'n') {
							cout << "Looks like you're not the 'risk it all' type." << endl;
						}
					break;
				}
				// sequential roll loses
				else if (sumDiceRoll2 == 7) {
				numRolls = 0;
					cout << "Shucks, you lose. Better luck next time!" << endl << endl;
					cout << "Current bank balance: $" << bankBalance << endl; 
					sumDiceRoll1 = 0;
					sumDiceRoll2 = 0;
					sumWager = 0;
					cout << "Would you like to play another round? y/n: ";
					cin >> userPick;
						if (userPick == 'n') {
							cout << "Looks like you're not the 'risk it all' type." << endl;
						}
					break;
				}
				// keep rolling til point is made
				else {
					cout << "You need to keep rolling to make your point (" << sumDiceRoll1 << ")." << endl;
					getline(cin, temp);
					cout << "Press enter to continue." << endl << endl;
					getline(cin, temp);
				}
			}
		}
	}
	return 0;	
}
