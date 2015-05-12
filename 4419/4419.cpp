#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
#include "source/oj.cpp"


int main()
{
	// freopen("input.txt", "r", stdin);
	BiNode dataa = {'a', NULL, NULL};
    BiNode datab = {'b', NULL, NULL};
    BiNode datac = {'c', NULL, NULL};
    BiNode datad = {'d', NULL, NULL};
    BiNode datae = {'e', NULL, NULL};
    BiNode dataf = {'f', NULL, NULL};
    BiNode datag = {'g', NULL, NULL};
    BiNode datah = {'h', NULL, NULL};
    BiNode datai = {'i', NULL, NULL};
    BiNode dataj = {'j', NULL, NULL};
    BiNode datak = {'k', NULL, NULL};
    BiNode datal = {'l', NULL, NULL};
    BiNode datam = {'m', NULL, NULL};
    BiNode datan = {'n', NULL, NULL};
    BiNode datao = {'o', NULL, NULL};
    BiNode datap = {'p', NULL, NULL};

    dataa.left = &datab;
    dataa.right = &datac;
    datab.left = &datad;
    datab.right = &datae;
    datac.left = &dataf;
    datac.right = &datag;
    datad.left = &datah;
    // datad.right = &datai;
    // datae.left = &dataj;
    // datae.right = &datak;
    // dataf.left = &datal;
    // dataf.right = &datam;
    // datag.left = &datan;
    // datag.right = &datao;
    datah.left = &datap;

    unsigned int ulWidth = 0;
    unsigned int ulHeight = 0;

    cout << GetBiNodeInfo(dataa, &ulWidth, &ulHeight) << endl;
    cout<<ulWidth<<endl;
    cout<<ulHeight<<endl;
	return 0;
}