module student_1bib21083.Lab2.Variant17.Task4;

import :a;

using namespace RBPO::Lab2::Variant17::Task4;

namespace RBPO::Lab2::Variant17::Task4{
    double f4(double e){
        double sum = 0;
        int i = 0;
        do {
            if(a(i+1)-a(i)>e){
                sum+=a(i);
                i++;
            }
        }while (a(i+1)-a(i)>e);
        return sum;
    }
}