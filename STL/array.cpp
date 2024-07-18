#include <iostream>
#include <array>
using namespace std;
void print(array<int, 5> arr, int size);

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};

    int size = arr.size();
    
    print(arr, size);

    cout<<"Size "<<size<<endl;

    cout<<"Element at 2nd index "<<arr.at(2)<<endl;

    cout << "Array is " << (arr.empty() ? "empty" : "not empty") << endl;

    cout<<"First Element " <<arr.front() << endl;
    cout<<"Last Element " <<arr.back() << endl; 

    return 0;
}
void print(array<int, 5> arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}