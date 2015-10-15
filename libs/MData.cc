#include "air/MData.hh"
#include "AirLog.hh"
#include "SpeedMData.hh"
#include "CffexMData.hh"

#include "boost/tokenizer.hpp"

namespace air
{

MDataFieldCallback::MDataFieldCallback(MData* mdata):
    mdata_(mdata)
{
  AIR_TRACE <<"MDataFieldCallback::MDataFieldCallback()";
  

}

MDataFieldCallback::~MDataFieldCallback()
{
  AIR_TRACE <<"MDataFieldCallback::~MDataFieldCallback()";
}

void MDataFieldCallback::msgCallback( const MDataField* msg)
{
  AIR_TRACE <<"MDataFieldCallback::msgCallback()";

  mdata_->outMData( msg );
}


MData::MData(const std::string& file,
             const std::string& instrus_filter)
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

  callback_.reset( new MDataFieldCallback(this) );

  mdata_queue_.reset( new soil::MsgQueue<MDataField, MDataFieldCallback>(callback_.get()) );
  
}

MData::~MData()
{
  AIR_TRACE <<"MData::~MData()";
  
  file_.close();
}

void MData::outMData(const MDataField* data)
{
  AIR_TRACE <<"MData::outMData()";

  if( instrus_filter_.empty() ||
      instrus_filter_.count( data->instruID() )>0 )
  {
    data->toFile( file_ );
  }
}

MData* MData::create(MDataType type,
                     const std::string& file,
                     const std::string& instrus_filter)
{
  AIR_TRACE <<"MData::create()";
  
  switch( type )
  {
    case SPEED_MDATA:
      return new SpeedMData(file, instrus_filter);

    case CFFEX_MDATA:
      return new CffexMData(file, instrus_filter);

    default:
      throw std::runtime_error("the mdata type is not supported.");
  };

  return 0;
}


};
