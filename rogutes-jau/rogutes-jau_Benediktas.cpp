#include <iostream>
#include <algorithm>

using namespace std;

int main() {
     int atk, greit;
     int ret = 0;
     cin >> atk >> greit;
     for (int x = 0;x<atk;x++) {
          int m;
          if (ret > greit ) {
               ret-=1;
               m=1;
          }
          int i;
          cin >> i;    
          if (i > greit && m<0) {
               ret+=i-1;
          }
          else {
               ret+=i;
          }

     }
     std::cout << ret;
}