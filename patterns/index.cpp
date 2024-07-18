#include <iostream>
using namespace std;

class Patterns {
    private:
    int rows, cols, n;

    public:
        Patterns(int rows, int cols);
        void rectangle();
        void hollowRectangle();
        Patterns(int n);
        void invertedHalfPyramid();
        void halfPyramin180Rotate();
        void halfPyraminUsingNumber();
        void floyidTriangle();
        void butterflyPattern();
        void invertedPattern();
        void oddEvenPattern();
        void rhombusPattern();
        void numberPattern();
        void palindromePattern();
        void starPattern();

};

int main() {
    /* int rows, cols;
    cin >> rows>>cols;
    Patterns P(rows, cols);
     P.rectangle();
    P.hollowRectangle(); */
    int n;
    cin >> n;
    Patterns P(n);
    // P.invertedHalfPyramid();
    // P.halfPyramin180Rotate();
    // P.halfPyraminUsingNumber();
    // P.floyidTriangle();
    // P.butterflyPattern();
    // P.invertedPattern();
    // P.oddEvenPattern();
    // P.rhombusPattern();
    // P.numberPattern();
    // P.palindromePattern();
    P.starPattern();
    return 0;
}
Patterns::Patterns(int rows,int cols){
    this->rows = rows;
    this->cols = cols;
}
void Patterns::rectangle() {
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void Patterns::hollowRectangle(){
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            if(i == 0 || i == this->rows - 1 || j == 0 || j == this->cols - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

}
Patterns::Patterns(int n){
    this->n=n;
}

void Patterns::invertedHalfPyramid(){
    for(int i=0;i<this->n;i++){
        for(int j=i;j<this->n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void Patterns::halfPyramin180Rotate(){
    for(int i=1;i<=this->n;i++){
        for(int j=1;j<=this->n;j++){
            if(j <= this->n - i)
                cout<<"  ";
            else
                cout<<"* ";
        }
        cout<<endl;
    }
}
void Patterns::halfPyraminUsingNumber(){
    for(int i=1;i<=this->n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void Patterns::floyidTriangle(){
    int count =1;
    for(int i=1;i<=this->n;i++){
        for(int j=0;j<i;j++){
            cout<<count++<<" ";
        }
        cout<<endl;
    }
}
void Patterns::butterflyPattern(){
    for(int i=1;i<=this->n;i++){
        for(int j=0;j<i;j++){
                cout<<"* ";
        }
        int space = 2*n-2*i;
        for(int j=0;j<space;j++){
            cout<<"  ";
        }
        for(int j=0;j<i;j++){
                cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=this->n;i>0;i--){
        for(int j=0;j<i;j++){
                cout<<"* ";
        }
        int space = 2*n-2*i;
        for(int j=0;j<space;j++){
            cout<<"  ";
        }
        for(int j=0;j<i;j++){
                cout<<"* ";
        }
        cout<<endl;
    }
}
void Patterns::invertedPattern(){
    for(int i=this->n;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void Patterns::oddEvenPattern(){
    for(int i=1;i<=this->n;i++){
        for(int j=0;j<i;j++){
            if((i+j)%2!= 0)
                cout<<1<<" ";
            else
                cout<<0<<"  ";
        }
        cout<<endl;
    }
}
void Patterns::rhombusPattern(){
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->n-i;j++){
            cout<<"  ";
        }
        for(int j=0;j<this->n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void Patterns::numberPattern(){
    for(int i=1;i<=this->n;i++){
        for(int j=1;j<=this->n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void Patterns::palindromePattern(){
    for(int i = 1; i <= this->n; i++) {
        int spaces = (this->n - i) * 2;
        for(int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for(int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        for(int j = 2; j <= i; j++) {
            cout << j<<" ";
        }
        cout << endl;
    }
}
void Patterns::starPattern(){
    for(int i = 1; i <= this->n; i++) {
        int spaces = (this->n - i) * 2;
        for(int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for(int j = 2; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for(int i = this->n;i>=1; i--) {
        int spaces = (this->n - i) * 2;
        for(int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "* ";
        }
        for(int j = 2; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}