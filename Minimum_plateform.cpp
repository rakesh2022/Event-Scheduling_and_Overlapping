/*
	link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
	sol: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N * logN)
	SC: O(n)
*/
   
   
   
   
   //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    vector<pair<int,int>>train;
    	for(int i=0;i<n;i++)
    	train.push_back({arr[i],dep[i]});
    	sort(train.begin(),train.end());
    // 	vector<pair<int,int>>v;
    int prev=0;
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(train[0].second);
    	for(int i=1;i<n;i++){
    	    
    	    int low=pq.top();
    	   // cout<<low<<" "<<train[i].second<<" "<<endl;
    	    if(low< train[i].first)pq.pop();
    	    pq.push(train[i].second);
    	}
    	return pq.size();
    }
};