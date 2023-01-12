#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool flag = true;
    int num = 0;
    cin >> num;
    if (num < 2)
    {
        cout << "Not Prime" << endl;
        return 0;
    }
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            flag = false;
    }
    if (flag == true)
        cout << "Prime Number" << endl;
    else
        cout << "Not Prime Number" << endl;
}