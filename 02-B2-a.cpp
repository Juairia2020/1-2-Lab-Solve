/*Create a Matrix class that-
--> Uses a parameterized constructor to dynamically allocate a 2D matrix of size r*c
--> Implements a copy constructor for deep copying
--> Uses a destructor to deallocate memory and print a message
--> Uses a static counter to track the number of active matrices
*/

#include <bits/stdc++.h>
using namespace std;

class Matrix{
   int row,col;
   int **matrix;
   public:
       static int cnt;
       Matrix(int r, int c){
           row=r;
           col=c;

           cnt++;
           matrix = new int*[row];
           for(int i=0; i<row; i++){
            matrix[i] = new int[col];
           }

           for(int i=0; i<row; i++){
              for(int j=0; j<col; j++){
                matrix[i][j]=0;
              }
           }
       }
       Matrix(Matrix &mat){
           row = mat.row;
           col = mat.col;
           cnt++;

           matrix = new int*[row];
           for(int i=0; i<row; i++){
            matrix[i] = new int[col];
            for(int j=0; j<col; j++){
                matrix[i][j] = mat.matrix[i][j];
            }
           }

       }
       ~Matrix(){

           for(int i=0; i<row; i++){
               delete[] matrix[i];
           }
           delete[] matrix;
           cnt--;
           cout<<"Matrix destroyed. Active count: "<<cnt<<endl;
       }



       // Just to show usage
    void setVal(int r, int c, int val) { matrix[r][c] = val; }
    void print(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};

int Matrix::cnt=0;

int main(){

    Matrix m1(2, 3);
    m1.setVal(0, 0, 5);
    m1.setVal(1, 2, 9);
    cout<<"Matrix m1:\n";
    m1.print();

    Matrix m2=m1;
    cout<<"Matrix m2 (copied from m1):\n";
    m2.print();

    cout<<"Active matrices: "<<Matrix::cnt<<"\n";
}
