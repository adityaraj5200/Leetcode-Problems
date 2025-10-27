// Time Complexity: O(m * n) where m = number of rows, n = number of columns
// Space Complexity: O(1)

// Approach:
// • For each row, count the number of '1's (security devices).
// • Whenever we find a non-empty row, multiply its count with the previous non-empty row's count.
// • Keep updating the last non-empty row’s device count.

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDevices = 0, totalBeams = 0;
        
        for (const string& row : bank) {
            int currDevices = count(row.begin(), row.end(), '1');
            if (currDevices > 0) {
                totalBeams += prevDevices * currDevices;
                prevDevices = currDevices;
            }
        }
        return totalBeams;
    }
};
