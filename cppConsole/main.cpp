#include <iostream>
#include <vector>

using namespace std;

#define VOLUMN 10

void nextFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns);
void firstFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns);
void bestFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns);

int main() {
    int block;
    vector<int> answer;
    vector<int> volumns;
    volumns.push_back(VOLUMN);
    int cnt = 1;
    while(cin >> block) {
//        nextFit(block, answer, cnt, volumns);
//        firstFit(block, answer, cnt, volumns);
        bestFit(block, answer, cnt, volumns);
    }

    for(auto& s:answer) {
        cout << s << " ";
    }

    return 0;
}

void nextFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns) {
    if(volumns[cnt - 1] >= block) {
        answer.push_back(cnt);
        volumns[cnt - 1] -= block;
    } else {
        ++cnt;
        answer.push_back(cnt);
        volumns.push_back(VOLUMN - block);
    }
}

void firstFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns) {
    for(vector<int>::iterator iter = volumns.begin(); iter != volumns.end(); ++iter) {
        if((*iter) >= block) {
            answer.push_back(iter - volumns.cbegin() + 1);
            *iter -= block;
            return;
        }
    }

    volumns.push_back(VOLUMN - block);
    ++cnt;
    answer.push_back(cnt);
}

void bestFit(int block, vector<int>& answer, int& cnt, vector<int>& volumns) {
    int bestPosition = cnt + 1;
    int min_volumn = VOLUMN;
    for(vector<int>::iterator iter = volumns.begin(); iter != volumns.end(); ++iter) {
        if((*iter) >= block && (*iter) - block <= min_volumn) {
            bestPosition = iter - volumns.cbegin() + 1;
            min_volumn = (*iter) - block;
        }
    }
    if(bestPosition == cnt + 1) {
        volumns.push_back(VOLUMN - block);
        ++cnt;
        answer.push_back(cnt);
    } else {
        answer.push_back(bestPosition);
        volumns[bestPosition] -= block;
    }
}
