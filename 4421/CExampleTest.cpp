
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include "FileManager.h"

// ע������׵�CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// ��������ʵ��ʾ��

// SetUp: ��ÿ������ǰִ��һ��
void CExampleTest::setUp()
{

}

// tearDown: ��ÿ��������ִ��һ��
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
