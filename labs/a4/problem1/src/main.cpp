#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NumberOps {
public:
    void countNumbers(const vector<int>& nums) {
        int pos = 0, neg = 0, zero = 0;
        for (int num : nums) {
            if (num > 0) pos++;
            else if (num < 0) neg++;
            else zero++;
        }
        cout << "Positive: " << pos << endl;
        cout << "Negative: " << neg << endl;
        cout << "Zeros: " << zero << endl;
    }

    int findFirstPrime(const vector<int>& nums) {
        for (int num : nums) {
            if (num <= 0) return -1;
        }
        for (int num : nums) {
            if (isPrime(num)) return num;
        }
        return -1;
    }

    int sumEvenNegatives(const vector<int>& nums) {
        for (int num : nums) {
            if (num >= 0) return -1;
        }
        int sum = 0;
        for (int num : nums) {
            if (num % 2 == 0) sum += num;
        }
        return sum;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        return true;
    }
};

int main() {
    NumberOps ops;

    // Test countNumbers
    vector<int> test1 = {1, -2, 0, 3, -4};
    ops.countNumbers(test1);

    // Test findFirstPrime
    vector<int> validPrimes = {4, 6, 7, 9};
    vector<int> invalidPrimes = {4, -5, 6};
    vector<int> noPrimes = {4, 6, 8};
    cout << "First prime (valid): " << ops.findFirstPrime(validPrimes) << endl;
    cout << "First prime (invalid input): " << ops.findFirstPrime(invalidPrimes) << endl;
    cout << "First prime (no primes): " << ops.findFirstPrime(noPrimes) << endl;

    // Test sumEvenNegatives
    vector<int> validNegs = {-2, -4, -6};
    vector<int> invalidNegs = {-1, 2, -3};
    cout << "Sum even negatives (valid): " << ops.sumEvenNegatives(validNegs) << endl;
    cout << "Sum even negatives (invalid): " << ops.sumEvenNegatives(invalidNegs) << endl;

    return 0;
}