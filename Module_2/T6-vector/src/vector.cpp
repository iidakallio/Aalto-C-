#include "vector.hpp"

#include <vector>

int GetMin(std::vector<int> v) {
  int min = 1000;  
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i] < min)
            min = v[i];
    }
  return min;
}

int GetMax(std::vector<int> v) {
  int max = -1000;  // hmm... -1000 is the smallest number
    for (unsigned int i = 0; i < v.size(); i++) {
        if (v[i] > max)
            max = v[i];
    }
  return max;
}

double GetAvg(std::vector<int> v) {
  int sum = 0;
  for (unsigned int i = 0; i<v.size(); i++){
    sum += v[i];
  }
  double avg = double(sum)/ double(v.size());
  return avg; 
}
