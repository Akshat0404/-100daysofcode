class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        
        for (const vector<int>& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            
            for (int neighbor : adj[course]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (result.size() != numCourses) {
            return {}; 
        }
        
        return result;
    }
};
