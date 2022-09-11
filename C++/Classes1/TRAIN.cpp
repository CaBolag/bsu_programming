#include <iostream>
#include "TRAIN.h"
#include <algorithm>
#include <iterator>

std::ostream & operator <<(std::ostream & out,const TRAIN &train){
    out<<train.destination<<" "<<train.number<<" ";
    if(train.express){
        out<<"express";
    }
    else{
        out<<"not express";
    }
    return out;
}

TRAIN::TRAIN(std::string destination, int number, bool express):
destination(destination),
number(number),
express(express) {}

TRAIN::TRAIN(const TRAIN &train):
destination(train.destination),
number(train.number),
express(train.express) {};
//geters
std::string TRAIN::get_destination(){
return this->destination;
};

bool TRAIN::get_express() {
    return this->express;
}

void print_destination(std::vector<TRAIN> &Trains){
    std::string destination;
    std::cout<<"Enter a destination(all trains):";
    std::cin>>destination;
    std::copy_if(Trains.begin(),Trains.end(),std::ostream_iterator<TRAIN>(std::cout,"\n"),
            [destination](TRAIN train1){return(train1.get_destination()==destination);});
}
void print_destination_express(std::vector<TRAIN> &Trains){
    std::string destination;
    std::cout<<"Enter a destination(express):";
    std::cin>>destination;
    std::copy_if(Trains.begin(),Trains.end(),std::ostream_iterator<TRAIN>(std::cout,"\n"),
                 [destination](TRAIN train1){return(train1.get_destination()==destination && train1.get_express()==true);});
}
