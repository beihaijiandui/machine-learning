#ifndef KNN_H_INCLUDED
#define KNN_H_INCLUDED
#include <stdio.h>
#include <string.h>//c”Ô—‘◊÷∑˚¥Æ¥¶¿Ì
#include <stdlib.h>
#include <map>
#include <string>  //c++string¿‡

typedef std::pair<int,double> PAIR;
const int collen=2;
const int rowlen=12;
const int maxlen=100;

class KNN
{
public:
    KNN(int k,double data[][2],std::string label[]);
    void get_all_distance();
    void get_max_freq_label();
    struct CmpByVal
    {
        bool operator()(const PAIR& p1,const PAIR& p2)
        {
            return p1.second<p2.second;
        }
    };
private:
    int k;
    char line[maxlen];
    double dataSet[rowlen][collen];
    std::string   labelSet[rowlen];
    double testSet[collen];
    std::map<int,double> map_index_dis;
    std::map<std::string,int> map_label_freq;
    double get_distance(double* p1,double* p2);
};



#endif // KNN_H_INCLUDED
