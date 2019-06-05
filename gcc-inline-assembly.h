#include "compiler.h"

static __always_inline unsigned long
current_stack_pointer(void)
{
	unsigned long sp;
	asm volatile (
		"movq %%rsp, %0\n"
		: "=r" (sp)
	);
	return sp;
}

/**
 * rdtsc() - returns the current TSC without ordering constraints
 *
 * rdtsc() returns the result of RDTSC as a 64-bit integer.  The
 * only ordering constraint it supplies is the ordering implied by
 * "asm volatile": it will put the RDTSC in the place you expect.  The
 * CPU can and will speculatively execute that RDTSC, though, so the
 * results can be non-monotonic if compared on different CPUs.
 */
static __always_inline unsigned long rdtsc(void)
{
	unsigned long low, high;
	asm volatile("rdtsc" : "=a" (low), "=d" (high));
	return ((low) | (high) << 32);
}
