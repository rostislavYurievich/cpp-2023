module;
#include <cmath>
module student_1bib21083.Lab2.Variant17.Task4;

namespace RBPO::Lab2::Variant17::Task4{
    double f2(double x){
        return x>=1.1 ? 9-x : std::sin(3*x)/(std::pow(x,4)+1);
    }
}