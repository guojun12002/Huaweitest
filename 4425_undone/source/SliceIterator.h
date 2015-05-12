#ifndef SLICE_ITERATOR_H
#define SLICE_ITERATOR_H

#define MAX_COORD_NUM 10

typedef struct
{
	unsigned long start;//��ʼ�±�
	unsigned long end; //�����±�
}CoordSlice;

typedef struct
{
    int* first_element_of_orignal_array;//ԭʼ����ĵ�һ��Ԫ��ָ��
    unsigned long coord_num; //ά�ȸ��������ȡֵΪMAX_COORD_NUM��ֵΪ10
    //ԭʼ��������Ҹ�ά���±����Ա�ʾ����(��0��coord_num-1):
	unsigned long coord_spec[MAX_COORD_NUM];//ԭʼ����ÿ��ά���±�����ȡֵ
	CoordSlice coord_slice[MAX_COORD_NUM];//��Ƭ��ÿ��ά���ϵ���ֹ�±�
}SliceDesc;

typedef struct
{
	//�ṹ�����ɿ���������ƶ���
}SliceIterator;

int SliceIteratorInit (const SliceDesc* slice_desc, SliceIterator* slice_iterator);
int* SliceIteratorGetCurr(const SliceIterator* slice_iterator);
void SliceIteratorNext(SliceIterator* slice_iterator);
int SliceIteratorEnd(const SliceIterator* slice_iterator);
int CopySlice (const SliceDesc* slice_desc,int** first_element_of_slice_array,unsigned long* slice_element_num);

#endif
