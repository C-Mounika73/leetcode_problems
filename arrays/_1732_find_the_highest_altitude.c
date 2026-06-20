/*
LeetCode 1732 - Find the Highest Altitude

Problem:
A biker starts at altitude 0. Given an array gain where
gain[i] represents the net altitude change between points
i and i+1, return the highest altitude reached during the trip.

Approach:
Maintain the current altitude while traversing the gain array.
Update the maximum altitude whenever the current altitude exceeds
the previous maximum.

Pattern: Prefix Sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

int largestAltitude(int* gain, int gainSize) {
    int maxaltitude=0;
    int n;
    int currentaltitude=0;
    for(n=0;n<gainSize;n++){
        currentaltitude=currentaltitude + gain[n];
        if(currentaltitude>maxaltitude){
            maxaltitude=currentaltitude;
        }
    }

    return maxaltitude;
    
}