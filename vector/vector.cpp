#include <iostream>
#include <vector> 
using namespace std;

int main() {
    vector<int> v;
    
    for(int i=1; i<=5; i++)
    {
        v.push_back(i);
    }
    for (int i : v)
    cout << i<<" ";
    

    return 0;
}