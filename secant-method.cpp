#include <bits/stdc++.h>

using namespace std;

class SecantMethod {
private:
    double epsilon = 0.001;

    double function(double x) {
        //return x * x * x + x * x - 1;
        return (x * x) + (5 * x) + 6;
    }
public:
    double root;

    void solve() {
        srand((int)time(0));
        root = rand() % 10;
        root = -1 * root;
        double previousRoot = 1000;
        while (true) {
            double newRoot = root - (function(root) * (root - previousRoot)) / (function(root) - function(previousRoot));
            if (abs((newRoot - root) / newRoot) < epsilon) {
                break;
            }
            previousRoot = root;
            root = newRoot;
        }
        cout << "The root is " << root << "\n";
    }
};

int main() {
    SecantMethod x = SecantMethod();
    x.solve();
    return 0;
}
