#include "air/TimeStampDataFile.hh"
#include "AirLog.hh"

#include "soil/String.hh"


namespace air
{

TimeStampData::TimeStampData(int order_ref):
    order_ref_(order_ref)
{
  AIR_TRACE <<"TimeStampData::TimeStampData()";
}

void TimeStampData::updateT1()
{
  AIR_TRACE <<"TimeStampData::updateT1()";

  t1_ = std::chrono::system_clock::now();
}

void TimeStampData::updateT2()
{
  AIR_TRACE <<"TimeStampData::updateT2()";

  t2_ = std::chrono::system_clock::now();
}

void TimeStampData::writeToFile(std::ofstream& os) const
{
  AIR_TRACE <<"TimeStampData::writeToFile()";

  try
  {
    std::chrono::system_clock::duration d1 = t1_ - t0_;
    std::chrono::system_clock::duration d2 = t2_ - t0_;
    
    os <<order_ref_ <<"\t"
       <<t0_ <<"\t"
       <<t1_ <<"\t"
       <<t2_ <<"\t"
       <<d1.count() <<"\t"
       <<d2.count() <<std::endl;
  }
  catch( ... )
  {
    AIR_ERROR <<"catch exception on write to file.";
  }
}

TimeStampDataFile::TimeStampDataFile(const std::string& file_name):
    soil::DataFile(file_name)
{
  AIR_TRACE <<"TimeStampDataFile::TimeStampDataFile()";

}

TimeStampDataFile::~TimeStampDataFile()
{
  AIR_TRACE <<"TimeStampDataFile::~TimeStampDataFile()";
  
}

};
