// Copyright (c) 2010
// All rights reserved.

#include <iomanip>

#include "air/CearData.hh"
#include "fmt/format.h"
#include "soil/json.hh"
#include "soil/Log.hh"

namespace air {

void CearData::writeToFile(std::ofstream* os) const {
  LOG_TRACE("CearData::writeToFile()");

  (*os) <<fmt::format("{}\t{} ({}.{:0>3})\t{}\t{}\t{}\t{}",
                      instru,
                      time_stamp,
                      update_time,
                      update_millisec,
                      bid_price1,
                      bid_volume1,
                      ask_price1,
                      ask_volume1)
        <<std::endl;
}

void CearData::fromString(const std::string& msg) {
  rapidjson::Document doc;
  doc.Parse(msg);

  std::string root = "/CThostFtdcDepthMarketDataField";
  std::string key = root + "/InstrumentID";
  soil::json::get_item_value(&instru, doc, key);

  key = root + "/UpdateTime";
  soil::json::get_item_value(&update_time, doc, key);
  key = root + "/UpdateMillisec";
  soil::json::get_item_value(&update_millisec, doc, key);
  key = root + "/BidPrice1";
  soil::json::get_item_value(&bid_price1, doc, key);
  key = root + "/BidVolume1";
  soil::json::get_item_value(&bid_volume1, doc, key);
  key = root + "/AskPrice1";
  soil::json::get_item_value(&ask_price1, doc, key);
  key = root + "/AskVolume1";
  soil::json::get_item_value(&ask_volume1, doc, key);

  return;
}

};  // namespace air
