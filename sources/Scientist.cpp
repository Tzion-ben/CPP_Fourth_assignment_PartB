/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Scientist:: Scientist (Board& board, City city, int n)
            : Player(board, city, "Scientist"), _n_cards_discover_cure(n)
                {}


/*discover a new cure for one of the disease*/
Player& Scientist::discover_cure (Color color){
    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        ==
        this->_board.GetCitiesResearchStations().end()){
        throw "no have a reserch station, can't discover a cure";
    }
    if(!isHave_5_or_n_cards(color, this->_n_cards_discover_cure)){
        throw "no have n cards in the specific color";
    }
    this->_board.SetCure(color);
    return *this;
}