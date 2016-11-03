// Copyright (c) 2010
// All rights reserved.

#include <iomanip>
#include "air/MDataFile.hh"
#include "soil/String.hh"
#include "json/json.hh"
#include "Log.hh"

namespace air {

void SpeedMData::writeToFile(std::ofstream* os) const {
  AIR_TRACE <<"SpeedMData::writeToFile()";

  try {
    soil::DateTime start_time(update_time);

    start_time += std::chrono::milliseconds(update_millisec);

    std::chrono::system_clock::duration delay = time_stamp - start_time;

    (*os) <<update_time <<"." <<std::setfill('0') <<std::setw(3)
       <<update_millisec <<"\t"
       <<start_time <<"\t"
       <<time_stamp <<"\t"
       <<delay.count() <<std::endl;
  }
  catch( ... ) {
    AIR_ERROR <<"catch exception on time conversion.";
  }
}

void CffexMData::writeToFile(std::ofstream* os) const {
  AIR_TRACE <<"CffexMDataField::writeToFile()";

  (*os) <<*this <<std::endl;
}

void ShfeMData::writeToFile(std::ofstream* os) const {
  AIR_TRACE <<"ShfeMDataField::writeToFile()";

  (*os) <<*this <<std::endl;
}


MDataFile::MDataFile(const std::string& file_name,
                     const std::string& instrus_filter):
    soil::DataFile(file_name) {
  AIR_TRACE <<"MDataFile::MDataFile()";

  soil::splitString(&instrus_filter_, instrus_filter);
}

MDataFile::~MDataFile() {
  AIR_TRACE <<"MDataFile::~MDataFile()";
}

bool MDataFile::filterData(const soil::Data* data) {
  AIR_TRACE <<"MData::filterData()";

  const MData* mdata = dynamic_cast<const MData*>(data);

  if (instrus_filter_.empty() ||
      instrus_filter_.count(mdata->instruID()) > 0) {
    return true;
  }

  return false;
}

void ShfeMData::fromString(const std::string& msg) {
  json::Document doc;
  json::fromString(msg, &doc);

  if (doc.HasMember("OnRtnDepthMarketData")) {
    const json::Value& rtn_depth_data = doc["OnRtnDepthMarketData"];

    if (rtn_depth_data.HasMember("CThostFtdcDepthMarketDataField")) {
      const json::Value& data = rtn_depth_data["CThostFtdcDepthMarketDataField"];  // NOLINT(*)
      this->TradingDay = data["TradingDay"].GetString();
      this->InstrumentID = data["InstrumentID"].GetString();
      this->ExchangeID = data["ExchangeID"].GetString();
      this->ExchangeInstID = data["ExchangeInstID"].GetString();
      this->LastPrice = atof(data["LastPrice"].GetString());
      this->PreSettlementPrice = atof(data["PreSettlementPrice"].GetString()); // NOLINT(*)
      this->PreClosePrice = atof(data["PreClosePrice"].GetString());
      this->PreOpenInterest = atof(data["PreOpenInterest"].GetString());
      this->OpenPrice = atof(data["OpenPrice"].GetString());
      this->HighestPrice = atof(data["HighestPrice"].GetString());
      this->LowestPrice = atof(data["LowestPrice"].GetString());
      this->Volume = atoi(data["Volume"].GetString());
      this->Turnover = atof(data["Turnover"].GetString());
      this->OpenInterest = atof(data["OpenInterest"].GetString());
      this->ClosePrice = atof(data["ClosePrice"].GetString());
      this->SettlementPrice = atof(data["SettlementPrice"].GetString());
      this->UpperLimitPrice = atof(data["UpperLimitPrice"].GetString());
      this->LowerLimitPrice = atof(data["LowerLimitPrice"].GetString());
      this->PreDelta = atof(data["PreDelta"].GetString());
      this->CurrDelta = atof(data["CurrDelta"].GetString());
      this->UpdateTime = data["UpdateTime"].GetString();
      this->UpdateMillisec = atoi(data["UpdateMillisec"].GetString());

      this->BidPrice1 = atof(data["BidPrice1"].GetString());
      this->BidVolume1 = atoi(data["BidVolume1"].GetString());
      this->AskPrice1 = atof(data["AskPrice1"].GetString());
      this->AskVolume1 = atoi(data["AskVolume1"].GetString());

      this->BidPrice2 = atof(data["BidPrice2"].GetString());
      this->BidVolume2 = atoi(data["BidVolume2"].GetString());
      this->AskPrice2 = atof(data["AskPrice2"].GetString());
      this->AskVolume2 = atoi(data["AskVolume2"].GetString());

      this->BidPrice3 = atof(data["BidPrice3"].GetString());
      this->BidVolume3 = atoi(data["BidVolume3"].GetString());
      this->AskPrice3 = atof(data["AskPrice3"].GetString());
      this->AskVolume3 = atoi(data["AskVolume3"].GetString());

      this->BidPrice4 = atof(data["BidPrice4"].GetString());
      this->BidVolume4 = atoi(data["BidVolume4"].GetString());
      this->AskPrice4 = atof(data["AskPrice4"].GetString());
      this->AskVolume4 = atoi(data["AskVolume4"].GetString());

      this->BidPrice5 = atof(data["BidPrice5"].GetString());
      this->BidVolume5 = atoi(data["BidVolume5"].GetString());
      this->AskPrice5 = atof(data["AskPrice5"].GetString());
      this->AskVolume5 = atoi(data["AskVolume5"].GetString());

      this->AveragePrice = atof(data["AveragePrice"].GetString());
      this->ActionDay = data["ActionDay"].GetString();
    } else {
      throw std::runtime_error("Invalid string, no tag: CThostFtdcDepthMarketDataField");
    }
  } else {
    throw std::runtime_error("Invalid string, no tag: OnRtnDepthMarketData");
  }


  return;
}

};  // namespace air
