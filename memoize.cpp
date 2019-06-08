#include <iostream>
using namespace std;

long long int global[100];

long long int fib(int n) {
    cout << "Current N: " << n << endl;
    if (n == 0 || n == 1) {
        return global[n];
    }
    else {
        if (global[n - 1] == 0 && global[n - 2] == 0) {
            long long int result = fib(n-1) + fib(n-2);
            global[n] = result;
            cout << "(NA)" << endl;
            return result;
        }
        else if (global[n - 2] == 0 && global[n - 1] != 0) {
            long long int result = global[n - 1] + fib(n - 2);
            global[n - 2] = result;
            cout << "(AA-1)" << endl;
            return result;
        }
        else if (global[n - 1] == 0 && global[n - 2] != 0) {
            long long int result = global[n - 1] + fib(n - 1);
            global[n - 1] = result;
            cout << "(AA-2)" << endl;
            return result;
        }
        else if (global[n - 2] != 0 && global[n - 1] != 0) {
            long long int result = global[n - 1] + global[n - 2];
            global[n] = result;
            cout << "(AA-BC)" << endl;
            return result;
        }
    }
}

void printGlobal() {
    cout << endl;
    for (int i = 0; i < 100; i++) {
        cout << global[i] << " ";
    }
}

int main () {
    global[0] = global[1] = 1;
    for (int i = 2; i < 100; i++) {
        global[i] = 0;
    }
    int x = 5;
    cout << "Fib(" << x << "): " << endl << fib(x) << endl;
    printGlobal();
    return 0;
}