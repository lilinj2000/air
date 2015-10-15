#include "CffexMData.hh"
#include "AirLog.hh"

namespace air
{

void CffexMDataField::toFile(std::ofstream& os) const
{
  AIR_TRACE <<"CffexMDataField::toFile()";

  os <<*this <<std::endl;
}

CffexMData::CffexMData(const std::string& file, const std::string& instrus_filter):
    MData(file, instrus_filter)
{
  AIR_TRACE <<"CffexMData::CffexMData()";
  
}

CffexMData::~CffexMData()
{
  AIR_TRACE <<"CffexMData::~CffexMData()";
}

void CffexMData::pushMData(const MDataField* data)
{
  AIR_TRACE <<"CffexMData::pushMData()";

  std::auto_ptr<CffexMDataField> msg(new CffexMDataField());

  std::memcpy(msg.get(), data, sizeof(CffexMDataField));
  
  mdata_queue_->pushMsg( msg.release() );
}


};
