#include "air/MDataFile.hh"
#include "AirLog.hh"

#include "boost/tokenizer.hpp"

namespace air
{

void SpeedMData::writeToFile(std::ofstream& os) const
{
  AIR_TRACE <<"SpeedMData::writeToFile()";

  try
  {
    soil::DateTime start_time(update_time);
    
    start_time += soil::milliseconds(update_millisec);

    soil::time_duration delay = time_stamp - start_time;

    os <<update_time <<"." <<std::setfill('0') <<std::setw(3)
       <<update_millisec <<"\t"
       <<start_time <<"\t"
       <<time_stamp <<"\t"
       <<delay.total_microseconds() <<std::endl;
  }
  catch( ... )
  {
    AIR_ERROR <<"catch exception on time conversion.";
  }
}

void CffexMData::writeToFile(std::ofstream& os) const
{
  AIR_TRACE <<"CffexMDataField::writeToFile()";

  os <<*this <<std::endl;
}


MDataFile::MDataFile(const std::string& file_name,
                     const std::string& instrus_filter):
    soil::DataFile(file_name)
{
  AIR_TRACE <<"MDataFile::MDataFile()";
  
  boost::tokenizer<> tok( instrus_filter );
  for( boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end(); ++beg )
  {
    AIR_DEBUG <<"instrus filter: " <<*beg;
    instrus_filter_.insert(*beg);
  }

}

MDataFile::~MDataFile()
{
  AIR_TRACE <<"MDataFile::~MDataFile()";
  
}

bool MDataFile::filterData(const soil::Data* data)
{
  AIR_TRACE <<"MData::filterData()";

  const MData* mdata = dynamic_cast<const MData*>(data);
  
  if( instrus_filter_.empty() ||
      instrus_filter_.count( mdata->instruID() )>0 )
  {
    return true;
  }

  return false;
}

};
