
#include <iostream>
using namespace std;

// Non-Recursive Function
void fibonacciNonRecursive(int n)
{
    int a = 0, b = 1, c;

    cout << "Non-Recursive Fibonacci Series: ";

    for (int i = 0; i < n; i++)
    {
        cout << a;
        cout << " ";

        c = a + b;
        a = b;
        b = c;
    }

    cout << endl;
}

// Recursive Function
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number.";
        return 0;
    }

    fibonacciNonRecursive(n);

    cout << "Recursive Fibonacci Series: ";

    for (int i = 0; i < n; i++)
    {
        cout << fibonacciRecursive(i);
        cout << " ";
    }

    cout << endl;

    return 0;
}
