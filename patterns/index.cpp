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
    P.invertedHalfPyramid();
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
