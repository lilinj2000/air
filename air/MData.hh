#ifndef AIR_MDATA_HH
#define AIR_MDATA_HH

#include <string>
#include <fstream>
#include <set>

#include "soil/MsgQueue.hh"
#include "boost/date_time.hpp"

namespace air
{

class MData;

typedef std::set<std::string> InstrusFilter;

typedef struct
{
  std::string instru;
  std::string update_time;
  int update_millisec;

  boost::posix_time::ptime time_stamp;
}MarketInfo;

class MarketInfoCallback
{
 public:
  MarketInfoCallback(MData* mdata);

  ~MarketInfoCallback();

  void msgCallback(const MarketInfo* msg);

 private:

  MData* mdata_;
};


class MData
{
 public:
  MData(const std::string& file,
        const std::string& instrus_filter="");

  virtual ~MData();

  void pushMData(const std::string& instru, const std::string& update_time, int update_millisec);

  void outMData(const MarketInfo* data);

 private:
  
  std::ofstream  file_;
  
  InstrusFilter instrus_filter_;

  std::auto_ptr<soil::MsgQueue<MarketInfo, MarketInfoCallback> > market_queue_;

  std::auto_ptr<MarketInfoCallback> callback_;
};

};

#endif
