#include<bits/stdc++.h>
#include<vector>
using namespace std;

void checkConsecutive(int arr[], int n) {
  int countA=1;
  int countB=1;
  vector<int> consecutive;

  //first sort the array
  for(int i=0;i<n;i++) {
    for(int j=0;j<n-1;j++) {
      if (arr[i] <arr[j]) {
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
      }
    }
  }
  // for(int i=0;i<n;i++) {
  //   cout<<arr[i];
  // }
  for(int i=0;i<n;i++) {
    if(i>0){
      if(arr[i] == arr[i-1]+1){
        if(countA == 1) {
          consecutive.push_back(arr[i-1]);
        }
        countA++;
        consecutive.push_back(arr[i]);
      } else {
        if(countA > countB) {
          countB = countA;
          countA = 1;
          consecutive.clear();
        }
      }
    }
  }
  int res = (countA>=countB) ? countA : countB;

  if(res == 1) {
    for(int i = 0;i<n;i++) {
      consecutive.push_back(arr[i]);
    }
  }
  cout<< res <<endl;
  for(int i = 0;i<consecutive.size();i++) {
    cout<<consecutive[i]<<" ";
  }
}

int main(){
  int arr[5] = {1,1,1,1,1};
  checkConsecutive(arr, 5);
  return 0;
}
