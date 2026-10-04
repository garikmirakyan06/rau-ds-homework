#include <iostream>
#include <string>
#include <cassert>

template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) {
        return data[row][col];
    }

    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(Matrix& other) {
        Matrix result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

void test_Matrix() {
    Matrix<int, 2, 2> a, b;
    a.set(0, 0, 1); a.set(0, 1, 2);
    a.set(1, 0, 3); a.set(1, 1, 4);
    b.set(0, 0, 10); b.set(0, 1, 20);
    b.set(1, 0, 30); b.set(1, 1, 40);
    Matrix<int, 2, 2> c = a + b;
    assert(c.get(0, 0) == 11 && c.get(1, 1) == 44);
    c.print();

    Matrix<double, 1, 2> d1, d2;
    d1.set(0, 0, 1.5); d1.set(0, 1, 2.5);
    d2.set(0, 0, 0.5); d2.set(0, 1, 0.5);
    Matrix<double, 1, 2> d3 = d1 + d2;
    assert(d3.get(0, 0) == 2.0 && d3.get(0, 1) == 3.0);
    d3.print();

    Matrix<std::string, 1, 2> s1, s2;
    s1.set(0, 0, "ab"); s1.set(0, 1, "cd");
    s2.set(0, 0, "12"); s2.set(0, 1, "34");
    Matrix<std::string, 1, 2> s3 = s1 + s2;
    assert(s3.get(0, 0) == "ab12" && s3.get(0, 1) == "cd34");
    s3.print();

    std::cout << "Matrix passed" << std::endl;
}

int main() {
    test_Matrix();
    return 0;
}
