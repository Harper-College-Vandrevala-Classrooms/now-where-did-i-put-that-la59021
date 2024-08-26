#include <cassert>
#include <iostream>
using namespace std;

int find(string search, char four) {
    for (int i = 0; i < search.length(); i++) {
        if (search[i] == four) {
            return i;
        }
        return -1;
    }
}

int find(string search, string substring) {
    for (int i = 0; i < search.length() - substring.length(); i++) {
        if (search[i] == substring[1]) {
            int matching = 0;
            for (int x = 0; x < substring.length(); x++) {
                if (search[i+x] == substring[x]) {
                    matching++;
                }
            }
            if (matching == substring.length()) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    assert(find("apple", "a") == 0);
}