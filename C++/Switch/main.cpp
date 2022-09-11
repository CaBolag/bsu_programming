//Вариант 1
#include <iostream>
#include<cmath>
using namespace std;
int main() {
    enum task {
        task1 = 1, task2, task3, exit
    };
    int choice,ex=0;
    while (ex==0) {
        cout << "1-Task 1\n2-Task 2\n3-Task 3\n4-Exit\nEnter the number of task:";
        cin >> choice;
        switch (choice) {
            case task1: {
                double x, y, z;
                cout << "Enter x,y,z:";
                cin >> x;
                cin >> y;
                cin >> z;
                cout << "Result is "<<2 * cos((x - 2.0/ 3)) * (1 + pow(z, 2) / 3 - pow(z, 2) / 5) / (0.5 + pow(sin(y), 2)) << endl;
                break;
            }

            case task2: {
                double x, y, z;
                cout << "Enter x,y,z:";
                cin >> x;
                cin >> y;
                cin >> z;
                cout << "a = " << 1 / (1 + pow(x, 2) / 2 + pow(y, 4) / 4)<< endl;
                cout << "b = " << x * (tan(z) + exp(y)) << endl;
                break;
            }

            case task3: {
                double x, y, z;
                cout << "Enter x,y,z:" ;
                cin >> x;
                cin >> y;
                cin >> z;
                cout << "a = " << (sqrt(fabs(x - 1)) - cbrt(fabs(y) / (1 + pow(x, 2) / 2 + pow(y, 2.0/3) / 4)))<<endl;
                cout << "b = " << x * (atan(z) + exp(-(x + 3))) << endl;
                break;
            }
            case exit: {
                ex = 1;
                break;
            }
            default:ex=1;
            cout<<"Unknown value";
        }
    }

}
