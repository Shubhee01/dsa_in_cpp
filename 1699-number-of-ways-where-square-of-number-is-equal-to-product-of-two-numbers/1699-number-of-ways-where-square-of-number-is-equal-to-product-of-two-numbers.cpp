class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<long long, long long> m1;
        map<long long, long long>m2;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            m1[(long long)nums1[i]*(long long)nums1[i]]++;
        }
        for(int i=0;i<m;i++){
            m2[(long long)nums2[i]*(long long)nums2[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(m2[(long long)nums1[i]*(long long)nums1[j]]>0){
                    count+=m2[(long long)nums1[i]*(long long)nums1[j]];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(m1[(long long)nums2[i]*(long long)nums2[j]]>0){
                    count+=m1[(long long)nums2[i]*(long long)nums2[j]];
                }
            }
        }
        return count;
    }
};