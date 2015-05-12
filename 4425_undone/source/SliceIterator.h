#ifndef SLICE_ITERATOR_H
#define SLICE_ITERATOR_H

#define MAX_COORD_NUM 10

typedef struct
{
	unsigned long start;//起始下标
	unsigned long end; //结束下标
}CoordSlice;

typedef struct
{
    int* first_element_of_orignal_array;//原始数组的第一个元素指针
    unsigned long coord_num; //维度个数，最大取值为MAX_COORD_NUM，值为10
    //原始数组从左到右各维度下标属性表示如下(从0到coord_num-1):
	unsigned long coord_spec[MAX_COORD_NUM];//原始数组每个维度下标的最大取值
	CoordSlice coord_slice[MAX_COORD_NUM];//切片在每个维度上的起止下标
}SliceDesc;

typedef struct
{
	//结构内容由考生自行设计定义
}SliceIterator;

int SliceIteratorInit (const SliceDesc* slice_desc, SliceIterator* slice_iterator);
int* SliceIteratorGetCurr(const SliceIterator* slice_iterator);
void SliceIteratorNext(SliceIterator* slice_iterator);
int SliceIteratorEnd(const SliceIterator* slice_iterator);
int CopySlice (const SliceDesc* slice_desc,int** first_element_of_slice_array,unsigned long* slice_element_num);

#endif
