/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Medic.hpp"

using namespace std;
using namespace pandemic;

/*using father constractor*/
Medic:: Medic (Board& board, City city)
            : Player(board, city, "Medic")
                {}

Player& Medic::drive (City city){
    this->Player::drive(city);
    if(this->_board.isFoundCure(city)){
        this->_board[this->_currentCity] = 0;
    }
    return *this;
}

/***********************************************************/
Player& Medic::fly_direct (City city){
    this->Player::fly_direct(city);
    if(this->_board.isFoundCure(city)){
        this->_board[this->_currentCity] = 0;
    }
    return *this;
}

/***********************************************************/
Player& Medic::fly_charter (City city){
    this->Player::fly_charter(city);
    if(this->_board.isFoundCure(city)){
        this->_board[this->_currentCity] = 0;
    }
    return *this;
}

/***********************************************************/
Player& Medic::fly_shuttle (City city){
    this->Player::fly_shuttle(city);
    if(this->_board.isFoundCure(city)){
        this->_board[this->_currentCity] = 0;
    }
    return *this;
}

/***********************************************************/
/*decrementing disease stage in the city to 0*/
Player& Medic::treat (City city){
    /*no Infection in the city = 0*/
    if(this->_board[city] == 0){throw "There is no Infection in the city at all";}
    this->_board[city] = 0;
    return *this;
}