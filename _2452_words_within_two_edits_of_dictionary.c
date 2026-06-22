/*
LeetCode 2452 - Words Within Two Edits of Dictionary

Problem:
Given two arrays of equal-length words, queries and dictionary, determine
which query words can be transformed into at least one dictionary word using
at most two character replacements.

Approach:
For each query word, compare it with every word in the dictionary.
Count the number of differing character positions between the two words.
If the difference count is at most 2, the query is valid and is added to
the result. Stop checking further dictionary words once a match is found.

Pattern: Brute Force / String Comparison

Time Complexity: O(Q * D * L)
Space Complexity: O(Q)

Where:
Q = queriesSize
D = dictionarySize
L = length of each word
*/

int isValid(char *a, char *b) {
    int diff = 0;
    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 2) return 0;
        }
    }
    return 1; // diff <= 2
}

char** twoEditWords(char** queries, int queriesSize,
                   char** dictionary, int dictionarySize,
                   int* returnSize) {
    
    char **result = (char**)malloc(sizeof(char*) * queriesSize);
    int k = 0;

    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictionarySize; j++) {
            
            if (isValid(queries[i], dictionary[j])) {
                result[k++] = queries[i];
                break; // no need to check more dictionary words
            }
        }
    }

    *returnSize = k;
    return result;
}