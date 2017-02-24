#ifndef GOMP_H_
#define GOMP_H_

#include <stdbool.h>

extern void GOMP_barrier (void);

extern void GOMP_critical_start (void);
extern void GOMP_critical_end (void);

extern void GOMP_atomic_start (void);
extern void GOMP_atomic_end (void);

extern void GOMP_parallel_start (void (*fn) (void *), unsigned char *data,
                                 unsigned int num_threads);
extern void GOMP_parallel_end(void);

extern void GOMP_task (void (*fn) (void *), unsigned char *data,
                        void (*cpyfn)(unsigned char *, unsigned char *),
                        int arg_size, int arg_align, int if_clause, int flags);
extern void GOMP_taskwait(void);

extern unsigned char GOMP_single_start(void);
extern void          GOMP_single_copy_start(void);
extern void          GOMP_single_copy_end(void *data);

extern bool GOMP_loop_static_start (long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_dynamic_start(long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_guided_start (long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_runtime_start (long start, long end, long incr,
			             long *istart, long *iend);

extern bool GOMP_loop_static_next  (long *istart, long *iend);
extern bool GOMP_loop_dynamic_next (long *istart, long *iend);
extern bool GOMP_loop_guided_next  (long *istart, long *iend);
extern bool GOMP_loop_runtime_next (long *istart, long *iend);

extern void GOMP_parallel_loop_static_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);
extern void GOMP_parallel_loop_dynamic_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr, long chunk_size);
extern void GOMP_parallel_loop_guided_start (void (*fn) (void *), void *data,
				 unsigned num_threads, long start, long end,
				 long incr, long chunk_size);
extern void GOMP_parallel_loop_runtime_start (void (*fn) (void *), void *data,
				  unsigned num_threads, long start, long end,
				  long incr);

extern void GOMP_loop_end        (void);
extern void GOMP_loop_end_nowait (void);

/* sections */
extern unsigned GOMP_sections_start      (unsigned count);
extern unsigned GOMP_sections_next       (void);
extern void     GOMP_sections_end        (void);
extern void     GOMP_sections_end_nowait (void);
extern void     GOMP_parallel_sections_start (void (*fn) (void *), void *data,
			                  unsigned num_threads, unsigned count);
/* ordered */
extern void GOMP_ordered_start       (void);
extern void GOMP_ordered_end         (void);
extern bool GOMP_loop_ordered_static_start (long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_ordered_dynamic_start(long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_ordered_guided_start (long start, long end, long incr, 
                                    long chunk_size, long *istart, long *iend);
extern bool GOMP_loop_ordered_runtime_start (long start, long end, long incr,
			             long *istart, long *iend);

extern bool GOMP_loop_ordered_static_next  (long *istart, long *iend);
extern bool GOMP_loop_ordered_dynamic_next (long *istart, long *iend);
extern bool GOMP_loop_ordered_guided_next  (long *istart, long *iend);
extern bool GOMP_loop_ordered_runtime_next (long *istart, long *iend);

extern void    __gomp_flush0 (void);

#endif /* GOMP_H_ */
