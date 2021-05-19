/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include "Board.hpp"

const int FIVE_SAME_CARDS = 5;

namespace pandemic {
    class Player {

        protected:
          Board &_board;
          City _currentCity; 
          std::set <City> _playerCards; 
          std::string _role;

        public:

            /*a generic constractor*/
            Player (Board &board, City city, std::string role);
            /*virtual distractor*/
            virtual ~Player();
          /*****************************************************************************/
            /*move from current city to the nearest city*/
            virtual Player& drive (City city);

          /*****************************************************************************/
            /*move from the current city to the city of some card in his hand*/
            virtual Player& fly_direct (City city);

          /*****************************************************************************/
            /*move from the current city to some city*/
            virtual Player& fly_charter (City city);

          /*****************************************************************************/\
            /*move from the current city to some city iff in current
            city exiset a research station */
            virtual Player& fly_shuttle (City city);

          /*****************************************************************************/
            /*builds a research station*/
            virtual Player& build ();

          /*****************************************************************************/
            /*discover a new cure for one of the disease*/
            virtual Player& discover_cure (Color color);
            
          /*****************************************************************************/
            /*decrementing disease stage in the current ity*/
            virtual Player& treat (City city);

          /*****************************************************************************/
            /*returns the role player*/
            virtual std::string role (){return this->_role;}

          /*****************************************************************************/
            /*a player will take a card that belong to a certain city*/
            virtual Player& take_card (City city){
              this->_playerCards.insert(city);
              return *this;
            }

            /*remove all the cards of the player*/
            virtual void remove_cards(){this->_playerCards.clear();}

/*************************************************************************************************/
            /******** Private Methods ********/ 
            /*return true or false depend on if the player hold 5 cards from the same Color */ 
            bool isHave_5_or_n_cards (Color color, int n);
    };
} 