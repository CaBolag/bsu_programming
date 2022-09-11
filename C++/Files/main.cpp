#include<iostream>
#include<fstream>
#include<string>

bool checkFileOpen(std::ifstream & in);
void countKeyWords(std::ifstream &in,std::ofstream& out, std::string[], int[], size_t);
void DeleteElements(std::ifstream &in,std::ofstream &out, std::string[], int);
void addElement(std::ifstream &in,std::ofstream &out,std::string before_elem,std::string elem);
void replaceElements(std::ifstream&, std::ofstream&,std::string,std::string);

int main()
{
    setlocale(LC_ALL,"Russian");
    {
        //task1
        char value1;
        std::ifstream in("C:\\Clion projects\\Guseinova\\week5\\main.cpp");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week5\\task1.txt");
        std::string before_elem="char",elem="unsigned";
        if (checkFileOpen(in)){
            addElement(in,out,before_elem,elem);
        }
        char value2;
    }

    {
        //task2
        std::ifstream in("C:\\Clion projects\\Guseinova\\week5\\text.txt");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week5\\task2.txt");
        if (checkFileOpen(in)) {
            std::string element="We", replace="THEY";
            replaceElements(in, out, element, replace);
        }

    }
    {
        //Task3
        std::ifstream in("C:\\Clion projects\\Guseinova\\week5\\main.cpp");
        std::ofstream out("C:\\Clion projects\\Guseinova\\week5\\task3.txt", std::ios::trunc);
        std::string str;
        const size_t size = 7;
        std::string keyWords[size] = {"if", "while", "int", "return", "true", "false", "bool"};
        int countWords[size] = {0};

        if (checkFileOpen(in)) {
            countKeyWords(in, out, keyWords, countWords, size);
            int index = findMax(countWords, size);
            DeleteElements(in, out, keyWords, index);

        }
    }
    return 0;
}


bool checkFileOpen(std::ifstream & in){
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

void countKeyWords(std::ifstream &in,std::ofstream& out, std::string keyWords[], int countWords[],size_t size){
    std::string str;
    while (!in.eof())
    {
        getline(in, str);
        for (size_t i = 0; i < size; i++)
        {
            int position = 0;
            while (position != std::string::npos)
            {
                position = str.find(keyWords[i], position);
                if (position == std::string::npos)
                {
                    break;
                }
                else
                {
                    position++;
                    countWords[i]++;
                }
            }
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        out << keyWords[i] << " " << countWords[i] << "\n";
    }
}

void DeleteElements(std::ifstream &in,std::ofstream& out,std::string keyWords[], int index){
    std::string str;
    in.seekg(0,std::ios::beg);
    while (!in.eof())
    {
        getline(in, str);

        int position = 0;
        while (position != std::string::npos)
        {
            position = str.find(keyWords[index], position);
            if (position == std::string::npos)
            {
                break;
            }
            else
            {
                str.erase(position, keyWords[index].length());

            }
        }
        out << str << "\n";
    }
}

void addElement(std::ifstream &in,std::ofstream &out,std::string before_elem,std::string elem){
   std::string str;
   int position=0;
    while(!in.eof()){
        getline(in,str);
        while (position != std::string::npos){
            position=str.find(before_elem[0],position);
            if (position == std::string::npos)
            {
                break;
            }
            else
            {
                str.insert(position,elem);
            }
            position++;
        }
        out<<str<<"\n";
    }
}

void replaceElements(std::ifstream &in,std::ofstream &out,std::string element,std::string replace){
    std::string str;
    while(!in.eof()){
        getline(in,str);
        int position=0;
        while (position != std::string::npos){
            position=str.find(element,position);
            if (position == std::string::npos)
            {
                break;
            }
            else
            {
                str.replace(position,element.length(),replace);
            }
            position+= element.length();
        }
        out<<str<<"\n";
    }
}
