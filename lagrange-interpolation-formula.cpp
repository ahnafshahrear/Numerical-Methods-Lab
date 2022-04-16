#include <bits/stdc++.h>

using namespace std;

class LagrangeInterpolationFormula {
private:

public:
    int n, at;
    double x[100], y[100];
    double ans = 0;
    LagrangeInterpolationFormula() {
        cin >> n;
        for (int k = 0; k < n; k++) {
            cin >> x[k] >> y[k];
        }
        cin >> at;
    }
    void solve() {
        for (int i = 0; i < n; i++) {
            double term = y[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    term = term * (at - x[j]) / (x[i] - x[j]);
                }
            }
            ans += term;
        }
        cout << ans;
    }
};

int main() {
    LagrangeInterpolationFormula x = LagrangeInterpolationFormula();
    x.solve();
}