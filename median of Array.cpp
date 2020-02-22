#include<bits/stdc++.h>
#include<vector>
using namespace std;

float median(int arr1[], int arr2[]){
  vector<int> vec;
  float med=0;
  for(int i=0; i<3 ; i++){
    vec.push_back(arr1[i]);
  }
  for(int i=0; i<3 ; i++){
    vec.push_back(arr2[i]);
  }

  for(int i=0;i<vec.size();i++){
    for(int j=0; j<vec.size();j++){
      if(vec[i] > vec[j]){
        int temp;
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }

  if(vec.size()%2 !=0) {
    int idx = (vec.size() +1) /2;
    med = vec[idx-1];
  } else {
    int idx1 = (vec.size())/2;
    int idx2 = idx1 +1;
    med = (vec[idx1-1] + vec[idx2-1]);
    med /= 2;
  }

  return med;

}

int main() {
    int arr1[3] = {1, 3, 5};
    int arr2[3] = {2, 4, 6};

    float med = median(arr1, arr2);

    cout<<med<<endl;
}
