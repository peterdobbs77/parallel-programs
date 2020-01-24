/* threads.cpp
  This program can now handle varying data sets
  due to dynamic memory allocation. 
  It can also be set to handle threading on
  different machines with varying numbers
  of cores
*/

#include <stdio.h>
#include <thread>
#include <mutex>

using namespace std;

std::mutex add_mutex;
int global_sum = 0;

void add(int threadId, int *arr, int start, int end)
{
  int sum = 0;
  for (int i = start; i < end; i++)
  {
    sum = sum + arr[i];
  }
  printf("Thread Id = [%d], local sum = %d \n", threadId, sum);

  add_mutex.lock();
  global_sum = global_sum + sum;
  add_mutex.unlock();
}

int main(int argc, const char *argv[])
{
  // initialization values could really be anything
  int N = 100;
  int nThreads = 4;

  int *arr = (int *)malloc(N * sizeof(int));
  for (int i=0; i<N; i++){
    arr[i] = i+2; // values could instead be read from a file or other source
  }

  for (int i = 0; i < nThreads; i++)
  {
    thread t(add, i + 1, arr, i * N / nThreads, (i + 1) * N / nThreads);
    t.join();
  }

  printf("Final sum = %d \n", global_sum);
  return 0;
}
