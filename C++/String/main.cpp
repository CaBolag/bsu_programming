#include<iostream>
#include<fstream>
#include<string>
//week_5_string
bool checkFileOpen(std::ifstream & in)
{
    if (!in.is_open())
    {
        std::cout << "Error file open\n";
        return false;
    }
    return true;
}
int findMax(int a[], size_t size)
{
    int max = a[0];
    int index = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return index;
}

void addElement(std::ifstream &in,std::ofstream &out,std::string before_elem,std::string elem);
void replaceElements(std::ifstream&, std::ofstream&,std::string,std::string);
void countKeyWords(std::ifstream &in,std::ofstream& out, std::string[], int[], size_t);
void DeleteElements(std::ifstream &in,std::ofstream &out, std::string);
void Convector(std::ifstream &in,std::ofstream& out);
int main() {
    {
        //task1
        // Вставить слово перед другим словом
        char value1;
        std::ifstream in("C:\\Clion projects\\Guseinova\\week_5_string\\main.cpp");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week_5_string\\task1.txt");
        std::string before_elem = "char", elem = "unsigned";
        if (checkFileOpen(in)) {
            addElement(in, out, before_elem, elem);
        }
        char value2;
    }
    {
        //task2
        //заменить элемент на другой
        std::ifstream in("C:\\Clion projects\\Guseinova\\week_5_string\\text.txt");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week_5_string\\task2.txt");
        if (checkFileOpen(in)) {
            std::string element = "We", replace = "THEY";
            replaceElements(in, out, element, replace);
        }
    }
    {
        //Task3
        //Найти все встречающий ключевые слова, удалить наиболее встречающееся
        std::ifstream in("C:\\Clion projects\\Guseinova\\week_5_string\\main.cpp");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week_5_string\\task3.txt", std::ios::trunc);
        std::string str;
        const size_t size = 7;
        std::string keyWords[size] = {"if", "while", "int", "return", "true", "false", "bool"};
        int countWords[size] = {0};

        if (checkFileOpen(in)) {
            countKeyWords(in, out, keyWords, countWords, size);
            int index = findMax(countWords, size);
            std::string delete_word=keyWords[index];
            DeleteElements(in, out, delete_word);
        }
        in.close();
    }
    {
        //task4
        //Преобразовать число double(представляющее собой денежную сумму в рублях и копейках) в строку, разделив тройки цифр в рублях пробелом
        std::ifstream in("C:\\Clion projects\\Guseinova\\week_5_string\\task4_input.txt");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week_5_string\\task4.txt", std::ios::trunc);
        Convector(in, out);
    }
    return 0;
}

void addElement(std::ifstream &in, std::ofstream &out, std::string before_elem, std::string elem) {
    std::string str;
    int position = 0;
    while (!in.eof()) {
        getline(in, str);
        while (position != std::string::npos) {
            position = str.find(before_elem, position);
            if (position == std::string::npos) {
                break;
            } else {
                str.insert(position, elem);
                position += 13;//длина "unsigned char"
            }
        }
        out << str << "\n";
    }
}
void replaceElements(std::ifstream &in, std::ofstream &out, std::string element, std::string replace) {
    std::string str;
    while (!in.eof()) {
        getline(in, str);
        int position = 0;
        while (position != std::string::npos) {
            position = str.find(element, position);
            if (position == std::string::npos) {
                break;
            } else {
                str.replace(position, element.length(), replace);
            }
            position += element.length();
        }
        out << str << "\n";
    }
}
void countKeyWords(std::ifstream &in, std::ofstream &out, std::string keyWords[], int countWords[], size_t size) {
    std::string str;
    while (!in.eof()) {
        getline(in, str);
        for (size_t i = 0; i < size; i++) {
            int position = 0;
            while (position != std::string::npos) {
                position = str.find(keyWords[i], position);
                if (position == std::string::npos) {
                    break;
                } else {
                    position++;
                    countWords[i]++;
                }
            }
        }
    }

    for (size_t i = 0; i < size; i++) {
        out << keyWords[i] << " " << countWords[i] << "\n";
    }
}
void DeleteElements(std::ifstream &in, std::ofstream &out, std::string delete_word) {
    std::string str;
    in.seekg(0, std::ios::beg);
    while (!in.eof()) {
        getline(in, str);
        int position = 0;
        while (position != std::string::npos) {
            position = str.find(delete_word, position);
            if (position == std::string::npos) {
                break;
            } else {
                str.erase(position, delete_word.length());
                position++;
            }
        }
        out << str << "\n";
    }
}

void Convector(std::ifstream &in, std::ofstream &out) {
    double number;
    if (checkFileOpen(in)) {
        in >> number;
        int rub = (int) number;
        int kop = (int) (number - rub) * 100;
        std::string str = std::to_string(rub);
        for (int i = str.length() - 3; i > 0; i -= 3) {
            str.insert(i, " ");
        }
        int last = rub % 100;
        if (last / 10 == 1) {
            last = 0;
        }
        last %= 10;
        switch (last) {
            case 1:
                str += " rubl";
                break;
            case 2:
            case 3:
            case 4:
                str += " rublya";
                break;
            default:
                str += " rubley";
                break;
        }
        str += " " + std::to_string(kop) + " kop.";
        out << str;
    }
}

