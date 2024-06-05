#include <map>
#include <iostream>

int main() {
    std::map<char, int> mymap;
    mymap['a'] = 50;
    mymap['b'] = 100;
    mymap['c'] = 150;
    mymap['d'] = 200;

    std::map<char, int>::iterator it = mymap.find('d');
    if (it != mymap.end()) {
        std::cout << "key 'e' found: " << it->second << '\n';
    } else {
        std::cout << "key 'e' not found\n";
    }

    return 0;
}