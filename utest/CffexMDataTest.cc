#include <memory>

#include "gtest/gtest.h"
#include "air/CffexMData.hh"
#include "soil/Condition.hh"

namespace air
{

class CffexMDataTest : public ::testing::Test
{
public:
  CffexMDataTest()
  {
  }

  void SetUp()
  {
  }

  void TearDown()
  {
  }

 protected:
};

TEST_F(CffexMDataTest, sampleTest)
{
  std::string name = "cffex_data_test.data";
  std::auto_ptr<CffexMData> cffex_mdata(new CffexMData(name));

  std::auto_ptr<CffexDepthMarketData> data(new CffexDepthMarketData());
  
  cffex_mdata->pushMData( data.get() );

  std::auto_ptr<soil::Condition> cond( soil::Condition::create() );
  cond->wait( 1000 );
  
  ASSERT_TRUE( true );
}


}  // namespace air
