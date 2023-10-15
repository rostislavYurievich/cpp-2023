// 17 вариант
module;
#include <cmath>
module student_1bib21083.Lab2.Variant17.Task2;

double a(double i){
    return std::pow(-1,i) * (i+1) / (std::pow(i,3)+1);
}
namespace RBPO::Lab2::Variant17::Task2{
    double f2(double x){
        if (x>=1.1) return 9-x;
        return std::sin(3*x)/(std::pow(x,4)+1);
    }

    double f3(int n){
        double sum = 0;
        int i = 0;
        while (i<n){
            sum+=a(i);
            i++;
        }
        return sum;
    }

    double f4(double e){
        double sum = 0;
        int i = 0;
        while (a(i+1)-a(i)>e){
            sum+=a(i);
            i++;
        }
        return sum;
    }
}