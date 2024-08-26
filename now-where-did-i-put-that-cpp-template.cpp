#include <cassert>
#include <iostream>
using namespace std;

int find(string search, char four) {
    for (int i = 0; i < search.length(); i++) {
        if (search[i] == four) {
            return i;
        }
    }
    return -1;
}

int find(string search, string substring) {
    if (search == substring) {
        return 0;
    }
    for (int i = 0; i <= search.length() - substring.length(); i++) {
        if (search[i] == substring[0]) {
            int matching = 0, matchingindex = 0;
            for (int x = 0; x < substring.length(); x++) {
                if (search[i+x] == substring[x]) {
                    matching++;
                }
            }
            if (matching == substring.length() && i != search.length()) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string fox = "the quick brown fox jumps over the lazy dog";
    
    // Character search testing
    assert(find(fox, ' ') == 3); // "Empty" Character is present
    assert(find("thequickbrownfox", ' ') == -1); // "Empty" Character not present
    assert(find(fox, 'a') == 36); // Character is present
    assert(find(fox, '!') == -1); // character not present    

    // String search testing 
    assert(find(fox, "") == -1); // Empty string not present
    assert(find("", "") == 0); // Empty string is present
    assert(find(fox, "e") == 2); // Character string is present
    assert(find("thequickbrownfox", "z") == -1); // Character string not present
    assert(find(fox, "is") == -1); // whole word not present
    assert(find(fox, "quick") == 4); // whole word is present
    assert(find(fox, "blac") == -1); // partal word not present
    assert(find(fox, "brown") == 10); // partal word is present
    assert(find(fox, "jackalopes love jumping") == -1); // multi word not present
    assert(find(fox, "the lazy dog") == 31); // multi word is present

    // Example output tests
    assert(find("The quick brown fox", 'e') == 2);
    assert(find("The quick brown fox", "e") == 2);
    assert(find("The quick brown fox", ' ') == 3);
    assert(find("The quick brown fox", "quick") == 4);
    assert(find("The quick brown fox", "quiet") == -1);
    return 1;
}