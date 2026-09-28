// no. of steps = 2N -1
// TC : 2N     SC : N

#include <iostream>
using namespace std;

// Tower of Hanoi function with 'destination' as the last parameter
void towerOfHanoi(int n, int source, int helper, int destination) {
    // Base Case: If only 1 disk is left, move it directly from source to destination
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << "\n";
        return;
    }
    
    // Step 1: Move top n-1 disks from source to destination (acting as temporary helper) using helper
    towerOfHanoi(n - 1, source, destination, helper);
    
    // Step 2: Move the remaining nth (largest) disk from source to destination
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << "\n";
    
    // Step 3: Move the n-1 disks from helper to destination using source
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int n = 3; // Number of disks
    
    // 1 = source, 2 = helper, 3 = destination
    towerOfHanoi(n, 1, 2, 3);
    
    return 0;
}
