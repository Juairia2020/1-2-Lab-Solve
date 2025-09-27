#include <bits/stdc++.h>
using namespace std;

class Relation{
int num,den;
public:
    Relation(int x=0, int y=1){
      num=x;
      den=y;
      if(y==0){
        cout<<"Invalid fraction";
        exit(0);
      }
    }

    Relation & operator=(const Relation & obj){

     if(this!= &obj){

        num = obj.num;
        den = obj.den;

     }

     return *this;

    }
    friend istream& operator>>(istream & input, Relation &obj);
    friend ostream& operator<<(ostream & output, Relation &obj);
    friend Relation operator+ (Relation &obj1, Relation &obj2);
    friend Relation operator/ (Relation &obj1, Relation &obj2);
    friend bool operator== (Relation &obj1, Relation &obj2);

};
istream& operator>>(istream & input, Relation &obj){
   input>>obj.num>>obj.den;
   return input;
}

Relation operator+ (Relation &obj1, Relation &obj2){
    Relation r;
    r.num = obj1.num * obj2.den + obj2.num * obj1.den;
    r.den = obj1.den * obj2.den;
    return r;
}

Relation operator/ (Relation &obj1, Relation &obj2){
    Relation r;
    r.num = obj1.num * obj2.den;
    r.den = obj1.den * obj2.num;
    return r;
}
ostream& operator<<(ostream & output, Relation &obj){

      int gcd= __gcd(obj.num, obj.den);
      obj.num/=gcd;
      obj.den/=gcd;

      if(obj.den!=1)output<<obj.num<<"/"<<obj.den;
      else output<<obj.num;
      return output;

}

bool operator== (Relation &obj1, Relation &obj2){
    return obj1.num*obj2.den == obj1.den*obj2.num;
}

int main(){

    Relation r1,r2,r3,r4;
    cin>>r1>>r2;
    r3= r1+r2;
    r4= r1/r2;
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4;
    if(r1==r2)cout<<"\nGiven fractions are equal.\n";
    else cout<<"\nGiven fractions are not equal.\n";

}
