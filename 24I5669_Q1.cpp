#include <iostream>
using namespace std;


class RecursionTasks {
public:

    void ChangeLocation(char* arr, int b1, int b2) {
        if (b1 >= b2) return;
       
        char temp = arr[b1];
        arr[b1] = arr[b2];
        arr[b2] = temp;
        
        ChangeLocation(arr, b1 + 1, b2 - 1);
    }

   
    void PrintPattern(int n) {
        if (n == 0) return; 
        PrintPattern(n - 1);
       
        int remaining = n;
        while (remaining > 0) {
            cout << 1 << " ";
            remaining--;
        }
        cout << endl;
    }
};

int main() {
    RecursionTasks task;

    
    char arr[8] = {'C','O','M','P','U','T','E','R'};
    cout << "Original array: ";
    for (int i = 0; i < 8; i++) {      
        cout << arr[i] << " ";
    }
    cout << endl;

    task.ChangeLocation(arr, 2, 6); 
    cout << "After ChangeLocation: ";
    for (int i = 0; i < 8; i++) {     
        cout << arr[i] << " ";
    }
    cout << endl << endl;

     
    int n = 4;
    cout << "PrintPattern for n = " << n << ":\n";
    task.PrintPattern(n);

    return 0;
}
 
