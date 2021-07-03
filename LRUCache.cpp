#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int,int> cnt;
    queue<int> accessed;
    unordered_map<int,char> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    void put(int key, char value) {
        if((int)cache.size() < capacity) {
            if(cache.find(key) != cache.end()) {
                cout << "ERROR: Key already exists" << endl;
            } else {
                cache[key] = value;
                accessed.push(key);
                cnt[key]++;
            }
        } else {
            while(true) {
                int check_number = accessed.front();
                if(--cnt[check_number] == 0) {
                    cache.erase(check_number);
                    accessed.pop();
                    cache[key] = value;
                    accessed.push(key);
                    cnt[key]++;
                    return;
                }
                accessed.pop();
            }
        }
    }
    char get(int key) {
        if(cache.find(key) != cache.end()) {
            accessed.push(key);
            cnt[key]++;
            return cache[key];
        } else {
            cout << "ERROR: Key doesn't exists";
        }
        return '*';
    }
    void displayCache() {
        for(auto it = cache.begin(); it != cache.end(); ++it) {
            cout << it->first << " --> " << it->second << endl;
        }
    }
};


int main() {
    int size, choice, key;
    char value;
    cout << "Enter the size: ";
    cin >> size;
    LRUCache a(size);
    while(1) {
        cout << "\n1. put in cache\n2. get from cache\n3. display cache\n4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\nEnter the key and value to put: ";
                cin >> key >> value;
                a.put(key, value);
                break;
            case 2:
                cout << "\nEnter the value to get: ";
                cin >> key;
                value = a.get(key);
                if(value == '*') break;
                cout << "\nvalue: " << value;
                break;
            case 3:
                a.displayCache();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    } 
}
