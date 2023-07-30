#include <vector>
#include <map>
#include <thread>
#include <fmt/core.h>

#include "SPSCQueue.hpp"


int main(/*int argc, char* argv[]*/) 
{
  lockfree::SPSCQueue<int,5> q;

  std::jthread thread1([&]()
  {
    for(int i=0;i<10;++i)
    {
      while(!q.push(i));
    }
    
  });
  std::jthread thread2([&]()
  {
    int ret;
    for(int i=0;i<10;++i)
    {
      while(!q.pop(ret));
      fmt::print("queue pop: {}\n", ret);
    }
  });

  return 0;
}


