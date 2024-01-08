module student_1bib21083.Lab2.Variant17.Task3;

using namespace RBPO::Lab2::Variant17::Task3;

double a(double);

namespace RBPO::Lab2::Variant17::Task3{
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
