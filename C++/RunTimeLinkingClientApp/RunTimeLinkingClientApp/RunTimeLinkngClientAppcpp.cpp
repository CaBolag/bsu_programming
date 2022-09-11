
#include <windows.h>
#include <iostream>
#include <conio.h>

typedef void* (__cdecl* IMPORTEDFUNCTION)();

int main(int argc, char* argv[])
{
	HINSTANCE hdll = NULL;
	IMPORTEDFUNCTION CreateVector;


	hdll = LoadLibrary("DllMain.dll");		// load the dll
	CreateFoo = static_cast <fpFunctv> (		// get the function pointer
		GetProcAddress(hdll, "_CreateFooClassInstance"));

	piFoo = static_cast<piFoo*> (CreateFoo());	// get pointer to object

	piFoo->SetNumber(8);				// start using the object
	cout << "Foo::number is epual to: "
		<< piFoo->GetNumber()
		<< endl;

	cout << "Enter new value for Foo::number: ";
	int temp;
	cin >> temp;
	piFoo->SetNumber(temp);
	cout << "Foo::number is now: "
		<< piFoo->GetNumber()
		<< endl;
	getch();
	delete piFoo = NULL;				// delete the object
	FreeLibrary(hdll);				// free the dll
}