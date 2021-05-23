/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Researcher:: Researcher (Board& board, City city)
            : Player(board, city, "Researcher")
                {}

/*discover a new cure for one of the disease in any sity that she wants*/
Player& Researcher::discover_cure (Color color){
    if(this->_board.isFoundCure(color)){return *this;}/*already found a cure*/

    if(isHave_5_or_n_cards(color, FIVE_SAME_CARDS)){
        this->_board.SetCure(color);
        return *this;
    }
    throw "no have 5 cards in the specific color";
}