/*
LeetCode 1189 - Maximum Number of Balloons

Problem:
Given a string text, determine the maximum number of times the word "balloon"
can be formed using the characters in the string, where each character can be used at most once.

Approach:
Count the frequency of the required characters: b, a, l, o, and n.
Since "balloon" contains two 'l's and two 'o's, divide their frequencies by 2.
The answer is the minimum count among b, a, l/2, o/2, and n.

Pattern: Hash Map / Frequency Counting

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxNumberOfBalloons(char* text) {

    int freq[5]={0};

    int n=strlen(text);
    for(int i=0;i<n;i++){

        

            if(text[i]=='b'){
                freq[0]++;
            }

            if(text[i]=='a'){
                freq[1]++;
            }

            if(text[i]=='l'){
                freq[2]++;
            }

            if(text[i]=='o'){
                freq[3]++;
            }

            if(text[i]=='n'){
                freq[4]++;
            }
            
    }   

 int ans=freq[0];

 if(freq[1]<ans) ans=freq[1];
 if(freq[2]/2<ans) ans=freq[2]/2;
 if(freq[3]/2 < ans)  ans=freq[3]/2;
if(freq[4] <ans )  ans=freq[4];

return ans;



    
}