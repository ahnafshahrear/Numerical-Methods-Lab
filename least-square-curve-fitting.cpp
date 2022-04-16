#include <bits/stdc++.h>

using namespace std;

class LeastSquareCurveFitting {
private:
    int size;
    int x[100], y[100];
public:
    double a, b;

    LeastSquareCurveFitting() {
        cin >> size;
        for (int k = 0; k < size; k++) {
            cin >> x[k] >> y[k];
        }
    }
    
    void solve() {
        double xSum = 0, ySum = 0, xySum = 0, xSquare = 0;
        for (int k = 0; k < size; k++) {
            xSum += x[k];
            ySum += y[k];
            xSquare += x[k] * x[k];
            xySum += x[k] * y[k];
        }
        a = (size * xySum) - (xSum * ySum);
        a /= (size * xSquare) - (xSum * xSum);
        b = (ySum - a * xSum) / size;
        cout << fixed << showpoint;
        cout << setprecision(1);
        cout << "Y = " << a << " * X + " << b << "\n";
    }
};

int main() {
    LeastSquareCurveFitting x = LeastSquareCurveFitting();
    x.solve();
}
