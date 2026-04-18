int jump(vector<int> &nums)
{
    int jump = 0, l = 0, r = 0;
    int n = nums.size();
    while (r < n)
    {
        int farest = 0;
        for (int i = l; i < r; i++)
        {
            farest = max(farest, i + nums[i]);
        }
        l = r + 1;
        r = farest;
        jump++;
    }

    return jump;
}

int jump(vector<int> &nums)
{
    int jump = 0, currEnd = 0, farest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        farest = max(farest, i + nums[i]);
        if (i == currEnd)
        {
            jump++;
            currEnd = farest;
        }
    }
    return jump;
}