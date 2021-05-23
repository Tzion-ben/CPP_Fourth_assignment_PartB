
#include <iostream>
#include <stdexcept>
#include "sources/allSources.hpp"

using namespace std;
using namespace pandemic;

const int DIFF_PLAYERS = 8;

int main()
{
    Board board;
    OperationsExpert operationsExpert{board, City::Atlanta};
    operationsExpert.take_card(City::Atlanta);

    Dispatcher dispatcher{board, City::Beijing};
    dispatcher.take_card(City::Beijing);

    Scientist scientist{board, City::Lagos, 4};
    scientist.take_card(City::Lagos);

    Researcher researcher{board, City::Tehran};
    researcher.take_card(City::Tehran);

    Medic medic{board, City::Cairo};
    medic.take_card(City::Cairo);

    Virologist virologist{board, City::Seoul};
    virologist.take_card(City::Seoul);

    GeneSplicer geneSplicer{board, City::Mumbai};
    geneSplicer.take_card(City::Mumbai);

    FieldDoctor fieldDoctor{board, City::Taipei};
    fieldDoctor.take_card(City::Taipei);

    board[City::Atlanta] = 7;
    board[City::Beijing] = 4;
    board[City::Lagos] = 8;
    board[City::Tehran] = 1;
    board[City::Cairo] = 24;
    board[City::Seoul] = 23;
    board[City::Mumbai] = 56;
    board[City::Taipei] = 78;
    board[City::Baghdad] = 6;
    board[City::Baghdad] = 4;
    
    cout << "Before changes" << endl;
    cout << board << endl;

    try{
        virologist.take_card(City::Baghdad);
        medic.treat(City::Beijing);
        virologist.treat(City::Baghdad);
        researcher.build();
        virologist.build();
        operationsExpert.build();
        geneSplicer.treat(City::Cairo);
    }catch (const exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // prints a meaningful error message.
	}

    cout << "After changes" << endl;    
    cout << board << endl;
	

	return 0;
}
