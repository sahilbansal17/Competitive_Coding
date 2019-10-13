#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
template <typename T> class Matrix;
template <typename T> istream& operator>>(istream&in, Matrix<T> &m);
template <typename T> ostream& operator<<(ostream &out, const Matrix<T> &m);
template <class T>
class Matrix {
    private:
        int rows, cols;
        vector<vector<T>> mat;

    public:
    /* Constructors to initialize matrix */
        Matrix(int r, int c) : rows(r), cols(c) {
            this->mat = vector<vector<T>>(r, vector<T>(c));
        }   
        Matrix(int r, int c, int z) : rows(r), cols(c) {
            this->mat = vector<vector<T>>(r, vector<T>(c, z));
        }
        /* Copy and Move constructors */
        Matrix(vector<vector<T>> &mat) : mat(mat) {}
        Matrix(vector<vector<T>> &&mat) : mat(move(mat)) {}

        Matrix(Matrix &m) : mat(m.mat), rows(m.rows), cols(m.cols) {}
        Matrix(Matrix &&m) : mat(move(m.mat)), rows(move(m.rows)), cols(move(m.cols)) {}
        /* Getters  */
        int getRows() { return this->rows; }
        int getCols() { return this->cols; }
        vector<vector<T>> getMat() { return this->mat; }
        Matrix<T> minorMatrix(int x, int y); //Calculate minor matrix for cofactor calculation

        void operator=(Matrix<T> &other);
        void operator=(Matrix<T> &&other);
        
        vector<T>& operator[](const int &i);
        Matrix<T> operator+(Matrix<T> &other);
        Matrix<T> operator-(Matrix<T> &other);
        Matrix<T> operator*(Matrix<T> &other);
        Matrix<T> operator*(const T &other);

        double determinant(void);
        Matrix<T> transpose(void);
        Matrix<T> identity(void);
        Matrix<double> adjoint(void);
        Matrix<double> inverse(void);

        friend istream& operator>>(istream &in, Matrix<T> &m) {
            for(auto &it : m.mat)
                for(auto &it2 : it)
                    in >> it2;
            return in;
        }
        friend ostream& operator<<(ostream &out, const Matrix<T> &m) {
            for(auto it : m.mat) {
                for(auto it2 : it) out << it2 << " ";
                    out << endl;
            }
            return out;
        };
};

template <typename T>
vector<T>& Matrix<T>::operator[](const int &i) {
    /*
        Access matrix element using [] operator
        @returns vector<T> 
     */
    if(abs(i) > this->getRows())
        throw invalid_argument("operator[] out of bounds in Matrix");
    if(i >= 0)
        return this->mat[i];
    else
        return this->mat[this->getRows() + i];
}

template <typename T>
Matrix<T> Matrix<T>::minorMatrix(int x, int y) {
    /*
        Calculates minor matrix for mat[x][y]
        @return Matrix<T> 
     */
    if(x < 0 || y < 0 || x >= this->getRows() || y >= this->getCols())
        throw invalid_argument("Out of bounds for submatrix");

    //Select elements from all rows and columns except row x and column y
    Matrix<T> minor(this->getRows() - 1, this->getCols() - 1);
    int i = 0, j = 0;
    for(int row = 0; row < minor.getRows();row++) {
        for(int col = 0;col < minor.getCols();col++) {
            if(row != x && col != y) {
                minor.mat[i][j++] = this->mat[row][col];
                if(j == this->getCols() - 1) {
                    j = 0;
                    i++;
                } 
            }
        }
    }
    return minor;
}
 
template <typename T>
void Matrix<T>::operator=(Matrix<T> &other) {
    //Assignment operator for copying
    this->mat = other.mat;
    this->rows = other.rows;
    this->cols = other.cols;
}

