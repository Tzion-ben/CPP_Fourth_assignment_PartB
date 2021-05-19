/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*GeneSplicer extends Player*/
    class GeneSplicer : public Player{

        public:
            /*inhereted constractor*/
            GeneSplicer(Board& board, City city);

            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color);
    };
}