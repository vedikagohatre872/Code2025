#include <stdio.h>

int trapRainWater(int height[], int n) {
    if (n <= 2) return 0; // At least 3 bars needed
    
    int left_max[n], right_max[n];
    int water = 0;

    // Step 1: Fill left_max[]
    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = (height[i] > left_max[i-1]) ? height[i] : left_max[i-1];
    }

    // Step 2: Fill right_max[]
    right_max[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--) {
        right_max[i] = (height[i] > right_max[i+1]) ? height[i] : right_max[i+1];
    }

    // Step 3: Calculate trapped water
    for (int i = 0; i < n; i++) {
        int min_height = (left_max[i] < right_max[i]) ? left_max[i] : right_max[i];
        if (min_height > height[i]) {
            water += min_height - height[i];
        }
    }

    return water;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height) / sizeof(height[0]);

    int result = trapRainWater(height, n);
    printf("Total trapped rain water = %d\n", result);

    return 0;
}
