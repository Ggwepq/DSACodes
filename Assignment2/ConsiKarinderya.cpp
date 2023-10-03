#include <windows.h>
#include <iostream>
using namespace std;

string foodMenu[] = {"Adobo","Afritada","Caldereta","Sinigang","Tinolang Manok","Nilagang Baboy","Paksiw","Hotdog","Longganisa"};
string currOrder[10] = {};

int foodPrice[] = {60,70,70,50,60,65,50,15,20};
int priceRecord[10] = {};

int len1 = size(foodMenu);
int len2 = size(currOrder);
int len3= size(priceRecord);
int pos = 0;

void showCurrentOrder();
void viewMenu();
void checkout();
void payScreen(int balance);
void clearCurr();

int main(){
    int choice;

    system("cls");
    cout << "\n***** Consi Eatery *****" << endl;
    cout << "Order: ";
    showCurrentOrder();
    cout << "\n" << endl;
    cout << "[1] View Menu\n[2] Checkout\n[3] Clear Order\n[4] Exit\n>> ";
    cin >> choice;

    switch (choice){
        case 1:
            viewMenu();
        case 2:
            checkout();
        case 3:
            clearCurr();
            main();
        case 4:
            exit(0);
    }
}

void showCurrentOrder(){
    for (int i = 0; i < len2; i++){
        if (currOrder[i].empty()){
            continue;
        } else {
            cout << currOrder[i] << ", ";
        }
    }
}

void viewMenu(){
    int choice;

    do {
        system("cls");
        cout << "----- View Menu -----" << endl;
        cout << "Order: ";
        showCurrentOrder();
        cout << "\n" << endl;

        for (int i = 0; i < len1; i++){
            cout << "[" << i << "] " << foodMenu[i] << " -- " << foodPrice[i] << endl;
        }

        cout << "[9] Back\n>> ";
        cin >> choice;

        if (choice == 9){
            main();
        } else {
            currOrder[pos] = foodMenu[choice];
            priceRecord[pos] = foodPrice[choice];
            pos++;
        }
    } while (choice != 9);
}

void checkout(){
    string choice;

    if (!currOrder[0].empty()){
        system("cls");
        cout << "----- Food Checkout -----" << endl;
        cout << "Current Order: " << endl;

        for (int i = 0; i < len3; i++){
            if (!currOrder[i].empty()){
                cout << currOrder[i] << " -- " << priceRecord[i] << endl;
            } else {
                continue;
            }
        }

        int sum = 0;
        for (int i = 0; i < len3; i++){
            sum += priceRecord[i];
        }

        cout << "Total: " << sum << endl; 
        cout << "\nCheckout? [Y][N]\n>> ";
        cin >> choice;

        if (choice == "Y" || choice == "y"){
            payScreen(sum);
        } else {
            main();
        }
    } else {
        cout << "\nPlease Order First. Thank you!" << endl;
        system("pause");
        main();
    }
}

void payScreen(int balance){
    int paymentAmount, change;

    system("cls");
    cout << "----- Payment Screen -----" << endl;
    cout << "Total Balance: " << balance << endl;
    cout << "Amount of Payment: ";
    cin >> paymentAmount;

    if (paymentAmount < balance){
        cout << "\nPlease pay the exact amount!" << endl;
        system("pause");
        checkout();
    } else {
        change = paymentAmount - balance;
    }
    
    cout << "================\n" << endl;
    cout << "Received: " << paymentAmount << endl;
    cout << "Change: " << change << endl;
    cout << "\nThank you for paying your food!" << endl;
    system("pause");

    pos = 0;
    clearCurr();
    main();
}

void clearCurr(){
    for (int i = 0; i < len2; i++){
        currOrder[i] = "";
        priceRecord[i] = 0;
    }
}