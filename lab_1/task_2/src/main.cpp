#include <string>

void WritePersonData(const std::string &name, const unsigned short *age, const std::string &height="", const std::string &weight="");
void ReadPersonData(std::string &name, unsigned short &age, unsigned short &h, unsigned short &weight);
void ReadPersonData(std::string &name, unsigned short &age, double &salary);

extern std::string salary;

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
