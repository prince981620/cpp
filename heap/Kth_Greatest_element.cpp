#include <iostream>
#include <queue>
using namespace std;


int getKthSmallestElement(int arr[],int n, int k){

  if(k>n){
    return -1;
  }
    priority_queue<int> pq;

  // push 1st k element into queue

  for(int i = 0 ; i < k ; i++){
    pq.push(arr[i]);
  }

  // for remaining element push only if is smaller than top

  for(int i=k;i<n;i++){
    if(arr[i] < pq.top()){
      pq.pop();
      pq.push(arr[i]);
    }
  }

  // cout << pq.top();
  return pq.top();
}

int main() {
  int arr[] = {10,5,20,4,15};
  int n = 5;
  int k = 2;

  int ans = getKthSmallestElement(arr,n,k);

  cout << ans;

  return 0;
}