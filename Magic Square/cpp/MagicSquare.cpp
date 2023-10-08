#include <windows.h>
#include <iostream>
using namespace std;

const int N = 10; // MAX 

void OddMagicSquare(int matrix[N][N], int n);
void DoublyEvenMagicSquare(int matrix[N][N], int n);
void SinglyEvenMagicSquare(int matrix[N][N], int n);
void MagicSquare(int matrix[N][N], int n);
void PrintMagicSquare(int matrix[N][N], int n);

int main(){
    int n, choice;
    int matrix[N][N] = {0};

    system("cls");
    cout << "\n***** Magic Square *****" << endl;
    cout << "[1] 3x3\n[2] 4x4\n[3] 5x5\n[4] 6x6\n[5] Custom Order Number\n[6] Exit\n>> ";
    cin >> choice;

    if (choice == 1){
        n = 3;
    } else if (choice == 2){
        n = 4;
    } else if (choice == 3){
        n = 5;
    } else if (choice == 4){
        n = 6;
    } else if (choice == 5){
        do {
            cout << "Enter Order of Square: ";
            cin >> n;

            if (n < 3 || n > N){
                cout << "Must be 3 - 10" << endl;
            }
        } while (n < 3 || n > N);
    } else if (choice == 6){
        exit(0);
    }

    MagicSquare(matrix,n);
    Sleep(1000);
    cout << endl;
    PrintMagicSquare(matrix, n);
    system("pause");
    main();
}

void MagicSquare(int matrix[N][N], int n){
    if (n % 2 == 1){
        OddMagicSquare(matrix, n);
    } else if (n % 4 == 0) {
        DoublyEvenMagicSquare(matrix, n);
    } else {
        SinglyEvenMagicSquare(matrix, n);
    }
}

void OddMagicSquare(int matrix[N][N], int n){
    int nsqr = n * n;
    int i = 0, j = n / 2; // start position

    for (int k = 1; k <= nsqr; ++k){
        matrix[i][j] = k;

        i--;
        j++;

        if (k % n == 0){
            i += 2;
            --j;
        } else if (j == n){
            j -= n;
        } else if (i < 0) {
            i += n;
        }
    }
}

void DoublyEvenMagicSquare(int matrix[N][N], int n){
    int I[N][N] = {0};
    int J[N][N] = {0};

    int i, j;

    // Prepare I, J
    int index = 1;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            I[i][j] = ((i + 1) % 4) / 2;
            J[j][i] = ((i + 1) % 4) / 2;
            matrix[i][j] = index;
            index++;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            if (I[i][j] == J[i][j])
                matrix[i][j] = n * n + 1 - matrix[i][j];
        }
    }
}

void SinglyEvenMagicSquare(int matrix[N][N], int n){
    int p = n / 2;

    int M[N][N] = {0};
    MagicSquare(M, p);

    int i, j, k;

    for (i = 0; i < p; i++){
        for (j = 0; j < p; j++){
            matrix[i][j] = M[i][j];
            matrix[i + p][j] = M[i][j] + 3 * p * p;
            matrix[i][j + p] = M[i][j] + 2 * p * p;
            matrix[i + p][j + p] = M[i][j] + p * p;
        }
    }

    if (n == 2){
        return;
    }

    int I[p] = {0};
    int J[N];

    for (i = 0; i < p; i++){
        I[i] = i + 1;
    }

    k = (n - 2) / 4;

    for (i = 1; i <= k; i++){
        J[i - 1] = i;
    }

    for (i = n - k + 1; i <= n; i++){
        J[i - k - 1] = i;
    }

    int temp;
    for (i = 1; i <= p; i++){
        for (j = 1; j <= k; j++){
            temp = matrix[i - 1][J[j - 1] - 1];
            matrix[i - 1][J[j - 1] - 1] = matrix[i + p - 1][J[j - 1] - 1];
            matrix[i + p - 1][J[j - 1] - 1] = temp;
        }
    }

    i = k;
    j = 0;
    temp = matrix[i][j];
    matrix[i][j] = matrix[i + p][j];
    matrix[i + p][j] = temp;

    j = i;
    temp = matrix[i + p][j];
    matrix[i + p][j] = matrix[i][j];
    matrix[i][j] = temp;
}

void PrintMagicSquare(int matrix[N][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << " " << matrix[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}