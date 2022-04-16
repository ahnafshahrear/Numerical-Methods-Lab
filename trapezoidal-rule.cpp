#include <bits/stdc++.h>

using namespace std;

class TrapezoidalRule {
private:
    double lower, upper, grids;
    double gridSpacing;

    double function(double x) {
        return 1 / (1 + x * x);
    }
public:
    double answer;
    
    TrapezoidalRule(double a, double b, double n) {
        lower = a;
        upper = b;
        grids = n;
    }
    void solve() {
        gridSpacing = (upper - lower) / grids;
        answer = function(lower) + function(upper);
        for (int k = 1; k < grids; k++) {
            answer += 2 * function(lower + k * gridSpacing);
        }
        answer = (gridSpacing / 2) * answer;
        cout << answer;
    }
};

int main() {
    TrapezoidalRule x = TrapezoidalRule(0, 1, 10);
    x.solve();
    return 0;
}