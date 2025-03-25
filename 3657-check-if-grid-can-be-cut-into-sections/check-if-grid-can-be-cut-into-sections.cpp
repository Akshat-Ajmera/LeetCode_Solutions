// class Solution {
// public:
//     bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
//         vector<pair<int, int>> hor, ver;
//         int cnt = 0, inc = 0;
//         for(auto &it : rectangles) {
//             ver.push_back({it[0], 1});
//             ver.push_back({it[2], 0});
//             hor.push_back({it[1], 1});
//             hor.push_back({it[3], 0});
//         }
//         sort(hor.begin(), hor.end());
//         for(int i=0; i<hor.size(); i++) {
//             if(!hor[i].second) inc++;
//             else {
//                 inc--;
//                 if(!inc) cnt++;
//             }
//         }
//         cout << "cnthor " << cnt << endl;
//         if(cnt >= 2) return true;
//         cnt = 0, inc = 0;
//         sort(ver.begin(), ver.end());
//         for(int i=0; i<ver.size(); i++) {
//             cout << "ver " << ver[i].first << " " << ver[i].second << "\n";

//             if(!ver[i].second) inc++;
//             else {
//                 inc--;
//                 if(!inc) cnt++;
//             }
//         }
//         cout << "cntver " << cnt << endl;
//         if(cnt >= 2) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        // Track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim + 2];

        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }
};