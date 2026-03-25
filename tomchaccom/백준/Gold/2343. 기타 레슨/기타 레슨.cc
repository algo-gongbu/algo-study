#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int ans = 0;

int binarySearch(int st, int en, int blueRay, int n ){
    // 9 ~45 까지의 값만 가지고 count를 계산하면 되는거 아님?
    if(st > en) return ans;
    int mid = (st + en )/2;
    int sum =0;
    int count = 1;

    // 중간 인덱스로 하여금. 합계를 구해서 계산하면 되지
    for(int i =0; i< n;i++){
        if(sum + arr[i] > mid){
            sum = arr[i];
            count++;
        }else{
            sum += arr[i];
        }
    }

    if(count <= blueRay){
        ans = mid;
        return binarySearch(st,mid-1,blueRay,n);
        
    }else if( count > blueRay){
        return binarySearch(mid +1, en,blueRay,n);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;
    int end = 0;

    arr = vector<int> (n);

    for(int i = 0; i < n;i++){
        cin >> arr[i];
        end += arr[i];
    }
    int start = *max_element(arr.begin(), arr.end());
    
    
    cout << binarySearch(start,end,m,n);

    
}