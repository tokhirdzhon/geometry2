#include <stdio.h>
int main()
{
    int x, y, r;
    float perimetr;

    printf("\nInput center(x, y) and radius separated by space: ");
    scanf("%i%i%i", &x, &y, &r);
    printf("\ncircle(%i %i, %i)", x, y, r);

    perimetr = 2 * 3.14 * r;
    printf("\n  perimetr = %.2f\n\n", perimetr);
}