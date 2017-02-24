/**
 * \file omp.h
 *
 * \brief OMP header file to include in user applications
 */

#ifndef OMP_H_
#define OMP_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Lock type */
typedef struct _omp_lock
{
    volatile int  entered;
    void         *owner_task;
    volatile int  count;
    int           hw_sem;
} *omp_lock_t;

typedef struct _omp_lock *omp_nest_lock_t;

/* Schedule kinds */
typedef enum omp_sched_t
{
  omp_sched_static = 1,
  omp_sched_dynamic = 2,
  omp_sched_guided = 3,
  omp_sched_auto = 4
} omp_sched_t;

/* Execution environment routines */
void omp_set_num_threads (int nthreads);
int omp_get_num_threads (void);
int omp_get_max_threads (void);
int omp_get_thread_num (void);
int omp_get_num_procs(void);
int omp_in_parallel(void);
void omp_set_dynamic (int nthreads);
int omp_get_dynamic (void);
void omp_set_nested (int val);
int omp_get_nested (void);
void omp_set_schedule (omp_sched_t kind, int modifier);
void omp_get_schedule (omp_sched_t *kind, int *modifier);
int omp_get_thread_limit (void);
void omp_set_max_active_levels(int val);
int omp_get_max_active_levels(void);
int omp_get_level (void);
int omp_get_ancestor_thread_num (int level);
int omp_get_team_size (int level);
int omp_get_active_level (void);
int omp_is_initial_device (void);
#if 0
int omp_in_final (void);
#endif

/* Lock Routines */
void omp_init_lock (omp_lock_t* lock);
void omp_destroy_lock (omp_lock_t *lock);
void omp_set_lock (omp_lock_t* lock);
int  omp_test_lock (omp_lock_t* lock);
void omp_unset_lock (omp_lock_t* lock);

void omp_init_nest_lock (omp_nest_lock_t* lock);
void omp_destroy_nest_lock (omp_nest_lock_t *lock);
void omp_set_nest_lock (omp_nest_lock_t* lock);
int  omp_test_nest_lock (omp_nest_lock_t* lock);
void omp_unset_nest_lock (omp_nest_lock_t* lock);

/* Timing Routines */
double omp_get_wtime (void);
double omp_get_wtick (void);

/* TI specific API to configure the OpenMP runtime */
void __TI_omp_configure(void);
void __TI_omp_config_thread_stack(char from_heap, unsigned int size);

void __TI_omp_reset(void);

void __TI_omp_configure_caches(void);
void __TI_omp_enable_caching(unsigned int start, unsigned int length);
void __TI_omp_disable_caching(unsigned int start, unsigned int length);

void __TI_setMPAX(unsigned int mpax_id, unsigned int base_addr, 
                  unsigned long long replacement_addr,
                  unsigned int seg_size_encoding);

void __TI_omp_config_cores (unsigned char master_core_idx, 
                            unsigned char num_cores);

void __TI_omp_config_hw_queues (char init_qmss,
                                int  hw_queue_base_idx,
                                int  first_desc_idx_in_linking_ram,
                                int  first_memory_region_idx);

void __TI_omp_config_hw_semaphores(unsigned char hw_sem_base_idx);

void __TI_omp_config_clock_freq_in_mhz(unsigned int clock_freq);

void __TI_omp_wait_at_core_barrier(void);

/* Dynamic memory management APIs */
#include <stdlib.h>

void  __heap_init_ddr  (void *ptr,  size_t size);
void *__malloc_ddr     (size_t size);
void *__calloc_ddr     (size_t num, size_t size);
void *__realloc_ddr    (void *ptr,  size_t size);
void  __free_ddr       (void *ptr);
void *__memalign_ddr   (size_t alignment, size_t size);

void  __heap_init_msmc (void *ptr, size_t size);
void *__malloc_msmc    (size_t size);
void *__calloc_msmc    (size_t num, size_t size);
void *__realloc_msmc   (void *ptr, size_t size);
void  __free_msmc      (void *ptr);
void *__memalign_msmc  (size_t alignment, size_t size);

void  __heap_init_l2   (void *ptr, size_t size);
void *__malloc_l2      (size_t size);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* OMP_H_ */
