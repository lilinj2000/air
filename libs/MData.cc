#include "air/MData.hh"
#include "AirLog.hh"

#include "boost/tokenizer.hpp"

namespace air
{

MarketInfoCallback::MarketInfoCallback(MData* mdata):
    mdata_(mdata)
{
  AIR_TRACE <<"MarketInfoCallback::MarketInfoCallback()";
  

}

MarketInfoCallback::~MarketInfoCallback()
{
  AIR_TRACE <<"MarketInfoCallback::~MarketInfoCallback()";
}

void MarketInfoCallback::msgCallback( const MarketInfo* msg)
{
  AIR_TRACE <<"MarketInfoCallback::msgCallback()";

  mdata_->outMData( msg );
}

MData::MData(const std::string& file, const std::string& instrus_filter)
{
  AIR_TRACE <<"MData::MData()";
  
  file_.open( file.data() );
  
  if( !file_.good() )
  {
    throw std::runtime_error("open the data file " + file + " failed.");
  }

  boost::tokenizer<> tok( instrus_filter );
  for( boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end(); ++beg )
  {
    AIR_DEBUG <<"instrus filter: " <<*beg;
    instrus_filter_.insert(*beg);
  }

  callback_.reset( new MarketInfoCallback(this) );

  market_queue_.reset( new soil::MsgQueue<MarketInfo, MarketInfoCallback>(callback_.get()) );
  
}

MData::~MData()
{
  AIR_TRACE <<"MData::~MData()";
  
  file_.close();
}

void MData::pushMData(const std::string& instru,
                      const std::string& update_time,
                      int update_millisec)
{
  AIR_TRACE <<"MData::pushMData()";

  std::auto_ptr<MarketInfo> msg(new MarketInfo());
  msg->time_stamp = boost::posix_time::microsec_clock::local_time();
  msg->instru = instru;
  msg->update_time = update_time;
  msg->update_millisec = update_millisec;

  market_queue_->pushMsg( msg.release() );

}

void MData::outMData(const MarketInfo* data)
{
  AIR_TRACE <<"MData::outMData()";

  if( instrus_filter_.count( data->instru )>0 )
  {
    namespace bg=boost::gregorian;
    namespace bp=boost::posix_time;
  
    bg::date today( bg::day_clock::local_day() );
    bp::ptime start_time(today, bp::duration_from_string(data->update_time));
    start_time = start_time + bp::milliseconds(data->update_millisec);

    bp::time_duration delay = data->time_stamp - start_time;
  
    file_<<data->update_time <<"." <<std::setfill('0') <<std::setw(3)
         <<data->update_millisec <<"\t"
         <<start_time <<"\t"
         <<data->time_stamp <<"\t"
         <<delay.total_microseconds() <<std::endl;
  }
}


};
