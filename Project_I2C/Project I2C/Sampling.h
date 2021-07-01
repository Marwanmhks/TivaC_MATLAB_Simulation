#include "Water.h"


//Time constant =2.369    //at 2.369 the output reaches 63%
//according to nyquist sampling theory sampling is atleast half the time constant but we took it 1/10


/* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.2369 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */

#define SamplingTime  237 //ms 