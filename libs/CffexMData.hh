#ifndef AIR_CFFEX_MDATA_HH
#define AIR_CFFEX_MDATA_HH

#include "air/MData.hh"

namespace air
{

class CffexMData : public MData
{
 public:
  CffexMData(const std::string& file,
        const std::string& instrus_filter="");

  virtual ~CffexMData();

  virtual void pushMData(const MDataField* data);

 private:
  
};

};

#endif
