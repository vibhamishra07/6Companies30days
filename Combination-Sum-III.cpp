// Problem 02: Combination Sum with a twist.


//Solution by using backtracking

vector<vector<int>> combinationSum3(int k, int n)
{
    if (k > n)
        return {};
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(k, n, 1, 0, ds, ans);
    return ans;
}
void findCombinations(int k, int n, int curr_num, int sum, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ds.size() > k)
        return;
    if (sum == n && ds.size() == k)
    {
        ans.push_back(ds);
        return;
    }

    for (int j = curr_num; j <= 9; j++)
    {
        if (n - j >= 0)
        {
            sum += j;
            ds.push_back(j);
            findCombinations(k, n, j + 1, sum, ds, ans);
            ds.pop_back();
            sum -= j;
        }
    }
}