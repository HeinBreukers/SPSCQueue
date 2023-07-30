#pragma once

#include <queue>
#include <atomic>
#include <new>

namespace lockfree
{

template<typename T, std::size_t Size>
class SPSCQueue
{
    using valueType = T;
    using SizeType = std::size_t;
    static constexpr SizeType interferenceSize = 64;
public:
    SPSCQueue():
    head(0),
    tail(0)
    {}

    bool push(const valueType& item)
    {       
    const auto currentTail = tail.load(std::memory_order_relaxed); 
    const auto currentHead= head.load(std::memory_order_acquire);   
    const auto nextTail = nextIndex(currentTail);          
    if(nextTail!=currentHead)                        
    {     
        m_queue[currentTail] = item;                                   
        tail.store(nextTail, std::memory_order_release);              
        return true;
    }
    return false; // full queue
    }

    bool pop(valueType& value)
    {
        auto currentHead = head.load(std::memory_order_relaxed);
        auto currentTail = tail.load(std::memory_order_acquire);
        if(currentHead==currentTail)
        {
            return false; // empty queue
        }

        value = m_queue[currentHead];

        head.store(nextIndex(currentHead), std::memory_order_release);
        
        return true;
    }


private:
    [[nodiscard]] static constexpr SizeType nextIndex(SizeType index)
    {
        return (index+1)%Size;
    }

    std::array<T,Size> m_queue;
    alignas(interferenceSize) std::atomic<SizeType> head;
    alignas(interferenceSize) std::atomic<SizeType> tail;
    
};

}
