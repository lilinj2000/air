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

class CffexMData : public MData {
 public:
  virtual const std::string& instruID() const {
    return InstrumentID;
  }

  virtual void writeToFile(std::ofstream* os) const;

  std::string TradingDay;
  std::string SettlementGroupID;
  std::string SettlementID;
  double PreSettlementPrice;
  double PreClosePrice;
  double PreOpenInterest;
  double PreDelta;
  double OpenPrice;
  double HighestPrice;
  double LowestPrice;
  double ClosePrice;
  double UpperLimitPrice;
  double LowerLimitPrice;
  double SettlementPrice;
  double CurrDelta;
  double LastPrice;
  double Volume;
  double Turnover;
  double OpenInterest;
  double BidPrice1;
  double BidVolume1;
  double AskPrice1;
  double AskVolume1;
  double BidPrice2;
  double BidVolume2;
  double BidPrice3;
  double BidVolume3;
  double AskPrice2;
  double AskVolume2;
  double AskPrice3;
  double AskVolume3;
  double BidPrice4;
  double BidVolume4;
  double BidPrice5;
  double BidVolume5;
  double AskPrice4;
  double AskVolume4;
  double AskPrice5;
  double AskVolume5;
  std::string InstrumentID;
  std::string UpdateTime;
  int UpdateMillisec;
};

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CffexMData const& aCffexMData) {  // NOLINT(whitespace/line_length)
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CffexDepthMarketData\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aCffexMData.TradingDay  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"SettlementGroupID\": \"" <<aCffexMData.SettlementGroupID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"SettlementID\": \"" <<aCffexMData.SettlementID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"PreSettlementPrice\": \"" <<aCffexMData.PreSettlementPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"PreClosePrice\": \"" <<aCffexMData.PreClosePrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"PreOpenInterest\": \"" <<aCffexMData.PreOpenInterest  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"PreDelta\": \"" <<aCffexMData.PreDelta  <<"\"," <<std::endl;
    os <<"        \"OpenPrice\": \"" <<aCffexMData.OpenPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"HighestPrice\": \"" <<aCffexMData.HighestPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"LowestPrice\": \"" <<aCffexMData.LowestPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"ClosePrice\": \"" <<aCffexMData.ClosePrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"UpperLimitPrice\": \"" <<aCffexMData.UpperLimitPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"LowerLimitPrice\": \"" <<aCffexMData.LowerLimitPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"SettlementPrice\": \"" <<aCffexMData.SettlementPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"CurrDelta\": \"" <<aCffexMData.CurrDelta  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"LastPrice\": \"" <<aCffexMData.LastPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"Volume\": \"" <<aCffexMData.Volume  <<"\"," <<std::endl;
    os <<"        \"Turnover\": \"" <<aCffexMData.Turnover  <<"\"," <<std::endl;
    os <<"        \"OpenInterest\": \"" <<aCffexMData.OpenInterest  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidPrice1\": \"" <<aCffexMData.BidPrice1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidVolume1\": \"" <<aCffexMData.BidVolume1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskPrice1\": \"" <<aCffexMData.AskPrice1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskVolume1\": \"" <<aCffexMData.AskVolume1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidPrice2\": \"" <<aCffexMData.BidPrice2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidVolume2\": \"" <<aCffexMData.BidVolume2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidPrice3\": \"" <<aCffexMData.BidPrice3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidVolume3\": \"" <<aCffexMData.BidVolume3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskPrice2\": \"" <<aCffexMData.AskPrice2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskVolume2\": \"" <<aCffexMData.AskVolume2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskPrice3\": \"" <<aCffexMData.AskPrice3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskVolume3\": \"" <<aCffexMData.AskVolume3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidPrice4\": \"" <<aCffexMData.BidPrice4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidVolume4\": \"" <<aCffexMData.BidVolume4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidPrice5\": \"" <<aCffexMData.BidPrice5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"BidVolume5\": \"" <<aCffexMData.BidVolume5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskPrice4\": \"" <<aCffexMData.AskPrice4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskVolume4\": \"" <<aCffexMData.AskVolume4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskPrice5\": \"" <<aCffexMData.AskPrice5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"AskVolume5\": \"" <<aCffexMData.AskVolume5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"InstrumentID\": \"" <<aCffexMData.InstrumentID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"UpdateTime\": \"" <<aCffexMData.UpdateTime  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"        \"UpdateMillisec\": \"" <<aCffexMData.UpdateMillisec  <<"\"" <<std::endl;  // NOLINT(whitespace/line_length)
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

class ShfeMData : public MData {
 public:
  virtual const std::string& instruID() const {
    return InstrumentID;
  }

  virtual void writeToFile(std::ofstream* os) const;

  std::string TradingDay;
  std::string InstrumentID;
  std::string ExchangeID;
  std::string ExchangeInstID;
  double LastPrice;
  double PreSettlementPrice;
  double PreClosePrice;
  double PreOpenInterest;
  double OpenPrice;
  double HighestPrice;
  double LowestPrice;
  int Volume;
  double Turnover;
  double OpenInterest;
  double ClosePrice;
  double SettlementPrice;
  double UpperLimitPrice;
  double LowerLimitPrice;
  double PreDelta;
  double CurrDelta;
  std::string UpdateTime;
  int UpdateMillisec;
  double BidPrice1;
  double BidVolume1;
  double AskPrice1;
  double AskVolume1;
  double BidPrice2;
  double BidVolume2;
  double AskPrice2;
  double AskVolume2;
  double BidPrice3;
  double BidVolume3;
  double AskPrice3;
  double AskVolume3;
  double BidPrice4;
  double BidVolume4;
  double AskPrice4;
  double AskVolume4;
  double BidPrice5;
  double BidVolume5;
  double AskPrice5;
  double AskVolume5;
  double AveragePrice;
  std::string ActionDay;
};

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, ShfeMData const& aShfeMData) {  // NOLINT(whitespace/line_length)
  os <<std::endl;
  os <<"{" <<std::endl;
  os <<"    \"ShfeDepthMarketDataField\": {" <<std::endl;
  os <<"        \"TradingDay\": \"" <<aShfeMData.TradingDay  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"InstrumentID\": \"" <<aShfeMData.InstrumentID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"ExchangeID\": \"" <<aShfeMData.ExchangeID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"ExchangeInstID\": \"" <<aShfeMData.ExchangeInstID  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"LastPrice\": \"" <<aShfeMData.LastPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"PreSettlementPrice\": \"" <<aShfeMData.PreSettlementPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"PreClosePrice\": \"" <<aShfeMData.PreClosePrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"PreOpenInterest\": \"" <<aShfeMData.PreOpenInterest  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"OpenPrice\": \"" <<aShfeMData.OpenPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"HighestPrice\": \"" <<aShfeMData.HighestPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"LowestPrice\": \"" <<aShfeMData.LowestPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"Volume\": \"" <<aShfeMData.Volume  <<"\"," <<std::endl;
  os <<"        \"Turnover\": \"" <<aShfeMData.Turnover  <<"\"," <<std::endl;
  os <<"        \"OpenInterest\": \"" <<aShfeMData.OpenInterest  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"ClosePrice\": \"" <<aShfeMData.ClosePrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"SettlementPrice\": \"" <<aShfeMData.SettlementPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"UpperLimitPrice\": \"" <<aShfeMData.UpperLimitPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"LowerLimitPrice\": \"" <<aShfeMData.LowerLimitPrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"PreDelta\": \"" <<aShfeMData.PreDelta  <<"\"," <<std::endl;
  os <<"        \"CurrDelta\": \"" <<aShfeMData.CurrDelta  <<"\"," <<std::endl;
  os <<"        \"UpdateTime\": \"" <<aShfeMData.UpdateTime  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"UpdateMillisec\": \"" <<aShfeMData.UpdateMillisec  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"BidPrice1\": \"" <<aShfeMData.BidPrice1  <<"\"," <<std::endl;
  os <<"        \"BidVolume1\": \"" <<aShfeMData.BidVolume1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AskPrice1\": \"" <<aShfeMData.AskPrice1  <<"\"," <<std::endl;
  os <<"        \"AskVolume1\": \"" <<aShfeMData.AskVolume1  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"BidPrice2\": \"" <<aShfeMData.BidPrice2  <<"\"," <<std::endl;
  os <<"        \"BidVolume2\": \"" <<aShfeMData.BidVolume2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AskPrice2\": \"" <<aShfeMData.AskPrice2  <<"\"," <<std::endl;
  os <<"        \"AskVolume2\": \"" <<aShfeMData.AskVolume2  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"BidPrice3\": \"" <<aShfeMData.BidPrice3  <<"\"," <<std::endl;
  os <<"        \"BidVolume3\": \"" <<aShfeMData.BidVolume3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AskPrice3\": \"" <<aShfeMData.AskPrice3  <<"\"," <<std::endl;
  os <<"        \"AskVolume3\": \"" <<aShfeMData.AskVolume3  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"BidPrice4\": \"" <<aShfeMData.BidPrice4  <<"\"," <<std::endl;
  os <<"        \"BidVolume4\": \"" <<aShfeMData.BidVolume4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AskPrice4\": \"" <<aShfeMData.AskPrice4  <<"\"," <<std::endl;
  os <<"        \"AskVolume4\": \"" <<aShfeMData.AskVolume4  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"BidPrice5\": \"" <<aShfeMData.BidPrice5  <<"\"," <<std::endl;
  os <<"        \"BidVolume5\": \"" <<aShfeMData.BidVolume5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AskPrice5\": \"" <<aShfeMData.AskPrice5  <<"\"," <<std::endl;
  os <<"        \"AskVolume5\": \"" <<aShfeMData.AskVolume5  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"AveragePrice\": \"" <<aShfeMData.AveragePrice  <<"\"," <<std::endl;  // NOLINT(whitespace/line_length)
  os <<"        \"ActionDay\": \"" <<aShfeMData.ActionDay  <<"\"" <<std::endl;
  os <<"    }" <<std::endl;
  os <<"}" <<std::endl;
}

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
