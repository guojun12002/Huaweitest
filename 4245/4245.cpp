#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
// #include "source/"

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */
//本文件中的宏、结构体、API函数供考生使用，但不需更改
#define min(a,b)    (((a) < (b)) ? (a) : (b))
//医生初始信息的记录数
#define MAX_DOCTOR_RECORD       1
//病人初始信息的记录数
#define MAX_PATIENT_RECORD      6
//医生允许排队就诊的病人最大数量
#define MAX_DOCTOR_CAPABILITY   4
//挂号费
#define REG_FEE                 10
//处方费
#define DIAG_FEE                50
//命名字符串最大长度
#define CMD_LEN                 10000
//命令分隔符
#define CMD_SEPARATRIX          ","
#define true 1
//操作码定义
typedef enum _OpRet
{
    E000_INITITIAL_SUCC             = 0, //E000:初始化成功
    E002_DIAGNOSE_NOT_END           = 2, //E002:本次看病未结束
    E003_QUEUE_EXCEED_OF_PER_DOCTOR = 3, //E003:医生排队人数达到上限
    E004_LACK_FEE_FOR_REGISTER      = 4, //E004:无足够挂号费用
    E005_DIAGNOSE_SUCC              = 5, //E005:诊治成功
    E006_NO_PATIENT_IN_QUEUE        = 6, //E006:无病人排队
    E007_PAY_SUCC                   = 7, //E007:缴费成功
    E008_BALANCE_NOT_ENOUGH         = 8, //E008:余额不足
    E014_PATIENT_NOT_BE_PAY_STATUS  = 14, //E014:无该病人待缴费
    E016_NO_PATIENT_IN_HOSP         = 16, //E016:本院无该病人
    E017_DCT_DIAG_NOBODY            = 17, //E017:医生尚未诊断过任何病人
}OpRet;
//病人就诊的状态
typedef enum
{
    PS_IDLE,    //未挂号
    PS_IN_QUEUE,//待就诊
    PS_WAIT_PAY,//待缴费
}PatientStatus;
//病人类型
typedef enum
{
    PM_CREDIT,  //无社保病人
    PM_INSURE,  //有社保病人
 //在挂号和缴费是有区别
}PayMethod;
//查询方式
typedef enum
{
    Q_DOCTOR,   //按医生ID查询
    Q_PATIENT,  //按病人ID查询
}QueryType;
//单条的病人初始信息记录
struct PatientIni
{
    const char *patientId;  //病人ID
    int patientLevel;       //病人类型
    int creditBalance;      //现金金额
    int insureBalance;      //社保金额
};
//查询医生的信息结果
typedef struct
{
    int queueNum;                               //排队的病人数量
    char *pPatientIdInfo[MAX_DOCTOR_CAPABILITY];//排队的病人ID列表
 //用指针数组，Queue->pPatientIdInfo[0]表示的为排在第一位的病人。
}DoctorQueue;
//病人信息，测试的依据，考生不允许更改其数值
static struct PatientIni gPatientIniCfg[] =
{
    //病人ID  病人类型 现金金额 社保金额
    {"pat01", 0,       100,     0  ,},
    {"pat02", 1,       100,     100,},
    {"pat03", 0,       100,     0  ,},
    {"pat04", 1,       100,     50 ,},
    {"pat05", 1,       10 ,     10 ,},
    {"pat06", 1,       20 ,     10 ,},
};
static PatientStatus Status[]={PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE,PS_IDLE};
static DoctorQueue Queue={0,""};
/*****************************************************************************
 函 数 名  : api_print_operation_result
 功能描述  : 系统提供的函数,供考生调用,打印操作结果信息
 输入参数  : OpRet opRet 操作码定义
*****************************************************************************/
void api_print_operation_result(OpRet opRet);
/*****************************************************************************
 函 数 名  : api_print_register_succ
 功能描述  : 系统提供的函数,供考生调用,挂号成功返回的信息
*****************************************************************************/
void api_print_register_succ(void);
/*****************************************************************************
 函 数 名  : api_print_patient_query_info
 功能描述  : 系统提供的函数,供考生调用,按照病人方式查询的结果
 输入参数  : const char *pPatientId 病人ID
             PatientStatus patientStatus 病人就诊的状态
             int sequence 病人正在排队就诊时的序号,仅在patientStatus为PS_IN_QUEUE有效
                          patientStatus为其他值时sequence可以输入任意值
             int insureBalance 社保帐户余额
             int creditBalance 现金帐户余额
*****************************************************************************/
void api_print_patient_query_info(const char *pPatientId,
                                  PatientStatus patientStatus,
                                  int sequence,
                                  int insureBalance,
                                  int creditBalance);
