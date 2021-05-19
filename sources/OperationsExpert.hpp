/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*OperationsExpert extends Player*/
    class OperationsExpert : public Player{

        public:
            /*inhereted constractor*/
            OperationsExpert(Board& board, City city);
            
            /*builds a research station*/
            virtual Player& build ();
    };
}