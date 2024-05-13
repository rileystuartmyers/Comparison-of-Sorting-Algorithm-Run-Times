#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>

#ifndef SORTING_H
#define SORTING_H

using namespace std::chrono;

std::vector<int> qsort_rand(std::vector<int> &S) {

  if (S.size() <= 1) {

    return S;

  } else {

    std::vector<int> S1;
    std::vector<int> S2;

    int p_ind = rand() % S.size();

    int p = S[p_ind];

    for (int i = 0; i < S.size(); ++i) {

      if (i == p_ind) {

        continue;
      }

      if (S[i] < p) {

        S1.push_back(S[i]);

      } else {

        S2.push_back(S[i]);
      }
    }

    std::vector<int> SR;

    S1 = qsort_rand(S1);
    S2 = qsort_rand(S2);

    SR = S1;

    SR.push_back(p);

    for (int i = 0; i < S2.size(); ++i) {

      SR.push_back(S2[i]);
    }

    S = SR;

    return SR;
  }
}

std::vector<int> qsort(std::vector<int> &S) {

  if (S.size() <= 1) {

    return S;

  } else {

    std::vector<int> S1;
    std::vector<int> S2;

    int p = S[0];

    for (int i = 1; i < S.size(); ++i) {

      if (S[i] < p) {

        S1.push_back(S[i]);

      } else {

        S2.push_back(S[i]);
      }
    }

    std::vector<int> SR;

    S1 = qsort(S1);
    S2 = qsort(S2);

    SR = S1;

    SR.push_back(p);

    for (int i = 0; i < S2.size(); ++i) {

      SR.push_back(S2[i]);
    }

    S = SR;

    return SR;
  }
}

void merge(int arr[], int left, int right) {

  int i = left;
  int middle = floor((right + left) / 2);
  int j = middle + 1;
  int k = 0;

  int temp[right - left + 1];

  while ((i <= middle) && (j <= right)) { //repeatedly chooses smallest int 
  //from each half and merges into temp array


    if (arr[i] <= arr[j]) {

      temp[k] = arr[i];
      i++;

    } else {

      temp[k] = arr[j];
      j++;

    }

    k++;

  }

  while (j <= right) { // remaining from right half

    temp[k] = arr[j];
    ++k;
    ++j;

  }

  while (i <= middle) { // remaining from left half

    temp[k] = arr[i];
    ++k;
    ++i;

  }

  for (int t = 0; t < (right - left + 1); ++t) {

    arr[left + t] = temp[t];

  }

  return;

}

void merge_sort_helper(int arr[], int left, int right) {

  if (left >= right) {

    return;

  }

  int middle = floor((right + left) / 2);
  merge_sort_helper(arr, left, middle);
  merge_sort_helper(arr, middle + 1, right);
  merge(arr, left, right);



}

void merge_sort(int arr[], int size) {

  merge_sort_helper(arr, 0, size - 1);

  return;

}

void reverse_set(int arr[], int size) {

  int count = size;
  
  for (int i = 0; i < size; ++i) {

    arr[i] = count;
    --count;
    
  }

  return;
  
}

void random_set(int arr[], int size) {

  for (int i = 0; i < size; ++i) {

    arr[i] = i + 1;
    
  }

  std::random_shuffle(arr, arr + size);

  return;
  
}

void odd_even_set(int arr[], int size) {

  int i = 0;

  
  int odds = 1;
  
  while (odds < size) {

    arr[i] = odds;
    odds += 2;
    ++i;
    
  }

  int evens = 2;
  
  while (evens <= size) {

    arr[i] = evens;
    evens += 2;
    ++i;
    
  }

  return;
  
}

void reverse_set(std::vector<int> &S, int size) {

  S.clear();
  
  int count = size;
  
  for (int i = 0; i < size; ++i) {

    S.push_back(count);
    --count;
    
  }

  return;
  
}

void random_set(std::vector<int> &S, int size) {

  S.clear();
  
  for (int i = 0; i < size; ++i) {

    S.push_back(i + 1);
    
  }

  std::shuffle(std::begin(S), std::end(S), std::default_random_engine{});

  return;
  
}

void odd_even_set(std::vector<int> &S, int size) {

  S.clear();
  
  int odds = 1;

  while (odds < size) {

    S.push_back(odds);
    odds += 2;

  }

  int evens = 2;

  while (evens <= size) {

    S.push_back(evens);
    evens += 2;

  }

  return;
  
}
#endif
