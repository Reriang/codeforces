#include <iostream>
using namespace std;
/*
Codeforces: 370A. Rook, Bishop and King
*/

void solution(int a, int b, int x, int y) {
    if (a == x || b == y)
        cout << 1 << ' ';
    else
        cout << 2 << ' ';
    
    if (abs(x - a) == abs(y - b))
        cout << 1 << ' ';
    else if ((a + b) % 2 == (x + y) % 2)
        cout << 2 << ' ';
    else 
        cout << 0 << ' ';
    
    cout << max(abs(x - a), abs(y - b)) << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    solution(a, b, x, y);

    return 0;
}