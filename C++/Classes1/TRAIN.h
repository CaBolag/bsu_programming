#ifndef WEEK_6_CLASS_TRAIN_H
#define WEEK_6_CLASS_TRAIN_H

#include <string>
#include <vector>
class TRAIN{
private:
    std::string destination;
    int number;
    bool express;
public:
    friend std::ostream & operator <<(std::ostream & out,const TRAIN &train);
    TRAIN(std::string destination,int number, bool express);
    TRAIN(const TRAIN &train);
    std::string get_destination();
    bool get_express();
};
void print_destination(std::vector<TRAIN>&);
void print_destination_express(std::vector<TRAIN>&);
#endif //WEEK_6_CLASS_TRAIN_H
