#pragma once

#include "core/cpu/cpu.h"

class cpu_core_base
{
public:
    virtual void init() = 0;
    virtual void shutdown() = 0;
    virtual void run() = 0;
    virtual void single_step() = 0;
private:
    CPU::cpu_state* state;
};