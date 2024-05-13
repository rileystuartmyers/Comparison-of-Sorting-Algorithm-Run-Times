#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>

#include "sorting.h"


using namespace std::chrono;

int main() {

  int input_sizes[5] = {32, 64, 128, 256, 512};
  
  for (int i = 0; i < 5; ++i) {

    int list_length = input_sizes[i];

    std::vector<int> quick_rand;
    std::vector<int> quick_start;
    int merge[list_length];

    
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Input size: " << list_length << std::endl << std::endl;

    std::cout << "Reverse: " << std::endl;

    reverse_set(quick_rand, list_length);
    reverse_set(quick_start, list_length);
    reverse_set(merge, list_length);

    auto start = high_resolution_clock::now();
    qsort_rand(quick_rand);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "quicksort(random pivot): " << duration.count() << std::endl;

    auto start2 = high_resolution_clock::now();
    qsort(quick_start);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    std::cout << "quicksort(start pivot): " << duration2.count() << std::endl;

    auto start3 = high_resolution_clock::now();
    merge_sort(merge, list_length);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    std::cout << "merge: " << duration3.count() << std::endl;

    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Random: " << std::endl;

    random_set(quick_rand, list_length);
    random_set(quick_start, list_length);
    random_set(merge, list_length);

    auto start4 = high_resolution_clock::now();
    qsort_rand(quick_rand);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    std::cout << "quicksort(random pivot): " << duration4.count() << std::endl;

    auto start5 = high_resolution_clock::now();
    qsort(quick_start);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);
    std::cout << "quicksort(start pivot): " << duration5.count() << std::endl;

    auto start6 = high_resolution_clock::now();
    merge_sort(merge, list_length);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6 - start6);
    std::cout << "merge: " << duration6.count() << std::endl;

    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Odd/Even: " << std::endl;

    odd_even_set(quick_rand, list_length);
    odd_even_set(quick_start, list_length);
    odd_even_set(merge, list_length);

    auto start7 = high_resolution_clock::now();
    qsort_rand(quick_rand);
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(stop7 - start7);
    std::cout << "quicksort(random pivot): " << duration7.count() << std::endl;


    auto start8 = high_resolution_clock::now();
    qsort(quick_start);
    auto stop8 = high_resolution_clock::now();
    auto duration8 = duration_cast<microseconds>(stop8 - start8);
    std::cout << "quicksort(start pivot): " << duration8.count() << std::endl;


    auto start9 = high_resolution_clock::now();
    merge_sort(merge, list_length);
    auto stop9 = high_resolution_clock::now();
    auto duration9 = duration_cast<microseconds>(stop9 - start9);
    std::cout << "merge: " << duration9.count() << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    
    std::cout << std::endl << std::endl;
    
  }
  /* std::cout << "Sorted List (S): ";

  auto start = high_resolution_clock::now();

  qsort(S);

  auto stop = high_resolution_clock::now();

  for (int i = 0; i < S.size(); ++i) {

    std::cout << S[i] << " ";
    
  }

  std::cout << std::endl << std::endl;

  auto duration = duration_cast<microseconds>(stop - start);

  std::cout << "done in " << duration.count() << " microseconds" << std::endl
            << std::endl;

  std::cout << "Sorted List(S_rand): ";

  start = high_resolution_clock::now();

  qsort_rand(S_rand);

  stop = high_resolution_clock::now();

  for (int i = 0; i < list_length; ++i) {

    std::cout << S_rand[i] << " ";
  }

  duration = duration_cast<microseconds>(stop - start);

  std::cout << "done in " << duration.count() << " microseconds"; */

  return 0;
  
}