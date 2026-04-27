class Solution {
  public:
  
    void solve(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){
        ans.push_back(temp);

        for(int i = index; i < arr.size(); i++){
            
           
            if(i > index && arr[i] == arr[i-1]) continue;

            temp.push_back(arr[i]);
            solve(i + 1, arr, temp, ans);
            temp.pop_back();
        }
    }
  
    vector<vector<int>> findSubsets(vector<int>& arr) {
        
        sort(arr.begin(), arr.end()); 
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, arr, temp, ans);
        
        return ans;
    }
};