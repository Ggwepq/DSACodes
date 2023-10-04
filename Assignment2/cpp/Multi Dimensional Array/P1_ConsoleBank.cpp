#include <windows.h>
#include <iostream>
using namespace std;

// Multi Dimensional Array (3D) Program #3
string mainArr[2][10][2] = {
    // Accounts
    {{"admin","admin"}},

    // Active Account
    {{"","0"}},
};

int len1 = 10;
int len2 = 2;

string currUser = "";
int usrBalance = 0;

void accScreen();
void deposit();
void withdraw();
void accountInfo();
void signInAcc();
void registerAcc();
void setCurrUser();
void signinFirst();

int main(){
    int menuChoice;

    system("cls");
    cout << "\n***** Console Banking *****" << endl;

    if (currUser.empty()){
        cout << "Welcome User! Please Sign In to Deposit/Withdraw\n" << endl;
    } else {
        cout << "Welcome " << currUser << "! Enjoy Console Banking!\n" << endl;
    }
    
    cout << "[0] Sign In/Register\n[1] Deposit\n[2] Withdraw\n[3] Account Info\n[4] Quit\n>> "; 
    cin >> menuChoice;

    if (menuChoice == 0){
        accScreen();
    } else if (menuChoice == 1){
        deposit();
    } else if (menuChoice == 2){
        withdraw();
    } else if (menuChoice == 3){
        accountInfo();
    } else if (menuChoice == 4){
        exit(0);
    }
}

void accScreen(){
    int accountChoice;
    
    system("cls");
    cout << "---- Sign In/Register -----" << endl;
    cout << "[0] Sign In\n[1] Register\n[9] Back\n>> ";
    cin >> accountChoice;

    if (accountChoice == 0){
        signInAcc();
    } else if (accountChoice == 1){
        registerAcc();
    } else if (accountChoice == 9){
        main();
    }
}

int checkEmpty(int pos){
    int empty;

    for (int i = 0; i < len1; i++){
        if (mainArr[pos][i][0].empty()){
            empty = i;
            break;
        } else {
            continue;
        }
    }

    return empty;
}

void registerAcc(){
    string usrName, password, password2;

    system("cls");
    cout << "----- Register Account -----" << endl;
    cout << "Enter Username: ";
    cin >> usrName;
    cout << "Enter Password: ";
    cin >> password;

    do {
        cout << "Re-enter Password: ";
        cin >> password2;

        if (password2 != password){
            cout << "\nWrong Password." << endl;
            system("pause");
        } else {
            break;
        }
    } while (password2 != password);

    int empty = checkEmpty(0);

    for (int i = 0; i < len2; i++){
        if (i == 0){
            mainArr[0][empty][i] = usrName;
        } else if (i == 1){
            mainArr[0][empty][i] = password;
        }
    }

    cout << "\nAccount Registered! You can now log in." << endl;
    system("pause");
    accScreen();
}

void setCurrUser(string user){
    mainArr[1][0][0] = user;
    mainArr[1][0][1] = to_string(usrBalance);
    currUser = user;
}

bool checkRecord(string name, string pwd){
    for (int i = 0; i < len1; i++){
        for (int j = 0; j < len2; j++){
            int num = j+1;

            if (mainArr[0][i][j] == name && mainArr[0][i][num] == pwd){
                return 1;
            } else {
                continue;
            }
        }
    }
    return 0;
}

void signInAcc(){
    system("cls");
    string name, password;

    cout << endl;
    cout << "----- Sign In Account -----" << endl;
    cout << "Username: ";
    cin >> name;
    cout << "Password: ";
    cin >> password;
        
    if (checkRecord(name,password)){
        setCurrUser(name);
        cout << "\nYou are now Signed In!" << endl;
        system("pause");
        main();        
    } else {
        cout << "\nSomething is Wrong. Please Sign in Again." << endl;
        system("pause");
        accScreen();
    }
}

void deposit(){
    if (currUser.empty()){
        signinFirst();
    } else {
        system("cls");
        int depAmount, depChoice;

        cout << "----- Deposit Money -----" << endl;
        cout << "Current Balance: " << usrBalance << endl;
        cout << "\n[0] Deposit Money\n[9] Back\n>> ";
        cin >> depChoice;
        cout << endl;

        if (depChoice == 0){
            cout << "Deposit Amount: ";
            cin >> depAmount;

            usrBalance += depAmount;
            setCurrUser(currUser);

            cout << "\nThank you for Depositing!\nCurrent Balance is " << usrBalance << endl;
            cout << endl;

            system("pause");
            deposit();
        } else {
            main();
        }
    }
}

void withdraw(){
    if (currUser.empty()){
        signinFirst();
    } else {
        system("cls");
        int wdAmount, wdChoice;

        cout << "----- Withdraw Money -----" << endl;
        cout << "Current Balance: " << usrBalance << endl;
        cout << "\n[0] Withdraw Money\n[9] Back\n>> ";
        cin >> wdChoice;
        cout << endl;

        if (wdChoice == 0){
            cout << "Withdraw Amount: ";
            cin >> wdAmount;

            if (wdAmount > usrBalance){
                cout << "\nSorry. Balance is too low.";
                system("pause");
                withdraw();
            } else {
                usrBalance -= wdAmount;
                setCurrUser(currUser);
            }

            cout << "\nWithdraw Successful!\nCurrent Balance is " << usrBalance << endl;
            cout << endl;

            system("pause");
            withdraw();
        } else {
            main();
        }
    }
}

void accountInfo(){
    system("cls");
    if (currUser.empty()){
        signinFirst();
    } else {
        cout << "----- Account Info -----" << endl;
        cout << "Account Name: " << currUser << endl;
        cout << "Current Balance: " << mainArr[1][0][1] << endl;
        cout << endl;

        system("pause");
        main();
    }
}

void signinFirst(){
    cout << "\nPlease Sign In First!" << endl;
    system("pause");
    main();
}