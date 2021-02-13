class LRUCache {
public:
    
    vector< pair<int, int> > v;
    int capacity = 0;
    int count = 0;
    LRUCache(int capacity) {
     this->capacity = capacity;
    }
    
    int get(int key) {
        int flag = 0;
        int index = -1;
        pair<int, int> temp;
        for(int i = 0; i< v.size(); i++){
            if(v[i].first == key) {
                flag = 1;
                index = i;
                break;
            }
        }
        if(flag){
            temp = v[index];
            
            v.erase(v.begin()+index);
            v.push_back(temp);
            return temp.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        int flag = 0;
        int index = -1;
        pair<int,int> temp;
         for(int i = 0; i< v.size(); i++){
            if(v[i].first == key) {
                v[i].second = value;
                flag = 1;
                index = i;
                break;
            } 
        }
        if(flag){
            temp = v[index];
            
            v.erase(v.begin()+index);
            v.push_back(temp);
            return;
        }
        
        if(capacity > count){
            v.push_back(make_pair(key,value));
            count++;
            cout<<count;
            cout<<"empty"<<v.size()<<endl;
            return;
        }
        
        else{
            cout<<"before:"<<v.size()<<endl;
            v.erase(v.begin());
            cout<<"after:"<<v.size()<<endl;
            v.push_back(make_pair(key,value));
        }
        
    }
};

int main(){
    
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */