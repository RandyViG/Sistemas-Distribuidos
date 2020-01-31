#include <iostream>
using namespace std;

int main( )
{
	int varn = 2;
	int nvarn=varn+(++varn);
	cout << "Valor con n+(++n) es: \n";
	cout << nvarn;
	cout << "\n";
return 0;
}