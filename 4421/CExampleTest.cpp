
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include "FileManager.h"

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// 测试用例实现示例

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{

}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
    Clear();
}

void CExampleTest::TestCase01()
{
    CreateDir("root", "DirA");
    CreateFile("DirA", "File1");
    CPPUNIT_ASSERT(1 == GetFileNum("DirA"));
}
