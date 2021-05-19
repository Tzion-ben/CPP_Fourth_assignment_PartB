
#include <iostream>
#include "sources/allSources.hpp"

using namespace std;
using namespace pandemic;


int main()
{
    Board b;
    Dispatcher d{b , City::Atlanta};
    b[City::Baghdad] = 7;
    cout << b << endl;
	


	return 0;
}
