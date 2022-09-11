#include"Rational.h"
#include "TRAIN.h"

int main()
{
    {
        //task 1
        Rational r(1, 2), r1(2,3), r2 = r;
        std::cout<<"r1="<<r1<<std::endl;
        std::cout<<"r2="<<r2<<std::endl;
        r2 = r + r1;
        std::cout <<"Sum = "<< r2<<"\n";
        r2 = r * r1;
        std::cout <<"Product = "<<r2<<"\n";
        r2 = r / r1;
        std::cout <<"Quotient  = "<<r2 << "\n";
        std::cout << (r == r1)<<"\n";
        std::cout << (r < r1) << "\n";
        std::cout << (r > r1) << "\n";
    }
    {
        //task 2
        TRAIN train1("Minsk",1,true);
        TRAIN train2("Orsha",2,false);
        TRAIN train3("Minsk",3,true);
        TRAIN train4("Minsk",4,false);
        TRAIN train5(train3);//Проверяем работу копирующего конструктора
        std::vector<TRAIN> trains={train1,train2,train3,train4,train5};
        print_destination(trains);
        print_destination_express(trains);
    }
    return 0;
}