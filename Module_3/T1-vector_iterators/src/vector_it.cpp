#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  
  int a;
  while(std::cin>>a){
    v.push_back(a);
  }
  return v;
}

void PrintSum1(const std::vector<int>& v) {
  int n = v.size();
  std::vector<int> s;
  for(int i = 1; i<n; i++){
    int b;
    b = v[i]+v[i-1];
    std::cout<<b<<" ";

  }
  std::cout<<std::endl;


}

void PrintSum2(const std::vector<int>& v) {
  int n = v.size();
  for(int i = 0; i<n/2; i++){
    int b;
    b = v[i]+v[n-1-i];
    std::cout<<b<<" ";
  }
  std::cout<<std::endl;
}
