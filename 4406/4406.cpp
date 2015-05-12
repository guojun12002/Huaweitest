
#include "source/swischedule.cpp"

void CPPUNIT_ASSERT(bool flag)
{
	if(flag) cout<<"YES"<<endl;
	else cout<<0<<endl;
}
static unsigned int * schedTrace;
static unsigned int   schedTraceCnt;
static unsigned int   schedTraceSize;

static void SchedTraceInit(unsigned int * p, unsigned int size)
{
	schedTrace = p;
	schedTraceCnt = 0;
	schedTraceSize = size;
}

static void SchedTraceRecord(unsigned int pid)
{
	if (schedTraceCnt < schedTraceSize)
		schedTrace[schedTraceCnt++] = pid;
}
void TestCase01_proc1()
{
	SchedTraceRecord(1);
	SwiActivate(2);
	SchedTraceRecord(1);
}

void TestCase01_proc2()
{
	SchedTraceRecord(2);
	SwiActivate(3);
	SchedTraceRecord(2);
}
void TestCase01_proc3()
{
	SchedTraceRecord(3);
}
int main()
{
	// freopen("input.txt", "r", stdin);
	int ret;
	unsigned int trace[10];
	unsigned int expect[] = {1, 2, 2, 3, 1};

	SchedTraceInit(trace, 10);
	Clear();

	ret = SwiCreate(1, 5, TestCase01_proc1);
    CPPUNIT_ASSERT(0 == ret);

	ret = SwiCreate(2, 3, TestCase01_proc2);
    CPPUNIT_ASSERT(0 == ret);

	ret = SwiCreate(3, 4, TestCase01_proc3);
    CPPUNIT_ASSERT(0 == ret);

	ret = SwiActivate(1);
	CPPUNIT_ASSERT(0 == ret);

	CPPUNIT_ASSERT(5 == schedTraceCnt);
	CPPUNIT_ASSERT(0 == memcmp(expect, trace, sizeof(expect)));
	return 0;
}