#ifndef UVIEW_FITZ_HASH_H
#define UVIEW_FITZ_HASH_H

#include "uview/fitz/system.h"
#include "uview/fitz/context.h"
#include "uview/fitz/output.h"

/*
 * Generic hash-table with fixed-length keys.
 */

typedef struct fz_hash_table_s fz_hash_table;

fz_hash_table *fz_new_hash_table(fz_context *ctx, int initialsize, int keylen, int lock);
void fz_empty_hash(fz_context *ctx, fz_hash_table *table);
void fz_drop_hash(fz_context *ctx, fz_hash_table *table);

void *fz_hash_find(fz_context *ctx, fz_hash_table *table, const void *key);
void *fz_hash_insert(fz_context *ctx, fz_hash_table *table, const void *key, void *val);
void *fz_hash_insert_with_pos(fz_context *ctx, fz_hash_table *table, const void *key, void *val, unsigned *pos);
void fz_hash_remove(fz_context *ctx, fz_hash_table *table, const void *key);
void fz_hash_remove_fast(fz_context *ctx, fz_hash_table *table, const void *key, unsigned pos);

int fz_hash_len(fz_context *ctx, fz_hash_table *table);
void *fz_hash_get_key(fz_context *ctx, fz_hash_table *table, int idx);
void *fz_hash_get_val(fz_context *ctx, fz_hash_table *table, int idx);

void fz_print_hash(fz_context *ctx, fz_output *out, fz_hash_table *table);
void fz_print_hash_details(fz_context *ctx, fz_output *out, fz_hash_table *table, void (*details)(fz_context*, fz_output*, void*));

#endif
