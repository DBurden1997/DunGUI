//
//  timer.cpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-14.
//

#include "timer.hpp"

Timer::Timer() :
    mStartTicks(0),
    mPauseTicks(0),
    mStarted(false),
    mPaused(false)
{}

void Timer::start()
{
    mStarted = true;
    mPaused = false;
    
    mStartTicks = SDL_GetTicks();
    mPauseTicks = 0;
}

void Timer::stop()
{
    mStarted = false;
    mPaused = false;
    
    mStartTicks = 0;
    mPauseTicks = 0;
}

void Timer::pause()
{
    if(mStarted && !mPaused)
    {
        mPaused = true;
        
        mPauseTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void Timer::unpause()
{
    if(mStarted && mPaused)
    {
        mPaused = false;
        
        mStarted = SDL_GetTicks() + mPauseTicks;
        mPauseTicks = 0;
    }
}

Uint32 Timer::getTicks()
{
    if(mStarted)
    {
        if(mPaused)
        {
            return mPauseTicks;
        }
        
        return SDL_GetTicks() - mStartTicks;
    }
    
    return 0;
}
