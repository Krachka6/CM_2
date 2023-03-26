#include <iostream>
#include "locale.h"
#include <cstdio>

#include "Cubic_Interpolation_Spline_1D.h"
double f0(double x)  //Дана функция x^3 - x^2
{
    return x * x * x - x * x;
}
double f1(double x)
{
    return 3 * x * x - 2 * x;
}
double f2(double x)
{
    return 6 * x - 2;
}

int main() {

    try {
        std::vector<Com_Methods::Point> Mesh = {
          Com_Methods::Point(-1.0, 0.0, 0.0),
          Com_Methods::Point(0.0, 0.0, 0.0),
          Com_Methods::Point(1.0, 0.0, 0.0),
        };
        std::vector<double> Func = { -2.0, 0.0, 0.0};
        Com_Methods::Cubic_Interpolation_Spline_1D Spline;
        Spline.Update_Spline(Mesh, Func);

        float x = 0.0125;

        double Res[3];
        Spline.Get_Value(Com_Methods::Point(x, 0.0, 0.0), Res);
        std::cout << "f(" << x << ") = " << f0(x) << std::endl;
        std::cout << "f(" << x << ")' = " << f1(x) << std::endl;
        std::cout << "f(" << x << ")'' = " << f2(x) << std::endl;
        std::cout << "spline f(" << x << ") = " << Res[0] << std::endl;
        std::cout << "spline f(" << x << ")' = " << Res[1] << std::endl;
        std::cout << "spline f(" << x << ")'' = " << Res[2] << std::endl; std::getchar();
    }
    catch (std::exception& Ex) {
        std::cout << "Error: " << Ex.what() << std::endl;
    }
}
