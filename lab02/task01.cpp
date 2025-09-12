#include <iostream>
using namespace std;

class DynArray {
private:
    int* data;
    int capacity;
    int length;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynArray(int cap = 2) {
        capacity = cap;
        length = 0;
        data = new int[capacity];
    }

    void push_back(int val) {
        if (length == capacity) {
            resize();
        }
        data[length++] = val;
    }

    void display() {
        cout << "Array Elements: ";
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~DynArray() {
        delete[] data;
    }
};

int main() {
    DynArray arr;
    int n, val;
    cout << "How many numbers to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> val;
        arr.push_back(val);
    }

    arr.display();
    return 0;
}

