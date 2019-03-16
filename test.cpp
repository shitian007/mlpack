#include <iostream>
#include <armadillo>

using namespace arma;
// using namespace mlpack;

int main() {
    mat A;
    A << 1 << 2 << endr
      << 2 << 2;
    cout << A << endl;
}