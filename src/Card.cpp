#include "../includes/Card.hpp"

Card::Card(int value): _value(value){}
Card::~Card(){}
int Card::getValue(){return _value;}

Card::Card():_value(0){}
Card::Card(Card const &src):_value(src._value){}
