/*
 * x86_utils.h
 *
 *  Created on: Apr 6, 2012
 *      Author: jbarbosa
 */

#ifndef X86_UTILS_H_
#define X86_UTILS_H_

#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>

#define CLOCK CLOCK_REALTIME
//CLOCK_MONOTONIC

__forceinline double getTimeMS()
{
        struct timeval tp;
        struct timezone tzp;
        gettimeofday(&tp,&tzp);
        return ((tp.tv_sec) * 1000 + tp.tv_usec/1000.0);
}

__forceinline void X86MemFence() {
//    asm volatile("" ::: "memory");
	asm volatile("lfence" ::: "memory");
}

__forceinline
void process_mem_usage(double& vm_usage, double& resident_set)
{
   using std::ios_base;
   using std::ifstream;
   using std::string;

   vm_usage     = 0.0;
   resident_set = 0.0;

   // 'file' stat seems to give the most reliable results
   //
   ifstream stat_stream("/proc/self/stat",ios_base::in);

   // dummy vars for leading entries in stat that we don't care about
   //
   string pid, comm, state, ppid, pgrp, session, tty_nr;
   string tpgid, flags, minflt, cminflt, majflt, cmajflt;
   string utime, stime, cutime, cstime, priority, nice;
   string O, itrealvalue, starttime;

   // the two fields we want
   //
   unsigned long vsize;
   long rss;

   stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
               >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
               >> utime >> stime >> cutime >> cstime >> priority >> nice
               >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest

   stat_stream.close();

//   printf("f: %d %d \n",vsize,rss);

   long page_size_kb = sysconf(_SC_PAGE_SIZE) / 2048; // in case x86-64 is configured to use 2MB pages
   vm_usage     = (double)vsize / 1024.0;
   resident_set = (double)rss * (double)page_size_kb;
}

__forceinline unsigned int roundUpToNextPowerOfTwo(unsigned int x)
{
	x--;
	x |= x >> 1;  // handle  2 bit numbers
	x |= x >> 2;  // handle  4 bit numbers
	x |= x >> 4;  // handle  8 bit numbers
	x |= x >> 8;  // handle 16 bit numbers
	x |= x >> 16; // handle 32 bit numbers
	x++;

	return x;
}

__forceinline unsigned roundUp(unsigned numToRound, unsigned multiple)
{
 if(multiple <= 0)
 {
  return numToRound;
 }

 int remainder = numToRound % multiple;
 if (remainder == 0)
  return numToRound;
 return numToRound + multiple - remainder;
}

#endif /* X86_UTILS_H_ */
