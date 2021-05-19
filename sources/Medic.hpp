/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Player.hpp"

namespace pandemic{

    /*Medic extends Player*/
    class Medic : public Player{

        public:
            /*inhereted constractor*/
            Medic(Board& board, City city);
            
            /*move from current city to the nearest city*/
            virtual Player& drive (City city);

            /*move from the current city to the city of some card in his hand*/
            virtual Player& fly_direct (City city);

            /*move from the current city to some city*/
            virtual Player& fly_charter (City city);

            /*move from the current city to some city iff in current
              city exiset an */
            virtual Player& fly_shuttle (City city);

            /*decrementing disease stage in the city*/
            virtual Player& treat (City city);
    };
}