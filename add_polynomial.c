#include <stdio.h>
#define max 10

void main()
{

    int arr1[max], arr2[max], deg, deg1;
    // Element for the first polynomial
    printf("\nEnter the Highest Degree for the first Polynomials(max. 10):\n");
    scanf("%d", &deg);
    // Element for the second polynomial
    printf("\nEnter the Highest Degree for the second Polynomials(max. 10):\n");
    scanf("%d", &deg1);

    if (deg < deg1)
    {
        deg = deg1;
    }
    // first polynomial
    printf("\n\nWrite down the Elemnts for the first polynomial:\n");
    for (int i = deg; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d:\t", i);
        scanf("%d", &arr1[i]);
    }
    // second polynomial
    printf("\n\nWrite down the Elemnts for the second polynomial:\n");
    for (int i = deg; i >= 0; i--)
    {
        printf("Enter the Coefficient of x^%d:\t", i);
        scanf("%d", &arr2[i]);
    }

    printf("The Final Polynomial we get is:");
    // displaying the final polynomial
    for (int i = deg; i >= 0; i--)
    {
        if (i != 0)
        printf("%dx^%d + ", arr1[i] + arr2[i], i);
        else
            continue;
    }
    printf("0");
}
