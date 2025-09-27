/*Design a HotelRoom class-
-->A parameterized constructor initializes room number, price, availability
-->A static variable tracks total available rooms
-->Provide bookRoom() and freeRoom() to update availability
-->Use a destructor to print when a room object is removed
*/


#include <bits/stdc++.h>
using namespace std;

class HotelRoom{

  int room_num, price;
  bool avlbl;

  public:
      static int cnt;
      HotelRoom(int rn, int pr, bool av){

          room_num = rn;
          price = pr;
          avlbl = av;
          if(av)cnt++;
      }

      void bookRoom(){
        if (avlbl) {
            avlbl = false;
            cnt--;
            cout << "Room " << room_num << " booked.\n";
        } else {
            cout << "Room " << room_num << " already booked.\n";
        }
      }

      void freeRoom(){
         if (!avlbl) {
            avlbl = true;
            cnt++;
            cout << "Room " << room_num << " is now available.\n";
        } else {
            cout << "Room " << room_num << " was already free.\n";
        }
      }

      ~HotelRoom(){
         cout << "Room object for " << room_num
             << " destroyed. Remaining available rooms: "
             << --cnt << endl;
      }

};

int HotelRoom::cnt = 0;

int main(){

  HotelRoom r1(106, 10000, true), r2(86, 15000, true);
  cout<<"Rooms: "<<HotelRoom::cnt<<endl;
  r1.bookRoom();
  cout<<"Available: "<<HotelRoom::cnt<<endl;
  r1.freeRoom();
  cout<<"Available: "<<HotelRoom::cnt<<endl;



}
