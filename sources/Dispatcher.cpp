/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Dispatcher::Dispatcher(Board& board, City city)
            : Player(board, city, "Dispatcher")
            {}


/*Dispatcher can move every city he wants if current city contains a reaserch station
  if not : move from the current city to the city of some card in his hand*/
Player& Dispatcher::fly_direct (City city){
    if(this->_currentCity == city){throw "can't fly from citu to it self";}

    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        != 
        this->_board.GetCitiesResearchStations().end()){
            this->_currentCity = city;
            return *this;
    }
 
    return this->Player::fly_direct(city); 
}