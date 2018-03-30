#ifndef HWPAIR_H_INCLUDED
#define HWPAIR_H_INCLUDED
//解题工具类
class hwpair {
    friend std::istream& operator>>(std::istream& in, hwpair& block);
    friend std::ostream& operator<<(std::ostream& out, hwpair& block);
    friend bool operator>=(hwpair& volumn, hwpair& block);
    friend bool operator<=(hwpair& volumn, hwpair& block);
    friend bool operator<(hwpair& volumn, hwpair& block);
    friend hwpair& operator-=(hwpair& volumn, hwpair& block);
    friend hwpair& operator-(hwpair& volumn, hwpair& block);
private:
    int first;
    int second;
public:
    hwpair() = default;
    hwpair(const int& x, const int& y) : first(x), second(y) {};
    hwpair(std::istream& in);

    int getFirst() {
        return this->first;
    }
    int getSecond() {
        return this->second;
    }
};

inline hwpair::hwpair(std::istream& in) {
    in >> this->first >> this->second;
}

inline std::istream& operator>>(std::istream& in, hwpair& block) {
    char b;
    in >> block.first >> b >> block.second;
    return in;
}

inline std::ostream& operator<<(std::ostream& out, hwpair& block) {
    out << "[" << block.first << ", " << block.second << "]";
    return out;
}

inline bool operator>=(hwpair& volumn, hwpair& block) {
    if(volumn.first >= block.first && volumn.second >= block.second) {
        return true;
    } else {
        return false;
    }
}

inline bool operator<=(hwpair& volumn, hwpair& block) {
    if(volumn.first <= block.first && volumn.second <= block.second) {
        return true;
    } else {
        return false;
    }
}

inline bool operator<(hwpair& volumn, hwpair& block) {
    if(volumn.first < block.first && volumn.second < block.second) {
        return true;
    } else {
        return false;
    }
}
inline hwpair& operator-=(hwpair& volumn, hwpair& block) {
    volumn.first -= block.first;
    volumn.second -= block.second;
    return volumn;
}

inline hwpair& operator-(hwpair& volumn, hwpair& block) {
    volumn.first -= block.first;
    volumn.second -= block.second;
    return volumn;
}
#endif // HWPAIR_H_INCLUDED
