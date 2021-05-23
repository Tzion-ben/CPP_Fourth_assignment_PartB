/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */
#pragma once

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "City.hpp"
#include "Color.hpp"


namespace pandemic {
    class Board{

        protected:
            
            /*List of each city's connections to cities directly connected to it*/
            std::map <City, std::vector <City>> _connections;
            std::map <Color, std::vector <City>> _diseasesColors;
            std::map <City,int> _citiesDiseasesStage;/*the level of disease of each city, 0 to inf*/
            std::set <City> _citiesResearchStations;/*adding the city number where we have a research station*/ 
            std::map <Color, bool> _foundCure;/*changing a specific color to true if found a drug for it*/
            
            /*init to maps to print out Board state*/
            static std::map <City, std::string> _citiesToPrint;
            static std::map <Color, std::string> _colorToPrint;

            /*initialization of the data structures that need for the start of the game*/
            void initConnections();
           
        public:
            /*default empty constractor, will create an array of integers
            for every enum City, array of bool , false if num have a research station
            in coresponding city , true if there is*/
            Board();
        
            /*returns true if all the board is empty*/
            bool is_clean();

            /****** IMPLEMENTED ONLY for tests ******/
            /*cleaning all the founded cures*/
            void remove_cures ();

            /*cleaning all existing research stations at the game Board*/
            void remove_stations();

            
            /********* Getters and Setters *********/
            /***************************************/
            /**get the research stations status*/
            std::set <City>& GetCitiesResearchStations();
            
            /**get vector of connections of a specific City*/
            std::vector <City>& GetConnections(City city);

            /*return a color of the City*/
            Color GetCityColor(const City city) const;

            /*found a cure in a specif color*/
            void SetCure(Color color);

            /*return true or false if there is a cure for this City Color*/
            bool isFoundCure(City city);

            /*return true or false if there is a cure for this Color*/
            bool isFoundCure(Color color);

            /******** operators overloading ********/
            /***************************************/
            /*[] operator : can get and set the value at specific index(key)*/
            int& operator[](City city);

            /*return an output of the Board*/
            friend std::ostream& operator<<(std::ostream& output, const Board& b);
    };
}