//sorting_algorithms
#include<iostream>
#include<ctime>

int GetOddOccurrence (int *, size_t);
int MaxProduct(int *, int);
void Sort(int *,size_t);
void ChoicesSort(int *, size_t);
int BinarySearch(int *, size_t, int);
void InsertSort(int *, size_t);
void PrintArray(int*, size_t,const char[]);
void InitArray(int*, size_t);
void Progression(int *,int );
void Subset(int *array1,int *array2,int max,int min);


int main(){
    //task1
    //все числа в массиве кроме одного встречаются четное количество раз,
    // одно число встречается нечетное количество раз. Найти это число.
    std::cout<<"Task1"<<std::endl;
    int Size;
    std::cout << "Enter the size:\n";
    std::cin >> Size;
    int *Array= new int[Size] ;
    std::cout << "Enter the elements of array:\n";
    for(int i=0; i<Size; i++){
        std::cin >> Array[i];
    }
    std::cout<<GetOddOccurrence(Array, Size)<<std::endl;

    //task2
    // Выбрать три числа, произведение которых максимально.
    Size=10;
    std::cout<<"Task2"<<std::endl;
    srand(static_cast<size_t>(time(0)));
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    std::cout<<"Max Product="<<MaxProduct(Array, Size)<<std::endl;

    //task3
    //Сумма и произведение многочленов
    {
        int size1;
        std::cout << "Enter the size of array1:";
        std::cin>>size1;
        int *array1=new int[size1];
        std::cout << "Enter the kofficents1:\n";
        for (int i = 0; i < size1; i++) {
            std::cin >> array1[i];
        }
        int size2;
        std::cout << "Enter the size of array2:";
        std::cin>>size2;
        int *array2=new int[size2];
        std::cout << "Enter the kofficents2:\n";
        for (int i = 0; i < size2; i++) {
            std::cin >> array2[i];
        }

        //СУММА
        int max;
        if (size2 <= size1)
            max = size1;
        else
            max = size2;
        int *sum = new int[max];
        for (int k = 0; k < max; k++) {
            sum[k] = array1[k]+array2[k];
            std::cout << sum[k] << " ";
        }
        //ПРОИЗВЕДЕНИЕ
        int *product=new int[size1+size2]{0};
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                product[i + j] += array1[i] * array2[j];
            }
        }
        for (int i = 0; i < max; i++)
            std::cout << product[i]<<" ";
    }
    //task4
    //Функция находит минимальный элемент массива и сортирует все элементы левее его по убыванию, а правее его – по возрастанию
    std::cout<<"Task4"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    Sort(Array,Size);
    PrintArray(Array, Size, "Sorted Array\n");

    //task5
    // Добавить к некоторой последовательности наименьшее  число элементов,  чтобы  получить  арифметическую прогрессию
    int size;
    std::cout << "\nEnter the size of array:\n";
    std::cin >> size;
    int *array=new int [size];
    std::cout << "Enter the elements of array:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    InsertSort(array, size);
    Progression(array,size);

    //task6
    // Найти минимальный элемент, реализовав сортировку выбором
    std::cout<<"Task6"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    ChoicesSort(Array,Size);
    PrintArray(Array, Size, "Sorted Array\n");
    std::cout<<"Min element:"<<Array[0]<<std::endl;

    //task
    //Сортировка вставками с двоичным поиском
    std::cout<<"Task7"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    InsertSort(Array, Size);
    PrintArray(Array, Size, "Sorted Array\n");
    {//task8
        //Является ли один массив элементов подмножеством другого

        int max;
        std::cout << "Enter the size of bigger array:";
        std::cin>>max;
        int *array1=new int[max];
        std::cout << "Enter the elements of bigger array:\n";
        for (int i = 0; i < max; i++) {
            std::cin >> array1[i];
        }
        int min;
        std::cout << "Enter the size of array2:";
        std::cin>>min;
        int *array2=new int[min];
        std::cout << "Enter the elements of array:\n";
        for (int i = 0; i < min; i++) {
            std::cin >> array2[i];
        }
        Subset(array1,array2,max,min);
    }
}


