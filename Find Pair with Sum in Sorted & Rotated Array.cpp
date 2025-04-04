#include <bits/stdc++.h>
using namespace std;

int calculateDigitSum(int number) {
    int sum = 0;
    number = abs(number);
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

long long countSpecialPairs(int n, vector<int> numbers) {
    unordered_map<int, int> digitSumCounts;
    for (int num : numbers) {
        int currentSum = calculateDigitSum(num);
        digitSumCounts[currentSum]++;
    }
    
    long long totalPairs = 0;
    for (auto& [sum, count] : digitSumCounts) {
        if (count >= 2) {
            totalPairs += (long long)count * (count - 1) / 2;
        }
    }
    return totalPairs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int size;
    cin >> size;
    vector<int> numbers(size);
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    
    long long result = countSpecialPairs(size, numbers);
    cout << result << endl;
    
    return 0;
}
