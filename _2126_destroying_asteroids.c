/*
LeetCode 2126 - Destroying Asteroids

Problem:
Given the initial mass of a planet and an array of asteroid masses, determine
whether the planet can destroy all asteroids. The planet can destroy an asteroid
only if its current mass is greater than or equal to the asteroid's mass, and
its mass increases by the asteroid's mass after destruction.

Approach:
Sort the asteroids in ascending order and process them from smallest to largest.
Destroying smaller asteroids first maximizes the planet's growth, making it easier
to destroy larger asteroids later. If at any point the planet's mass is smaller
than the current asteroid's mass, it is impossible to destroy all asteroids.

Pattern: Greedy

Time Complexity: O(n log n)
Space Complexity: O(1)

Where n = asteroidsSize (excluding the sorting algorithm's internal stack space).
*/

#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {

    qsort(asteroids, asteroidsSize, sizeof(int), compare);

    long long currMass = mass;

    for(int i = 0; i < asteroidsSize; i++) {
        if(currMass >= asteroids[i]) {
            currMass += asteroids[i];
        }
        else {
            return false;
        }
    }

    return true;
}