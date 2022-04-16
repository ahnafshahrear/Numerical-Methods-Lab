#include <bits/stdc++.h>

using namespace std;

class SimpsonsRule {
private:
    double lower, upper, grids;
    double gridSpacing;

    double function(double x) {
        return 1 / (1 + x * x);
    }
public:
    double answer;
    
    SimpsonsRule(double a, double b, double n) {
        lower = a;
        upper = b;
        grids = n;
    }
    void solve() {
        gridSpacing = (upper - lower) / grids;
        answer = function(lower) + function(upper);
        for (int k = 1; k < grids; k++) {
            if (k % 2 == 0) {
                answer += 2 * function(lower + k * gridSpacing);
            }
            else answer += 4 * function(lower + k * gridSpacing);
        }
        answer = (gridSpacing / 3) * answer;
        cout << answer;
    }
};

int main() {
    SimpsonsRule x = SimpsonsRule(0, 1, 10);
    x.solve();
    return 0;
}