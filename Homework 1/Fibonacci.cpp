#include <iostream>
long long int fib(int n);
long long int improvedFib(int n);
long long int bestFib(int n);
int main ()
{
    int n;
    std::cin >> n;
    std::cout << bestFib(n) << std::endl;
    return 0;
}
long long int fib(int n) // O(2^n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n-1)+fib(n-2);
}
long long int improvedFib(int n) // O(n)
{
    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
void multiply(long long int F[2][2],long long int M[2][2])
{
    long long int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
    long long int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
    long long int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
    long long int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
void power(long long int F[2][2], int n) // O(logn) Function that multiplies matrices quicker than O(n)
{
    if (n == 0 || n == 1)
        return;
    long long int M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    multiply(F,F);
    if(n % 2 != 0)
        multiply(F,M);
}
long long int bestFib(int n) // O(logn)
{
    long long int F[2][2] = {{1,1},{1,0}};
    if(n == 0)
        return 0;
    power (F,n-1);
    return F[0][0];

}
