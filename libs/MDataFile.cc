// Copyright (c) 2010
// All rights reserved.

#include <iomanip>
#include "air/MDataFile.hh"
#include "soil/String.hh"
#include "soil/json.hh"
#include "soil/Log.hh"

namespace air {

void SpeedMData::writeToFile(std::ofstream* os) const {
  SOIL_TRACE("SpeedMData::writeToFile()");

  soil::DateTime start_time(update_time);

  start_time += std::chrono::milliseconds(update_millisec);

  std::chrono::system_clock::duration delay = time_stamp - start_time;

  (*os) <<update_time <<"." <<std::setfill('0') <<std::setw(3)
        <<update_millisec <<"\t"
        <<start_time <<"\t"
        <<time_stamp <<"\t"
        <<delay.count() <<std::endl;
}

MDataFile::MDataFile(
    const std::string& file_name,
    const std::string& instrus_filter):
    soil::DataFile(file_name) {
  SOIL_TRACE("MDataFile::MDataFile()");

  soil::splitString(&instrus_filter_, instrus_filter);
}

MDataFile::~MDataFile() {
  SOIL_TRACE("MDataFile::~MDataFile()");
}

bool MDataFile::filterData(const soil::Data* data) {
  SOIL_TRACE("MData::filterData()");

  const MData* mdata
      = dynamic_cast<const MData*>(data);

  if (instrus_filter_.empty()
      || instrus_filter_.count(
          mdata->instruID()) > 0) {
    return true;
  }

  return false;
}

ShfeMData::ShfeMData(const std::string& md):
    md_(md) {
  rapidjson::Document doc;
  doc.Parse(md_);

  std::string key
      = "/CThostFtdcDepthMarketDataField/InstrumentID";
  soil::json::get_item_value(&instru_, doc, key);

  return;
}

};  // namespace air
