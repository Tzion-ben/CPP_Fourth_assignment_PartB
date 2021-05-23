/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
FieldDoctor:: FieldDoctor(Board& board, City city)
            : Player(board, city, "FieldDoctor")
            {}

/*decrementing disease stage in the city, can do it nor only in current city
  but in every connected city to vurrent city*/
Player& FieldDoctor::treat (City city){
    /*if the given city is not connected to this->CurrentCity,
    cant treat*/
    bool connected = false;

    if(city == this->_currentCity){
    if(this->_board[this->_currentCity] != 0){
            if(this->_board.isFoundCure(this->_currentCity)){this->_board[this->_currentCity] = 0;}
            else{this->_board[this->_currentCity]--;}
            return *this;
        }
        throw "There is no Infection in the city at all";
    }
    
    /*checks if the currentCIty is connected to given city*/
    for(auto it : this->_board.GetConnections(this->_currentCity)){
        if(it == city){connected = true;}
    }

    if(connected){
        if(this->_board[city] != 0){
            if(this->_board.isFoundCure(city)){this->_board[city] = 0;}
            else{this->_board[city]--;}
            return *this;
        }
        throw "There is no Infection in the city at all";
    }
    
    /*if not nearby city OR not this->currentCity*/
    throw "can't treat";
}