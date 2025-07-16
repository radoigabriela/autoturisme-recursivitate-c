#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int a[100], n, i;
int maxim(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int minim(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int maxim_vector(int a[], int n)
{
    if(n==2)
        return maxim(a[n], a[n-1]);
    else
        return maxim(a[n], maxim_vector(a, n-1));
}

int minim_vector(int a[], int n)
{
    if(n==2)
        return minim(a[n], a[n-1]);
    else
        return minim(a[n], minim_vector(a, n-1));
}

int main()
{
    printf("Introduceti numarul de elemente ale vectorului:");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului:\n");
    for(int i=1; i<=n ; i++)
        scanf("%d", &a[i]);
    printf("Maximul din vector este: %d\n", maxim_vector(a,n));
    printf("Minimul din vector este: %d", minim_vector(a,n));
    return 0;
}
