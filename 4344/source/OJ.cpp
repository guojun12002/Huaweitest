#include <stdlib.h>
#include "oj.h"


/*
����:
	����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A������B������C������D������E����
	90������ΪA 80-89��ΪB 70-79��ΪC 60-69��ΪD 60������ΪE

����:
	����score

���:
	��

����:
	�ּ����
	��������100��Χʱ����-1
*/

int ScoreLevel(int score)
{
    if(score>100 || score<0) return -1;
    else if(score >= 90) return 'A';
    else if(score >= 80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 60) return 'D';
    else return 'E';
}