// class TaskManager {
// public:

//     unordered_map<int, pair<int, int>> tasktsMap;   // taskId -> {userId, priority}
//     set<pair<int, int>> tasksPriority;              // {priority, taskId}

//     TaskManager(vector<vector<int>>& tasks) {
//         for(int i=0; i<tasks.size(); i++){
//             tasktsMap[tasks[i][1]] = {tasks[i][0],  tasks[i][2]};
//             tasksPriority.insert({ tasks[i][2], tasks[i][1]});
//         }
//     }
    
//     void add(int userId, int taskId, int priority) {
//         tasksPriority.insert({priority, taskId});
//         tasktsMap[taskId] = {userId,  priority};
//     }
    
//     void edit(int taskId, int newPriority) {
//         auto [userId, oldPriority] = tasktsMap[taskId];

//         tasksPriority.erase({oldPriority, taskId});
//         tasksPriority.insert({newPriority, taskId});

//         tasktsMap[taskId]  = {userId, newPriority};
//     }
    
//     void rmv(int taskId) {
//         auto [userId, priority] = tasktsMap[taskId];

//         tasksPriority.erase({priority, taskId});

//         tasktsMap.erase(taskId);
//     }
    
//     int execTop() {
//         if (tasktsMap.empty()) return -1;
//         auto it = tasksPriority.end();
//         it--;
//         auto [priority, taskId] = *it;
//         int ans = tasktsMap[taskId].first;
//         tasktsMap.erase(taskId);
//         tasksPriority.erase(it);
//         return ans;
//     }
// };

// /**
//  * Your TaskManager object will be instantiated and called as such:
//  * TaskManager* obj = new TaskManager(tasks);
//  * obj->add(userId,taskId,priority);
//  * obj->edit(taskId,newPriority);
//  * obj->rmv(taskId);
//  * int param_4 = obj->execTop();
//  */


#pragma GCC optimize("O3,unroll-loops,Ofast")
#include <bits/stdc++.h>
using namespace std;

// Fast I/O setup
static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class TaskManager {
public:
    // taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> tasktsMap;

    // {priority, taskId} -> max priority first (by default set is ascending)
    set<pair<int, int>> tasksPriority;

    // Constructor
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            tasktsMap[taskId] = {userId, priority};
            tasksPriority.insert({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        tasktsMap[taskId] = {userId, priority};
        tasksPriority.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = tasktsMap[taskId];
        tasksPriority.erase({oldPriority, taskId});
        tasktsMap[taskId] = {userId, newPriority};
        tasksPriority.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        auto [userId, priority] = tasktsMap[taskId];
        tasksPriority.erase({priority, taskId});
        tasktsMap.erase(taskId);
    }

    int execTop() {
        if (tasktsMap.empty()) return -1;
        auto it = prev(tasksPriority.end()); // Get the max {priority, taskId}
        auto [priority, taskId] = *it;
        int userId = tasktsMap[taskId].first;
        tasktsMap.erase(taskId);
        tasksPriority.erase(it);
        return userId;
    }
};
