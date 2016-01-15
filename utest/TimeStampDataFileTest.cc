#include <memory>

#include "gtest/gtest.h"
#include "soil/STimer.hh"
#include "air/TimeStampDataFile.hh"

namespace air
{

class TimeStampDataFileTest : public ::testing::Test
{
public:
  TimeStampDataFileTest()
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

TEST_F(TimeStampDataFileTest, timeStampDataTest)
{
  std::string file = "timestamp_data_test.data";
  std::unique_ptr<TimeStampDataFile> timestamp_file( new TimeStampDataFile(file) );

  int order_ref = 1;
  std::unique_ptr<TimeStampData> data(new TimeStampData(1));

  cond_->wait( 1000 );

  data->updateT1();

  cond_->wait( 1000 );

  data->updateT2();
  
  timestamp_file->putData( data.release() );

  cond_->wait( 1000 );
  
  ASSERT_TRUE( true );
}

}  // namespace air
