#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int y = 1; y < n + 1; y++) {
        for(int x = 1; x < n + 1; x++) {
            int tmp = x % y;
            if(tmp < k) {
                continue;
            } else {
                ++cnt;
            }
            if(x > y) {
                cout << x << " " << y << endl;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

