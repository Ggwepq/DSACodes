#include <windows.h>
#include <iostream>
using namespace std;

const int n = 10;

void Example1(); // 3x3
void Example2(); // 4x4
void Example3(); // 5x5 (1)
void Example4(); // 6x6
void Example5(); // 5x5 (2)
void PrintMagicSquare(int matrix[n][n],int len);
void GetMagicSum(int matrix[n][n], int len);

int main(){
    int choice;

    system("cls");
    cout << "***** Magic Square Samples ******" << endl;
    cout << "[1] 3x3\n[2] 4x4\n[3] 5x5 (1)\n[4] 6x6\n[5] 5x5 (2)\n[6] Exit\n>> ";
    cin >> choice;
    cout << endl;
    Sleep(1000);

    if (choice == 1){
        Example1();
    } else if (choice == 2){
        Example2();
    } else if (choice == 3){
        Example3();
    } else if (choice == 4){
        Example4();
    } else if (choice == 5){
        Example5();
    } else if (choice == 6){
        exit(0);
    }

    system("pause");
    main();
}

void Example1(){
    int magicSquare3x3[n][n] = {
        {8,1,6},
        {3,5,7},
        {4,9,2}
    };
    PrintMagicSquare(magicSquare3x3,3);
}

void Example2(){
    int magicSquare4x4[n][n] = {
        {16,2,3,13},
        {5,11,10,8},
        {9,7,6,12},
        {4,14,15,1}
    };
    PrintMagicSquare(magicSquare4x4,4);
}

void Example3(){
    int magicSquare5x5[n][n] = {
        {17,24,1,8,15},
        {23,5,7,14,16},
        {4,6,13,20,22},
        {10,12,19,21,3},
        {11,18,25,2,9},
    };
    PrintMagicSquare(magicSquare5x5,5);
}

void Example4(){
    int magicSquare6x6[n][n] = {
        {35,1,6,26,19,24},
        {3,32,7,21,23,25},
        {31,9,2,22,27,20},
        {8,28,33,17,10,15},
        {30,5,34,12,14,16},
        {4,36,29,13,18,11}
    };
    PrintMagicSquare(magicSquare6x6,6);
}

void Example5(){
    int magicSquare5x52[n][n] = {
        {3,16,9,22,15},
        {20,8,21,14,2},
        {7,25,13,1,19},
        {24,12,5,18,6},
        {11,2,17,10,23}, // 2nd, 4
    };
    PrintMagicSquare(magicSquare5x52,5);
}

void PrintMagicSquare(int matrix[n][n], int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    GetMagicSum(matrix, len);
}

void GetMagicSum(int matrix[n][n], int len){
    int horizontalSum = 0, verticalSum = 0, diagonalSum = 0, magicSum = 0;

    for (int j = 0; j < len; j++){
        horizontalSum += matrix[0][j];
    }

    for (int i = 0; i < len; i++){
        verticalSum += matrix[i][0];
    }

    for (int i = 0; i <= len - 1; i++){
        for (int j = 0; j <= len - 1; j++){
            if (i == j){
                diagonalSum += matrix[i][j];
            }
        }
    }

    if (horizontalSum == verticalSum && verticalSum == diagonalSum && diagonalSum == horizontalSum){
        magicSum = (horizontalSum+verticalSum+diagonalSum)/3;

        cout << "Horizontal Sum: " << horizontalSum << endl;
        cout << "Vertical Sum: " << verticalSum << endl;
        cout << "Diagonal Sum: " << diagonalSum << endl;
        cout << "Magic Sum: " << magicSum << endl;
        cout << endl;
    } else {
        cout << "Not a Magic Square" << endl;
        cout << endl;
    }
}