#pragma once
#ifndef BLOBSTORE_INTERFACE_BLOB_H_
#define BLOBSTORE_INTERFACE_BLOB_H_

#include <cstring>
#include <cstdint>
#include <messmer/blockstore/utils/Key.h>

namespace blobstore {

class Blob {
public:
  virtual ~Blob() {}

  //TODO Use own Key class for blobstore
  virtual blockstore::Key key() const = 0;

  virtual uint64_t size() const = 0;
  virtual void resize(uint64_t numBytes) = 0;

  virtual void read(void *target, uint64_t offset, uint64_t size) const = 0;
  virtual uint64_t tryRead(void *target, uint64_t offset, uint64_t size) const = 0;
  virtual void write(const void *source, uint64_t offset, uint64_t size) = 0;

  //TODO Test tryRead
};

}


#endif