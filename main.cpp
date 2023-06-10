/*
 * File:   main.cpp
 * Author: Haylee Ferguson
 * Created on
 * Purpose: Game of Cards: Higher or Lower V6
*/

//System Libraries 
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

string  getCard(int& cardVal, string& suit);

int main(int argc, char** argv) {
	// Set Random Number seed

	//Declare Variables
	char x, answer, guess1 = 0, guess2 = 0, choice; // Diamonds, Spades, Clubs, and Hearts
	int  bet1, bet2, cardVal, pCard = 0, suitI; //Card value 1-13, including King, Queen, and Jack **comparing face value
	bool drawCard, vBet;
	string suits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
	string pSuit, suit, card, name1, name2;
	float balance1, balance2, player;

	// Initialize Inputs 

		cout<<setw(15)<<right<<"Welcome!"<<endl;
		cout<<"Let's play a card game!"<<endl<<endl;                    //Beginning of game 
		cout<<"************************"<<endl;
		cout<<setw(20)<<right<<"HIGHER OR LOWER!"<<endl;
		cout<<"************************"<<endl<<endl;



		bool readRules = true;
		for (int i = 0; i < 1 && readRules; i++) {
			cout<<"Do you want to read the rules? (y/n) "<<endl;
			cin>>choice;

			if (choice == 'y' || choice == 'Y') {
				ifstream file("Rules.txt");                             //Open the "Rules.txt" file for reading

				if (!file) {
					cout << "Failed to open file.\n";
					return 1;
				}

				                                                         // Read and output the rules from the file
				string line;
				while (getline(file, line)) {
					cout << line << endl;
				}

				file.close();                                          //Close the file after reading
				readRules = false;                                     //Set the flag to false to exit the loop
			}
			else if (choice == 'n' || choice == 'N') {
				readRules = false;                                     //false to exits the loop
			}
			else {
				cout << "Invalid choice. Please enter 'y' or 'n'.\n";
			}
		}


		cout<<"\nLet's play!"<<endl<<endl;
		//cout<<"How many players would you like to start with? Enter 'O' for one or 'T' for two."<<endl;
		//cin>>player;
		//if (player == 'O' || player == 'o') 
			//cout<<"Single player slected! Let's continue!"<<endl;
		/*if (player == 'T' || player == 't') {
				cout<<"Two players selected! Let's continue!"<<endl;
				cout<<"Player one, what is your name?"<<endl;
				cin>>name1;
				cout<<"Player two, what is your name?"<<endl;
				cin>>name2; 
				cout<<name1<<" , how much money would you like to start with?"<<endl;
				cin>>balance1;
				cout<<name2<<" , how much money would you like to start with?"<<endl;
				cin>>balance2;
				cout<<"Enter 'S' to start!";
				cin>>x;
				if (x == 's' || x == 'S')
					cout<<"\n\nLet's begin!"<<endl<<endl;*/
		
		
		
		
		cout<<"What is your name?"<<endl;
		cin>>name1;
		cout<<"How much money would you like to start with, "<<name1<<"?"<<endl;
		cin>>balance1;
		cout<<"Enter 'S' to start!";
		cin>>x;
		if (x == 's' || x == 'S')
			cout<<"\n\nLet's begin!"<<endl<<endl;

		do {
			
			cout<<"Your current balance is $"<<balance1<<endl;
			cout<<"How much would you like to bet, "<<name1<<"?"<<endl;
			cin>>bet1;

			if (bet1 > balance1) {
				cout<<"I'm sorry "<<name1<<" you don't have enough to place that bet."<<endl;
				cout<<"Please place a new bet."<<endl;
				continue;
			}

			/*srand(time(0));          //random card and suit 
			suitI = rand() % 4;
			suit = suits[suitI];
			cardVal = rand() % 13 + 2;


			if (cardVal >= 2 && cardVal <= 10) {
				card = to_string(cardVal);
			}
			else {
				switch (cardVal) {
				case 11:
					card = "Jack";                  //Cards and their values
					break;
				case 12:
					card = "Queen";
					break;
				case 13:
					card = "King";
					break;
				case 14:
					card = "Ace";
					break;
				}
			}*/
			
			

			cout<<"You drew the "<<card<<" of "<<suit<<"."<<endl;
			cout<<"Will the next card be higher (H) or lower (L)?"<<endl;
			cin>>guess1;
			cout<<endl;

			srand(time(0));          //random card and suit 
			suitI = rand() % 4;
			suit = suits[suitI];
			pCard = rand() % 13 + 2;


			if (pCard >= 2 && pCard <= 10) {
				card = to_string(pCard);
			}
			else {
				switch (pCard) {
				case 11:
					card = "Jack";                  //Cards and their values
					break;
				case 12:
					card = "Queen";
					break;
				case 13:
					card = "King";
					break;
				case 14:
					card = "Ace";
					break;
				}
			}

			cout<<"The next card is the "<<card<<" of "<<suit<<"."<<endl<<endl;

			if ((guess1 == 'H' || guess1 == 'h' && cardVal < pCard) ||
				(guess1 == 'L' || guess1 == 'l' && cardVal > pCard)) {
				cout << "Congratulations, "<<name1<<"! You guessed correctly!"<<endl<<endl;
				balance1 += bet1;
				cout<<"Would you like to continue playing? (y/n)"<<endl;
				cin>>choice;
			}
			else {
				cout<<"Sorry, "<<name1<<", you guessed incorrectly."<<endl<<endl;
				balance1 -= bet1;                                                     //Lose bet amount from balance if guessed incorrectly 
				cout<<"Would you like to continue playing? (y/n)"<<endl;
				cin>>choice;
			}

			if (balance1 <= 0)
			{
				cout<<"Sorry, "<<name1<<" You've run out of funds! Game over! Thanks for playing :)"<<endl;
                                exit (0);
			}
			
		} while (balance1 > 0 && choice == 'Y' || choice == 'y');
		



	ofstream outputFile("PlayerData.txt");                                  //Open a new file for writing

	if (!outputFile) {
		cout<<"Failed to create file.\n";
		return 1;
	}

	// Write player's name and money to the file
	outputFile<<"Player: "<<name1<<endl;
	outputFile<<"Money: $"<<balance1<<endl;

	outputFile.close(); // Close the file after writing
	cout<<"\n\n*******************************************"<<endl;
	cout<<"You finished with $"<<balance1<< ", "<<name1<<"."<<endl;
	cout<<"Thank you for playing!"<<endl;
	cout<<"*******************************************"<<endl;
	return 0;
}




			
				
				
				
				
				
			string  getCard(int& cardVal, string& suit) {
				string suits[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
                                int suitI = rand() % 4;                //random card suit (face value)
                                suit = suits[suitI];
                                cardVal = rand() % 13 + 2;             //random card value (numerical)
                                
                        string card;
                        
			if (cardVal >= 2 && cardVal <= 10) {
				card = to_string(cardVal);
			}
			else {
				switch (cardVal) {
				case 11:
					card = "Jack";                  //Cards and their values
					break;
				case 12:
					card = "Queen";
					break;
				case 13:
					card = "King";
					break;
				case 14:
					card = "Ace";
					break;
				}
			}
			return card + " of " + suit;
			}