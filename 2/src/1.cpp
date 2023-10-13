// 17 вариант
module student.1bib21083.Lab2.Variant17.Task1; 
#include <cmath> 
namespace 
double f(double x){
    return std::sqrt(std::pow(3*x+2,2)-24*x)/(3*std::sqrt(x)- 2/std::sqrt(x));
}

double f2(double x){
    return x>=1.1 ? 9-x : std::sin(3*x)/(std::pow(x,4)+1);
}

double a(double i){
    return std::pow(-1,i) * (i+1) / (std::pow(i,3)+1);
}

double f3(int n){
    double sum = 0;
    for (int i = 0; i<n; i++){
        sum+=a(i);
    }
    return sum;
}

double f4(double e){
    double sum = 0;
    for (int i = 0; a(i+1)-a(i)>e; i++){
        sum+=a(i);
    }
    return sum;
}
