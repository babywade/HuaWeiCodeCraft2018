//��ά����װ������
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
//�������
#define VOLUMN_X 10
#define VOLUMN_Y 10

//�����㷨
void nextFit(pair<int, int>& block, vector<int>& answer, int& cnt, vector<pair<int, int>>& volumns);
void firstFit(int& block, vector<int>& answer, int& cnt, vector<int>& volumns);
void bestFit(int& block, vector<int>& answer, int& cnt, vector<int>& volumns);
//�ѻ��㷨
void firstFitDecreasing(vector<int>& blocks, vector<int>& answer, int& cnt, vector<int>& volumns);
void bestFitDecreasing(vector<int>& blocks, vector<int>& answer, int& cnt, vector<int>& volumns);

int main() {
    pair<int, int> block;
    vector<int> answer;
    vector<pair<int, int>> volumns;
    //#1���ӳ�ʼ��ΪVOLUMN
    volumns.push_back({VOLUMN_X, VOLUMN_Y});
    int cnt = 1;
    vector<pair<int, int>> blocks;

    while(cin >> block) {
        nextFit(block, answer, cnt, volumns);
//        firstFit(block, answer, cnt, volumns);
//        bestFit(block, answer, cnt, volumns);

//        blocks.push_back(block);
    }
//    firstFitDecreasing(blocks, answer, cnt, volumns);

    //������
    for(auto& s:answer) {
        cout << s << " ";
    }
    cout << endl;
    for(auto& s:volumns) {
        cout << s << " ";
    }
    return 0;
}
    //������Ӧ�㷨
void nextFit(pair<int, int>& block, vector<int>& answer, int& cnt, vector<pair<int, int>>& volumns) {
    //��Ҫ����>=������
    if(volumns[cnt - 1] >= block) {
        answer.push_back(cnt);
        //��Ҫ����-=������
        volumns[cnt - 1] -= block;
    } else {
        ++cnt;
        answer.push_back(cnt);
        //��Ҫ����-������
        volumns.push_back({VOLUMN_X, VOLUMN_Y} - block);
    }
}
    //�״���Ӧ�㷨
void firstFit(int& block, vector<int>& answer, int& cnt, vector<int>& volumns) {
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
    //�����Ӧ�㷨
void bestFit(int& block, vector<int>& answer, int& cnt, vector<int>& volumns) {
    int bestPosition = cnt + 1;
    int min_volumn = volumns[0];
    for(vector<int>::iterator iter = volumns.begin(); iter != volumns.end(); ++iter) {
        if((*iter) >= block && (*iter) - block <= min_volumn) {
            bestPosition = iter - volumns.cbegin() + 1;
            min_volumn = (*iter) - block;
            cout << min_volumn << " " << bestPosition << endl;
        }
    }

    if(bestPosition == (cnt + 1)) {
        volumns.push_back(VOLUMN - block);
        ++cnt;
        answer.push_back(cnt);
    } else {
        answer.push_back(bestPosition);
        volumns[bestPosition - 1] -= block;
    }
}

void firstFitDecreasing(vector<int>& blocks, vector<int>& answer, int& cnt, vector<int>& volumns) {
    sort(blocks.begin(), blocks.end());
    for(auto& block:blocks) {
        firstFit(block, answer, cnt, volumns);
    }
}

void bestFitDecreasing(vector<int>& blocks, vector<int>& answer, int& cnt, vector<int>& volumns) {
    sort(blocks.begin(), blocks.end());
    for(auto& block:blocks) {
        bestFit(block, answer, cnt, volumns);
    }
}
