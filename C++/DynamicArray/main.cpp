#include"Array.h"
int main()
{
    Array arr(20), arr1(10), arr2(std::move(arr1));
    arr =std::move(arr2);
    arr[0] = 1;

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        arr.SetAt(rand(), i);
        std::cout << arr[i] << "\t";
    }
    arr.InsertAt(2,1);
    std::cout<<"\n";
    std::cout<<arr.getSize()<<"\n";

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout<<"\n";
    std::cout<<arr.getSize()<<"\n";

    arr.RemoveAt(1);
    for (size_t i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout<<"\n";
    Array arr4(1);
    arr4[0]=1;
    Array arr3=arr.Append(arr4);
    for (size_t i = 0; i < arr.getSize()+arr4.getSize(); i++)
    {
        std::cout << arr3[i] << "\t";
    }
    arr3.RemoveAll();
    std::cout << arr3.getSize()<<std::endl;
    std::cout <<  arr.IsEmpty()<<std::endl;


    system("pause");
    return 0;
}