#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

// Compare items by their profit/weight ratio
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), cmp);

    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;
    return 0;
}
