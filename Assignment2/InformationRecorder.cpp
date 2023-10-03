#include <windows.h>
#include <iostream>
using namespace std;

string personalInfo[5][5]; 

int len1 = size(personalInfo), len2 = size(personalInfo[0]);

void firstMenu();
void viewRecords();

void saveInfo(string name,string age,string gender, string religion,string status){
    int emptyRow;
    
    for (int i = 0; i < len1; i++){
        if (personalInfo[i][0].empty()){
            emptyRow = i;
            break;
        } else {
            continue;
        }
    }

    for (int j = 0; j < len2; j++){
        if (j == 0){
            personalInfo[emptyRow][j] = name;
        } else if (j==1){
            personalInfo[emptyRow][j] = age;
        } else if (j==2){
            personalInfo[emptyRow][j] = gender;
        } else if (j==3){
            personalInfo[emptyRow][j] = religion;
        } else if (j==4){
            personalInfo[emptyRow][j] = status;
        }
    }
}

void recordInformation(){
    system("cls");
    string name, age, gender, religion, status, null;

    cout << "----- Record Info -----" << endl;
    getline(cin,null); // Fix for skipping name input
    cout << "Enter Name: ";
    getline(cin,name);
    cout << "Enter Age: ";
    getline(cin,age);
    cout << "Enter Gender: ";
    getline(cin,gender);
    cout << "Enter Religion: ";
    getline(cin,religion);
    cout << "Enter Marital Status: ";
    getline(cin,status);

    saveInfo(name,age,gender,religion,status);

    cout << "\nInformations are Recorded!\n" << endl;
    Sleep(1000);
    viewRecords();
}

void showList(){
    for (int i = 0; i < len1; i++){
        for (int j = 0; j < len2; j++){
            if (j == 0){
                if (!personalInfo[i][j].empty()){
                    cout << "[" << i << "] " << personalInfo[i][j] << endl;
                } else {
                    cout << "[" << i << "] " << "~" << endl;
                }
            } else {
                continue;
            }
        }
    }
}

void viewRecords(){
    system("cls");
    int name;

    cout << "----- View Records -----" << endl;
    showList();
    cout << "[9] BACK\n>> ";
    cin >> name;
    cout << endl;

    if (name == 9){
        firstMenu();
    } else {
        if (personalInfo[name][0].empty()){
            cout << "Record is empty." << endl;
        } else {
            for (int j = 0; j < len2; j++){
                if (j==0){
                    cout << "Name: " << personalInfo[name][j] << endl;
                } else if (j==1){
                    cout << "Age: " << personalInfo[name][j] << endl;
                } else if (j==2){
                    cout << "Gender: " << personalInfo[name][j] << endl; 
                } else if (j==3){
                    cout << "Religion: " << personalInfo[name][j] << endl;
                } else if (j==4){
                    cout << "Status: " << personalInfo[name][j] << endl; 
                }
            }
        }
    }
    cout << endl;

    system("pause");

    viewRecords();
}

void deleteRecord(){
    system("cls");
    int choice;

    cout << "----- Delete A Record -----" << endl;
    showList();
    cout << "[9] BACK\n>> ";
    cin >> choice;
    cout << endl;

    if (choice == 9){
        firstMenu();
    } else {
        for (int j = 0; j < len2; j++){
            personalInfo[choice][j] = "";
        }
    }
    cout << "Deleted!\n" << endl;
    Sleep(1000);
    deleteRecord();
}

void firstMenu(){
    system("cls");
    int firstChoice;

    cout << "\n****** Personal Info Recorder ******" << endl;
    cout << "\n[1] Record Information\n[2] View Records\n[3] Delete A Record\n[4] Exit\n>> ";
    cin >> firstChoice;
    cout << endl;

    switch (firstChoice){
        case 1:
            recordInformation();
        case 2:
            viewRecords();
        case 3:
            deleteRecord();
        case 4:
            system("cls");
            exit(0);
        default:
            firstMenu();
    }
}

int main(){
    firstMenu();
}