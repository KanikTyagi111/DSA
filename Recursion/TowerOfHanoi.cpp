// no. of steps = 2N -1
// TC : 2N     SC : N

#include <iostream>
using namespace std;


void towerOfHanoi(int n, int source, int helper, int destination) {
    
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << "\n";
        return;
    }
    
    
    towerOfHanoi(n - 1, source, destination, helper);
    
    
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << "\n";
    
    
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int n = 3; 
    
    // 1 = source, 2 = helper, 3 = destination
    towerOfHanoi(n, 1, 2, 3);
    
    return 0;
}
