#include <memory>

#include "gtest/gtest.h"
#include "air/MData.hh"
#include "soil/Condition.hh"

namespace air
{

class MDataTest : public ::testing::Test
{
public:
  MDataTest()
  {
    cond_.reset( soil::Condition::create() );
  }

  void SetUp()
  {
  }

  void TearDown()
  {
  }

 protected:
  std::auto_ptr<soil::Condition> cond_;
};

TEST_F(MDataTest, speedMDataTest)
{
  std::string file = "speed_data_test.data";
  std::auto_ptr<MData> speed_mdata( MData::create(MData::SPEED_MDATA,file) );
                                                 
  std::auto_ptr<SpeedMDataField> data(new SpeedMDataField());
  
  speed_mdata->pushMData( data.get() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}

TEST_F(MDataTest, cffexMDataTest)
{
  std::string file = "cffex_data_test.data";
  std::auto_ptr<MData> cffex_mdata( MData::create(MData::CFFEX_MDATA, file) );
                                                 
  std::auto_ptr<CffexMDataField> data(new CffexMDataField());
  
  cffex_mdata->pushMData( data.get() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}


}  // namespace air