template <typename T>
void Matrix<T>::operator=(Matrix<T> &&other) {
    //Assignment operator for copying
    this->mat = move(other.mat);
    this->rows = move(other.rows);
    this->cols = move(other.cols);
}

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &other) {
    /*
        Addition of matrices
        Only possible if dimensions are same
        @return Matrix<T> result with addition of both matrices 
     */
    if(this->getRows() != other.getRows() || this->getCols() != other.getCols())
        throw invalid_argument("Matrices could not be added, because dimensions are not same");

    Matrix<T> result(*this);
    for(int i = 0;i < this->getRows();i++)
        for(int j = 0;j < this->getCols();j++)
            result[i][j] = (*this)[i][j] + other[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &other) {
    /*
        Subtraction of matrices
        Only possible if dimensions are same
        @return Matrix<T> result with subtraction of both matrices 
     */
    if(this->getRows() != other.getRows() || this->getCols() != other.getCols())
        throw invalid_argument("Matrices could not be subtracted, because dimensions are not same");

    Matrix<T> result(*this);
    for(int i = 0;i < this->getRows();i++)
        for(int j = 0;j < this->getCols();j++)
            result[i][j] = (*this)[i][j] - other[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &other) {
    /*
        Matrix Multiplication of matrices
        Only possible if matA.cols == matb.rows
        @return Matrix<T> result with matrix multiplication of both matrices 
     */
    Matrix<T> result(this->getRows(), other.getCols());

    if(this->getCols() != other.getRows())
        throw invalid_argument("Matrices cannot be multiplied");
    
    for(int i = 0;i < this->getRows();i++) {
        for(int j = 0;j < other.getCols();j++) {
            T temp = 0;
            for(int k = 0;k < this->getRows();k++)
                temp += (*this)[i][k] * other[k][j];
            result[i][j] = temp;
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &other) {
    /*
        Scalar multiplication of matrices
        Multiplies each element in matrix with scalar quantity
        @returns Matrix<T> 
     */
    Matrix<T> result(*this);
    for(auto &it : result.mat)
        for(auto &it2 : it)
            it2 *= other;
    return result;
}

template <typename T>
double Matrix<T>::determinant(void) {
    /*
        Calculates determinant of the matrix
        Determinant calculated by taking cofactor of each element in top row and multipying them together.
        Each product added or subtracted from determinant alternatively.
        @return double value containg determinant
     */
    if(this->getRows() != this->getCols())
        throw logic_error("Cannot calculate determinant of non-square matrix");
    
    if(this->getCols() == 1)
        return this->getMat()[0][0];
    else if(this->getCols() == 2)
        return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    
    double det = 0;
    bool neg = false;
    for(int i = 0;i < this->getCols();++i, neg = !neg) {
        Matrix<T> m(this->getRows() - 1, this->getCols() - 1);
        for(int baseRow = 1, subRow = 0; baseRow < this->getRows() && subRow < m.getRows();++baseRow, subRow++) {
            for(int baseCol = 0, subCol = 0; baseCol < this->getCols() && subCol < m.getCols();++baseCol) {
                if(baseCol == i) continue;
                m[subRow][subCol++] = (*this)[baseRow][baseCol];
            }
        }
        det += (*this)[0][i] * m.determinant() * (neg ? -1 : 1);
    }
    return det;
}

template <typename T>
Matrix<T> Matrix<T>::transpose(void) {
    /*
        Transposes matrix by making columns into rows and rows into columns 
     */
    Matrix<T> result(this->getCols(), this->getRows());
    for(int i = 0;i < this->getRows();i++)
        for(int j = 0;j < this->getCols();j++)
            result.mat[j][i] = this->mat[i][j];
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::identity(void) {
    /*
        Creates identity matrix of the size of the matrix 
     */
    Matrix<T> result(this->getRows(), this->getCols(), 0);
    for(int i = 0;i < result.getRows();i++)
        result.mat[i][i] = 1;
    return result;
}

template <typename T>
Matrix<double> Matrix<T>::adjoint(void) {
    /*
        Adjoint of a matrix if the cofactor i.e. determinant of the minor matrix for each element with alternative plus and minus signs 
     */
    if(this->getRows() != this->getCols())
        throw logic_error("Cannot compute adjoint for non-square matrix");
    bool neg = false;
    Matrix<T> result(this->getCols(), this->getRows());
    for(int i = 0;i < this->getRows();i++)
        for(int j = 0;j < this->getCols();j++) {
            result.mat[j][i] = this->minorMatrix(i, j).determinant() * (neg ? -1 : 1);
            neg = !neg;
        }
    return result;
}

template <typename T>
Matrix<double> Matrix<T>::inverse(void) {
    /*
        Inverse of a matrix is calculated as: A^(-1) = adj(A) / det(A)
        adj(A) = adjoint of A
        det(A) = determinant of A 
     */
    double det = this->determinant();
    if(det == 0)
        throw logic_error("Inverse does not exist");
    return (this->adjoint() * (1/det));
}

int main(int argc, char const *argv[])
{
    cout << "Enter Matrix m: \n";
    Matrix<double> m(3, 3);
    cin >> m;
    cout << "Matrix m:\n";
    cout << m;
    cout << "Enter Matrix n:\n";
    Matrix<double> n(3, 3);
    cin >> n;
    cout << "Matrix n:\n";
    cout << n;
    cout << "Addition: \n";
    cout << (m + n);
    cout << "Subtraction: \n";
    cout << (m - n);
    cout << "Matrix Multiplication: \n";
    cout << (m * n);
    cout << "Scalar Multiplication: \n";
    cout << (m * 4);
    cout << "Determinant of Matrix: " << m.determinant() << endl;
    cout << "Identity Matrix: \n";
    cout << m.identity();
    cout << "Adjoint Matrix: \n";
    cout << m.adjoint();
    cout << "Inverse Matrix: \n";
    cout << m.inverse();
    return 0;
}
