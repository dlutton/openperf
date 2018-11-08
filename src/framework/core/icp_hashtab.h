#ifndef _ICP_HASHTAB_H_
#define _ICP_HASHTAB_H_

/**
 * @file
 *
 * This file includes the function declarations for a lock-free
 * hash table.  This table is implemented using a lock-free
 * list and has the same limitations with respect to delete
 * operations.
 *
 * This code is based on the implementation described in
 * _Split-Ordered Lists: Lock-Free Extensible Hash Tables_
 * by Ori Shalev and Nir Shavit.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "core/icp_list.h"

struct icp_hashtab;

typedef uintptr_t (icp_hasher)(const void *thing);

/**
 * Allocate a new hash table
 *
 * @return
 *   pointer to new allocated hashtab or NULL on error
 */
struct icp_hashtab *icp_hashtab_allocate();

/**
 * Set the hashing function for the hash table
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in] hasher
 *   key hashing function
 */
void icp_hashtab_set_hasher(struct icp_hashtab *tab, icp_hasher hasher);

/**
 * Set the destructor for hashtable keys.
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in] destructor
 *   key destructor
 */
void icp_hashtab_set_key_destructor(struct icp_hashtab *tab,
                                    icp_destructor destructor);

/**
 * Set the destructor for hashtable values.
 *
 * @param[in] tab
 *   pointer to hashtab
 * @param[in] destructor
 *   value destructor
 */
void icp_hashtab_set_value_destructor(struct icp_hashtab *tab,
                                      icp_destructor destructor);

/**
 * Destroy an existing hash table and free all allocated memory.
 * If key/value destructors were specified, they will be called on
 * all non-NULL key/value entries.
 *
 * @param[out] tabp
 *   address of hashtab pointer
 */
void icp_hashtab_free(struct icp_hashtab **tabp);

/**
 * Delete all current items in the hash table.
 *
 * @param[in] tab
 *   pointer to hash table
 *
 * @return
 *   -  0: Success
 *   - !0: Error
 */
 int icp_hashtab_purge(struct icp_hashtab *tab);

/**
 * Perform garbage collection on the underlying list.  Concurrent
 * access should be blocked by some external mechanism.
 *
 * @param[in] tab
 *   pointer to hash table
 */
void icp_hashtab_garbage_collect(struct icp_hashtab *tab);

/**
 * Insert key/value into the table.
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in] key
 *   key for associated value
 * @param[in] value
 *   value to insert into hash table
 *
 * @return
 *   -  true: success
 *   - false: error
 */
 bool icp_hashtab_insert(struct icp_hashtab *tab,
                         void *key,
                         void *value);

/**
 * Retrieve the value of key in the table.
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in] key
 *   search key
 *
 * @return
 *   pointer to value if found, otherwise NULL
 */
void *icp_hashtab_find(struct icp_hashtab *tab, const void *key);

/**
 * Retrieve the next item in the hash table after cursor.
 * This function treats the table as a ring, e.g. it will
 * always return a value.
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in,out] cursor
 *   address of pointer to entry in hash table; may point to NULL
 *   to retrieve the first entry
 *
 * @return
 *   value of subsequent entry
 */
void *icp_hashtab_next(struct icp_hashtab *tab, void **cursor);

/**
 * Iterate through the hashtable, stopping at the end
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in,out] cursor
 *   address of pointer to entry in hash table; may point to NULL
 *   to retrieve the first entry
 *
 * @return
 *   value of subsequent entry
 */
void *icp_hashtab_iterate(struct icp_hashtab *tab, void **cursor);

/**
 * Delete a key/value pair from the table.
 * Note: The key/value free functions are not called until the
 * entire table is freed.
 *
 * @param[in] tab
 *   pointer to hash table
 * @param[in] key
 *   search key
 *
 * @return
 *   -  true: success
 *   - false: key not found
 */
bool icp_hashtab_delete(struct icp_hashtab *tab, const void *key);

/**
 * Retrieve the current number of entries in the table.
 *
 * @param[in] tab
 *   pointer to hash table
 *
 * @return
 *   number of non-deleted key/value entries in the table
 */
size_t icp_hashtab_size(struct icp_hashtab *tab);

/**
 * Retrieve an array of item pointers.  Caller is responsible
 * for freeing itemsp when done.
 *
 * @param[in] tab
 *   pointer to a hash table of items
 * @param[out] itemsp
 *   address of pointer to items
 * @param[out] nb_items
 *   pointer to nb_items
 *
 * @return
 *   -  0: Success
 *   - !0: Error
 */
int icp_hashtab_snapshot(struct icp_hashtab *tab, void **itemsp[], size_t *nb_items);

#ifdef __cplusplus
}
#endif

#endif /* _ICP_HASHTAB_H_ */
