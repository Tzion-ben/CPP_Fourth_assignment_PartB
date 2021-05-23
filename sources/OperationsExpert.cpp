/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
OperationsExpert:: OperationsExpert (Board& board, City city)
            : Player(board, city, "OperationsExpert")
                {}

/*builds a research station in any city that he wants*/
Player& OperationsExpert::build (){
    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        == 
        this->_board.GetCitiesResearchStations().end()){
        this->_board.GetCitiesResearchStations().insert(this->_currentCity);
    }
    return *this;
}