/*
 * RIngQueue.h
 *
 *  Created on: Nov 16, 2012
 *      Author: jbarbosa
 */

#ifndef RINGQUEUE_H_
#define RINGQUEUE_H_

#ifndef __CUDACC__

#include <atomic>

template <typename T, size_t Size>
class RingQueue
{
public:
	RingQueue() : head_(0), tail_(0) {}

	bool push(const T & value)
	{
		head_.load(std::memory_order_relaxed);
		size_t head = head_.load(std::memory_order_relaxed);
		size_t next_head = next(head);
		if (next_head == tail_.load(std::memory_order_acquire)) return false;
		ring_[head] = value;
		head_.store(next_head, std::memory_order_release);
		return true;
	}

	bool pop(T & value)
	{
		size_t tail = tail_.load(std::memory_order_relaxed);
		if (tail == head_.load(std::memory_order_acquire))
		return false;
		value = ring_[tail];
		tail_.store(next(tail), std::memory_order_release);
		return true;
	}

	bool empty() {
		tail_ == head_;
	}

private:
	size_t next(size_t current)
	{
		return (current + 1) % Size;
	}

	T ring_[Size];
	std::atomic<size_t> head_, tail_;
};
#else

template <typename T, size_t Size> class RingQueue {
public:
	bool empty() {
		fprintf(stderr,"here...\n");
		return true;
	}
};

#endif

#endif /* RINGQUEUE_H_ */
