#ifndef AIR_SPEED_MDATA_HH
#define AIR_SPEED_MDATA_HH

#include "air/MData.hh"

namespace air
{

class SpeedMData : public MData
{
 public:
  SpeedMData(const std::string& file,
             const std::string& instrus_filter);

  virtual ~SpeedMData();

  virtual void pushMData(const MDataField* data);

};

};

#endif
