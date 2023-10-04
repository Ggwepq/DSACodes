#include <windows.h>
#include <iostream>
using namespace std;

// Multi Dimensional Array (3D) Program #2
string patientList[3][5] ={
    {"124","201","304","102","206"},
    {"Judy", "Ryan", "Kenneth", "Douglas", "Michael"},
    {"Liver Cancer", "Anemia", "Diabetes", "Brain Tumor", "Stroke"}
};

int main(){
    int patient;

    system("cls");
    cout << "***** Patient List *****" << endl;
    cout << "Choose a Patient to see information." << endl;
    
    for (int i = 0; i < 5; i++){
        cout << "[" << i << "]" << patientList[1][i] << endl;
    }
    cout << ">> ";
    cin >> patient;
    cout << endl;
    
    if (patient == 0){
        cout << "Patient: " << patientList[1][patient] << endl;
        cout << "Room #: " << patientList[0][patient] << endl;
        cout << "Disease: " << patientList[2][patient] << endl;
    } else if (patient == 1){
        cout << "Patient: " << patientList[1][patient] << endl;
        cout << "Room #: " << patientList[0][patient] << endl;
        cout << "Disease: " << patientList[2][patient] << endl;
    } else if (patient == 2){
        cout << "Patient: " << patientList[1][patient] << endl;
        cout << "Room #: " << patientList[0][patient] << endl;
        cout << "Disease: " << patientList[2][patient] << endl;
    } else if (patient == 3){
        cout << "Patient: " << patientList[1][patient] << endl;
        cout << "Room #: " << patientList[0][patient] << endl;
        cout << "Disease: " << patientList[2][patient] << endl;
    } else if (patient == 4){
        cout << "Patient: " << patientList[1][patient] << endl;
        cout << "Room #: " << patientList[0][patient] << endl;
        cout << "Disease: " << patientList[2][patient] << endl;
    }

    cout << endl;
    system("pause");
    main();
}