/*****************************************************************************
 函 数 名  : api_print_doctor_query_info
 功能描述  : 系统提供的函数,供考生调用,按照医生方式查询的结果
 输入参数  : DoctorQueue *pDoctorQueue 医生名下的病人排队情况
*****************************************************************************/
void api_print_doctor_query_info(DoctorQueue *pDoctorQueue);
//需考生实现的函数声明 BEGIN
void OpInit(void);
void OpRegister(const char *pPatientId);
void OpDiag();
void OpPay(const char *pPatientId);
void OpQuery(QueryType queryType, const char *pQueryId);
//需考生实现的函数声明 END
#ifdef __cplusplus
}
#endif /* __cplusplus */

// 定义一个病人
struct PatientIni patient[6];



/*****************************************************************************
函 数 名  : OpInit
功能描述  : 需要考生实现的接口,系统初始化
*****************************************************************************/
void OpInit(void)
{
	Queue.queueNum=0;
	for(int i=0;i<6;i++)
	{Queue.pPatientIdInfo[i]=NULL;
	 patient[i]=gPatientIniCfg[i];
	 Status[i]=PS_IDLE;
	}
api_print_operation_result(E000_INITITIAL_SUCC);

};

/*****************************************************************************
函 数 名  : OpRegister
功能描述  : 需要考生实现的接口,病人挂号
输入参数  : const char *pPatientId 病人ID
*****************************************************************************/
void OpRegister(const char *pPatientId)
{
	//判断病人看病是否结束
	for(int i=0;i<6;i++)
	{
		if(strcmp(patient[i].patientId,pPatientId)==0&&Status[i]!=PS_IDLE)//状态是否是没有挂号
		 { api_print_operation_result(E002_DIAGNOSE_NOT_END);
           return ;
		 }
	}

	if(Queue.queueNum==4)//队列排到了4  当然失败了
	{
	   api_print_operation_result(E003_QUEUE_EXCEED_OF_PER_DOCTOR);
       return ;
	}

	// 看钱有么有那么多  这个得看病人的 是否是社保
	int i=0;
	for(;i<6;i++)
	{
		if(strcmp(patient[i].patientId,pPatientId)==0)
			break;
	}
	if(patient[i].patientLevel==1){//有社保
		if(patient[i].insureBalance>=10){
			patient[i].insureBalance-=10;
		}
		else
			if(patient[i].creditBalance>=10){
			 patient[i].creditBalance-=10;
			}
			else{
			  api_print_operation_result(E004_LACK_FEE_FOR_REGISTER);
              return ;
			}
	}
	else{//没有社保
	    if(patient[i].creditBalance>=10){
		patient[i].creditBalance-=10;
		}
		else{
		 api_print_operation_result(E004_LACK_FEE_FOR_REGISTER);
         return ;
		}
	}
	Queue.pPatientIdInfo[Queue.queueNum]=(char *)patient[i].patientId;
	Queue.queueNum++;
	Status[i]=PS_IN_QUEUE;
    api_print_register_succ();
    return ;

 }
