#include <bits/stdc++.h>

using namespace std;

class NewtonsDividedDifferenceInterpolationFormula {
private:
    
public:
    int n;
    double x[100], y[100][100];
    double at;

    NewtonsDividedDifferenceInterpolationFormula() {
        cin >> n;
        for (int k = 0; k < n; k++) {
            cin >> x[k] >> y[k][0];
        }
        cin >> at;
    };

    double proTerm(int n) {
        double value = 1;
        for (int k = 0; k < n; k++) {
            value = value * (at - x[k]);
        }
        return value;
    }

    void createTable() {
        for (int c = 1; c < n; c++) {
            for (int r = 0; r < n - c; r++) {
                y[r][c] = (y[r + 1][c - 1] - y[r][c - 1]) / (x[r + c] - x[r]);
            }
        }
    }

    void solve() {
        createTable();
        double answer = y[0][0];
        for (int i = 1; i < n; i++) {
            answer += proTerm(i) * y[0][i];
        }
        cout << answer;
    }
};

int main() {
    NewtonsDividedDifferenceInterpolationFormula x = NewtonsDividedDifferenceInterpolationFormula();
    x.solve();
}