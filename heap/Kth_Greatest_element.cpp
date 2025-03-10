#include <iostream>
#include <queue>
using namespace std;

int getKthGreatestElement(int arr[],int n , int k) {
    // push first k element into max heap
    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i = 0 ; i < k ; i++){
        pq.push(arr[i]);
    }

    // push remaining only if it is greater than top

    for(int i = k ; i < n ; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main (){
    int arr[] = {10,5,20,4,15};
  int n = 5;
  int k = 3;

  int ans = getKthGreatestElement(arr,n,k);
  cout << ans;
  return 0;
}