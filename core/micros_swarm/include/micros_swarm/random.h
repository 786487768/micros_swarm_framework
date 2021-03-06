/**
Software License Agreement (BSD)
\file      random.h
\authors Xuefeng Chang <changxuefengcn@163.com>
\copyright Copyright (c) 2016, the micROS Team, HPCL (National University of Defense Technology), All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of micROS Team, HPCL, nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WAR-
RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, IN-
DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MICROS_SWARM_RANDOM_H_
#define MICROS_SWARM_RANDOM_H_

#include <random>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>

namespace micros_swarm{

    int random_int(int min, int max)
    {
        srand((unsigned)time(NULL));
        return (rand() % (max-min+1))+ min;
    }

    int random_int(int min, int max, int seed = 0)
    {
        static std::default_random_engine e(seed);
        static std::uniform_real_distribution<double> u(min, max);
        return u(e);
    }

    float random_float(float min, float max, unsigned int seed = 0)
    {
        static std::default_random_engine e(seed);
        static std::uniform_real_distribution<double> u(min, max);
        return u(e);
    }

    int test(void)
    {
        for (int i = 0; i < 15; ++i) {
            std::cout << random_int(0, 15, time(NULL)) << " ";
        }
        std::cout << std::endl;
        return 0;
    }
};

#endif
