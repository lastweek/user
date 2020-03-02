#ifndef _USER_ATOMIC_H_
#define _USER_ATOMIC_H_

#ifdef CONFIG_X86
# include <uapi/atomic_x86.h>
#elif CONFIG_ARM64
# include <uapi/atomic_arm64.h>
#else
#error "Undefined arch"
#endif

#endif /* _USER_ATOMIC_H_ */
