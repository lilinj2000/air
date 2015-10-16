#include <memory>

#include "gtest/gtest.h"
#include "soil/Condition.hh"
#include "air/MDataFile.hh"

namespace air
{

class MDataFileTest : public ::testing::Test
{
public:
  MDataFileTest()
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

TEST_F(MDataFileTest, speedMDataTest)
{
  std::string file = "speed_data_test.data";
  std::auto_ptr<MDataFile> speed_mdata( new MDataFile(file) );
                                                 
  std::auto_ptr<SpeedMData> data(new SpeedMData());
  
  speed_mdata->putData( data.release() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}

TEST_F(MDataFileTest, cffexMDataTest)
{
  std::string file = "cffex_data_test.data";
  std::auto_ptr<MDataFile> cffex_mdata( new MDataFile(file) );
                                                 
  std::auto_ptr<CffexMData> data(new CffexMData());
  
  cffex_mdata->putData( data.release() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}


}  // namespace air
