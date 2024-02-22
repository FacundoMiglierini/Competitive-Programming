#include <cstdio>
#include <vector>

std::vector<double> precios{4, 4.5, 5, 2, 1.5};

int X, Y;

int main()
{
    scanf("%d %d", &X, &Y); //código de producto y cantidad de unidades
    printf("Total: R$ %.2f", precios[X - 1] * Y);
}