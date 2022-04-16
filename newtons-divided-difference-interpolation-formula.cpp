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
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[i + j] - x[j]);
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