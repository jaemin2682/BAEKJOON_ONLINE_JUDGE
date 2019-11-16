#include <iostream>
#include <algorithm>

using namespace std;

bool rect[101][101];

int main()
{
    int area = 0;
    for (int i = 0; i < 4; i++)
    {
        int lbx, lby, rtx, rty;
        cin >> lbx >> lby >> rtx >> rty;
        for (int a = lby; a < rty; a++)
            for (int b = lbx; b < rtx; b++)
                rect[a][b] = true;
    }
    for (int a = 1; a <= 100; a++)
    {
        for (int b = 1; b <= 100; b++)
        {
            if (rect[a][b])
                area++;
        }
    }
    cout << area;
}