/*
	Zach Hofmeister		2/4/19
	Lab 1 - Grade Book	Grade book application to keep track of 3 exam scores for three students using 2D arrays.
*/

#include "pch.h"
#include <iostream>

using namespace std;

void enterScores(); //Asks for each score per student and exam number
void printScores(); //Prints out the scores of each student
void printAve(); //Prints out the average score for each student
void updateScore(); //Asks user if they would like to change any scores, and changes a score referenced by student and exam number

int arr[3][3]; //Stores all scores

int main() {
	cout << "====Grade Book Application====" << endl;
	enterScores();
	updateScore();
	printAve();

	return 0;
}

void enterScores() { //Asks for each score per student and exam number
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) { //Nested for loop for each score
			cout << "Enter Student " << i + 1 << "\'s Exam " << j + 1 << " score: ";
			cin >> arr[i][j];
		}
	}
	cout << endl;
	printScores(); //Prints scores that were just entered
}

void printScores() { //Prints out the scores of each student
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) { //Nested for loop for each score
			cout << "Student " << i + 1 << "\'s Exam " << j + 1 << " score is: " << arr[i][j] << endl;
		}
		cout << endl;
	}
	printAve(); //Prints the averages of each score
}

void printAve() { //Prints out the average score for each student
	for (int i = 0; i < 3; i++) {
		cout << "The Average Score for Student " << i + 1 << " is " << (arr[i][0] + arr[i][1] + arr[i][2]) / 3.0 << endl;
	}
	cout << endl;
}

void updateScore() { //Asks user if they would like to change any scores, and changes a score referenced by student and exam number
	char response;
	cout << "Would you like to update an exam score? Y/N: ";
	cin >> response;

	if (response == 'Y') {
		int student, exam, score; //The student and exam indexes, and the score to replace the old one with.
		cout << "Enter a student's number (1-3): ";
		cin >> student;
		cout << "Enter a exam number (1-3): ";
		cin >> exam;
		cout << "Enter a score: ";
		cin >> score;
		arr[student-1][exam-1] = score; //Updates the array.
		cout << "Student " << student << "\'s Exam " << exam << " score is: " << arr[student-1][exam-1] << endl;
		updateScore(); //Recursive when an exam score is updated.
	}
}

/*
====Grade Book Application====
Enter Student 1's Exam 1 score: 10
Enter Student 1's Exam 2 score: 10
Enter Student 1's Exam 3 score: 10
Enter Student 2's Exam 1 score: 10
Enter Student 2's Exam 2 score: 10
Enter Student 2's Exam 3 score: 10
Enter Student 3's Exam 1 score: 10
Enter Student 3's Exam 2 score: 10
Enter Student 3's Exam 3 score: 10

Student 1's Exam 1 score is: 10
Student 1's Exam 2 score is: 10
Student 1's Exam 3 score is: 10

Student 2's Exam 1 score is: 10
Student 2's Exam 2 score is: 10
Student 2's Exam 3 score is: 10

Student 3's Exam 1 score is: 10
Student 3's Exam 2 score is: 10
Student 3's Exam 3 score is: 10

The Average Score for Student 1 is 10
The Average Score for Student 2 is 10
The Average Score for Student 3 is 10

Would you like to update an exam score? Y/N: Y
Enter a student's number (1-3): 2
Enter a exam number (1-3): 2
Enter a score: 100
Student 2's Exam 2 score is: 100
Would you like to update an exam score? Y/N: N
The Average Score for Student 1 is 10
The Average Score for Student 2 is 40
The Average Score for Student 3 is 10


C:\Users\zachh\Documents\GitHub\Lab1GradeBook\Debug\Lab1GradeBook.exe (process 12544) exited with code 0.
Press any key to close this window . . .
*/