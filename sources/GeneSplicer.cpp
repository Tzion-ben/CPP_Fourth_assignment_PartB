/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
GeneSplicer:: GeneSplicer (Board& board, City city)
            : Player(board, city, "GeneSplicer")
                {}


/*discover a new cure for one of the disease with any cards of any color*/
Player& GeneSplicer::discover_cure (Color color){
    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        !=
      this->_board.GetCitiesResearchStations().end()){
        if(this->_playerCards.size() >= FIVE_SAME_CARDS){
            this->_board.SetCure(color);
            this->_playerCards.clear();
            return *this;
        }
    }
    /*else ->*/
   throw "no have 5 cards at all";
}