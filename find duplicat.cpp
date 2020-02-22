#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> duplicate;

void finDuplicates(vector<int> &arr, int n){
  int temp1 = 0;
  int temp2 = 0;

  for(int i=0;i<arr.size();i++){
    for(int j=0; j<arr.size();j++){
      if(arr[i] < arr[j]){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for(int i=0;i<n;i++) {
    temp1 = arr[i];
    arr[i] = -1;
    for(int j=0; j<n;j++) {
      if(arr[j] == temp1 && arr[j] != -1) {
        duplicate.push_back(temp1);
        arr[j] == -1;
      }
    }
  }
}
int main(){
  vector<int> vec;
  vec.push_back(10);
  vec.push_back(10);
  vec.push_back(8);
  vec.push_back(20);
  vec.push_back(30);

  finDuplicates(vec, vec.size());

  for(int i=0; i<duplicate.size();i++){
    cout<<duplicate[i]<<' ';
  }
  cout<<endl;

  return 0;
}
