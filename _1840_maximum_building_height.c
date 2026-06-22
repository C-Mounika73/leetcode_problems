/*
LeetCode 1840 - Maximum Building Height

Problem:
Given n buildings in a line, building 1 has height 0, adjacent buildings can differ in height by at most 1,
and some buildings have maximum height restrictions. Find the maximum possible height of any building.

Approach:
Add two boundary restrictions: building 1 with height 0 and building n with height n-1.
Sort all restrictions by building index. Perform a left-to-right pass to enforce the maximum height
reachable from previous buildings, then a right-to-left pass to enforce constraints from the right side.
After both passes, every restriction becomes feasible. For each adjacent pair of restricted buildings,
compute the highest peak achievable between them using the available distance and endpoint heights.
The maximum such peak is the answer.

Pattern: Greedy

Time Complexity: O(m log m)
Space Complexity: O(m)

Where m = restrictionsSize + 2.
*/

int cmp(const void *a,const void *b){
    return ((int *) a)[0]-((int *)b)[0];
}


int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {

    if(restrictionsSize==0)
       return n-1;

    int m=restrictionsSize +2;
    int arr[m][2];

    arr[0][0]=1;
    arr[0][1]=0;

    for(int i=0;i<restrictionsSize ; i++){
        arr[i+1][0]=restrictions[i][0];
        arr[i+1][1]=restrictions[i][1];

    }
    
    qsort(arr+1,restrictionsSize,sizeof(arr[0]),cmp);

    arr[m-1][0]=n;
    arr[m-1][1]=n-1;

    for(int i=1;i<m;i++){
        int dist = arr[i][0]-arr[i-1][0];
        arr[i][1]= fmin (arr [i][1] , arr[i-1][1] + dist);

    }

    for(int i=m-2;i>=0;i--){
        int dist =arr[i+1][0]-arr[i][0];
        arr[i][1] = fmin (arr [i][1] , arr[i+1][1] + dist);

    } 


    int ans=0;
    for(int i=0;i<m-1;i++){
        int dist = arr[i+1][0] - arr[i][0];

        int peak = (arr[i][1] + arr [i+1][1] + dist)/2;

        if (peak > ans)
            ans=peak;
    }

    return ans;

}

