#include <iostream>
#include <windows.h>
#include <cmath>
#include <ctime>
#include <unistd.h> // Changed from <thread> for sleep
#include <conio.h>
#include <fstream>
using namespace std;

int score = 0;
string playerName;

void welcomeScreen() {
    Beep(2000, 100);
    cout << "\nWelcome to Math Quiz Game!\n";
    cout << "========================================\n";
    cout << "Please Enter Your Name: ";
    cin >> playerName;
    cout << "\nHello, " << playerName << "! Get ready to play...\n";
    sleep(2); // Changed sleep method here
    cout << "========================================\n\n";
}

void askQuestion(const string& question, int correctAnswer) {
    cout << question << " = ";
    int userAnswer;
    time_t startTime = time(0);

    while (true) {
        if (kbhit()) {
            cin >> userAnswer;
            time_t endTime = time(0);
            int elapsedTime = difftime(endTime, startTime);

            if (elapsedTime > 7) {
                cout << "\nTime's Up!\n";
                break;
            }

            if (userAnswer == correctAnswer) {
                cout << "Correct! +10 points\n";
                score += 10;
            } else {
                cout << "Wrong answer! The correct answer was: " << correctAnswer << "\n";
            }
            break;
        }

        time_t now = time(0);
        int elapsedTime = difftime(now, startTime);
        if (elapsedTime >= 7) {
            cout << "\nTime's Up!\n";
            break;
        }
    }
    Beep(2000, 100);
}

void playGame() {
    srand(time(0));

    // Addition Quiz
    cout << "LEVEL 1: Addition Quiz (7 seconds per question)\n";
    for (int i = 1; i <= 5; ++i) {
        int A = rand() % 20 + 1;
        int B = rand() % 20 + 1;
        askQuestion("Question " + to_string(i) + ": " + to_string(A) + " + " + to_string(B), A + B);
    }

    // Subtraction Quiz
    cout << "LEVEL 2: Subtraction Quiz (7 seconds per question)\n";
    for (int i = 1; i <= 5; ++i) {
        int A = rand() % 20 + 10;
        int B = rand() % 10 + 1;
        askQuestion("Question " + to_string(i) + ": " + to_string(A) + " - " + to_string(B), A - B);
    }

    // Multiplication Quiz
    cout << "LEVEL 3: Multiplication Quiz (7 seconds per question)\n";
    for (int i = 1; i <= 5; ++i) {
        int A = rand() % 10 + 1;
        int B = rand() % 10 + 1;
        askQuestion("Question " + to_string(i) + ": " + to_string(A) + " x " + to_string(B), A * B);
    }

    // Division Quiz
    cout << "LEVEL 4: Division Quiz (7 seconds per question)\n";
    for (int i = 1; i <= 5; ++i) {
        int A = (rand() % 10 + 1) * (rand() % 5 + 1); // Ensure divisible values
        int B = rand() % 5 + 1;
        askQuestion("Question " + to_string(i) + ": " + to_string(A) + " / " + to_string(B), A / B);
    }
}

void displayFinalScore() {
    cout << "\n========================================\n";
    cout << "GAME OVER! Final Score: " << score << "\n";
    if (score >= 100) cout << "Excellent Work!";
    else if (score >= 70) cout << "Great Job!";
    else cout << "Keep Practicing!";
    cout << "\n========================================\n";
}

int main() {
    welcomeScreen();
    playGame();
    displayFinalScore();
    return 0;
}
