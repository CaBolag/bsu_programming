#include<iostream>
#include<ctime>

int GetOddOccurrence (int*, size_t);
int MaxProduct(int*, size_t);
void Sort(int*,size_t);
void ChoicesSort(int *, size_t);
int BinarySearch(int*, size_t, int);
void InsertSort(int*, size_t);
void PrintArray(int*, size_t,const char[]);
void InitArray(int*, size_t);
void Subset(int* ,int* , size_t, size_t);

int main(){
    //task1
    std::cout<<"Task1"<<std::endl;
    size_t Size=10;
    int *Array= new int[Size] ;
    std::cout << "Enter the size of an array1:";
    std::cin>>Size;
    std::cout<<"Enter the elements:";
    for(int i=0;i<Size;i++){
        std::cin>>Array[i];
    }
    std::cout<<GetOddOccurrence(Array, Size)<<std::endl;;

    Size=10;
    //task2
    std::cout<<"Task2"<<std::endl;
    srand(static_cast<size_t>(time(0)));
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    std::cout<<MaxProduct(Array, Size)<<std::endl;

    //task3
    std::cout<<"Enter the number of coefficients1:";
    size_t size1;
    std::cin >>size1;
    std::cout<<"Enter the number of coefficients2:";
    size_t size2;
    std::cin>>size2;

    int *array1= new int[size1];
    int *array2= new int[size2];
    std::cout<<"Enter coefficients 1:";
    for (int i=0;i<=size1;i++){
        std::cin>>array1[i];
    }
    std::cout<<"Enter coefficients 2:";
    for (int i=0;i<=size2;i++){
        std::cin>>array2[i];
    }
    int maxsize,minsize;
    (size1>=size2)?maxsize=size1,minsize=size2:maxsize=size2,minsize=size1;
    int sum[maxsize];
    for(int i=0;i<=minsize;i++){
        sum[i]=array1[i]+array2[i];
    }
    for(int i=minsize+1;i<=maxsize;i++){
        (size1>=size2)?sum[i]=array1[i]:sum[i]=array2[i];
    }
    std::cout << "Sum: ";
    for(int i=0; i<=maxsize; i++){
        std::cout << sum[i] << " ";
    }

    int size=size1+1+size2;
    int *product=new int[size];

    for(int i=0; i<=minsize;i++){
        for(int j=i;j<=minsize;j++){
            (size1<size2)?product[j+i]=product[j+i]+array1[j]*array2[i]:product[i+j]=product[i+j]+array1[i]*array2[j];
        }
    }
        for(int i=minsize+1;i<=maxsize;i++){
            (size1>size2)?product[i]+=array1[i]:product[i]+=array2[i];
        }

    std::cout << "\nProduct: ";
    for(int i=0; i<=size1+1+size2; i++){
        std::cout << product[i] << " ";
    }


    //task4
    std::cout<<"Task4"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    Sort(Array,Size);
    PrintArray(Array, Size, "Sorted Array\n");

    //task5
    std::cout << "Task 5" << std::endl;
    const size_t max_size = 100;
    int array[max_size];
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    PrintArray(array, n, "Original array  ");
    InsertSort(array, n);
    PrintArray(array, n, "Sorted array:");

    int min_diff = 1000;
    for (int i = 1; i < n; i++)
    {
        if (array[i] - array[i - 1] < min_diff)
        {
            min_diff = array[i] - array[i - 1];
        }
    }
    int i = 1;
    while (i < n)
    {
        int diff = array[i] - array[i - 1];
        if (diff % min_diff != 0)
        {
            //Первый множитель min_diff
            int div = 2;
            while (min_diff % div != 0)
            {
                if (div == 2)
                {
                    div++;
                }
                else
                {
                    div += 2;
                }
            }
            min_diff /= div;
            i = 0;
        }
        i++;
    }
    for (int i = array[0]; i <= array[n - 1]; i += min_diff)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //task6
    std::cout<<"Task6"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    ChoicesSort(Array,Size);
    PrintArray(Array, Size, "Sorted Array\n");

    //task7
    std::cout<<"Task7"<<std::endl;
    InitArray(Array, Size);
    PrintArray(Array, Size,"Initial Array\n");
    InsertSort(Array, Size);
    PrintArray(Array, Size, "Sorted Array\n");

    //task 8
    std::cout<<"Task8"<<std::endl;
    std::cout << "Enter the size of bigger array:";
    std::cin>>size1;
    std::cout << "Enter the size of smaller array:";
    std::cin>>size2;
    int *Array1= new int[size1] ;
    int *Array2= new int[size2] ;
    std::cout << "Enter a big array:";
    for (int i=0;i<=size1;i++){
        std::cin>>Array1[i];
    }
    std::cout << "Enter a small array:";
    for (int j=0;j<=size2;j++){
        std::cin>>Array2[i];
    }
    Subset(Array1,Array2,size1,size2);
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

int MaxProduct(int *array, size_t size)
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

void Subset(int* big ,int* small, size_t big_size, size_t small_size){
    int m=0;
    int *count=new int[big_size+small_size];
    for(int i=0;i<=big_size;i++){
            if(small[0]=big[i]){
                count[m]=i;
                m++;
            }
        }
    bool result;
    for (int i=0;i<=m;i++){
        int x=count[i];
        int ind=0;
        for(int j=x;j<=j+small_size+1;j++) {
            if (big[j] = small[ind]) {
                ind++;
                result=true;
            }
            else{
                result=false;
            }
        }
        if(result==true){
            std::cout<<count[i];
            break;
        }
    }
}

