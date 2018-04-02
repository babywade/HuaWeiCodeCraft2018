#ifndef HWMATRIX_H_INCLUDED
#define HWMATRIX_H_INCLUDED

template<typename T> hwmatrix {
//    friend std::istream& operator>>(std::istream& in, hwmatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, hwmatrix& mat);
    friend hwmatrix<typename T>& operator+(hwmatrix& matA, hwmatrix& matB);
    friend hwmatrix& operator-(hwmatrix& matA, hwmatrix& matB);
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
        row = mat.size();
        col = mat[0].size();

        if(row != col) {
            cout << "error, mat is not a square matrix" << endl;
        } else {
            T res;

        }

    }
    void resize(int rows, int cols) {
        matrix.resize(rows);
        for(auto& s:matrix) {
            s.resize(cols);
        }
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
