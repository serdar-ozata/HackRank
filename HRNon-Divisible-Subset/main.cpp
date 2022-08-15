#include <string>
#include <vector>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <iostream>

using namespace std;

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> &s) {
    int *counts = new int[k - 1];
    bool divisibleFound = false;
    for (int i = 0; i < k - 1; ++i) {
        counts[i] = 0;
    }
    for (auto x: s) {
        int mod = x % k;
        if (mod != 0) counts[mod - 1]++;
        else divisibleFound = true;
    }
    int sum = 0;
    int end = (k - 1) / 2;
    for (int i = 0; i < end; ++i) {
        if (counts[i] > counts[k - i - 2])
            sum += counts[i];
        else
            sum += counts[k - i - 2];
    }
    if ((k % 2) == 0 && counts[(k - 1) / 2] > 0) {
        sum++;
    }
    if (divisibleFound)
        sum++;
    delete[] counts;
    return sum;
}

int main() {
    int k, num;
    int length;
    cin >> length;
    cin >> k;
    vector<int> v;
    v.reserve(length);
    for (int i = 0; i < length; ++i) {
        cin >> num;
        v.push_back(num);
    }

    cout << nonDivisibleSubset(k, v) << endl;
}
