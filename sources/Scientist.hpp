/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Scientist extends Player*/
    class Scientist : public Player{

        protected:
          int _n_cards_discover_cure;

        public:
            /*inhereted constractor*/
            Scientist(Board& board, City city, int n);
        
            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color);
    };
}