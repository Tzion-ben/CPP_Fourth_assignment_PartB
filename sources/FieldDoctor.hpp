/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*FieldDoctor extends Player*/
    class FieldDoctor : public Player{

        public:
            /*inhereted constractor*/
            FieldDoctor(Board& board, City city);

            /*decrementing disease stage in the city*/
            virtual Player& treat (City city);
    };
}