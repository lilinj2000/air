// Copyright (c) 2010
// All rights reserved.

#ifndef AIR_CEAR_DATA_HH
#define AIR_CEAR_DATA_HH

#include <string>
#include "MDataFile.hh"

namespace air {
class CearData : public MData {
 public:
  virtual const std::string& instruID() const {
    return instru;
  }

  virtual void writeToFile(std::ofstream* os) const;

  void fromString(const std::string& msg);

  std::string instru;
  std::string update_time;
  int update_millisec;

  double bid_price1;
  double bid_volume1;

  double ask_price1;
  double ask_volume1;

  soil::DateTime time_stamp;
};

};  // namespace air
#endif
