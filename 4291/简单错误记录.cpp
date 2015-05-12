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
    Recond recond[8] = {{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1},{"","",1}}; //存储所有文件名和行号
    string filename = "";     //记录文件名
    string linenum = "";      //记录行号
    int recond_idx = 0;
    int count = 0;
    size_t pathidx = 0;

    while (cin>>filename>>linenum)
    {
        flag = true;
         s = "";
         pathidx = filename.find_last_of('\\',filename.size()-1); //返回最后一个“\”的索引

        if(pathidx == string::npos)   //不存在路径
        {
            if(filename.size() > 16)  //文件名超过16字符
            {
                s.assign(filename,filename.size() - 16,16);
                filename = s;
            }


            for(j = 0; j < 8; ++j)   //查找是否相同记录
            {
                if(filename == recond[j].filename && linenum == recond[j].linenum)
                {
                    ++(recond[j].num);
                    flag = false;
                    break;
                }
            }

            if(flag)   //新增加记录
            {
                recond[recond_idx].filename = filename;
                recond[recond_idx].linenum = linenum;
                recond[recond_idx].num = 1;
                recond_idx++;
            }
        }
        else    //存在路径
        {
            s.assign(filename,pathidx+1,filename.size() - pathidx - 1);  //获取文件名
            //cout<<filename<<linenum<<endl;
            filename = s;

            if(filename.size() > 16)  //文件名超过16字符
            {
                s = "";
                s.assign(filename,filename.size() - 16,16);
                filename = s;
            }

            for(j = 0; j < 8; ++j)   //查找是否相同记录
            {
                if(filename == recond[j].filename && linenum == recond[j].linenum)
                {
                    ++(recond[j].num);
                    flag = false;
                    break;
                }
            }

            if(flag)   //新增加记录
            {
                recond[recond_idx].filename = filename;
                recond[recond_idx].linenum = linenum;
                recond[recond_idx].num = 1;
                recond_idx++;
            }
        }

        if(recond_idx == 8)   //循环记录
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