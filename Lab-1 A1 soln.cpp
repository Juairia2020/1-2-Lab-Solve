#include <bits/stdc++.h>
using namespace std;

class point{
    int x,y;
    public:
    void set_val(int a,int b){
        x=a;
        y=b;
    }

    int get_x(){
        return x;
    }

    int get_y(){
        return y;
    }

};

class triangle{
    point p1,p2,p3;

    public:
    void getter(){
        int a,b;
        cin>>a>>b;
        p1.set_val(a,b);

        cin>>a>>b;
        p2.set_val(a,b);

        cin>>a>>b;
        p3.set_val(a,b);
    }

    void setter(){
        cout<<"Points of the triangle:\n";
        cout<<"P1("<<p1.get_x()<<","<<p1.get_y()<<"), ";
        cout<<"P2("<<p2.get_x()<<","<<p2.get_y()<<"), ";
        cout<<"P3("<<p3.get_x()<<","<<p3.get_y()<<")";
    }

    double area(){
        double ans= p1.get_x()*p2.get_y() + p2.get_x()*p3.get_y() - p1.get_y()*p2.get_x() + p2.get_y()*p3.get_x();

        return 0.5*abs(ans);
    }
};

int main() {
    triangle t;

    t.getter();
    t.setter();
    cout<<"\nArea of triangle is\n";
    cout<<fixed<<setprecision(2)<<t.area();

}
