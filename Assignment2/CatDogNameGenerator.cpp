#include <windows.h>
#include <iostream>
using namespace std;

string dogNames(int gender){
    string dogName[2][10] = {
        {"Max","Charlie","Cooper","Milo","Buddy","Rocky","Bear","Teddy","Duke","Leo"},
        {"Luna","Bella","Daisy","Lucy","Lily","Zoe","Lola","Saidy","Bailey","Stella"}
    };

    return dogName[gender][rand()%10];
}

string catNames(int gender){
    string catName[2][10] = {
        {"Ralphie","Wally","Bubba","Odie","Andy","Winston","Aimsley","Tubby","Charlie"},
        {"Margot","Angel","Honey","Ellie","Gladis","Gigi","Sheba","Callie","Millie","Piper"}
    };

    return catName[gender][rand()%10];
}

int main(){
    bool state;
    int petChoice, petGender;

    system("cls");
    cout << "***** Random Pet Name Generator ******" << endl;
    cout << "\nWhat kind of pet do you have?\n[1] Dog\n[2] Cat\n";
    cin >> petChoice;
    system("cls");
    cout << "\nWhat is the gender of your pet?\n[1] Male\n[2] Female\n";
    cin >> petGender;
    system("cls");

    int genderIndex = (petGender == 1) ? 0 : 1;

    do {
        system("cls");
        if (petChoice == 1){
            cout << "\nDog Name: " << dogNames(genderIndex);
        } else if (petChoice == 2){
            cout << "\nCat Name: " << catNames(genderIndex);
        }

        string choice;
        cout << "\nGenerate Again? [Y][N]\n";
        cin >> choice;

        if (choice == "Y" || choice == "y"){
            state = true;
        } else{
            state = false;
        }
    } while (state);
}