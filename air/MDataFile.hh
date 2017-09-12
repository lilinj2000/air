// Copyright (c) 2010
// All rights reserved.

#ifndef AIR_MDATA_FILE_HH
#define AIR_MDATA_FILE_HH

#include <string>
#include <set>

#include "soil/DataFile.hh"
#include "soil/DateTime.hh"

namespace air {

class MDataFile;

typedef std::set<std::string> InstrusFilter;

class MData : public soil::Data {
 public:
  virtual const std::string& instruID() const = 0;
};

class SpeedMData : public MData {
 public:
  virtual const std::string& instruID() const {
    return instru;
  }

  virtual void writeToFile(std::ofstream* os) const;

  std::string instru;
  std::string update_time;
  int update_millisec;

  soil::DateTime time_stamp;
};

// class CffexMData : public MData {
//  public:
//   explicit CffexMData(const std::string& md);

//   virtual const std::string& instruID() const {
//     return InstrumentID;
//   }

//   virtual void writeToFile(std::ofstream* os) const {
//     (*os) <<md_ <<std::endl;
//   }

//  private:
//   std::string instru_;
//   std::string md_;
// };

class ShfeMData : public MData {
 public:
  explicit ShfeMData(const std::string& md);

  virtual const std::string& instruID() const {
    return instru_;
  }

  virtual void writeToFile(std::ofstream* os) const {
    (*os) <<md_ <<std::endl;
  }

 private:
  std::string instru_;
  std::string md_;
};

class MDataFile : public soil::DataFile {
 public:
  MDataFile(const std::string& file_name,
            const std::string& instrus_filter = "");

  virtual ~MDataFile();

 protected:
  virtual bool filterData(const soil::Data* data);

 private:
  InstrusFilter instrus_filter_;
};

};  // namespace air

#endif
