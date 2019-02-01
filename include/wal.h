#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "lmdb.h"

#if defined(STDC_VERSION__) && \
  (__STDC_VERSION__ >= 201112L) || !defined(_STRICT_ANSI__) && \
   !defined(__cplusplus)
#define _cdecl __attribute__((cdecl))
#define __cdecl __attribute__((cdecl))
#define _stdcall __attribute__((stdcall))
#define __stdcall __attribute__((stdcall))
#define GX_WRAPPER_FUNC  __attribute__ ((dllexport))
#ifdef BUILDING_WAL_SHARED
#define WAL_EXTERN __declspec(dllexport)
#else
#define WAL_EXTERN
#define WAL_CDECL __cdecl
#else
#define WAL_EXTERN
#define WAL_CDECL
#endif

/*
 * LMDB API calls.
 */

#define mdb_env_open(env, path, flags, mode) wal_env_open(env, path, flags, mode)
#define mdb_env_create(env) wal_env_create(env)
#define mdb_env_copy(env) wal_env_copy(env)
#define mdb_env_stat(env) wal_env_stat(env)
#define mdb_env_info(env) wal_env_info(env)
#define mdb_env_get_path(env) wal_env_get_path(env)
#define mdb_env_set_maxdbs(env, dbs) wal_env_set_maxdbs(env, dbs)
#define mdb_txn_id(txn) wal_txn_id(txn)
#define mdb_drop(txn, dbi, del) wal_env_set_mdbdrop(txn, dbi, del)
#define mdb_env_set_userctx(env) wal_env_set_userctx(env)
#define mdb_txn_begin(env, pawalnt, flags, txn) re_txn_begin(env, parent, flags, txn)
#define mdb_txn_commit(txn) wal_txn_commit(txn)
#define mdb_txn_abort(txn) wal_txn_abort(txn)
#define mdb_put(txn, dbi, key, data, flags) wal_put(txn, dbi, key, data, flags)
#define mdb_get(txn, dbi, key, data) wal_get(txn, dbi, key, data)
#define mdb_dbi_close(env, dbi) wal_dbi_close(env, dbi)
#define mdb_env_close(env) wal_env_close(env)
#ifdef __cplusplus
}
#endif
