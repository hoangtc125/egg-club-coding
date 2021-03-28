#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string duration;
    cin >> duration;
    int sum = 0;
    string tmp1 = duration.substr(0, 2);
    string tmp2 = duration.substr(3, 5);
    sum += stoi(tmp1) * 60 + stoi(tmp2);
    cout << sum << endl;
    return 0;
}