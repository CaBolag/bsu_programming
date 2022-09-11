
#include<windows.h>
#include"resource.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"

HINSTANCE hInst;

INT_PTR CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WndProc);
    return 0;
}


INT_PTR CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    static Model model;
    static Controller controller(model);
    static View ResultView (model, hDlg, IDC_EDIT_OUTPUT);


    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:

        return (INT_PTR)TRUE;

    case WM_COMMAND:
        controller.ProcessInput(hDlg, wParam);
        return (INT_PTR)TRUE;
        break;
    }
    return (INT_PTR)FALSE;

    return 0;
}


//int main() {
//
//    Set set1{ 1,2,3 };
//    Set set2{ 2,3,4 };
//    std::cout << "set1=" << set1;
//    std::cout << "set2=" << set2 << "\n";
//
//    //operator+
//    Set union_set = set1 + set2;
//    std::cout << "set1+set2=" << union_set << "\n";
//
//    //operator+=
//    std::cout << "set1+=set2\n";
//    set1 += set2;
//    std::cout << "set1=" << set1 << "\n";
//
//    //operator*
//    Set set3{ 2,4 };
//    std::cout << "set3=" << set3;
//    Set intersection_set = set1 * set3;
//    std::cout << "set1*set3= " << intersection_set << "\n";
//
//    //operator*=
//    set1 *= set3;
//    std::cout << "set1*=set3" << "\n";
//    std::cout << "set1=" << set1 << "\n";
//
//
//    //Swap()
//    std::cout << "set1=" << set1;
//    std::cout << "set2=" << set2;
//    set1.Swap(set2);
//    std::cout << "set1.Swap(set2)\n";
//    std::cout << "set1=" << set1;
//    std::cout << "set2=" << set2 << "\n";
//
//    /*  Set::SetIterator iterator(set1);
//      for(iterator.First();!iterator.IsDone();iterator.Next()){
//        std::cout<<iterator.CurrentItem();
//      }*/
//
//      //operator=(Set&)
//    Set set4{ 1,3 };
//    std::cout << "set3=" << set3;
//    std::cout << "set4=" << set4;
//    std::cout << "set4=set3" << "\n";
//    set4 = set3;
//    std::cout << "set3=" << set3;
//    std::cout << "set4=" << set4;
//    std::cout << "set4==set3" << "\n";
//    std::cout << (set4 == set3) << "\n";
//    std::cout << "set4!=set3" << "\n";
//    std::cout << (set4 != set3) << "\n";
//
//
//    //operator=(Set&& )
//    std::cout << "\n";
//    Set set5{ 1,3 };
//    std::cout << "set4=" << set4;
//    std::cout << "set5=" << set5;
//    set4 = std::move(set5);
//    std::cout << "set4=std::move(set5)\n";
//    std::cout << "set4=" << set4;
//    std::cout << "set5=" << set5 << "\n";
//
//    Set set6(std::move(set4));
//    std::cout << "Set set6(std::move(set4))\n";
//    std::cout << "set4=" << set4;
//    std::cout << "set6=" << set6 << "\n";
//
//    std::cout << "set1=" << set1;
//    Set set7(set1);
//    std::cout << "Set set7(set1)\n";
//    std::cout << "set7=" << set7 << "\n";
//    std::cout << "set6==set7" << "\n";
//    std::cout << (set6 == set7) << "\n";
//    std::cout << "set6!=set7" << "\n";
//    std::cout << (set6 != set7) << "\n\n";
//
//    std::cout << "set1=" << set1;
//    set1.Clear();
//    std::cout << "set1.Clear()\n";
//    std::cout << "set1=" << set1 << "\n";
//
//
//    std::cout << "SumVisitor\n";
//    SumVisitor sum_visitor;
//    set7.Accept(sum_visitor);
//    std::cout << "Set7 sum = " << sum_visitor.GetTotal() << "\n";
//
//    //Errors
//
//    /*std::cout<<"set6=set7 (unequal size)\n";
//    set6=set7;*/
//
//    /*  std::cout<<"set7[4] (set.Size()=3)";
//      std::cout<<set7[4];*/
//    return 0;
//}