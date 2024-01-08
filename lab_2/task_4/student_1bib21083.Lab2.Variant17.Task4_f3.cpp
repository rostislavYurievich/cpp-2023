module student_1bib21083.Lab2.Variant17.Task4;

import :a;

using namespace RBPO::Lab2::Variant17::Task4;

namespace RBPO::Lab2::Variant17::Task4{
    double f3(int n){
        double sum = 0;
        int i = 0;
        do
        {
            if (i<n){
                sum+=a(i);
                i++;
            }
        }while (i<n);
        return sum;
    }
}
