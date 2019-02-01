#include "lmdb.h"
#include "wal-lmdb.h"

TEST_CASE("initialize LMDB for wal", "wal") {
    MDB_env* env(nullptr);
    //MDB_dbi dbi(NULL);
    //MDB_txn* txn(nullptr);

    mdb_dbi_close(env, dbi);
    mdb_env_close(env);
}
