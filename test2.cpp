#include <chrono>
#include <iostream>

bool linear_search(int haystack[], int needle, int haystack_length) {
  for (int i = 0; i < haystack_length; ++i) {
    if(haystack[i] == needle) {
      return true;
    }
  }

  return false;
}

int main() {
  int arr[10000];

  for(int i = 0; i < 10000; ++i) {
    arr[i] = i;
  }

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  int meow = linear_search(arr, 9999, 9999);

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Found: " << meow << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
  std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}
