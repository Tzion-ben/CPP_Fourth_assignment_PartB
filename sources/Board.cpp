/**
 * Author: Tzion Beniaminov
 * Since : 2021-04
 */ 

#include "Board.hpp"
#include <iostream>

using namespace std;
using namespace pandemic;

/*default constractor*/
Board::Board(){
    initConnections();
}

/***********************************************************/
bool Board::is_clean(){
    for(auto it : this->_citiesDiseasesStage){
        if(it.second != 0){return false;}
    }
    return true;
}

/***********************************************************/
void Board::remove_cures (){
    _foundCure[Color::Black] = false;
    _foundCure[Color::Blue] = false;
    _foundCure[Color::Yellow] = false;
    _foundCure[Color::Red] = false;
}

/***********************************************************/
void Board::remove_stations(){
    _citiesResearchStations.clear();
}

/***********************************************************/
int&  Board::operator[](City city){
    return _citiesDiseasesStage[city];
}

/***********************************************************/
std::vector<City>& Board::GetConnections(City city){
    return _connections[city];
}

/***********************************************************/
void Board::SetCure(Color color){
    _foundCure[color] = true;
}

/***********************************************************/
std::set <City>& Board::GetCitiesResearchStations(){
    return this->_citiesResearchStations;
}

/***********************************************************/
Color Board::GetCityColor(const City city) const{
    for(const auto& it : _diseasesColors){
        for(auto itVec : it.second){
            if(itVec == city){return it.first;}
        } 
    }
    return Color::None;
}

/***********************************************************/
bool Board::isFoundCure(City city){
    return (_foundCure[GetCityColor(city)]);
}

/***********************************************************/
bool Board::isFoundCure(Color color){
    return (_foundCure.at(color));
}

/***********************************************************/
ostream& pandemic::operator<< (ostream& output, const Board& b){
    for(const auto& it : b._connections){
        output << "Name of the city is :" << Board::_citiesToPrint.at(it.first) <<" , ";
        output << "City color is : " << Board::_colorToPrint.at(b.GetCityColor(it.first)) << "\n";
        output << "City diseases stage is : " << b._citiesDiseasesStage.at(it.first) << "\n";
        output << "The city connected to : ";
        for(const auto itConnected : it.second){
            output << Board::_citiesToPrint.at(itConnected) << " | ";
        }

        output << "\n------------------------------------------------------------------------------\n\n";
    }

    output << "\n------------------------------------------------------------------------------\n\n";
    output << "\n------------------------------------------------------------------------------\n\n";

    output << "\nThe cities that have a Research Stations are: \n";
        for(const auto it : b._citiesResearchStations){
            output << Board::_citiesToPrint.at(it) << " | ";
        }
        
    output << "\n------------------------------------------------------------------------------\n\n";

    return output;
}

