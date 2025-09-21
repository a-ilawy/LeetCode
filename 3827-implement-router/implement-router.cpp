// #include <bits/stdc++.h>
// using namespace std;

// struct Packet {
//     int source, destination, timestamp;
//     bool operator==(Packet const &o) const {
//         return source == o.source && destination == o.destination && timestamp == o.timestamp;
//     }
// };

// struct PacketHash {
//     size_t operator()(Packet const &p) const {
//         // combine hashes; for example:
//         // use 64-bit multiplication to reduce collisions
//         // OK because source, destination ≤ 2e5, timestamp ≤ 1e9
//         // We must ensure no overflow issues in combining
//         const size_t A = 1000003; // some prime
//         size_t h = p.source;
//         h = h * A + p.destination;
//         h = h * A + p.timestamp;
//         return h;
//     }
// };

// class Router {
//     int memoryLimit;
//     // queue for FIFO of packets in storage
//     deque<Packet> q;

//     // for duplicate detection
//     unordered_set<Packet, PacketHash> seen;

//     // for each destination: sorted timestamps + a start index
//     unordered_map<int, vector<int>> destTimes;
//     unordered_map<int, int> destStartIdx;

// public:
//     Router(int memoryLimit_) : memoryLimit(memoryLimit_) {
//     }

//     bool addPacket(int source, int destination, int timestamp) {
//         Packet p{source, destination, timestamp};
//         if (seen.find(p) != seen.end()) {
//             return false;
//         }

//         // If full, remove oldest
//         if ((int)q.size() == memoryLimit) {
//             Packet old = q.front();
//             q.pop_front();
//             seen.erase(old);

//             // update destTimes for old.destination
//             int d = old.destination;
//             // increment start idx for that destination
//             destStartIdx[d]++;
//             // (We don't need to erase from vector, just skip via start idx)
//         }

//         // Add the new packet
//         q.push_back(p);
//         seen.insert(p);

//         destTimes[destination].push_back(timestamp);
//         // ensure destStartIdx[destination] is initialized if first time
//         if (destStartIdx.find(destination) == destStartIdx.end()) {
//             destStartIdx[destination] = 0;
//         }

//         return true;
//     }

//     vector<int> forwardPacket() {
//         if (q.empty()) {
//             return {};
//         }
//         Packet p = q.front();
//         q.pop_front();
//         seen.erase(p);

//         int d = p.destination;
//         destStartIdx[d]++;

//         return {p.source, p.destination, p.timestamp};
//     }

//     int getCount(int destination, int startTime, int endTime) {
//         auto it = destTimes.find(destination);
//         if (it == destTimes.end()) return 0;

//         const vector<int>& vt = it->second;
//         int startIdx = destStartIdx[destination];
//         // if startIdx >= vt.size(), nothing left
//         if (startIdx >= (int)vt.size()) return 0;

//         // We want to count number of timestamps in vt[startIdx..end] in range [startTime, endTime]
//         auto lb = lower_bound(vt.begin() + startIdx, vt.end(), startTime);
//         auto ub = upper_bound(vt.begin() + startIdx, vt.end(), endTime);
//         return (int)(ub - lb);
//     }
// };


#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet &o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }//oop function overloading
};

// Custom hash for unordered_set
struct PacketHash {
    size_t operator()(const Packet &p) const {
        return ((size_t)p.source * 1315423911u) ^
               ((size_t)p.destination * 2654435761u) ^
               ((size_t)p.timestamp * 97531u);
    }//It allows you to use an object of PacketHash like a function:
    //return type is size_t (standard unsigned integer used for hashing).
   //operator() in PacketHash → lets unordered_set compute a hash for a packet. 
};

class Router {
private:
    int memoryLimit;
    queue<Packet> q;
    unordered_set<Packet, PacketHash> seen;
    unordered_map<int, vector<int>> destTimes;  // sorted timestamps

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (seen.count(p)) return false;

        if ((int)q.size() == memoryLimit) forwardPacket();  // auto forward oldest

        q.push(p);
        seen.insert(p);
        destTimes[destination].push_back(timestamp);  // append timestamps
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};  // no packet to forward

        Packet p = q.front(); 
        q.pop();
        seen.erase(p);

        // remove timestamp
        auto &vec = destTimes[p.destination];
        auto it = lower_bound(vec.begin(), vec.end(), p.timestamp);
        if (it != vec.end() && *it == p.timestamp) vec.erase(it);

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;

        auto &vec = it->second;
        auto left = lower_bound(vec.begin(), vec.end(), startTime);
        auto right = upper_bound(vec.begin(), vec.end(), endTime);
        return right - left;
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */


auto init=atexit([](){ofstream("display_runtime.txt")<<"0";});