module student_1bib21083.Lab2.Variant17.Task3:f3;

double a(double);

double f3(int n){
    double sum = 0;
    int i = 0;
    do
    {
        sum+=a(i);
        i++;
    }while (i<n);
    return sum-=a(i);
}
