#ifndef _USER_CROSS_H_
#define _USER_CROSS_H_

/*
 * This file tries to define some user-space func/macros in kernel fashion.
 *
 * Below is a list of supported subsystems:
 * - list_head
 * - hlist
 * - hashtable
 * - bitops
 * - atomic_t
 * - spinlock (x)
 *
 * WIP if needed
 * - atomic
 */

#define USER

#ifdef USER

/*
 * spin lock related
 */
#include <pthread.h>
#define spin_lock(t)		pthread_spin_lock(t)
#define spin_unlock(t)		pthread_spin_unlock(t)
#define DEFINE_SPINLOCK(t)	pthread_spinlock_t t
#define spin_lock_init(t)	pthread_spin_init(t, PTHREAD_PROCESS_PRIVATE)

/*
 * alloc related
 */
#define GFP_KERNEL		(0)
#define kmalloc(s, f)		malloc(s)
#define kfree(p)		free(p)

#endif

#endif /* _USER_CROSS_H_ */
