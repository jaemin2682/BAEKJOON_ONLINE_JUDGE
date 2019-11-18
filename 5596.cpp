#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sum1, sum2, info1, info2, math1, math2, sci1, sci2, eng1, eng2;
    cin >> info1 >> math1 >> sci1 >> eng1;
    cin >> info2 >> math2 >> sci2 >> eng2;
    sum1 = info1 + math1 + sci1 + eng1;
    sum2 = info2 + math2 + sci2 + eng2;
    
    cout << max(sum1, sum2);

    return 0;
}