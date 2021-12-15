#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int main() {
     int x, y, z, t;
     vector<int> ret;
     cin >> x >> y >> z;
     cin >> t;
     ret.push_back(y*100+x*10+z);
     ret.push_back(y*100+z*10+x);
     ret.push_back(x*100+y*10+z);
     ret.push_back(x*100+z*10+y);
     ret.push_back(z*100+y*10+x);
     ret.push_back(z*100+x*10+y);
     sort(ret.begin(), ret.end());
     for (int i=0;i<ret.size();i++) {
          if (ret[i] == t) {
               cout << i+1;
          }
          else {
               continue;
          }
     }

}
