
#include "OJ.h"

/*
功能: 判断两台计算机IP地址是同一子网络。
原型：
    int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask);

输入参数：
    char * pcIP1: 计算机1的IP地址，格式：“192.168.0.254”；
    char * pcIP2: 计算机2的IP地址，格式：“192.168.0.1”；
    char * pcSubNetworkMask: 子网掩码，格式：“255.255.255.0”；

返回值：
    0：IP1与IP2不属于同一子网络；
    1：IP1与IP2属于同一子网络；
*/
void stoint(char* pcip, int* ip)
{
	for(int i=0; i<4; ++i)
	{
		ip[i] = 0;
		while(*pcip != '.' && *pcip != '\0')
		{
			ip[i] = ip[i] * 10 + *pcip - '0';
			++pcip;
		}
		++pcip;
	}
	return ;
}
int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask)
{
    /*在这里实现功能*/
	if(NULL == pcIp2 || NULL == pcIp1 || NULL == pcSubNetworkMask) return 0;
	int ip1[4],ip2[4],mask[4];
	stoint(pcIp1, ip1);
	stoint(pcIp2, ip2);
	stoint(pcSubNetworkMask, mask);
	for(int i=0; i<4; ++i)
		if((ip1[i] & mask[i]) != (ip2[i] & mask[i])) return 0;
    return 1;
}
