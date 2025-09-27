#include <bits/stdc++.h>
using namespace std;


class student{

  string name,dept;
  int roll;

  public:
  void set_val(string n, string d, int a){

      name=n;
      dept=d;
      roll=a;

  }

  void display(){
    cout<<"Name: "<<name<<"\nDepartment: "<<dept<<"\nRoll: "<<roll;
  }

};

class result{

  int marks[5];
  public:
    void set_val(int arr[]){
      for(int i=0; i<5; i++){
        marks[i] = arr[i];
      }
    }
    int* get_mark(){
        return marks;
    }

};

void everything(student stud, result res){

   cout<<"Student details:\n";
   stud.display();
   cout<<"\nMarks: ";

   int mrk[5];
   int tot=0;

   for(int i=0; i<5; i++){
        mrk[i] = *(res.get_mark()+i);
   }

   for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(mrk[j]<mrk[j+1])
                swap(mrk[j],mrk[j+1]);
        }
   }

   for(int i=0; i<5; i++){
    cout<<mrk[i]<<" ";
    tot+=mrk[i];
   }
   cout<<"\nTotal: "<<tot<<"\nAverage: "<<fixed<<setprecision(2)<<tot/5.0<<"\nHighest: "<<mrk[0]<<"\nLowest: "<<mrk[4]<<"\nSecond Highest: "<<mrk[1]<<endl;

}
int main(){

   student s;
   result r;

   string name,dep;
   int rll;
   int m[5];

   cout<<"Enter name: ";
   cin>>name;
   cout<<"Enter department: ";
   cin>>dep;
   cout<<"Enter roll: ";
   cin>>rll;
   cout<<"Enter 5 marks: ";
   for(int i=0; i<5; i++){
    cin>>m[i];
   }

   s.set_val(name,dep,rll);
   r.set_val(m);
   everything(s,r);


}
