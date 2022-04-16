#include <bits/stdc++.h>

using namespace std;

class NewtonRaphsonMethod {
private:
    double epsilon = 0.001;

    double function(double x) {
        return x * x * x + x * x - 1;
    }

    double functionPrime(double x) {
        return 3 * x * x + 2 * x;
    }
public:
    double root;

    void solve() {
        srand((int)time(0));
        while (true) {
            root = -9 + rand() % 10;
            if (functionPrime(root) != 0) {
                break;
            }
        }
        double previousRoot = 1000;
        while (true) {
            if (functionPrime(root) == 0) {
                root++;
            }
            root -= function(root) / functionPrime(root);
            if (abs((root - previousRoot) / root) < epsilon) {
                break;
            }
            previousRoot = root;
        }
        cout << "The root is " << root << "\n";
    } 
};

int main() {
    NewtonRaphsonMethod x = NewtonRaphsonMethod();
    x.solve();
    return 0;
}