/*****************************************************************************
函 数 名  : OpDiag
功能描述  : 需要考生实现的接口,就诊
*****************************************************************************/
void OpDiag(void)
{
	if(Queue.queueNum == 0) {
       api_print_operation_result(E006_NO_PATIENT_IN_QUEUE);
       return ;
       }
	for(int i=0;i<6;i++)
		if(strcmp(Queue.pPatientIdInfo[0],patient[i].patientId)==0){
                Status[i]=PS_WAIT_PAY;
                break;
         }

	for(int i=0;i<Queue.queueNum;i++)
        Queue.pPatientIdInfo[i]=Queue.pPatientIdInfo[i+1];
    Queue.queueNum--;

    api_print_operation_result(E005_DIAGNOSE_SUCC);
    return ;

}
/*****************************************************************************
函 数 名  : OpPay
功能描述  : 需要考生实现的接口,缴费
输入参数  : const char *pPatientId 病人ID
*****************************************************************************/
void OpPay(const char *pPatientId)
{
     int i;
     for(i=0;i<6;i++)
     if(strcmp(patient[i].patientId,pPatientId)==0)
        break;
     if(Status[i]!=PS_WAIT_PAY){
        api_print_operation_result(E014_PATIENT_NOT_BE_PAY_STATUS);
        return ;
       }
	 //看怎么付款
	 //只要进入到这一步付款了  不管钱够不够都得状态改为为挂号
	 Status[i]=PS_IDLE;
	 if(patient[i].patientLevel==1){//有社保
		if(patient[i].insureBalance>=50){
			patient[i].insureBalance-=50;
			api_print_operation_result(E007_PAY_SUCC);
            return ;

		}
		else
			if(patient[i].creditBalance>=50){
			 patient[i].creditBalance-=50;
			 api_print_operation_result(E007_PAY_SUCC);
             return ;
			}
			else{
			  api_print_operation_result(E008_BALANCE_NOT_ENOUGH);
              return ;
			}
	}
	else{//没有社保
	    if(patient[i].creditBalance>=50){
		patient[i].creditBalance-=50;
		api_print_operation_result(E007_PAY_SUCC);
        return ;
		}
		else{
		 api_print_operation_result(E008_BALANCE_NOT_ENOUGH);
         return ;
		}
	}

}
/*****************************************************************************
函 数 名  : OpQuery
功能描述  : 需要考生实现的接口,查询
输入参数  : QueryType queryType 查询方式
            const char *pQueryId 医生/病人ID
*****************************************************************************/
void OpQuery(QueryType queryType, const char *pQueryId)
{

    if(queryType==0)
      api_print_doctor_query_info(&Queue);
    else{
     int i , seq = 0 , num = Queue.queueNum;
     for(i=0;i<num;i++){
         if(strcmp(Queue.pPatientIdInfo[i],pQueryId)==0)
         {
           seq = i;
           break;
          }
        }
     for(i=0;i<6;i++){
		 if(strcmp(patient[i].patientId,pQueryId)==0)
         break;
      }
	 api_print_patient_query_info(pQueryId,Status[i],seq+1,patient[i].insureBalance,patient[i].creditBalance);

   }

}

