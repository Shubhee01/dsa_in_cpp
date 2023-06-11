class SnapshotArray {
public:
    map<int,map<int,int>> m;
    long long count=0;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++){
            map<int,int> mp;
            mp[0]=0;
            m[i]=mp;
        }
    }
    
    void set(int index, int val) {
        m[index][count]=val;
    }
    
    int snap() {
        count++;
        return count-1;
    }
    
    int get(int index, int snap_id) {
        auto x=m[index].upper_bound(snap_id);
        x--;
        return x->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */