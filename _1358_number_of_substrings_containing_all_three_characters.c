/*
LeetCode 1358 - Number of Substrings Containing All Three Characters

Problem:
Given a string consisting only of 'a', 'b', and 'c', return the number of substrings
that contain at least one occurrence of each of the three characters.

Approach:
Use the Sliding Window technique with two pointers. Expand the right pointer while
tracking the frequency of each character. Whenever the current window contains at
least one 'a', 'b', and 'c', every substring extending from the current right index
to the end of the string is also valid. Add (n - right) to the answer, then shrink
the window from the left to find more valid starting positions.

Pattern: Sliding Window

Time Complexity: O(n)
Space Complexity: O(1)
*/




int numberOfSubstrings(char* s) {

    int sSize=strlen(s);
    int count[3]={0};
    int left =0,right=0;
    int sub=0;

    while(right < sSize ){
        count[s[right]-'a']++;


        while(count[0] > 0 && count[1]>0 && count[2]>0){
            sub += (sSize - right);

            count[s[left]-'a']--;
            left++;
        }

        right++;
    }

    return sub;
    
}