// Copyright (c) 2010
// All rights reserved.

#ifndef AIR_TIMESTAMP_DATA_FILE_HH
#define AIR_TIMESTAMP_DATA_FILE_HH

#include <string>
#include <set>

#include "soil/DataFile.hh"
#include "soil/DateTime.hh"

namespace air {

class TimeStampDataFile;

class TimeStampData :
      public soil::Data {
 public:
  explicit TimeStampData(int order_ref);

  int orderRef() const {
    return order_ref_;
  }

  const soil::DateTime T0() const {
    return t0_;
  }

  const soil::DateTime T1() const {
    return t1_;
  }

  const soil::DateTime T2() const {
    return t2_;
  }

  void updateT1();
  void updateT2();

  bool isT1Updated() {
    return t1_updated_;
  }

  bool isT2Updated() {
    return t2_updated_;
  }

  virtual void writeToFile(std::ofstream* os) const;

 private:
  int order_ref_;
  // request order insert timestamp
  soil::DateTime t0_;
  // on rtn order, just from counter response
  soil::DateTime t1_;
  // on rtn order, from exchange response
  soil::DateTime t2_;

  bool t1_updated_;
  bool t2_updated_;
};

class TimeStampDataFile : public soil::DataFile {
 public:
  explicit TimeStampDataFile(const std::string& file_name);

  virtual ~TimeStampDataFile();
};

};  // namespace air

#endif
