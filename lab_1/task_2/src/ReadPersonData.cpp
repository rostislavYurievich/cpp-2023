#include <string>

extern unsigned short height;

std::string ReadPersonName();
unsigned short ReadPersonAge();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short &weight);


void ReadPersonData(std::string &name, unsigned short &age, unsigned short &h, unsigned short &weight){
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonHeight();
    h = height;
    ReadPersonWeight(weight);
    
}