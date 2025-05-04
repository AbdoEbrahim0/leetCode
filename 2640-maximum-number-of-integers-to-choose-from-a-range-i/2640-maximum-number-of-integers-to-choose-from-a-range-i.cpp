class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int bannedSize = banned.size();
        
        int counter = 0;
        sort(banned.begin(), banned.end());
        for (int j = 1; j <= n; j++)
        {
            //binary search
                int start = 0, end = bannedSize-1, mid, cur = -1; // 1 2 3 4 5 6 n
                while (start <= end)
                {
                    mid = (start + end) / 2;
                    //(maxSum -mid)>=0
                    if (j == banned[mid])
                    {
                        cur = mid;
                        break;
                    }
                    else if (  j >banned[ mid]) {

                        start = mid + 1;
                    }
                    else 
                    {
                        end = mid - 1;
                    }
                }
                if (cur == -1 && (maxSum - j) >= 0)
                {
                    counter++;
                    maxSum -= j; //maxSum -[2+3 
                }
        }
        return counter;
    }
};