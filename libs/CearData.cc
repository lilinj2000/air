// Copyright (c) 2010
// All rights reserved.

#include <iomanip>

#include "air/CearData.hh"
#include "json/json.hh"
#include "Log.hh"

namespace air {

void CearData::writeToFile(std::ofstream* os) const {
  AIR_TRACE <<"CearData::writeToFile()";

  (*os) <<instru <<"\t"
        <<time_stamp
        <<" (" <<update_time <<"." <<std::setfill('0') <<std::setw(3) <<update_millisec <<")" <<"\t"
        <<bid_price1 <<"\t"
        <<bid_volume1 <<"\t"
        <<ask_price1 <<"\t"
        <<ask_volume1 <<std::endl;
}

void CearData::fromString(const std::string& msg) {
  json::Document doc;
  json::fromString(msg, &doc);

  if (doc.HasMember("OnRtnDepthMarketData")) {
    const json::Value& rtn_depth_data = doc["OnRtnDepthMarketData"];

    if (rtn_depth_data.HasMember("CThostFtdcDepthMarketDataField")) {
      const json::Value& data = rtn_depth_data["CThostFtdcDepthMarketDataField"];  // NOLINT(*)

      this->instru = data["InstrumentID"].GetString();
      this->update_time = data["UpdateTime"].GetString();
      this->update_millisec = atoi(data["UpdateMillisec"].GetString());
      this->bid_price1 = atof(data["BidPrice1"].GetString());
      this->bid_volume1 = atoi(data["BidVolume1"].GetString());
      this->ask_price1 = atof(data["AskPrice1"].GetString());
      this->ask_volume1 = atoi(data["AskVolume1"].GetString());
      this->time_stamp = soil::DateTime(rtn_depth_data["timestamp"].GetString());  // NOLINT(*)
    }
  }

  return;
}

};  // namespace air
