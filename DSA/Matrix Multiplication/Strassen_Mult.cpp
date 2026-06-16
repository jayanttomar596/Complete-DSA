#include <iostream>
#include<vector>
using namespace std;



// Add two matrices
vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Split matrix into quadrants
void split(const vector<vector<int>>& A, vector<vector<int>>& A11, vector<vector<int>>& A12,
           vector<vector<int>>& A21, vector<vector<int>>& A22) {
    int n = A.size() / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n];
            A21[i][j] = A[i + n][j];
            A22[i][j] = A[i + n][j + n];
        }
    }
}

// Combine quadrants into one matrix
vector<vector<int>> combine(const vector<vector<int>>& C11, const vector<vector<int>>& C12,
                            const vector<vector<int>>& C21, const vector<vector<int>>& C22) {
    int n = C11.size();
    vector<vector<int>> C(2 * n, vector<int>(2 * n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
    }
    return C;
}







vector<vector<int>> multiplyDC(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // 8 multiplications
    auto M1 = multiplyDC(A11, B11);
    auto M2 = multiplyDC(A12, B21);
    auto M3 = multiplyDC(A11, B12);
    auto M4 = multiplyDC(A12, B22);
    auto M5 = multiplyDC(A21, B11);
    auto M6 = multiplyDC(A22, B21);
    auto M7 = multiplyDC(A21, B12);
    auto M8 = multiplyDC(A22, B22);

    // Combine results
    auto C11 = add(M1, M2);
    auto C12 = add(M3, M4);
    auto C21 = add(M5, M6);
    auto C22 = add(M7, M8);

    return combine(C11, C12, C21, C22);
}











vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // Strassen’s 7 multiplications
    auto M1 = strassen(add(A11, A22), add(B11, B22));
    auto M2 = strassen(add(A21, A22), B11);
    auto M3 = strassen(A11, subtract(B12, B22));
    auto M4 = strassen(A22, subtract(B21, B11));
    auto M5 = strassen(add(A11, A12), B22);
    auto M6 = strassen(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Compute result submatrices
    auto C11 = add(subtract(add(M1, M4), M5), M7);
    auto C12 = add(M3, M5);
    auto C21 = add(M2, M4);
    auto C22 = add(subtract(add(M1, M3), M2), M6);

    return combine(C11, C12, C21, C22);
}








int main() {

    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Divide & Conquer (8 mults):\n";
    auto C1 = multiplyDC(A, B);
    for (auto& row : C1) {
        for (auto val : row) cout << val << " ";
        cout << "\n";
    }

    cout << "\nStrassen’s (7 mults):\n";
    auto C2 = strassen(A, B);
    for (auto& row : C2) {
        for (auto val : row) cout << val << " ";
        cout << "\n";
    }
    
    return 0;
}