#include <iostream>
#include <ostream>
#include <string>

unsigned short ReadPersonAge(){
    unsigned short age;
    std::cout<<"Возраст >";
    std::cin>>age;
    return age;
}

std::string ReadPersonName(){
    std::string string;
    std::cout<<"Имя >";
    std::cin>>string;
    return string;
}

unsigned short height;

void ReadPersonHeight(){
    std::cout<<"Рост >";
    std::cin>>height;
}

void ReadPersonWeight(unsigned short &weight){
    std::cout<<"Вес >";
    std::cin>>weight;
}

void ReadPersonSalary(double *salary){
    std::cout<<"З/П >";
    std::cin>>*salary;
}


void ReadPersonData(std::string &name, unsigned short &age, double &salary){
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonSalary(&salary);
}

void ReadPersonData(std::string &name, unsigned short &age, unsigned short &h, unsigned short &weight){
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonHeight();
    h = height;
    ReadPersonWeight(weight);
    
}

std::string salary;

void WritePersonData(const std::string &name, const unsigned short *age, const std::string &height="", const std::string &weight=""){
    std::cout<<"\nИмя: "<<name<<" Возраст: "<<*age<<"\nРост: "<<height<<" Вес: "<<weight<<" З/П: "<<salary<<std::endl;
}
#ifndef DO_NOT_DEFINE_MAIN
int main(int argc, char *argv[])
{
    std::string name;
    unsigned short age, height, weight;
    double fSalary;
    ReadPersonData(name, age, fSalary);
    ReadPersonData(name, age, height, weight);
    salary = std::to_string(fSalary);
    WritePersonData(name, &age, std::to_string(height),std::to_string(weight));
}
#endif
