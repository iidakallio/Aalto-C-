#include "matrix.hpp"

#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  Matrix matrix;
  std::vector<int> lista;
  int a;
  for(int i=0;i<n; i++){
    lista.clear();
    for (int j = 0; j<n; j++){
      std::cin>>a;
      lista.push_back(a);
  
    }
    matrix.push_back(lista);
  }
  return matrix;
  
  }

Matrix Rotate90Deg(const Matrix &m) {
  Matrix new_matrix = m;
  int n = m.size();
  for (int i = 0; i < n / 2; i++) {
       
        for (int j = i; j < n - i - 1; j++) {
            
           int temp = new_matrix[i][j];

            new_matrix[i][j] = new_matrix[n-1-j][i];
 
            new_matrix[n-1-j][i] = new_matrix[n - 1 - i][n - 1 - j];
 
            new_matrix[n - 1 - i][n - 1 - j] = new_matrix[j][n-1-i];
 
            new_matrix[j][n-1-i] = temp; 
            
        }
    }
      
  return new_matrix;

}

void Print(const Matrix &m) {
  int n = m.size();
  std::cout<<"Printing out a " << n << " x " << n << " matrix:"<< std::endl;
 
  for(int i=0; i < n; i++){
    
    for (int j = 0; j < n; j++){
      std::cout << m[i][j]<< " ";
    }
    std::cout<<std::endl;
  }
}
