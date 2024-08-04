


#include <stdlib.h>
#include <iostream>
using namespace std;

int fat(int x) {
    if (x <= 1)
        return 1;
    
    return fat(x-1)*x;
}

int main() {
    cout << fat(5);
}