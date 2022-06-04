#include <iostream>

int main()
{
    int N, S;
    std::cin >> N >> S;
    unsigned int v = 0;
    for (unsigned int i = 0; i < N; ++i)
    {
        int ai;
        std::cin >> ai;
        v += v > S ? ai - 1 : ai;
    }
    std::cout << v;
}