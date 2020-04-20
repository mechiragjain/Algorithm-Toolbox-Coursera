#include<iostream>

using namespace std;

int merge(int arr[],int finalArray[],int left, int mid, int right){
  int i=left,j=mid,k=left,noOfInversions=0;

  while(i<=mid-1 && j<=right){
    if(arr[i]<=arr[j])
      finalArray[k++]=arr[i++];
    else{
      finalArray[k++]=arr[j++];
      noOfInversions+=(mid-i);
    }
  }
  while(i<=mid-1){
    finalArray[k++]=arr[i++];
  }
  while(j<=right){
    finalArray[k++]=arr[j++];
  }

  for(int i=left;i<=right;i++){
    arr[i]=finalArray[i];
  }

  return noOfInversions;
}

int mergeSort(int arr[],int finalArray[],int left,int right){
  int mid, noOfInversions=0;
  if(left>=right)
    return noOfInversions;
  
  mid=(right+left)/2;
  noOfInversions+=mergeSort(arr,finalArray,left,mid);
  noOfInversions+=mergeSort(arr,finalArray,mid+1,right);

  noOfInversions+=merge(arr,finalArray,left,mid+1,right);

  return noOfInversions;
}

int main(){
  int n;
  cin>>n;
  int arr[n],finalArray[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  cout<<mergeSort(arr,finalArray,0,n-1);

  return 0;
}