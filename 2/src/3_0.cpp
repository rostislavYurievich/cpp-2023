module;
#include <cmath>
module student_1bib21083.Lab2.Variant17.Task3;

namespace RBPO::Lab2::Variant17::Task3{
    double a(double i){
        return std::pow(-1,i) * (i+1) / (std::pow(i,3)+1);
    }
}