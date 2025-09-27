class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for(int i = 0; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                for(int k = j+1; k < n; k++){
                    int x3 = points[k][0], y3 = points[k][1];
                    // Compute cross product magnitude
                    long long cross = (long long)(x2 - x1) * (y3 - y1)
                                     - (long long)(x3 - x1) * (y2 - y1);
                    double area = fabs(cross) * 0.5;
                    if(area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
};
