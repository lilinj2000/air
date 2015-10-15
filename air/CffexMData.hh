#ifndef AIR_CFFEX_MDATA_HH
#define AIR_CFFEX_MDATA_HH

#include <fstream>

#include "soil/MsgQueue.hh"
#include "air/AirDef.hh"

namespace air
{

struct CffexDepthMarketData
{
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
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, CffexDepthMarketData const& aDepthMarketData)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"CffexDepthMarketData\": {" <<std::endl;
    os <<"        \"TradingDay\": \"" <<aDepthMarketData.TradingDay  <<"\"," <<std::endl;
    os <<"        \"SettlementGroupID\": \"" <<aDepthMarketData.SettlementGroupID  <<"\"," <<std::endl;
    os <<"        \"SettlementID\": \"" <<aDepthMarketData.SettlementID  <<"\"," <<std::endl;
    os <<"        \"PreSettlementPrice\": \"" <<aDepthMarketData.PreSettlementPrice  <<"\"," <<std::endl;
    os <<"        \"PreClosePrice\": \"" <<aDepthMarketData.PreClosePrice  <<"\"," <<std::endl;
    os <<"        \"PreOpenInterest\": \"" <<aDepthMarketData.PreOpenInterest  <<"\"," <<std::endl;
    os <<"        \"PreDelta\": \"" <<aDepthMarketData.PreDelta  <<"\"," <<std::endl;
    os <<"        \"OpenPrice\": \"" <<aDepthMarketData.OpenPrice  <<"\"," <<std::endl;
    os <<"        \"HighestPrice\": \"" <<aDepthMarketData.HighestPrice  <<"\"," <<std::endl;
    os <<"        \"LowestPrice\": \"" <<aDepthMarketData.LowestPrice  <<"\"," <<std::endl;
    os <<"        \"ClosePrice\": \"" <<aDepthMarketData.ClosePrice  <<"\"," <<std::endl;
    os <<"        \"UpperLimitPrice\": \"" <<aDepthMarketData.UpperLimitPrice  <<"\"," <<std::endl;
    os <<"        \"LowerLimitPrice\": \"" <<aDepthMarketData.LowerLimitPrice  <<"\"," <<std::endl;
    os <<"        \"SettlementPrice\": \"" <<aDepthMarketData.SettlementPrice  <<"\"," <<std::endl;
    os <<"        \"CurrDelta\": \"" <<aDepthMarketData.CurrDelta  <<"\"," <<std::endl;
    os <<"        \"LastPrice\": \"" <<aDepthMarketData.LastPrice  <<"\"," <<std::endl;
    os <<"        \"Volume\": \"" <<aDepthMarketData.Volume  <<"\"," <<std::endl;
    os <<"        \"Turnover\": \"" <<aDepthMarketData.Turnover  <<"\"," <<std::endl;
    os <<"        \"OpenInterest\": \"" <<aDepthMarketData.OpenInterest  <<"\"," <<std::endl;
    os <<"        \"BidPrice1\": \"" <<aDepthMarketData.BidPrice1  <<"\"," <<std::endl;
    os <<"        \"BidVolume1\": \"" <<aDepthMarketData.BidVolume1  <<"\"," <<std::endl;
    os <<"        \"AskPrice1\": \"" <<aDepthMarketData.AskPrice1  <<"\"," <<std::endl;
    os <<"        \"AskVolume1\": \"" <<aDepthMarketData.AskVolume1  <<"\"," <<std::endl;
    os <<"        \"BidPrice2\": \"" <<aDepthMarketData.BidPrice2  <<"\"," <<std::endl;
    os <<"        \"BidVolume2\": \"" <<aDepthMarketData.BidVolume2  <<"\"," <<std::endl;
    os <<"        \"BidPrice3\": \"" <<aDepthMarketData.BidPrice3  <<"\"," <<std::endl;
    os <<"        \"BidVolume3\": \"" <<aDepthMarketData.BidVolume3  <<"\"," <<std::endl;
    os <<"        \"AskPrice2\": \"" <<aDepthMarketData.AskPrice2  <<"\"," <<std::endl;
    os <<"        \"AskVolume2\": \"" <<aDepthMarketData.AskVolume2  <<"\"," <<std::endl;
    os <<"        \"AskPrice3\": \"" <<aDepthMarketData.AskPrice3  <<"\"," <<std::endl;
    os <<"        \"AskVolume3\": \"" <<aDepthMarketData.AskVolume3  <<"\"," <<std::endl;
    os <<"        \"BidPrice4\": \"" <<aDepthMarketData.BidPrice4  <<"\"," <<std::endl;
    os <<"        \"BidVolume4\": \"" <<aDepthMarketData.BidVolume4  <<"\"," <<std::endl;
    os <<"        \"BidPrice5\": \"" <<aDepthMarketData.BidPrice5  <<"\"," <<std::endl;
    os <<"        \"BidVolume5\": \"" <<aDepthMarketData.BidVolume5  <<"\"," <<std::endl;
    os <<"        \"AskPrice4\": \"" <<aDepthMarketData.AskPrice4  <<"\"," <<std::endl;
    os <<"        \"AskVolume4\": \"" <<aDepthMarketData.AskVolume4  <<"\"," <<std::endl;
    os <<"        \"AskPrice5\": \"" <<aDepthMarketData.AskPrice5  <<"\"," <<std::endl;
    os <<"        \"AskVolume5\": \"" <<aDepthMarketData.AskVolume5  <<"\"," <<std::endl;
    os <<"        \"InstrumentID\": \"" <<aDepthMarketData.InstrumentID  <<"\"," <<std::endl;
    os <<"        \"UpdateTime\": \"" <<aDepthMarketData.UpdateTime  <<"\"," <<std::endl;
    os <<"        \"UpdateMillisec\": \"" <<aDepthMarketData.UpdateMillisec  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
}

class CffexMData;

class CffexDepthMarketDataCallback
{
 public:
  CffexDepthMarketDataCallback(CffexMData* mdata);

  ~CffexDepthMarketDataCallback();

  void msgCallback(const CffexDepthMarketData* msg);

 private:

  CffexMData* cffex_mdata_;
};


class CffexMData
{
 public:
  CffexMData(const std::string& file,
        const std::string& instrus_filter="");

  virtual ~CffexMData();

  void pushMData(const CffexDepthMarketData* data);

  void outMData(const CffexDepthMarketData* data);

 private:
  
  std::ofstream  file_;
  
  InstrusFilter instrus_filter_;

  std::auto_ptr<soil::MsgQueue<CffexDepthMarketData, CffexDepthMarketDataCallback> > mdata_queue_;

  std::auto_ptr<CffexDepthMarketDataCallback> callback_;
};

};

#endif
