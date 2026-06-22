/*
LeetCode 1833 - Maximum Ice Cream Bars

Problem:
Given an array costs where costs[i] represents the price of an ice cream bar and
an integer coins representing the available money, return the maximum number of
ice cream bars that can be purchased. The solution must use counting sort.

Approach:
First, find the maximum cost and build a frequency array to count how many ice
cream bars exist for each price. Then iterate through prices in ascending order,
buying as many bars as possible at each price. Since cheaper bars are purchased
first, this greedy counting-sort approach maximizes the total number of bars bought.

Pattern: Greedy + Counting Sort

Time Complexity: O(n + m)
Space Complexity: O(m)

Where:
- n = costsSize
- m = maximum value in costs[]
*/

int maxIceCream(int* costs, int costsSize, int coins) {
    int maxCost = 0;

    // Find maximum cost
    for (int i = 0; i < costsSize; i++) {
        if (costs[i] > maxCost) {
            maxCost = costs[i];
        }
    }

    // Frequency array
    int *freq = (int *)calloc(maxCost + 1, sizeof(int));

    for (int i = 0; i < costsSize; i++) {
        freq[costs[i]]++;
    }

    int count = 0;

    // Process prices from smallest to largest
    for (int price = 1; price <= maxCost; price++) {
        if (freq[price] == 0) {
            continue;
        }

        int canBuy = coins / price;

        if (canBuy >= freq[price]) {
            count += freq[price];
            coins -= freq[price] * price;
        } else {
            count += canBuy;
            break;
        }
    }

    free(freq);
    return count;
}