#include "SpeedMData.hh"
#include "AirLog.hh"

namespace air
{

void SpeedMDataField::toFile(std::ofstream& os) const
{
  AIR_TRACE <<"SpeedMDataField::toFile()";

  try
  {
    namespace bg=boost::gregorian;
    namespace bp=boost::posix_time;
  
    bg::date today( bg::day_clock::local_day() );
    bp::ptime start_time(today, bp::duration_from_string(update_time));
    start_time = start_time + bp::milliseconds(update_millisec);

    bp::time_duration delay = time_stamp - start_time;

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

SpeedMData::SpeedMData(const std::string& file,
                       const std::string& instrus_filter):
    MData(file, instrus_filter)
{
  AIR_TRACE <<"SpeedMData::SpeedMData()";
}

SpeedMData::~SpeedMData()
{
  AIR_TRACE <<"SpeedMData::~SpeedMData()";
}

void SpeedMData::pushMData(const MDataField* data)       
{
  AIR_TRACE <<"SpeedMData::pushMData()";

  std::auto_ptr<SpeedMDataField> msg(new SpeedMDataField());
  // const SpeedMDataField* speed_data = dynamic_cast<const SpeedMDataField*>(data);

  std::memcpy(msg.get(), data, sizeof(SpeedMDataField));
  
  msg->time_stamp = boost::posix_time::microsec_clock::local_time();
  
  // msg->instru = speed_data->instru;
  // msg->update_time = speed_data->update_time;
  // msg->update_millisec = speed_data->update_millisec;

  mdata_queue_->pushMsg( msg.release() );
}

};
