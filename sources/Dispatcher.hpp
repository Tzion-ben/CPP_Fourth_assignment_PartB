/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Dispatcher extends Player*/
    class Dispatcher : public Player{

        public:
            /*inhereted constractor*/
            Dispatcher(Board& board, City city);

            /*move from the current city to the city of some card in his hand*/
            virtual Player& fly_direct (City city);
    };
} 