/*****************************************************************************
 函 数 名  : libOutputStr
 功能描述  : 内部函数: 考试系统的输出打印函数，考生无须关注
 输入参数  : pcStr  输出打印字符串
*****************************************************************************/
void libOutputStr(char* pcStr);
/*****************************************************************************
 函 数 名  : cmd_process
 功能描述  : 系统调用的函数,考生无需关注
*****************************************************************************/
void cmd_process(int argc, char* argv[]);
int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
    cmd_process(argc,argv);
    return 0;
}
//执行命令函数
void cmd_dispatch(char *pszCmd)
{
    char    Buff1[32];
    char    Buff2[32];
    char    Buff3[32];
    int     tmpParaA;
    int             GetParaCount;
    const char      *p = NULL;
    const char      *p1 = NULL;
    if (NULL == pszCmd)
    {
        return;
    }
    p = pszCmd;
    memset(Buff1, 0, sizeof(Buff1));
    memset(Buff2, 0, sizeof(Buff2));
    memset(Buff3, 0, sizeof(Buff3));
    //若为i则执行初始化函数
    if (p == strstr(p, "i"))
    {
        OpInit();
        return;
    }
 //若为挂号，则Buff1存储挂号的病人的ID，并执行挂号函数
    else if (p == strstr(p, "reg_"))
    {
        GetParaCount = sscanf(p, "reg_%s", Buff1);
        if (1 == GetParaCount)
        {
            OpRegister(Buff1);
            return;
        }
    }
 //若为诊治，则执行诊治函数
    else if (p == strstr(p, "diag"))
    {
        OpDiag();
        return;
    }
 //若为缴费则让病人Buff1进行缴费。
    else if (p == strstr(p, "pay"))
    {
        GetParaCount = sscanf(p, "pay_%s", Buff1);
        if (1 == GetParaCount)
        {
            OpPay(Buff1);
            return;
        }
    }
    else if (p == strstr(p, "qu"))
    {
        GetParaCount = sscanf(p, "qu_%d-%s", &tmpParaA, Buff1);
  //若为查询命令则执行查询，当tmpParaA为0，buffer1==dct是表示表示查询医生当前的病人排队情况
  //若tmpParaA为1，buffer1==patID则表示查询ID为pat01的病人信息。
        if (2 == GetParaCount)
        {
            OpQuery((QueryType)tmpParaA, Buff1);
            return;
        }
    }
    libOutputStr("无效命令");
    return;
}
void user_cmdproc(char *pszCmd, int iLen)
{
    if (NULL == pszCmd)
    {
        return;
    }
    cmd_dispatch(pszCmd);
    return;
}
void api_print_operation_result(OpRet opRet)
{
    switch (opRet)
    {
        case E000_INITITIAL_SUCC:
            libOutputStr("E000"); //:初始化成功
            break;
        case E002_DIAGNOSE_NOT_END:
            libOutputStr("E002"); //:本次看病未结束
            break;
        case E003_QUEUE_EXCEED_OF_PER_DOCTOR:
            libOutputStr("E003");  //:医生排队人数达到上限
            break;
        case E004_LACK_FEE_FOR_REGISTER:
            libOutputStr("E004"); //:无足够挂号费用
            break;
        case E005_DIAGNOSE_SUCC:
            libOutputStr("E005"); //:诊治成功
            break;
        case E006_NO_PATIENT_IN_QUEUE:
            libOutputStr("E006"); //:无病人排队
            break;
        case E007_PAY_SUCC:
            libOutputStr("E007"); //:缴费成功
            break;
        case E008_BALANCE_NOT_ENOUGH:
            libOutputStr("E008"); //:余额不足
            break;
        case E014_PATIENT_NOT_BE_PAY_STATUS:
            libOutputStr("E014"); //:无该病人待缴费
            break;
        case E016_NO_PATIENT_IN_HOSP:
            libOutputStr("E016"); //:本院无该病人
            break;
        case E017_DCT_DIAG_NOBODY:
            libOutputStr("E017"); //:医生尚未诊断过任何病人
            break;
        default:
            break;
    }
    return;
}
void api_print_register_succ(void)
{
    libOutputStr("E001"); //:挂号成功
    return;
}
void api_print_patient_query_info(const char *pPatientId, PatientStatus patientStatus, int sequence, int insureBalance, int creditBalance)
{
    char pBuff[512];
    if (NULL == pPatientId)
    {
        return;
    }
    memset(pBuff, 0, sizeof(pBuff));
    switch (patientStatus)
    {
        case PS_IN_QUEUE:
            sprintf(pBuff, "E012:%s 1 %d,%d,%d",  //待就诊 排在第%d位,社保帐户余额:%d,现金帐户余额:%d
                    pPatientId, sequence, insureBalance, creditBalance);
            libOutputStr(pBuff);
            break;
        case PS_IDLE:
            sprintf(pBuff, "E012:%s 0 %d,%d",//未挂号 社保帐户余额:%d,现金帐户余额:%d
                    pPatientId, insureBalance, creditBalance);
            libOutputStr(pBuff);
            break;
        case PS_WAIT_PAY:
            sprintf(pBuff, "E012:%s 2 %d,%d", //待缴费 社保帐户余额:%d,现金帐户余额:%d
                    pPatientId, insureBalance, creditBalance);
            libOutputStr(pBuff);
            break;
        default:
            break;
    }
    return;
}
void api_print_doctor_query_info(DoctorQueue *pDoctorQueue)
{
    char pBuff[512];
    if (NULL == pDoctorQueue)
    {
        return;
    }
    memset(pBuff, 0, sizeof(pBuff));
    if (0 == pDoctorQueue->queueNum)
    {
        libOutputStr("E013:dct 0"); //无人排队
    }
    else
    {
        int i;
        sprintf(pBuff, "E013:dct"); //等待队列
        for (i = 0; i < pDoctorQueue->queueNum; i++)
        {
            strcat(pBuff, " ");
            strcat(pBuff, pDoctorQueue->pPatientIdInfo[i]);
        }
        libOutputStr(pBuff);
    }
	 return;
}
/*****************************************************************************
 函 数 名  : libOutputStr
 功能描述  : 内部函数: 考试系统的输出打印函数
 输入参数  : pcStr  输出打印字符串
 输出参数  : 无
 返 回 值  : 无
*****************************************************************************/
void libOutputStr(char* pcStr)
{
    if (NULL != pcStr )
    {
        printf("%s\n", pcStr);
    }
}

