//#
//# FILE: gwatch.cc -- Implementation of portable stopwatch class
//#
//# $Id$
//#

#include "gwatch.h"
#include <math.h>

#ifdef __GNUG__
#include <sys/times.h>
#include <limits.h>

extern "C" long _sysconf(int);

#endif   // __GNUG__

#if defined __BORLANDC__
#include <sys\timeb.h>
#endif    // __GNUG__, __BORLANDC__


gWatch::gWatch(int run)
  : running(run), time_str(new char[30])
{
  if (run)
    Start();
  else 
    start = 0;
  stop = 0;
}

gWatch::~gWatch()
{
  delete time_str;
}

int gWatch::IsRunning(void) const
{
  return running;
}

void gWatch::Start(void)
{
#ifdef __GNUG__
  struct tms buffer;
  times(&buffer);
  start = buffer.tms_utime;
#elif defined __BORLANDC__
#error Implement me!
#endif   // __GNUG__, __BORLANDC__
}  

void gWatch::Stop(void)
{
  if (!running)   return;

#ifdef __GNUG__
  struct tms buffer;
  times(&buffer);
  stop = buffer.tms_utime;
#elif defined __BORLANDC__
#error Implement me!
#endif   // __GNUG__, __BORLANDC__
}

double gWatch::Elapsed(void) const
{
  if (running)   {
#ifdef __GNUG__
    struct tms buffer;
    times(&buffer);
    return (((double) (buffer.tms_utime - start)) / ((double) (CLK_TCK))); 
#elif defined __BORLANDC__
#error Implement me!
#endif   // __GNUG__, __BORLANDC__
  }

  return (((double) (stop - start)) / ((double) (CLK_TCK)));
}

char *const gWatch::ElapsedStr(void)
{
  double et = Elapsed();
  int total = (int) floor(et);

  int secs = total % 60;
  int temp = (total - secs) / 60;
  int mins = temp % 60;
  int hours = (temp - mins) % 60;

  int mus = (int) ((et * 1000) / floor(et));
  sprintf(time_str, "%02d:%02d:%02d.%03d", hours, mins, secs, mus);
  return time_str;
}



