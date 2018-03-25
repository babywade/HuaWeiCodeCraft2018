#include <iostream>
#include <deque>
#include <stack>

using namespace std;

void reverse(deque<int> &sequence);

int main() {
    int n;
    cin >> n;
    deque<int> asequence;
    int a;
    while(cin >> a) {
        asequence.push_back(a);
    }
    deque<int> bsequence;
    for(int i = 0; i < n; i++) {
        int temp;
        temp = asequence.front();
        asequence.pop_front();
        bsequence.push_back(temp);
        reverse(bsequence);
    }
    for(int i = 0; i < n; i++) {
        int tmp = bsequence.front();
        bsequence.pop_front();
        cout << tmp << " ";
    }
    return 0;
}

void reverse(deque<int> &sequence) {
    stack<int> tmp;
    int temp;
    for(int i = 0; i < sequence.size(); i++) {
        temp = sequence.front();
        sequence.pop_front();
        tmp.push(temp);
    }
    for(int i = 0; i < tmp.size(); i++) {
        temp = tmp.top();
        tmp.pop();
        sequence.push_back(temp);
    }
}