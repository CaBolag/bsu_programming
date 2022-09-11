#include <iostream>
//Вариант 1
int main() {

    {
        //Task1
        //Даны координаты поля шахматной доски x, y (целые числа, лежащие в диапазоне 1–8).
        //Учитывая, что левое нижнее поле доски (1, 1) является черным, проверить истинность высказывания: «Данное поле является белым».
        std::cout << "Enter x,y: ";
        int x, y;
        std::cin >> x >> y;
        if (x % 2 == 0 && y % 2 == 0 || x % 2 == 1 && y % 2 == 1) {
            std::cout << "False" << std::endl;
        }
        else
        {
            std::cout << "True" << std::endl;
        }

    }
    {
        //Task2
        //Задана точка M с координатами (x,y). Определить месторасположение этой точки в декартовой системе координат
        // (является ли эта точка началом координат, лежит на одной из координатных осей или расположена в одном из координатных углов).
        setlocale(LC_ALL, "Russian");
        std::cout << "Enter x,y:";
        float x, y;
        std::cin >> x >> y;
        if (x == 0 && y == 0) {
            std::cout << "Является началом координат" << std::endl;
        }
        else if (x == 0 || y == 0) {
            std::cout << "Лежит на координатной оси" << std::endl;
        }
        else {
            if (x > 0 && y > 0) {
                std::cout << "Лежит в 1ой четверти" << std::endl;
            }
            else if (x < 0 and y>0) {
                std::cout << "Лежит во 2ой четверти" << std::endl;
            }
            else if (x < 0 && y < 0) {
                std::cout << "Лежит в 3ей четверти" << std::endl;
            }
            else {
                std::cout << "Лежит в 4ой четверти" << std::endl;
            }
        }
    }
    {
        //Task3
        setlocale(LC_ALL, "Russian");
        std::cout << "Enter the number: " << std::endl;
        int n;
        std::cin >> n;
        std::string s;
        switch (n / 100)
        {
            case 1:
                s = "сто "; break;
            case 2:
                s = "двести "; break;
            case 3:
                s = "триста "; break;
            case 4:
                s = "четыреста "; break;
            case 5:
                s = "пятьсот "; break;
            case 6:
                s = "шестьсот "; break;
            case 7:
                s = "семьсот "; break;
            case 8:
                s = "восемьсот "; break;
            case 9:
                s = "девятьсот "; break;
        }
        if (((n % 100) >= 10) && (n % 100) < 20) {
            switch (n % 100) {
                case 10:
                    s += "десять "; break;
                case 11:
                    s += "одинадцать "; break;
                case 12:
                    s += "двенадцать "; break;
                case 13:
                    s += "тринадцать "; break;
                case 14:
                    s += "четырнадцать "; break;
                case 15:
                    s += "пятнадцать "; break;
                case 16:
                    s += "шестнадцать "; break;
                case 17:
                    s += "семнадцать "; break;
                case 18:
                    s += "восемнадцать "; break;
                case 19:
                    s += "девятнадцать "; break;
            }
        }
        else switch ((n % 100) / 10)
            {
                case 2:
                    s += "двадцать "; break;
                case 3:
                    s += "тридцать "; break;
                case 4:
                    s += "сорок "; break;
                case 5:
                    s += "пятьдесят "; break;
                case 6:
                    s += "шестьдесят "; break;
                case 7:
                    s += "семьдесят "; break;
                case 8:
                    s += "восемьдесят "; break;
                case 9:
                    s += "девяносто "; break;
            }
        switch (n % 10)
        {
            case 1:
                s += "один "; break;
            case 2:
                s += "два "; break;
            case 3:
                s += "три "; break;
            case 4:
                s += "четыре "; break;
            case 5:
                s += "пять "; break;
            case 6:
                s += "шесть "; break;
            case 7:
                s += "семь "; break;
            case 8:
                s += "восемь "; break;
            case 9:
                s += "девять "; break;
        }
        std::cout << s << std::endl;
    }
    {
        //Task4
        int year;
        std::cout << "Enter a year: " << std::endl;
        std::cin >> year;
        std::string s;
        switch ((year-1984)/12 % 5)
        {
            case 0:
                s = "зелён";
                break;
            case 1:
                s = "красн";
                break;
            case 2:
                s = "жёлт" ;
                break;
            case 3:
                s = "бел";
                break;
            case 4:
                s = "чёрн" ;
                break;
        }
        switch ((year-1984) % 12)
        {
            case 0:
                s += "ой крысы";
                break;
            case 1:
                s += "ой коровы";
                break;
            case 2:
                s += "ого тигра";
                break;
            case 3:
                s += "ого зайца";
                break;
            case 4:
                s += "ого дракона";
                break;
            case 5:
                s += "ой змеи";
                break;
            case 6:
                s += "ой лошади";
                break;
            case 7:
                s += "ой овцы";
                break;
            case 8:
                s += "ой обезьяны";
                break;
            case 9:
                s += "ой курицы";
                break;
            case 10:
                s += "ой собаки";
                break;
            case 11:
                s += "ой свиньи";
                break;
            default:
                std::cout<<"Error"<<std::endl;
                break;
        }
        std::cout << "Год " << s << std::endl;
    }
    {
        //Task5
        enum Mon { Jan = 1, Fab, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec };
        size_t day, month, year, helpDay;
        std::cout << "Enter today's date in numbers (day, month, year):\n";
        std::cin >> day >> month >> year;
        switch (month) {
            case Jan: case Mar: case May: case July: case Aug: case Oct: case Dec:
                helpDay = 31;
                break;
            case Apr: case June: case Sep: case Nov:
                helpDay = 30;
                break;
            case Fab:
                (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ? helpDay = 29 : helpDay = 28;
                break;
        }
        if (day < helpDay)
            day++;
        else if ((day == helpDay) && (month != 12)) {
            day = 1;
            month++;
        }
        else {
            day = 1;
            month = 1;
            year++;
        }
        std::cout << "Tomorrow is " << day << "." << month << "." << year << std::endl;
    }
    return 0;
}