int GetOddOccurrence(int *array, size_t size)
{
    int count = 0,odd=0;
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
                count++;
        }
        if (count % 2 != 0) {
            odd=i;
            break;
        }
    }
    return array[odd];
}

int MaxProduct(int *array, int size)
{
    for (int i =0;i<size;i++){
        for (int k=size-1;k>i;k--){
            if (array[k-1]>array[k]){
                int tmp=array[k-1];
                array[k-1]=array[k];
                array[k]=tmp;
            }
        }
    }
    int max;
    if (array[0]<0 && array[1]<0 && abs(array[1])>array[size-1]){
        max=array[0]*array[1]*array[size-1];
    }
    else {
        max=max=array[size-3]*array[size-2]*array[size-1];
    }
    return max;
}

void Sort(int *array,size_t size)
{

    int min = array[0];
    int index = 0;
    for (int i = 0;i<size;i++){
        if (array[i]<min){
            min = array[i];
            index = i;
        }
    }
    for (int i = 0;i<index;i++){
        for (int k = index - 1;k>i;k--){
            if(array[k]<array[k-1]){
                int tmp = array[k - 1];
                array[k-1]=array[k];
                array[k]=tmp;
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int k=size-1;k>index;k--){
            if (array[k]<array[k-1]){
                int tmp=array[k-1];
                array[k-1]=array[k];
                array[k]=tmp;
            }
        }
    }
}

void ChoicesSort(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        int min=i;
        for (int j = i + 1; j<size; j++) {
            if (array[j] < array[i]) {
                min=j;
            }
        }
        std::swap(array[min], array[i]);
    }
}
int BinarySearch(int *a, size_t size, int key)
{
    int l = 0, r = size;
    int m = (l + r) / 2;
    while (l < r)
    {
        if (a[m] < key)
        {
            l = m + 1;
        }
        else if (a[m] > key)
        {
            r = m;
        }
        else
        {
            return m;
        }
        m = (l + r) / 2;
    }
    return l;
}


void InsertSort(int *a, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int position = BinarySearch(a, i, a[i]);
        int temp = a[i];
        for (int j = i; j >= position; j--)
        {
            a[j] = a[j - 1];
        }
        a[position] = temp;
    }
}


void PrintArray(int *a, size_t size, const char str[])
{
    std::cout << str;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}


void InitArray(int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
    }
}
void Progression(int *array,int size){

    int mindifference = 100;
    for (int i = 1; i < size; i++) {
        if (array[i] - array[i - 1] < mindifference) {
            mindifference = array[i] - array[i - 1];
        }
    }
    for (int i = 1; i < size; i++) {
        if ((array[i] - array[i - 1]) % mindifference == 0)
            continue;
        else {
            int devisor = 2;
            while (mindifference % devisor != 0) {
                if (devisor == 2) {
                    devisor++;
                }
                else {
                    devisor += 2;
                }
            }
            mindifference /= devisor;
            i = 0;
        }
    }
    for (int i = array[0]; i <= array[size - 1]; i += mindifference) {
        std::cout << i << " ";
    }
}
void Subset(int *array1,int *array2,int max,int min){
    int *count=new int[max];
    int index=0;
    for(int i=0;i<max;i++){
        if (array1[i]=array2[0]){
            count[index]=i;//вносит индексы большего массива, которые совпадают с 1ым элементом меньшего массива
            index++;
        }
    }
    bool is_subset;
    for(int i=0;i<=index;i++){
        int x=count[i];
        int k=0;
        for(int j=x;j<=min;j++){
            if (array1[j]=array2[k]){
                is_subset=true;
            }
            else{
                is_subset=false;
            }
            k++;
        }
        if(is_subset==true){
            std::cout<<"Является, начиная с элемента под номером "<<x;
        }
    }
}

