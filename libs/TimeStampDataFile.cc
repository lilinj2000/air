// Copyright (c) 2010
// All rights reserved.

#include "fmt/format.h"
#include "air/TimeStampDataFile.hh"
#include "soil/Log.hh"

namespace air {

TimeStampData::TimeStampData(int order_ref):
    order_ref_(order_ref) {
  LOG_TRACE("TimeStampData::TimeStampData()");
}

void TimeStampData::updateT1() {
  LOG_TRACE("TimeStampData::updateT1()");

  t1_ = soil::DateTime::now();
}

void TimeStampData::updateT2() {
  LOG_TRACE("TimeStampData::updateT2()");

  t2_ = soil::DateTime::now();
}

void TimeStampData::writeToFile(std::ofstream* os) const {
  LOG_TRACE("TimeStampData::writeToFile()");

  std::chrono::system_clock::duration d1 = t1_ - t0_;
  std::chrono::system_clock::duration d2 = t2_ - t0_;

  (*os) <<fmt::format("{}\t{}\t{}\t{}\t{}\t{}",
                      order_ref_,
                      t0_,
                      t1_,
                      t2_,
                      d1.count(),
                      d2.count())
        <<std::endl;
}

TimeStampDataFile::TimeStampDataFile(const std::string& file_name):
    soil::DataFile(file_name) {
  LOG_TRACE("TimeStampDataFile::TimeStampDataFile()");
}

TimeStampDataFile::~TimeStampDataFile() {
  LOG_TRACE("TimeStampDataFile::~TimeStampDataFile()");
}

};  // namespace air
