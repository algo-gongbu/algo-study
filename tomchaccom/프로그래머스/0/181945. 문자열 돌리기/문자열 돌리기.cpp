#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char word : str){
        cout << word << "\n";
    }
        
    return 0;
}