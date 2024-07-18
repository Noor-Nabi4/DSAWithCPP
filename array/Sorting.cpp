#include <iostream>
using namespace std;
class Sorting{
private:    
    static const int n = 5;
    int arr[n] = {5, 2, 4, 1, 3};
public:
    void print();
    void bubble();
    void insertion();
    ~Sorting(){
        cout<<"after sorting :-> ";
        this->print();
    }
};
int main() {
    Sorting S;
    // S.bubble();
     S.insertion();
    

    return 0;
}
void Sorting::print(){
    for(int i=0;i<this->n;i++){
        cout<<this->arr[i]<<" ";
    }
    cout<<endl;
 
}
void Sorting::bubble(){
    bool swapped;
    for(int i=0;i<this->n-1;i++){
        swapped = false;
        for(int j=0;j<this->n-i-1;j++){
            if(this->arr[j]>this->arr[j+1]){
                int temp = this->arr[j];
                this->arr[j] = this->arr[j+1];
                this->arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void Sorting::insertion(){
    for (int i = 1; i <this->n;i++){
        int key = this->arr[i];
        int j = i - 1;
        while(j >= 0 && key < this->arr[j]){
            this->arr[j + 1] = this->arr[j];
            j--;
        }
        this->arr[j + 1] = key;
    }
}