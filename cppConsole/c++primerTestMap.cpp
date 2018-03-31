#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <utility>

using namespace std;

int main() {
    //统计单词数
//    map<string, int> word_count;
//    string word;
//    while(cin >> word) {
//        ++word_count[word];
//    }
//    for(const auto& w : word_count) {
//        cout << w.first << ": " << w.second << endl;
//    }

    //忽略常见单词并统计单词数
//    map<string, int> word_count;
//    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
//                           "the", "but", "and", "or", "an", "a"};
//    string word;
//    while(cin >> word) {
//        if(exclude.find(word) == exclude.end()) {
//            ++word_count[word];
//        }
//    }
//    for(const auto& w : word_count) {
//        cout << w.first << ": " << w.second << endl;
//    }

    //map和set中的关键字必须是唯一的，multimap和multiset则无此限制
    //set, multiset的声明都包含在头文件set中
//    vector<int> ivec;
//    for(int i = 0; i < 10; ++i) {
//        ivec.push_back(i);
//        ivec.push_back(i);
//    }
//
//    set<int> iset(ivec.begin(), ivec.end());
//    multiset<int> miset(ivec.begin(), ivec.end());
//    cout << ivec.size() << endl;
//    cout << iset.size() << endl;
//    cout << miset.size() << endl;

    //创建pair对象
//    pair<string, int> process(vector<string>& v) {
//        if(!v.empty()) {
//            return {v.back(), v.back().size()};
//        } else {
//            return pair<string, int>();
//        }
//    }

    //打印特定作者的所有著作
    multimap<string, string> authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    authors.insert(pair<string, string>("Alain de Botton", "On Love"));
    authors.insert(pair<string, string>("Alain de Botton", "Status Anxiety"));
    authors.insert(pair<string, string>("Alain de Botton", "Art of Travel"));
    authors.insert(pair<string, string>("Alain de Botton", "Architecture of Happiness"));

    string search_item("Alain de Botton"); // author we'll look for
    auto entries = authors.count(search_item);// number of elements
    auto iter = authors.find(search_item); // first entry for this author

    // loop through the number of entries there are for this author
    while(entries) {
        cout << iter->second << endl; // print each title
        ++iter;     // advance to the next title
        --entries;  // keep track of how many we've printed
    }
    return 0;
}
