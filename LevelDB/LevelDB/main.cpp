#include <assert.h>
#include <iostream>
#include "db.h" // ${leveldb}/include/leveldb/db.h

using namespace std;

int main(int argc,char * argv[])
{
    // Open/Create db
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    
    std::string dbpath = "/tmp/demodb.db";
    leveldb::Status status = leveldb::DB::Open(options, dbpath, &db);
    assert(status.ok());
    cout << "Open db OK" << std::endl;
    
    // Data to write to DB
    std::string key = "wangjia";
    std::string value = "wangjia@gamil.com";
    
    // write to leveldb
    leveldb::Status s ;
    s = db->Put(leveldb::WriteOptions(), key, value); // insert key-value pair
    
    // read from leveldb
    std::string value2;
    s = db->Get(leveldb::ReadOptions(), key, &value2); // get value back from DB
    
    cout << value2 << std::endl;
    delete db;
    
    return 0;
}
