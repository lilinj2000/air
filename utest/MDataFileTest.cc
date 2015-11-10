#include <memory>

#include "gtest/gtest.h"
#include "soil/STimer.hh"
#include "air/MDataFile.hh"

namespace air
{

class MDataFileTest : public ::testing::Test
{
public:
  MDataFileTest()
  {
    cond_.reset( soil::STimer::create() );
  }

  void SetUp()
  {
  }

  void TearDown()
  {
  }

 protected:
  std::unique_ptr<soil::STimer> cond_;
};

TEST_F(MDataFileTest, speedMDataTest)
{
  std::string file = "speed_data_test.data";
  std::unique_ptr<MDataFile> speed_mdata( new MDataFile(file) );
                                                 
  std::unique_ptr<SpeedMData> data(new SpeedMData());
  
  speed_mdata->putData( data.release() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}

TEST_F(MDataFileTest, cffexMDataTest)
{
  std::string file = "cffex_data_test.data";
  std::unique_ptr<MDataFile> cffex_mdata( new MDataFile(file) );
                                                 
  std::unique_ptr<CffexMData> data(new CffexMData());
  
  cffex_mdata->putData( data.release() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}


}  // namespace air
