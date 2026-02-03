// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int mid;
    int ans;
    while(start <= end){
        mid = start + (end - start) / 2;
        int res = isBadVersion(mid);
        if(res){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}