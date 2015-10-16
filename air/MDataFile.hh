#ifndef AIR_MDATA_FILE_HH
#define AIR_MDATA_FILE_HH

#include <string>
#include <set>

#include "boost/date_time.hpp"

#include "soil/DataFile.hh"

namespace air
{

class MDataFile;

typedef std::set<std::string> InstrusFilter;

class MData : public soil::Data
{
 public:
  virtual const std::string& instruID() const = 0;
};

class SpeedMData : public MData
{
 public:
  virtual const std::string& instruID() const
  {
    return instru;
  }

  virtual void writeToFile(std::ofstream& os) const;

  std::string instru;
  std::string update_time;
  int update_millisec;

  boost::posix_time::ptime time_stamp;
};

class CffexMData : public MData
{
 public:
  virtual const std::string& instruID() const
  {
    return InstrumentID;
  }

  virtual void writeToFile(std::ofstream& os) const;

  std::string	TradingDay;
  std::string	SettlementGroupID;
  std::string	SettlementID;
  double	PreSettlementPrice;
  double	PreClosePrice;
  double	PreOpenInterest;
  double	PreDelta;
  double	OpenPrice;
  double	HighestPrice;
  double	LowestPrice;
  double	ClosePrice;
  double	UpperLimitPrice;
  double	LowerLimitPrice;
  double	SettlementPrice;
  double	CurrDelta;
  double	LastPrice;
  double	Volume;
  double	Turnover;
  double	OpenInterest;
  double	BidPrice1;
  double	BidVolume1;
  double	AskPrice1;
  double	AskVolume1;
  double	BidPrice2;
  double	BidVolume2;
  double	BidPrice3;
  double	BidVolume3;
  double	AskPrice2;
  double	AskVolume2;
  double	AskPrice3;
  double	AskVolume3;
  double	BidPrice4;
  double	BidVolume4;
  double	BidPrice5;
  double	BidVolume5;
  double	AskPrice4;
  double	AskVolume4;
  double	AskPrice5;
  double	AskVolume5;
  std::string	InstrumentID;
  std::string	UpdateTime;
  int	UpdateMillisec;
};

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CffexMData const& aCffexMData)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CffexDepthMarketData\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aCffexMData.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aCffexMData.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aCffexMData.SettlementID  <<"\"," <<std::endl;
    os <<"        \"PreSettlementPrice\": \"" <<aCffexMData.PreSettlementPrice  <<"\"," <<std::endl;
    os <<"        \"PreClosePrice\": \"" <<aCffexMData.PreClosePrice  <<"\"," <<std::endl;
    os <<"        \"PreOpenInterest\": \"" <<aCffexMData.PreOpenInterest  <<"\"," <<std::endl;
    os <<"        \"PreDelta\": \"" <<aCffexMData.PreDelta  <<"\"," <<std::endl;
    os <<"        \"OpenPrice\": \"" <<aCffexMData.OpenPrice  <<"\"," <<std::endl;
    os <<"        \"HighestPrice\": \"" <<aCffexMData.HighestPrice  <<"\"," <<std::endl;
    os <<"        \"LowestPrice\": \"" <<aCffexMData.LowestPrice  <<"\"," <<std::endl;
    os <<"        \"ClosePrice\": \"" <<aCffexMData.ClosePrice  <<"\"," <<std::endl;
    os <<"        \"UpperLimitPrice\": \"" <<aCffexMData.UpperLimitPrice  <<"\"," <<std::endl;
    os <<"        \"LowerLimitPrice\": \"" <<aCffexMData.LowerLimitPrice  <<"\"," <<std::endl;
    os <<"        \"SettlementPrice\": \"" <<aCffexMData.SettlementPrice  <<"\"," <<std::endl;
    os <<"        \"CurrDelta\": \"" <<aCffexMData.CurrDelta  <<"\"," <<std::endl;
    os <<"        \"LastPrice\": \"" <<aCffexMData.LastPrice  <<"\"," <<std::endl;
    os <<"        \"Volume\": \"" <<aCffexMData.Volume  <<"\"," <<std::endl;
    os <<"        \"Turnover\": \"" <<aCffexMData.Turnover  <<"\"," <<std::endl;
    os <<"        \"OpenInterest\": \"" <<aCffexMData.OpenInterest  <<"\"," <<std::endl;
    os <<"        \"BidPrice1\": \"" <<aCffexMData.BidPrice1  <<"\"," <<std::endl;
    os <<"        \"BidVolume1\": \"" <<aCffexMData.BidVolume1  <<"\"," <<std::endl;
    os <<"        \"AskPrice1\": \"" <<aCffexMData.AskPrice1  <<"\"," <<std::endl;
    os <<"        \"AskVolume1\": \"" <<aCffexMData.AskVolume1  <<"\"," <<std::endl;
    os <<"        \"BidPrice2\": \"" <<aCffexMData.BidPrice2  <<"\"," <<std::endl;
    os <<"        \"BidVolume2\": \"" <<aCffexMData.BidVolume2  <<"\"," <<std::endl;
    os <<"        \"BidPrice3\": \"" <<aCffexMData.BidPrice3  <<"\"," <<std::endl;
    os <<"        \"BidVolume3\": \"" <<aCffexMData.BidVolume3  <<"\"," <<std::endl;
    os <<"        \"AskPrice2\": \"" <<aCffexMData.AskPrice2  <<"\"," <<std::endl;
    os <<"        \"AskVolume2\": \"" <<aCffexMData.AskVolume2  <<"\"," <<std::endl;
    os <<"        \"AskPrice3\": \"" <<aCffexMData.AskPrice3  <<"\"," <<std::endl;
    os <<"        \"AskVolume3\": \"" <<aCffexMData.AskVolume3  <<"\"," <<std::endl;
    os <<"        \"BidPrice4\": \"" <<aCffexMData.BidPrice4  <<"\"," <<std::endl;
    os <<"        \"BidVolume4\": \"" <<aCffexMData.BidVolume4  <<"\"," <<std::endl;
    os <<"        \"BidPrice5\": \"" <<aCffexMData.BidPrice5  <<"\"," <<std::endl;
    os <<"        \"BidVolume5\": \"" <<aCffexMData.BidVolume5  <<"\"," <<std::endl;
    os <<"        \"AskPrice4\": \"" <<aCffexMData.AskPrice4  <<"\"," <<std::endl;
    os <<"        \"AskVolume4\": \"" <<aCffexMData.AskVolume4  <<"\"," <<std::endl;
    os <<"        \"AskPrice5\": \"" <<aCffexMData.AskPrice5  <<"\"," <<std::endl;
    os <<"        \"AskVolume5\": \"" <<aCffexMData.AskVolume5  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aCffexMData.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"UpdateTime\": \"" <<aCffexMData.UpdateTime  <<"\"," <<std::endl;
    os <<"        \"UpdateMillisec\": \"" <<aCffexMData.UpdateMillisec  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

class MDataFile : public soil::DataFile
{
 public:
  
  MDataFile(const std::string& file_name,
            const std::string& instrus_filter="");

  virtual ~MDataFile();

 protected:

  virtual bool filterData(const soil::Data* data);

 private:
  
  InstrusFilter instrus_filter_;
};

};

#endif
