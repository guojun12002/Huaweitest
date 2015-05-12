#include <iostream>
#include <string>
using namespace std;

struct Recond
{
    string filename;
    string linenum;
    int num;
};

int main()
{
    bool flag = true;
    int i = 0;
    int j = 0;
    string temp = "";
    string s = "";
    Recond recond[8] = {{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1}}; //�洢�����ļ������к�
    string filename = "";     //��¼�ļ���
    string linenum = "";      //��¼�к�
    int recond_idx = 0;
    int count = 0;
    size_t pathidx = 0;

    while (cin>>filename>>linenum)
    {
        flag = true;
         s = "";
         pathidx = filename.find_last_of('\\',filename.size()-1); //�������һ����\��������

        if(pathidx == string::npos)   //������·��
        {
            if(filename.size() > 16)  //�ļ�������16�ַ�
            {
                s.assign(filename,filename.size() - 16,16);
                filename = s;
            }


            for(j = 0; j < 8; ++j)   //�����Ƿ���ͬ��¼
            {
                if(filename == recond[j].filename && linenum == recond[j].linenum)
                {
                    ++(recond[j].num);
                    flag = false;
                    break;
                }
            }

            if(flag)   //�����Ӽ�¼
            {
                recond[recond_idx].filename = filename;
                recond[recond_idx].linenum = linenum;
                recond[recond_idx].num = 1;
                recond_idx++;
            }
        }
        else    //����·��
        {
            s.assign(filename,pathidx+1,filename.size() - pathidx - 1);  //��ȡ�ļ���
            //cout<<filename<<linenum<<endl;
            filename = s;

            if(filename.size() > 16)  //�ļ�������16�ַ�
            {
                s = "";
                s.assign(filename,filename.size() - 16,16);
                filename = s;
            }

            for(j = 0; j < 8; ++j)   //�����Ƿ���ͬ��¼
            {
                if(filename == recond[j].filename && linenum == recond[j].linenum)
                {
                    ++(recond[j].num);
                    flag = false;
                    break;
                }
            }

            if(flag)   //�����Ӽ�¼
            {
                recond[recond_idx].filename = filename;
                recond[recond_idx].linenum = linenum;
                recond[recond_idx].num = 1;
                recond_idx++;
            }
        }

        if(recond_idx == 8)   //ѭ����¼
        {
            recond_idx = 0;
        }
    }



    for(i = 0; i < 8; ++i)
    {
        if(recond[i].filename == "")
        {
            continue;
        }

        cout<<recond[i].filename<<" "<<recond[i].linenum<<" "<<recond[i].num<<endl;
    }

    return 0;
}