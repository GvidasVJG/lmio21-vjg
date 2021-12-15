#include <iostream>
#include <string>

using namespace std;

int main()
{
    char s[29] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_', ',', '.'};

    string i = "";
    string ret = "";
    cin >> i;
    for (int x=0;x<i.size();x++) {
        for (int y=0;y<29;y++) {
            float temp = 0.0f;
            int mod = 0;
            if (i[x] == s[y]) {
                temp+=y;
                for (int c=0;c<29;c++) {
                    if (c*c*c%29==temp) {
                        mod=c*c*c%29;
                        temp=c*c*c;

                    }
                }
                temp=static_cast<int>(temp);
                for (int c=1;c<29;c++) {
                    if (c*c*c == temp) {
                        ret.push_back(s[c-1]);
                    }
                }

            }
        }
    }
    ret.push_back('.');
    std::cout << ret;
    return 0;
}

