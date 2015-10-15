#include "air/CffexMData.hh"
#include "AirLog.hh"

#include "boost/tokenizer.hpp"

namespace air
{

CffexDepthMarketDataCallback::CffexDepthMarketDataCallback(CffexMData* mdata):
    cffex_mdata_(mdata)
{
  AIR_TRACE <<"CffexDepthMarketDataCallback::CffexDepthMarketDataCallback()";
  

}

CffexDepthMarketDataCallback::~CffexDepthMarketDataCallback()
{
  AIR_TRACE <<"CffexDepthMarketDataCallback::~CffexDepthMarketDataCallback()";
}

void CffexDepthMarketDataCallback::msgCallback( const CffexDepthMarketData* msg)
{
  AIR_TRACE <<"CffexDepthMarketDataCallback::msgCallback()";

  cffex_mdata_->outMData( msg );
}

CffexMData::CffexMData(const std::string& file, const std::string& instrus_filter)
{
  AIR_TRACE <<"CffexMData::CffexMData()";
  
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

  callback_.reset( new CffexDepthMarketDataCallback(this) );

  mdata_queue_.reset( new soil::MsgQueue<CffexDepthMarketData, CffexDepthMarketDataCallback>(callback_.get()) );
  
}

CffexMData::~CffexMData()
{
  AIR_TRACE <<"CffexMData::~CffexMData()";
  
  file_.close();
}

void CffexMData::pushMData(const CffexDepthMarketData* data)
{
  AIR_TRACE <<"CffexMData::pushMData()";

  std::auto_ptr<CffexDepthMarketData> msg(new CffexDepthMarketData());

  std::memcpy(msg.get(), data, sizeof(CffexDepthMarketData));
  
  mdata_queue_->pushMsg( msg.release() );

}

void CffexMData::outMData(const CffexDepthMarketData* data)
{
  AIR_TRACE <<"CffexMData::outMData()";

  if( instrus_filter_.empty() ||
      instrus_filter_.count( data->InstrumentID )>0 )
  {
    file_ <<*data <<std::endl;
  }
}


};
