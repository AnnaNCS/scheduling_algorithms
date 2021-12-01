#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
class LRUCache {
    
    list<int> keys;
    unordered_map<int, list<int>::iterator> ref;
    int csize; 
 
    public:

    LRUCache(int);
    void refer(int);
    void display();
    };
 

LRUCache::LRUCache(int n){
    csize = n;
    }


void LRUCache::refer(int x){
    
    if (ref.find(x) == ref.end()) {
        if (keys.size() == csize) {
            int last = keys.back();
            keys.pop_back();
            ref.erase(last);}
        }
    else
        keys.erase(ref[x]);
    keys.push_front(x);
    ref[x] = keys.begin();
    }
 
void LRUCache::display(){
    for (auto it = keys.begin(); it != keys.end();
         it++)
        cout << (*it) << " ";
    cout << endl;
    }

int main(){
    int n;
    cout << "Input number of Process: ";
    cin >> n;
    
    LRUCache cash(n);
    
    int x;
    for (int i = 0; i < n; i++){
        cout << "Input Page Id: ";
        cin >> x;
        cash.refer(x);
        }
    
    cash.display();
    }
