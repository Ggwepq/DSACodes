#include <windows.h>
#include <iostream>
using namespace std;

// 2D Array Program #1
int grades[5][5] = {
    {89,91,92,90,94},
    {87,89,88,85,82},
    {90,90,91,87,79},
    {91,92,93,94,95},
    {86,87,87,84,89}
};

int getSum(int student);
int getAverage(int sum);
void getGrades(int student);

int main(){
    int studentChoice;

    system("cls");
    cout << "***** Get Student Average *****" << endl;
    cout << "[0] Ronald\n[1] Daisy\n[2] Gordon\n[3] Juan\n[4] Lucas\n>> ";
    cin >> studentChoice;
    cout << endl;

    string student;
    if (studentChoice == 0){
        student = "Ronald";
    } else if (studentChoice == 1){
        student = "Daisy";
    } else if (studentChoice == 2){
        student = "Gordon";
    } else if (studentChoice == 3){
        student = "Juan";
    } else if (studentChoice == 4){
        student = "Lucas";
    }

    int total = getSum(studentChoice);

    cout << "Student: " << student << endl;
    cout << "Grades: ";
    getGrades(studentChoice);
    cout << "Grade Sum: " << total << endl;
    cout << "Grade Average: " << getAverage(total);
    cout << endl;
    system("pause");
    main();
}

void getGrades(int student){
    for (int i = 0; i < 5; i++){
        cout << grades[student][i] << ", ";
    }
    cout << endl;
}

int getSum(int student){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += grades[student][i];
    }
    return sum;
}

int getAverage(int sum){
    int ave;
    return ave = sum/5;
}