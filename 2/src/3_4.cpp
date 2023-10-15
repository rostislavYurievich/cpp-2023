module student_1bib21083.Lab2.Variant17.Task3:f4;

double a(double);

double f4(double e){
    double sum = 0;
    int i = 0;
    do {
        sum+=a(i);
        i++;
    }while (a(i+1)-a(i)>e);
    return sum-=a(i);
}
