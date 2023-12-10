#include <string>

std::string ReadPersonName();
unsigned short ReadPersonAge();
void ReadPersonSalary(double *salary);


void ReadPersonData(std::string &name, unsigned short &age, double &salary){
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonSalary(&salary);
}
    