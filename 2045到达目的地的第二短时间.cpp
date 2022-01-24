class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> path(n+1); 
        for(auto& i: edges){
            int u = i[0];
            int v = i[1];
            path[u].push_back(v);
            path[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        vector<vector<int>> f(n+1,vector<int>(2,INT_MAX));
		f[1][0]=0;
        int step = 0;
		while (f[n][1] == INT_MAX){
			 int size = q.size();
			 while (size--){
			 	int a = q.front();
			 	q.pop();
			 	for (auto& i:path[a]){
			 		if (step + 1 < f[i][0]) {
					 	f[i][0] = step + 1;
					 	q.push(i);
					 }
					else if (step + 1 > f[i][0] && step + 1 < f[i][1]) {
						f[i][1] = step + 1;
						q.push(i);
					}
				 }
			 } 
            step += 1;
		}
		int ans = 0;
		for (int i = 0; i< f[n][1]; i++){
            if (ans % (2*change) < change) ans+=time;
            else ans+=time + 2*change - ans % (2*change);	       
    	}
    	return ans;
	}
};
