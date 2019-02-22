/* This program simulates a pomodoro for two personalized settings: 25 minutes for studying or 10 minutes for meditation.
It tracks the total amount of time in text file, uses sleep for the timers. */
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

const int STUDY = 25;
const int MEDITATE = 10;
int trackStudy, trackMed, selection;

void timer1(int&);
void timer2(int&);

int main() {

	std::fstream dataFile;
	dataFile.open("nums.txt", std::ios::in);
	dataFile >> trackStudy;
	dataFile >> trackMed;
	dataFile.close();

start:
	std::cout << "Please select:\n";
	std::cout << "(1) Study\n";
	std::cout << "(2) Meditate\n";
	std::cout << "(3) Quit\n";
	std::cin >> selection;

	switch (selection) {
		case 1: timer1(trackStudy);
			    break;
		case 2: timer2(trackMed);
			    break;
		case 3: goto quit;
			    break;
		default: 
			    break;
	}
	std::cout << "Make sure to select quit when done to keep your time updated.\n";
	goto start;

quit:
	dataFile.open("nums.txt", std::ios::out);
	dataFile << trackStudy;
	dataFile << trackMed;
	dataFile.close();

	return 0;

}

void timer1(int& trackStudy) {
	std::cout << "OK, go study..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1500000));
	std::cout << "\a" << "You're done!" << std::endl;
	trackStudy = trackStudy + STUDY;
	std::cout << "You've studied a total of " << trackStudy << " minutes!\n" << std::endl;
}

void timer2(int& trackMed) {
	std::cout << "OK, close your eyes..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(600000));
	std::cout << "\a" << "You're done!" << std::endl;
	trackMed = trackMed + MEDITATE;
	std::cout << "You've meditated a total of " << trackMed << " minutes!\n" << std::endl;
}