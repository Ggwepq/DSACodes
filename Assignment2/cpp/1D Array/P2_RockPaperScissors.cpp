#include <windows.h>
#include <iostream>
using namespace std;

// 1D Array Program #2
int life = 3, playerScore = 0, computerScore = 0;
string moveList[] = {"Rock", "Paper", "Scissors"};

string computerMove(){
    int random = rand() % 3;
    return moveList[random];
}

void draw(){
    cout << "Game is Draw! :|\n";
}

void win(){
    playerScore++;
    life++;
    cout << "Player Won! :D\n";
}

void lose(){
    computerScore++;
    life--;
    cout << "Player Lose! :<\n";
}

void compareMove(int pMove, string cMove){
    string currentPlayerMove = moveList[pMove--];

    if (currentPlayerMove == cMove){
        draw();
    } else if (currentPlayerMove == moveList[0]){
        if (cMove == moveList[1]){
            lose();
        } else if (cMove == moveList[2]){
            win();
        }
    } else if (currentPlayerMove == moveList[1]){
        if (cMove == moveList[2]){
            lose();
        } else if (cMove == moveList[0]){
            win();
        }
    } else if (currentPlayerMove == moveList[2]){
        if (cMove == moveList[0]){
            lose();
        } else if (cMove == moveList[1]){
            win();
        }
    }
}

int main(){
    int playerMove;
    string continueChoice = "y";
    bool playAgain;
    
    do {
        while (life != 0 || playerScore != 10 || computerScore != 10){
            system("cls");

            cout << "\n******* Rock Paper Scissors *******\n";
            cout << "\nLife: " << life << " || Player: " << playerScore << " || Computer: " << computerScore;
            cout << "\n[1] Rock\n[2] Paper\n[3] Scissors\nPlayer Move: ";
            cin >> playerMove;

            cout << "\nPlayer Move: " << moveList[--playerMove] << endl;
            Sleep(1000);
    
            string currentComputerMove = computerMove();
            cout << "Computer Move: " << currentComputerMove << endl;

            Sleep(1000);
            compareMove(playerMove,currentComputerMove);
            cout << endl;
            system("pause");
        
            if (life == 0 || computerScore == 10 || playerScore == 10){ //FIX FOR CONTINUOUS LOOP  
                break;
            }
        }

        if (life == 0 || computerScore == 10){
            cout << "Game Over. :<" << endl;
        } else if (playerScore == 10){
            cout << "Congratulations! You gain victory over a bot. :DD" << endl;
        }

        cout << "\nWould you like to try again? [Y][N]: ";
        cin >> continueChoice;

        if (continueChoice == "y" || continueChoice == "Y"){
            playAgain = true;
            life = 3;
            playerScore = 0;
            computerScore = 0;
        } else {
            cout << "Thank you for Playing!\n" << endl;
            playAgain = false;
        }
    } while (playAgain);
}