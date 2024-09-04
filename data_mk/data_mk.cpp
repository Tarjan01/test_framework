#include <iostream>

const int kdimension = 5;
const int kpointsnum = 10;
const int kquerynum = 5;
const int kmaxaxis = 1000; 

void random_axis() {
    std::cout << rand() % kmaxaxis << " ";
}
void random_points() {
    for(int i = 0;i < kdimension;i++) {
        random_axis();
    }
    std::cout << std::endl;
}
void make()
{
    srand(time(0));
    std::cout << kdimension << std::endl;
    std::cout << kpointsnum << std::endl;
    for (int i = 0; i < kpointsnum; i++) {
        random_points();
    }
    std::cout << kquerynum << std::endl;
    for (int i = 0; i < kquerynum; i++) {
        random_points();
    }
}
int main()
{
    make();
    return 0;
}