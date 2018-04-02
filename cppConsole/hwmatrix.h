#ifndef HWMATRIX_H_INCLUDED
#define HWMATRIX_H_INCLUDED

template<typename T> hwmatrix {
//    friend std::istream& operator>>(std::istream& in, hwmatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, hwmatrix<T>& mat);
    friend hwmatrix<T>& operator+(hwmatrix<T>& matA, hwmatrix<T>& matB);
    friend hwmatrix<T>& operator-(hwmatrix<T>& matA, hwmatrix<T>& matB);
    friend hwmatrix<T>& operator*(hwmatrix<T>& matA, hwmatrix<T>& matB);
private:
    vector<vector<T>> matrix;
public:
    hwmatrix() = default;
    hwmatrix(int m, int n) : matrix(m, vector<T>(n)) {};
    int rows() {
        return matrix.size();
    }
    int cols() {
        return matrix[0].size();
    }
    double det(hwmatrix<T>& mat) {
        row = mat.size();
        col = mat[0].size();

        if(row != col) {
            cout << "error, mat is not a square matrix" << endl;
        } else {
            hwmatrix<T> res;

        }
    }
    void resize(int rows, int cols) {
        matrix.resize(rows);
        for(auto& s:matrix) {
            s.resize(cols);
        }
    }
    hwmatrix<T>& transpose(hwmatrix<T>& mat) {

    }
};

inline hwmatrix<T>& operator+(hwmatrix<T>& matA, hwmatrix<T>& matB) {
    int rowA = matA.size();
    int colA = matA[0].size();
    int rowB = matB.size();
    int colB = matB[0].size();
    hwmatrix<T> res;

    if(rowA != rowB || colA != colB) {
        cout << "input error" << endl;
        return res;
    } else {
        res.resize(rowA, colA);
        for(int i = 0; i < rowA; i++) {
            res[i] = matA[i] + matB[i];
        }
    }
    return res;
}

inline hwmatrix<T>& oeprator*(hwmatrix<T>& matA, hwmatrix<T>& matB) {
    int rowA = matA.size();
    int colA = matA[0].size();
    int rowB = matB.size();
    int colB = matB[0].size();
    hwmatrix<T> res;

    if(colA != rowB) {
        cout << "input error" << endl;
        return res;
    } else {
        res.resize(rowA, colB);
        for(int i = 0; i < rowA; i++) {
            for(int j = 0; j < colB; j++) {
                for(int k = 0; k < colA; k++) {
                    res[i][j] += matA[i][k] * matB[k][j];
                }
            }
        }
    }
    return res;
}

inline hwmatrix<T>& operator-(hwmatrix& matA, hwmatrix& matB) {
    int rowA = matA.size();
    int colA = matA[0].size();
    int rowB = matB.size();
    int colB = matB[0].size();
    hwmatrix<T> res;

    if(rowA != rowB || colA != colB) {
        cout << "input error" << endl;
        return res;
    } else {
        res.resize(rowA, colA);
        for(int i = 0; i < rowA; i++) {
            res[i] = matA[i] - matB[i];
        }
    }
    return res;
}

#endif // HWMATRIX_H_INCLUDED
