#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
     int atk, greit;
     int ret = 0;
     cin >> atk >> greit;
     vector<int> grc;
     for (int x = 0;x<atk;x++) {
          int i;
          cin >> i;
          grc.push_back(i);
     }
     for (int x = 0;x<atk;x++) {
          if (grc[x] > greit && x == atk-1) {
              ret+=grc[x];
              continue;
          }
          if (grc[x] > greit) {
               ret+=grc[x];
               ret-=1;
          }
          else if (grc[x] == greit || grc[x] < greit) {
               ret+=grc[x];
          };
          if (ret < 0) {
               ret = 0;
          }
     }
     if (ret < 0) {
          ret=0;
     }
     std::cout << ret;

}
