//
//  timer.hpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-14.
//

#ifndef timer_hpp
#define timer_hpp

#include <stdio.h>

//#include <SDL.h>
#include <SDL2/SDL.h>

class Timer
{
    Uint32                                  mStartTicks;
    Uint32                                  mPauseTicks;
    
    bool                                    mStarted;
    bool                                    mPaused;
    
public:
    Timer();
    
    void start();
    void stop();
    void pause();
    void unpause();
    
    Uint32 getTicks();
    
    bool isStarted() {return mStarted;}
    bool isPaused() {return mPaused;}
};

#endif /* timer_hpp */
