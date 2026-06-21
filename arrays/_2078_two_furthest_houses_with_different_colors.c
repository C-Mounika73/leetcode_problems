/*
LeetCode 2078 - Two Furthest Houses With Different Colors

Problem:
Given an array where colors[i] represents the color of the ith house,
find the maximum distance between two houses that have different colors.

Approach:
The maximum distance must involve either the first house or the last house.
Scan from the end to find the furthest house whose color differs from the
first house, then scan from the beginning to find the furthest house whose
color differs from the last house. The larger of these two distances is the answer.

Pattern: Greedy

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxDistance(int colors[], int n) {
     int maxdist=0;
     int i;
     for(i=n-1;i>=0;i--){
        if(colors[i]!= colors[0]){
            maxdist=i;
            break;
        }
     }
     for(i=0;i<n;i++){
        if(colors[i] !=colors[n-1]){
            if((n-1-i)>maxdist)
            maxdist=n-1-i;
            break;
        }
     }
     return maxdist;
    
}