/*****************************************************************************
 函 数 名  : cmd_process
 功能描述  : 系统调用函数
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 无
*****************************************************************************/
void cmd_process(int argc, char* argv[])
{
    char *pszCmd = NULL;
    int iCmdNum =0;
//内存分配失败，退出函数
    pszCmd = (char*)malloc(CMD_LEN);
    if (NULL == pszCmd)
    {
        return;
    }

#ifdef _WIN32
  // while (true)
#endif
    {
        iCmdNum =0;
        memset(pszCmd, 0, CMD_LEN);
  //获取命令pszCmd。
        iCmdNum = scanf("%s", pszCmd);
        pszCmd[CMD_LEN-1] = 0;
        if (1 == iCmdNum)
        {
            char *pComma = pszCmd;
            char *pCmdStartPos = pszCmd;
            char pszCmdBuffer[512];
            // 多命令以逗号分割
            pComma = strstr(pCmdStartPos, CMD_SEPARATRIX);
   //存在多命令时处理方法
            while (NULL != pComma)
            {
                size_t uiCpyLen = 0;
    //针对存在多个逗号的问题，一直找到第一个不为逗号的位置pCmdStartPos，pComma为pCmdStartPos后的第一个逗号的位置
                if (pComma == pCmdStartPos)
                {
                    pCmdStartPos = pComma+1;
                    pComma = strstr(pCmdStartPos, CMD_SEPARATRIX);
                    continue;
                }
                memset(pszCmdBuffer, 0, sizeof(pszCmdBuffer));
    //uiCpyLen为第一个命令的长度，并将第一个命令复制给pszCmdBuffer。
                uiCpyLen = min(sizeof(pszCmdBuffer), (size_t)(pComma - pCmdStartPos));

                strncpy(pszCmdBuffer, pCmdStartPos, uiCpyLen);
    //执行pszCmdBuffer命令所对应的操作
                cmd_dispatch(pszCmdBuffer);

                pCmdStartPos = pComma+1;
                while(' ' == *pCmdStartPos)
                {
                    pCmdStartPos ++;
                }
                pComma = strstr(pCmdStartPos, CMD_SEPARATRIX);
            }
            cmd_dispatch(pCmdStartPos);
        }
        else
        {
            libOutputStr("Get command fail.");
        }
    }

    free(pszCmd);
    return;
}