#include <iostream>
#include<cmath>
#include <iomanip>
int main() {
    {
        //Task1
        std::cout << "Enter n:";
        int n;
        std::cin>>n;
        bool isAutom=true;
        int count=0;
        for(int i=1;count<n;i++){
            static_cast<unsigned long long>(i);
            unsigned long long copy=i;
            unsigned long long sqr=copy*copy;
            do{
                if (sqr==18446744073709551615) {
                    std::cout<<"N numbers cannot be found among numbers like unsigned int / unsigned long long"<<std::endl;
                    break;
                }
                if (sqr%10!=copy%10){
                    isAutom=false;
                }
                sqr/=10;
                copy/=10;
            }
            while(copy%10>0);
            //Проверяем, является ли чило автоморфным
            if(isAutom==true){
                std::cout<<i<<" ";
                count+=1;
            }
        }
    }

    {
        //Task2
        std::cout<<"\nEnter a:";
        int a;
        std::cin>>a;
        std::cout<<"Enter b:";
        int b;
        std::cin>>b;

        std::cout<<"Result:";
        for(int i=a;i<=b;i++) {
            int sum=0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if(sum>i){
                std::cout<<i<<" ";
            }
        }
    }

    {
        //Task3
        std::cout << "\nEnter n:";
        int n;
        std::cin >> n;
        std::cout<<"Result is ";
        for (int i = 2; i <= n; i++) {
            int j = 0;
            while (n % i == 0) {
                j += 1;
                n /= i;
            }
            if (j != 0) {
                std::cout <<i << "^" << j <<" ";
            }
        }
    }

    {
        //Task4
        std::cout<<"\nEnter n:";
        int n;
        std::cin>>n;
        double count=0;
        int m=n;
        int min=n;
        while ( m > 0 ) {
            if ((m % 10) < min) {
                min = m % 10; //Находит минимум
                count+=1; //Находит количество цифр
            }
            m/=10;
        }
        n=(n+pow(10.,count)*min)*10+min;
        std::cout<<n<<std::endl;
    }

    {
        //Task5
        long double x,k,epsilon,e;
        std::cout<<"Raised e to the power of ... : ";
        std::cin>>x;
        std::cout<<"Enter a number of simbols after comma:";
        std::cin>>k;
        epsilon=pow(10.,-k);
        //Вычисление по формуле
        long double fact = 1,sum=1,summand=1,power,numerator=1;
        for(power=1;summand>epsilon;power++) {
            fact *= power;
            numerator*=x;
            summand =  numerator/ fact;
            sum += summand;
        }
        //Вычисление с помощью стандартной функции
        e=exp(x);
        //Вывод и сравнение значений
        std::cout<<"Value by formula:"<<std::fixed<<std::setprecision(k)<<sum<<std::endl;
        std::cout<<"Value by function:"<<std::fixed<<std::setprecision(k)<<e<<std::endl;
        std::cout << (sum == e ? "Match" : "Dont match" )<< std::endl;
    }
    return 0;
}

