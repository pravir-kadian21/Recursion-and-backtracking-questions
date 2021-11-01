/*1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.
*/
#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    
    if(sr==dr && sc==dc){
        vector<string>base;
        base.push_back("");
        return base;
    }
    if(sr>dr || sc>dc){
        vector<string>base;
        return base;
    }
    
    
    vector<string>smallans1 = getMazePaths(sr,sc+1,dr,dc);
    vector<string>smallans2 = getMazePaths(sr+1,sc,dr,dc);
    
    vector<string>ans;
    
    for(int i=0;i<smallans1.size();i++){
        ans.push_back("h"+smallans1[i]);
    }
    for(int i=0;i<smallans2.size();i++){
        ans.push_back("v"+smallans2[i]);
    }
    return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}