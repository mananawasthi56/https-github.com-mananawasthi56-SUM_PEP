class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> a;
        unordered_set<int> b;
        for( int i = 0;i<n;i++){
            for(int j = i ; j<n;j++){
                a.insert(nums[i] ^ nums[j]);
            }
        }
        for (auto x : a) {
    for (int i = 0; i < nums.size(); i++) {
        b.insert(x ^ nums[i]);
    }
    
}
return b.size();

}
};