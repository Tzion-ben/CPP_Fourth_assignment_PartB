/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Virologist extends Player*/
    class Virologist : public Player{

        public:
            /*inhereted constractor*/
            Virologist(Board& board, City city);
            
            /*decrementing disease stage in the city*/
            virtual Player& treat (City city);
    };
}