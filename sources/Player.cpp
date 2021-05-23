/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */

#include "Player.hpp"

using namespace std;
using namespace pandemic;

/*constractor*/
Player:: Player (Board& board , City city, string role)
         :_board(board), _currentCity(city),_role(std::move(role))
         {}

/*virtual distractor*/
Player::~Player(){}

/*****************************************************************************/
Player& Player::drive (City city){   
    bool found = false;/*detect if city is a neighbor of this->_cirrentCity*/
    if(city ==this->_currentCity){throw "cant drive from city to it self";}       
    
    for(auto it : this->_board.GetConnections(this->_currentCity)){
        if(it == city){
        this->_currentCity = city;
        found = true;
        }
    }
    if(!found){throw "invalid move - NOT CONNECTEDCITIES";}
    return *this;
}

/*****************************************************************************/
Player& Player::fly_direct (City city){
    if(city ==this->_currentCity){throw "cant fly from city to it self";}

    if(this->_playerCards.find(city) != this->_playerCards.end()){
        _playerCards.erase(city);
        this->_currentCity = city;
        return *this;
    }
    throw "no have the rigth card"; 
}

/*****************************************************************************/
Player& Player::fly_charter (City city){
    if(city ==this->_currentCity){throw "cant fly from city to it self";}

    if(this->_playerCards.find(this->_currentCity) != this->_playerCards.end()){
        _playerCards.erase(this->_currentCity);
        this->_currentCity = city;
        return *this;
    }
    throw "no have the rigth card";
}

/*****************************************************************************/
Player& Player::fly_shuttle (City city){
    if(city ==this->_currentCity){throw "cant fly from city to it self";}

    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
    !=
    this->_board.GetCitiesResearchStations().end()){
            if(this->_board.GetCitiesResearchStations().find(city)
            !=
            this->_board.GetCitiesResearchStations().end()){
        this->_currentCity = city;
        return *this;
        }
        throw "no have a reserch station";
    }
    throw "no have a reserch station";
}

/*****************************************************************************/
Player& Player::build (){
    if(this->_playerCards.find(this->_currentCity) != this->_playerCards.end()){
    /*if no have a research station, build one*/
    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        == 
        this->_board.GetCitiesResearchStations().end()){
        _playerCards.erase(this->_currentCity);
        this->_board.GetCitiesResearchStations().insert(this->_currentCity);
        return *this;
    }
    
    /*the player holds the card, but this city already contains a reaserch station*/
    return *this;
    }
    throw "can't build a reaserch station";
}

/*****************************************************************************/
Player& Player::discover_cure (Color color){
    if(this->_board.isFoundCure(color)){return *this;}/*already have a cure*/

    if(this->_board.GetCitiesResearchStations().find(this->_currentCity)
        !=
        this->_board.GetCitiesResearchStations().end()
        && isHave_5_or_n_cards(color,FIVE_SAME_CARDS)){
        this->_board.SetCure(color);
        return *this;
    }
    throw "can't discover a cure";
}

/*****************************************************************************/
Player& Player::treat (City city){
    /*the paramiter is not the cirrent City*/
    // if(this->_currentCity != city){throw "not at the rigth city";}

    /*no Infection in the city = 0*/
    if(this->_board[city] == 0){throw "There is no Infection in the city at all";}

    if(this->_board.isFoundCure(city)){/*already have a cure*/
        this->_board[city] = 0;
        return *this;
    }
    /*else/ : no have a cure*/
    this->_board[city]--;
    return *this;
}

/***********************************************************/
bool Player::isHave_5_or_n_cards (Color color, int n){
    set<City> tempCards;/*if no have 5 cards, will return back to the player*/
    for(auto it : this->_playerCards){
        tempCards.insert(it);
    }

    int count = 0;
    for(auto it : this->_playerCards){
        if(_board.GetCityColor(it) == color && count < n){
            count++;
            tempCards.erase(it);
        }
    }
    
    if(count >= n ){
        _playerCards.clear();
        for(auto it : tempCards){this->_playerCards.insert(it);}
        return true;
    }
    return false;
}