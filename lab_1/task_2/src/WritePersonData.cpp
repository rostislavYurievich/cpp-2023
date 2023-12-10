#include <iostream>

std::string salary;

void WritePersonData(const std::string &name, const unsigned short *age, const std::string &height="", const std::string &weight=""){
    std::cout<<"\nИмя: "<<name<<" Возраст: "<<*age<<"\nРост: "<<height<<" Вес: "<<weight<<" З/П: "<<salary<<std::endl;
}