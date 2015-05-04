#include "KNN.h"
#include <math.h>
#include <algorithm>
#include <vector>

KNN::KNN(int k):k(k)
{

    char line[maxlen]={'#'};
    double dataSet[rowlen][collen]={0.0};
    char*   labelSet[rowlen]={NULL};
    double testSet[collen]={0.0};
    //this->k=k;
    FILE* fp;

    /*input training data*/
    fp=fopen("D:\\codeblocksproject\\github\\data.txt","r");
    int i=0;
    while(fgets(line,maxlen,fp)!=NULL)
    {
        char* subline;
        subline=strtok(line," ");
        int j=0;
        while(subline!=NULL)
        {
            if(strcmp(subline,"\n")!=0)
            {
                if(j<2)
                    {dataSet[i][j++]=atof(subline);
                    printf("%fl ",dataSet[i][j-1]);
				    }
                else
                    {labelSet[i]=subline;
                     printf("%s ",labelSet[i]);
                    }
            }
            subline=strtok(NULL," ");
        }
        printf("\n");
        i++;
    }
    fclose(fp);

    /*input test data*/
    printf("\nplease input test data:\n");
    for(int n=0;n<collen;n++)
    {
        scanf("%fl",&testSet[n]);
    }
    printf("%fl %fl\n",testSet[0],testSet[1]);
}


double KNN::get_distance(double* p1,double* p2)
{
   double sum=0;
   for(int i=0;i<collen;i++)
   {
       sum+=pow((p1[i]-p2[i]),2);
   }
   return sqrt(sum);
}


void KNN::get_all_distance()
{
    double distance=0.0;
    for(int j=0;j<rowlen;j++)
    {
        distance=get_distance(dataSet[j],testSet);
        printf("%fl ",distance);
        map_index_dis.insert(std::make_pair(j,distance));
    }

    std::map<int,double>::const_iterator iter=map_index_dis.begin();
    while(iter!=map_index_dis.end())
    {
        printf("index=%d    distance=%fl\n",iter->first,iter->second);
        iter++;
    }
}


void KNN::get_max_freq_label()
{
    std::vector<PAIR> vec_index_dis(map_index_dis.begin(),map_index_dis.end());
    sort(vec_index_dis.begin(),vec_index_dis.end(),CmpByVal());
    for(int i=0;i<k;i++)
    {
        printf("index=%d distance=%fl label=%s the coordinate(%fl,%fl)\n",vec_index_dis[i].first,vec_index_dis[i].second,labelSet[vec_index_dis[i].first],dataSet[vec_index_dis[i].first][0],dataSet[vec_index_dis[i].first][1]);
        map_label_freq[labelSet[vec_index_dis[i].first]]++;//value changes 1
    }
    std::map<char*,int>::const_iterator iter=map_label_freq.begin();

    int maxfreq=0;
    char* labelofmax=NULL;
    while(iter!=map_label_freq.end())
    {
        if(iter->second>maxfreq)
        {
            maxfreq=iter->second;
            labelofmax=iter->first;
        }
        iter++;
    }
    printf("the test data belongs to the %s label\n",labelofmax);
}


int main()
{
    int k;
    printf("please input the k value:\n");
    scanf("%d",&k);
    //printf("\n");
    KNN knn(k);
    knn.get_all_distance();
    knn.get_max_freq_label();
    return 0;
}



