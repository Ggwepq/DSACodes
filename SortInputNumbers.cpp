#include <iostream>
using namespace std;

int numberArr[10];
int len = size(numberArr);

void bubbleSort(string order);

int main(){
    int num = 1;

    cout << "\n***** Sorting Inputted Numbers *****" << endl;
    for (int i = 0; i < len; i++){

        if (num != 0){
            cout << "Index " << i << ": ";
            cin >> num;
            numberArr[i] = num;
        } else {
            break;
        }
    }

    int sortOrder;
    cout << "\n----- Sorting Order -----" << endl;
    cout << "[1] Ascending\n[2] Descending\n>> ";
    cin >> sortOrder;

    cout << "\nUnsorted Array: ";
    for (int el : numberArr){
        cout << el << ",";
    }

    if (sortOrder == 1){
        bubbleSort("ascending");
    } else if (sortOrder == 2){
        bubbleSort("descending");
    }

    cout << "\nSorted Array: ";
    for (int el : numberArr){
        cout << el << ",";
    }
    cout << endl;
    cout << "\nRun the program to input again. Thank you!\n" << endl;

}

void bubbleSort(string order){
    for (int i = 0; i < len; i++){
        for (int j = i+1; j < len; j++){
            int temp;
            if (order == "ascending"){
                if (numberArr[i] > numberArr[j]){
                    temp = numberArr[i];
                    numberArr[i] = numberArr[j];
                    numberArr[j] = temp;
                }
            } else if (order == "descending"){
                if (numberArr[i] < numberArr[j]){
                    temp = numberArr[i];
                    numberArr[i] = numberArr[j];
                    numberArr[j] = temp;
                }
            }
        }
    }
}
