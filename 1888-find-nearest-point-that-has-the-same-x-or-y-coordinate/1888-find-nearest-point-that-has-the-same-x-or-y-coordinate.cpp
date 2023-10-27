class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
      int minDistance = INT_MAX;
    int nearestIndex = -1;

    for(int i = 0; i < points.size(); i++) {
        int px = points[i][0];
        int py = points[i][1];
        if (x == px || y == py) {
            int distance = abs(x - px) + abs(y - py);
            if (distance < minDistance) {
                minDistance = distance;
                nearestIndex = i;
            }
        }
    }

    return nearestIndex;
}


};