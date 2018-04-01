#ifndef HWMATRIX_H_INCLUDED
#define HWMATRIX_H_INCLUDED

template<typename T> hwmatrix {
//    friend std::istream& operator>>(std::istream& in, hwmatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, hwmatrix& mat);
    friend hwmatrix& operator+(hwmatrix& matA, hwmatrix& matB);
    friend hwmatrix& operator*(hwmatrix& matA, hwmatrix& matB);
private:
    vector<vector<T>> matrix;
public:
    hwmatrix() = default;
    hwmatrix(T m, T n) : matrix(m, vector<T>(n)) {};
    T rows() {
        return matrix.size();
    }
    T cols() {
        return matrix[0].size();
    }
    double det(hwmatrix& mat) {

    }
};

inline hwmatrix<T>& operator+(hwmatrix<T>& matA, hwmatrix<T>& matB) {
    int rowA = matA.size();
    int colA = matA[0].size();
    int rowB = matB.size();
    int colB = matB[0].size();
    hwmatrix<T> res;

    if()
}


#endif // HWMATRIX_H_INCLUDED
