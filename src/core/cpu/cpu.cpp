#include "core/cpu/cpu.h"

namespace CPU
{
u32 translate_address(cpu_sreg* seg, u32 addr, cpu_state* cpu)
{
    u32 ret;
    if(!(cpu->cr[0] & 1))
    {
        //We're in real mode.
        ret = seg->base + addr;
    }
}

void update_sreg(cpu_sreg* seg, u16 val, cpu_state* cpu)
{
    if(!(cpu->cr[0] & 1))
    {
        //We're in real mode.
        seg->base = ((u32)val) << 4;
    }
}
}