#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int length;
    cin >> length;
    string inputString;
    cin >> inputString;

    if (length == 0){
        cout << 0 << endl;
        return 0;   
    }

    int cut[length] = {0};
    bool isPalindrome[length][length] = {false};
    for(int x = 1 ; x < length; x++){
        int minTemp = x;
        for(int y = 0; y <= x; y++){
            if(inputString[x] == inputString[y] && (x <= y + 1 || isPalindrome[x-1][y+1])){
                isPalindrome[x][y] = true;
                minTemp = min(minTemp, y == 0 ? 0 : 1 + cut[y-1]);
            }
        }
        cut[x] = minTemp;
    }
    cout << cut[length - 1] + 1;

    return 0;
}