/***********Implementation of Private methods*/
void Board:: initConnections(){
    _connections[City::Algiers] = {City::Madrid, City::Paris, City::Istanbul, City::Cairo};
    _connections[City::Atlanta] = {City::Chicago, City::Miami, City::Washington};
    _connections[City::Baghdad] = {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi};
    _connections[City::Bangkok] = {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong};
    _connections[City::Beijing] = {City::Shanghai, City::Seoul};
    _connections[City::Bogota] = {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires};
    _connections[City::BuenosAires] = {City::Bogota, City::SaoPaulo};
    _connections[City::Cairo] = {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh};
    _connections[City::Chennai] = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
    _connections[City::Chicago] = {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal};
    _connections[City::Delhi] = {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};
    _connections[City::Essen] = {City::London, City::Paris, City::Milan, City::StPetersburg};
    _connections[City::HoChiMinhCity] = {City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
    _connections[City::HongKong] = {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei};
    _connections[City::Istanbul] = {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow};
    _connections[City::Jakarta] = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
    _connections[City::Johannesburg] = {City::Kinshasa, City::Khartoum};
    _connections[City::Karachi] = {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi};
    _connections[City::Khartoum] =  {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg};
    _connections[City::Kinshasa] = {City::Lagos, City::Khartoum, City::Johannesburg};
    _connections[City::Kolkata] = {City::Delhi, City::Chennai, City:: Bangkok, City:: HongKong};
    _connections[City::Lagos] =  {City::SaoPaulo, City::Khartoum, City::Kinshasa};
    _connections[City::Lima] =  {City::MexicoCity, City::Bogota, City::Santiago};
    _connections[City::London] =  {City::NewYork, City::Madrid, City::Essen, City::Paris};
    _connections[City::LosAngeles] =  {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
    _connections[City::Madrid] =  {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers};
    _connections[City::Manila] =  {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney};
    _connections[City::MexicoCity] =  {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota};
    _connections[City::Miami] =  {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota};
    _connections[City::Milan] =  {City::Essen, City::Paris, City::Istanbul};
    _connections[City::Montreal] =  {City::Chicago, City::Washington, City::NewYork};
    _connections[City::Moscow] = {City::StPetersburg, City::Istanbul, City::Tehran};
    _connections[City::Mumbai] = {City::Karachi,  City::Delhi,  City::Chennai};
    _connections[City::NewYork] =  {City::Montreal,  City::Washington,  City::London,  City::Madrid};
    _connections[City::Osaka] =  {City::Taipei, City::Tokyo};
    _connections[City::Paris ] = {City::Algiers,  City::Essen, City::Madrid,  City::Milan ,City::London};
    _connections[City::Riyadh] =  {City::Baghdad,  City::Cairo,  City::Karachi};
    _connections[City::SanFrancisco] =  {City::LosAngeles,  City::Chicago, City::Tokyo, City::Manila};
    _connections[City::Santiago ] = {City::Lima};
    _connections[City::SaoPaulo] =  {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid};
    _connections[City::Seoul] =  {City::Beijing, City::Shanghai, City::Tokyo};
    _connections[City::Shanghai] =   {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo};
    _connections[City::StPetersburg] =  {City::Essen,  City::Istanbul,  City::Moscow};
    _connections[City::Sydney] =   {City::Jakarta,  City::Manila, City::LosAngeles};
    _connections[City::Taipei] =   {City::Shanghai, City::HongKong, City::Osaka, City::Manila};
    _connections[City::Tehran] =  {City::Baghdad, City::Moscow, City::Karachi, City::Delhi};
    _connections[City::Tokyo] = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
    _connections[City::Washington] =  {City::Atlanta, City::NewYork, City::Montreal, City::Miami};

    _diseasesColors[Color::Black] = {City::Algiers , City::Cairo, City::Istanbul,City::Baghdad,City::Moscow,
    City::Tehran, City::Karachi,City::Riyadh, City::Mumbai, City::Delhi, City::Kolkata, City::Chennai};
    _diseasesColors[Color::Red] = {City::HoChiMinhCity, City::Shanghai, City::HongKong, City::Bangkok, City::Jakarta,
    City::Manila, City::Sydney, City::Taipei, City::Osaka, City::Tokyo, City::Seoul,  City::Beijing};
    _diseasesColors[Color::Yellow] = {City::Khartoum, City::Kinshasa, City::Johannesburg, City::Lagos, 
    City::SaoPaulo, City::BuenosAires, City::Santiago, City::Lima, City::Bogota, City::Miami,
    City::MexicoCity, City::LosAngeles};
    _diseasesColors[Color::Blue] = {City::SanFrancisco, City::Chicago, City::Atlanta, City::Montreal,
    City::NewYork, City::Washington, City::Madrid, City::London, City::Paris, City::Essen,
    City::Milan, City::StPetersburg};
    
    _citiesDiseasesStage[City::Algiers] = 0;
    _citiesDiseasesStage[City::Atlanta] = 0;
    _citiesDiseasesStage[City::Baghdad] = 0;
    _citiesDiseasesStage[City::Bangkok] = 0;
    _citiesDiseasesStage[City::Beijing] = 0;
    _citiesDiseasesStage[City::Bogota] = 0;
    _citiesDiseasesStage[City::BuenosAires] = 0;
    _citiesDiseasesStage[City::Cairo] = 0;
    _citiesDiseasesStage[City::Chennai] = 0;
    _citiesDiseasesStage[City::Chicago] = 0;
    _citiesDiseasesStage[City::Delhi] = 0;
    _citiesDiseasesStage[City::Essen] = 0;
    _citiesDiseasesStage[City::HoChiMinhCity] = 0;
    _citiesDiseasesStage[City::HongKong] = 0;
    _citiesDiseasesStage[City::Istanbul] = 0;
    _citiesDiseasesStage[City::Jakarta] = 0;
    _citiesDiseasesStage[City::Johannesburg] = 0;
    _citiesDiseasesStage[City::Karachi] = 0;
    _citiesDiseasesStage[City::Khartoum] =  0;
    _citiesDiseasesStage[City::Kinshasa] = 0;
    _citiesDiseasesStage[City::Kolkata] = 0;
    _citiesDiseasesStage[City::Lagos] =  0;
    _citiesDiseasesStage[City::Lima] =  0;
    _citiesDiseasesStage[City::London] =  0;
    _citiesDiseasesStage[City::LosAngeles] =  0;
    _citiesDiseasesStage[City::Madrid] =  0;
    _citiesDiseasesStage[City::Manila] =  0;
    _citiesDiseasesStage[City::MexicoCity] =  0;
    _citiesDiseasesStage[City::Miami] =  0;
    _citiesDiseasesStage[City::Milan] =  0;
    _citiesDiseasesStage[City::Montreal] =  0;
    _citiesDiseasesStage[City::Moscow] = 0;
    _citiesDiseasesStage[City::Mumbai] = 0;
    _citiesDiseasesStage[City::NewYork] =  0;
    _citiesDiseasesStage[City::Osaka] =  0;
    _citiesDiseasesStage[City::Paris ] = 0;
    _citiesDiseasesStage[City::Riyadh] =  0;
    _citiesDiseasesStage[City::SanFrancisco] =  0;
    _citiesDiseasesStage[City::Santiago ] = 0;
    _citiesDiseasesStage[City::SaoPaulo] =  0;
    _citiesDiseasesStage[City::Seoul] =  0;
    _citiesDiseasesStage[City::Shanghai] =   0;
    _citiesDiseasesStage[City::StPetersburg] = 0;
    _citiesDiseasesStage[City::Sydney] = 0;
    _citiesDiseasesStage[City::Taipei] =   0;
    _citiesDiseasesStage[City::Tehran] =  0;
    _citiesDiseasesStage[City::Tokyo] = 0;
    _citiesDiseasesStage[City::Washington] =  0;

    _foundCure[Color::Black] = false;
    _foundCure[Color::Blue] = false;
    _foundCure[Color::Yellow] = false;
    _foundCure[Color::Red] = false;
}

map <City, string> Board::_citiesToPrint {
            {City::Algiers , "Algiers"},
            {City::Atlanta , "Atlanta"},
            {City::Baghdad , "Baghdad"},
            {City::Bangkok , "Bangkok"},
            {City::Beijing , "Beijing"},
            {City::Bogota , "Bogota"},
            {City::BuenosAires , "BuenosAires"},
            {City::Cairo , "Cairo"},
            {City::Chennai , "Chennai"},
            {City::Chicago , "Chicago"},
            {City::Delhi , "Delhi"},
            {City::Essen , "Essen"},
            {City::HoChiMinhCity , "HoChiMinhCity"},
            {City::HongKong, "HongKong"},
            {City::Istanbul , "Istanbul"},
            {City::Jakarta , "Jakarta]"},
            {City::Johannesburg , "Johannesburg"},
            {City::Karachi , "Karachi"},
            {City::Khartoum ,  "Khartoum"},
            {City::Kinshasa , "Kinshasa"},
            {City::Kolkata , "Kolkata"},
            {City::Lagos , "Lagos"},
            {City::Lima , "Lima"},
            {City::London , "London"},
            {City::LosAngeles, "LosAngeles"},
            {City::Madrid , "Madrid"},
            {City::Manila , "Manila"},
            {City::MexicoCity , "MexicoCity"},
            {City::Miami , "Miami"},
            {City::Milan , "Milan"},
            {City::Montreal , "Montreal"},
            {City::Moscow , "Moscow"},
            {City::Mumbai, "Mumbai"},
            {City::NewYork,  "NewYork"},
            {City::Osaka , "Osaka"},
            {City::Paris , "Paris"},
            {City::Riyadh , "Riyadh"},
            {City::SanFrancisco , "SanFrancisco"},
            {City::Santiago , "Santiago"},
            {City::SaoPaulo , "SaoPaulo"},
            {City::Seoul , "Seoul"},
            {City::Shanghai ,  "Shanghai"},
            {City::StPetersburg , "StPetersburg"},
            {City::Sydney ,  "Sydney"},
            {City::Taipei ,  "Taipei"},
            {City::Tehran, "Tehran"},
            {City::Tokyo, "Tokyo"},
            {City::Washington , "Washington"}
};

map <Color, string> Board::_colorToPrint {
            {Color::Black , "Black"},
            {Color::Blue , "Blue"},
            {Color::Red , "Red"},
            {Color::Yellow , "Yellow"},       
};