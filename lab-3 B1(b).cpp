//Task-2
#include<bits/stdc++.h>
using namespace std;

class Course{

  int code, max_cap;
  char* name;
  static int count;

  public:
      Course(char* s, int c, int cap){
        name = new char(sizeof(s));
        name=s;
        code=c;
        max_cap=cap;

      }
      void registerStudent(){
        if(count>max_cap){
            cout<<"No more registration for course "<<name<<" is possible."<<endl;
        }
        else{
            cout<<"Registered successfully at course "<<name<<"."<<endl;
            count++;
            cout<<"Total registered student: "<<count<<endl;
        }
      }
      void dropStudent(){
        count--;
        cout<<"One student dropped the course "<<name<<". Total registered student: "<<count<<endl;
      }
      ~Course(){
        cout<<"Course "<<name<<" is being deleted"<<endl;
        count--;
      }

};

int Course::count=0;

int main(){

    Course c1("CSE", 1101, 1);
    c1.registerStudent();
    c1.registerStudent();
    c1.registerStudent();
   // c1.dropStudent();
    Course c2("MATH", 1207, 1);
    c1.dropStudent();
    c1.registerStudent();
    c2.registerStudent();
    c2.registerStudent();

}
