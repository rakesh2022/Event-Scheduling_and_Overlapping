struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
* /

    class Solution
{
public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {

        sort(arr, arr + n, cmp);
        int taken[101] = {};
        int maxProfit = 0;
        int totalJob = 0;
        for (int i = 0; i < n; i++)
        {
            int t = arr[i].dead;
            for (int j = t; j > 0; j--)
            {
                if (taken[j] == 0)
                {
                    taken[j] = 1;
                    maxProfit += arr[i].profit;
                    totalJob++;
                    break;
                }
            }
        }
        return {totalJob, maxProfit};
    }
};
