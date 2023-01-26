class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses);
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (!indegrees[i])
                q.push(i);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : graph[u])
            {
                indegrees[v]--;
                if (!indegrees[v])
                    q.push(v);
            }
        }
        for (int i : indegrees)
        {
            if (i)
                return false;
        }
        return true;
    }
};