// https://leetcode.com/contest/biweekly-contest-61/problems/maximum-earnings-from-taxi/

typedef long long ll;
class Solution
{
public:
	long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
	{
		vector<ll> t(n + 1, 0);
		for (int i = 0; i < rides.size(); i++)
		{
			rides[i][2] += (rides[i][1] - rides[i][0]);
		}
		sort(rides.begin(), rides.end());
		int pos = 0;
		for (auto &r : rides)
		{
			for (; pos < r[0]; pos++)
			{
				t[pos + 1] = max(t[pos], t[pos + 1]);
			}
			t[r[1]] = max(t[r[0]] + r[2], t[r[1]]);
		}
		return *max_element(t.begin(), t.end());
	}
};