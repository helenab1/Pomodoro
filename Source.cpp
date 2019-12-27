/* This program simulates a pomodoro for 25 minutes for studying without a distracting visual countdown.
It tracks the total amount of time in text file, remembers when you next open it, uses sleep for the timer. */
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

const int STUDY = 25;
int trackStudy, selection;
std::fstream dataFile;

void load();
int menu();
void timer(int&);
void quit();


int main() {
	
	load();
	selection = menu();

	while(selection == 1) {
		timer(trackStudy);
		selection = menu();
	}

	if (selection == 2) {
		quit();
	}
	
	return 0;

}

int menu() {
	std::cout << "Please select:\n";
	std::cout << "(1) Study\n";
	std::cout << "(2) Quit\n";
	std::cin >> selection;
	while (selection < 1 || selection > 2) {
		std::cout << "Enter a valid selection (1 or 2).";
		std::cin >> selection;
	}
	return selection;
}

void load() {
	dataFile.open("nums.txt", std::ios::in);
	dataFile >> trackStudy;
	dataFile.close();
}


void timer(int& trackStudy) {
	std::cout << "OK, go study..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1500000));
	std::cout << "\a" << "You're done!" << std::endl;
	trackStudy = trackStudy + STUDY;
	std::cout << "You've studied a total of " << trackStudy << " minutes!\n" << std::endl;
}

void quit() {
	dataFile.open("nums.txt", std::ios::out);
	dataFile << trackStudy << std::endl;
	dataFile.close();
}

