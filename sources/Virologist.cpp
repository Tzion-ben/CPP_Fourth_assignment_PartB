/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Virologist:: Virologist (Board &board, City city)
            : Player(board, city, "Virologist")
                {
                    // _playerCards.insert(city);
                }

/*decrementing disease stage in every city that he wants*/
Player& Virologist::treat (City city){
    if(this->_playerCards.find(city) != this->_playerCards.end()
        ||
      this->_currentCity == city){
        this->Player::treat(city);
        return *this;
    }
    throw "can't_treat";
}