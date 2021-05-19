/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Researcher extends Player*/
    class Researcher : public Player{

        public:
            /*inhereted constractor*/
            Researcher(Board& board, City city);
            
            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color);
    };
}