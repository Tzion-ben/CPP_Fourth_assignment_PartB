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
  without throwing a city ,card/
  if there is no reaserch station: use regular fly_direct method*/
Player& Dispatcher::fly_direct (City city){
    if(this->_currentCity == city){throw "can't fly from city to it self";}

    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        != 
        this->_board.GetCitiesResearchStations().end()){
            this->_currentCity = city;
            return *this;
    }
 
    return this->Player::fly_direct(city); 
}