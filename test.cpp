#include <stdbool.h>
#include <stdio.h>
#include <chrono>
#include <iostream>

int binary_search(int haystack[], int needle, int start, int end) {
  int middle = start + ((end - start) / 2);
  int v = haystack[middle];

  if(needle == v) {
    return v;
  }

  if(needle > v) {
    return binary_search(haystack, needle, middle + 1, end);
  } else {
    return binary_search(haystack, needle, start, middle);
  }
} 

int main() {
  int v = 2;
  int arr[10000];

  for(int i = 0; i < 10000; ++i) {
    arr[i] = i;
  }

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  int meow = binary_search(arr, 9999, 0, 9999);

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Found: " << meow << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}
