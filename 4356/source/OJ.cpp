
#include "OJ.h"

/*
����: �ж���̨�����IP��ַ��ͬһ�����硣
ԭ�ͣ�
    int IsSameSubNetwork(char * pcIp1, char * pcIp2, char * pcSubNetworkMask);

���������
    char * pcIP1: �����1��IP��ַ����ʽ����192.168.0.254����
    char * pcIP2: �����2��IP��ַ����ʽ����192.168.0.1����
    char * pcSubNetworkMask: �������룬��ʽ����255.255.255.0����

����ֵ��
    0��IP1��IP2������ͬһ�����磻
    1��IP1��IP2����ͬһ�����磻
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
    /*������ʵ�ֹ���*/
	if(NULL == pcIp2 || NULL == pcIp1 || NULL == pcSubNetworkMask) return 0;
	int ip1[4],ip2[4],mask[4];
	stoint(pcIp1, ip1);
	stoint(pcIp2, ip2);
	stoint(pcSubNetworkMask, mask);
	for(int i=0; i<4; ++i)
		if((ip1[i] & mask[i]) != (ip2[i] & mask[i])) return 0;
    return 1;
}
