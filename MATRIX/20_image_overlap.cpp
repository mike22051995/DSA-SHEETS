/*
PROBLEM: Image Overlap (LeetCode 835)
Difficulty: Medium
Company: Google, Meta
Pattern: Matrix Sliding Window / Convolution

DESCRIPTION:
You are given two images img1 and img2 represented as binary n x n matrices.
A translation of img1 shifts it left/right and up/down. Return the largest 
possible overlap after translating one image (overlap = count of 1's at same position).

MATRIX DIAGRAM:
  img1:              img2:              Shift img1 right 1, down 1:
  1  1  0            0  0  0            -  -  -  -
  0  1  0     -->    0  1  1     -->    -  1  1  0
  0  1  0            0  0  1            -  0  1  0
                                        -  0  1  0
  
  After shift, overlay:
  img2:     Shifted img1:    Overlap (both 1):
  0  0  0       1  1  0           0  (positions)
  0  1  1       0  1  0           2  (at (1,1) and (1,2))
  0  0  1       0  1  0           1  (at (2,2))
  
  Total overlap: 3 ones match

APPROACH:
Method 1: Brute Force - Try All Translations
1. Try shifting img1 by dx in [-n+1, n-1] and dy in [-n+1, n-1]
2. For each shift, count overlapping 1's
3. Return maximum count
Time: O(n^4)

Method 2: Linear Transformation with HashMap
1. Record positions of all 1's in both images
2. For each pair of 1's, calculate translation vector
3. Count frequency of each translation vector
4. Maximum frequency = maximum overlap
Time: O(n^2 * m^2) where m = count of 1's

TIME COMPLEXITY: O(N^4) or O(N^2 * M^2)
SPACE COMPLEXITY: O(N^2) or O(M^2)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        // Collect positions of 1's in both images
        vector<pair<int, int>> ones1, ones2;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        // Count translation vectors
        unordered_map<string, int> count;
        int maxOverlap = 0;
        
        // For each pair of 1's, calculate translation vector
        for (auto& [i1, j1] : ones1) {
            for (auto& [i2, j2] : ones2) {
                int di = i2 - i1;
                int dj = j2 - j1;
                string key = to_string(di) + "," + to_string(dj);
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }
        
        return maxOverlap;
    }
    
    // Brute force: Try all translations
    int largestOverlapBruteForce(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;
        
        // Try all possible translations
        for (int di = -n + 1; di < n; di++) {
            for (int dj = -n + 1; dj < n; dj++) {
                maxOverlap = max(maxOverlap, countOverlap(img1, img2, di, dj));
            }
        }
        
        return maxOverlap;
    }
    
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int di, int dj) {
        int n = img1.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ni = i + di;
                int nj = j + dj;
                
                // Check if shifted position is within bounds
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    if (img1[i][j] == 1 && img2[ni][nj] == 1) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };
    
    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}
    };
    
    cout << "Largest Overlap: " << sol.largestOverlap(img1, img2) << endl;
    
    return 0;
}

/*
INPUT:
img1 = [[1,1,0],
        [0,1,0],
        [0,1,0]]

img2 = [[0,0,0],
        [0,1,1],
        [0,0,1]]

OUTPUT:
3

EXPLANATION:
1's in img1: (0,0), (0,1), (1,1), (2,1)
1's in img2: (1,1), (1,2), (2,2)

Best translation: shift img1 right by 1, down by 1
After shift:
img1 positions → (1,1), (1,2), (2,2), (3,2)
img2 positions: (1,1), (1,2), (2,2)

Overlapping positions: (1,1), (1,2), (2,2)
Count: 3

Translation vector (1,1) appears 3 times:
(0,0)→(1,1), (0,1)→(1,2), (1,1)→(2,2)
*/
