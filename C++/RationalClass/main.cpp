#include"Rational.h"
int main()
{
    {
        Rational r(1, 2), r1(2,3), r2 = r;
        r2 = r + r1;
        std::cout << r2<<"\n";
        r2 = r * r1;
        std::cout << r2<<"\n";
        r2 = r / r1;
        std::cout << r2 << "\n";
        std::cout << (r == r1)<<"\n";
        std::cout << (r < r1) << "\n";
        std::cout << (r > r1) << "\n";
    }
    return 0;
}
