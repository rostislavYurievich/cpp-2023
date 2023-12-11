#include <iostream>

import student_1bib21083.Lab2.Variant17.Task1;
import student_1bib21083.Lab2.Variant17.Task2;
import student_1bib21083.Lab2.Variant17.Task3;
import student_1bib21083.Lab2.Variant17.Task4;
import student_1bib21083.Lab2.Variant17.Task5;

int main() {
    double num,e;
    int i;
    std::cout << "Enter x,i,e "; 
    std::cin>>num>>i>>e;
    while (true) {
        char c;
        std::cout << "Enter task number 1-5, q to quit "; 
        std::cin >> c;
        switch (c){
            case '1':
                std::cout<<RBPO::Lab2::Variant17::Task1::f1(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task1::f2(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task1::f3(i)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task1::f4(e)<<std::endl;
                break;
            case '2':
                std::cout<<RBPO::Lab2::Variant17::Task2::f1(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task2::f2(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task2::f3(i)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task2::f4(e)<<std::endl;
                break;
            case '3':
                std::cout<<RBPO::Lab2::Variant17::Task3::f1(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task3::f2(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task3::f3(i)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task3::f4(e)<<std::endl;
                break;
            case '4':
                std::cout<<RBPO::Lab2::Variant17::Task4::f1(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task4::f2(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task4::f3(i)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task4::f4(e)<<std::endl;
                break;
            case '5':
                std::cout<<RBPO::Lab2::Variant17::Task5::f1(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task5::f2(num)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task5::f3(i)<<std::endl;
                std::cout<<RBPO::Lab2::Variant17::Task5::f4(e)<<std::endl;
                break;
            case 'q':
                return 0;
        }
    }
    return 0;
}