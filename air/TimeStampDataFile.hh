#ifndef AIR_TIMESTAMP_DATA_FILE_HH
#define AIR_TIMESTAMP_DATA_FILE_HH

#include <string>
#include <set>

#include "soil/DataFile.hh"
#include "soil/DateTime.hh"

namespace air
{

class TimeStampDataFile;

class TimeStampData : public soil::Data
{
 public:
  TimeStampData(int order_ref);
  
  int orderRef() const { return order_ref_; }

  const soil::DateTime T0() const { return t0_; }

  const soil::DateTime T1() const { return t1_; }

  const soil::DateTime T2() const { return t2_; }

  void updateT1();

  void updateT2();

  virtual void writeToFile(std::ofstream& os) const;

 private:
  
  int order_ref_;
  // request order insert timestamp
  soil::DateTime t0_;
  // on rtn order, just from counter response
  soil::DateTime t1_;
  // on rtn order, from exchange response
  soil::DateTime t2_;
};

template< typename CharT, typename TraitsT >
std::basic_ostream< CharT, TraitsT >& operator<<(std::basic_ostream< CharT, TraitsT >& os, TimeStampData const& aTimeStampData)
{
    os <<std::endl;
    os <<"{" <<std::endl;
    os <<"    \"TimeStampData\": {" <<std::endl;
    os <<"        \"order_ref\": \"" <<aTimeStampData.orderRef()  <<"\"," <<std::endl;
    os <<"        \"t0\": \"" <<aTimeStampData.T0()  <<"\"," <<std::endl;
    os <<"        \"t1\": \"" <<aTimeStampData.T1()  <<"\"," <<std::endl;
    os <<"        \"t2\": \"" <<aTimeStampData.T2()  <<"\"" <<std::endl;
    os <<"    }" <<std::endl;
    os <<"}" <<std::endl;
};

class TimeStampDataFile : public soil::DataFile
{
 public:
  
  TimeStampDataFile(const std::string& file_name);

  virtual ~TimeStampDataFile();

 protected:

 private:
  
};

};

#endif
