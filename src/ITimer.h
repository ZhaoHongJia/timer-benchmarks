// Copyright (C) 2018 ichenq@outlook.com. All rights reserved.
// Distributed under the terms and conditions of the Apache License. 
// See accompanying files LICENSE.

#pragma once

#include <stdint.h>
#include <functional>

// callback on timed-out
typedef std::function<void()> TimerCallback;

// timer queue scheduler
struct ITimerQueue
{
    // add a timer to schedule after `ms` milliseconds
    // returns an unique id identify this timer
    virtual int AddTimer(int millsec, TimerCallback cb) = 0;

    // cancel a timer by id
    virtual void CancelTimer(int id) = 0;

    // per-tick bookkeeping
    virtual void Tick(int64_t now) = 0;
};
