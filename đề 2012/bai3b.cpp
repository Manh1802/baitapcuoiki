#include <math.h>
#include <stdio.h>

class Function
{
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Cos : public Function
{
public:
    double Value(double x)
    {
        return cos(x);
    }

    double Derive(double x)
    {
        return -sin(x); // Đạo hàm của cos(x) là -sin(x)
    }
};

double DeriveProduct(Function *f, Function *g, double x)
{
    if (f != NULL && g != NULL)
    {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}
void main()
{
    double x = 3.14 / 6; // PI/6
    Cos *c = new Cos();
    double y = DeriveProduct(c, c, x)
        printf("cos(x)=%f;cos'(x)=%f\n", c->Value(x), c->Derive(x));
    printf("y=%f\n", y);
}