#pragma once

namespace CPU
{

union cpu_gpr
{
    u32 d;
    u16 w;
    u8 b[2];
};

struct cpu_sreg
{
    u16 sel;
    u16 flags;
    u32 base;
    u32 limit;
    int d;
    bool valid;
};

struct cpu_systbl
{
    u32 base;
    u16 limit;
};

union cpu_flags
{
    struct
    {
        u32 carry : 1;
        u32 : 1;
        u32 parity : 1;
        u32 : 1;
        u32 adjust : 1;
        u32 : 1;
        u32 zero : 1;
        u32 sign : 1;
        u32 trap : 1;
        u32 interrupt : 1;
        u32 direction : 1;
        u32 overflow : 1;
        u32 iopl : 2;
        u32 nt : 1;
        u32 : 1;
        u32 resume : 1;
        u32 vm : 1;
        u32 ac : 1;
        u32 vif : 1;
        u32 vip : 1;
        u32 id : 1;
        u64 : 10;
    };
    u32 hex;
};

struct cpu_state
{
    cpu_gpr r[8];
    cpu_sreg sr[6];
    u32 eip;
    cpu_flags eflags;
    cpu_systbl gdtr, idtr;
    cpu_sreg ldtr, tr;
    
    bool irq;
    u8 irqnum;
    
    bool halted;
    
    u8 cpl; //Only 2 bits.
    
    u32 cr[5];
    u32 dr[8];
    
    int rep;
    int seg;
};

u32 translate_address(cpu_sreg* seg, u32 addr, cpu_state* cpu);
void update_sreg(cpu_sreg* seg, u16 val, cpu_state* cpu);
}