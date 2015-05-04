#include "KNN.h"
#include <math.h>
#include <algorithm>
#include <vector>

KNN::KNN(int k,double data[12][2],std::string label[12]):k(k)
{
    for(int i=0;i<12;i++)
    for(int j=0;j<2;j++)
       dataSet[i][j]=data[i][j];

	for(int i=0;i<12;i++)
		labelSet[i]=label[i];

    for(int i=0;i<collen;i++)
    scanf("%lf",&testSet[i]);
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
        map_index_dis.insert(std::make_pair(j,distance));
    }

    std::map<int,double>::const_iterator iter=map_index_dis.begin();
    printf("\n");
    while(iter!=map_index_dis.end())
    {
        printf("index=%d    distance=%lf\n",iter->first,iter->second);
        iter++;
    }
}


void KNN::get_max_freq_label()
{
    std::vector<PAIR> vec_index_dis(map_index_dis.begin(),map_index_dis.end());
    sort(vec_index_dis.begin(),vec_index_dis.end(),CmpByVal());
    printf("\n");
    for(int i=0;i<k;i++)
    {
        printf("index=%d distance=%lf label=%s the coordinate(%lf,%lf)\n",vec_index_dis[i].first,vec_index_dis[i].second,labelSet[vec_index_dis[i].first].c_str(),dataSet[vec_index_dis[i].first][0],dataSet[vec_index_dis[i].first][1]);
        map_label_freq[labelSet[vec_index_dis[i].first]]++;//value changes 1
    }
    std::map<std::string,int>::iterator iter=map_label_freq.begin();

    int maxfreq=0;
    std::string labelofmax;
    while(iter!=map_label_freq.end())
    {
        if((iter->second)>maxfreq)
        {
            maxfreq=iter->second;
            labelofmax=iter->first;
        }
        iter++;
    }
    printf("\n");
    printf("the test data belongs to the %s label\n",labelofmax.c_str());
}


int main()
{
    int k;
    printf("please input the k value:\n");
    scanf("%d",&k);
    char line[100]={'#'};
    double data[12][2]={0.0};
	std::string label[12];
    FILE* fp;
    fp=fopen("D:\\data.txt","r");
    if(fp==NULL)
        perror("can not open file!");

    int i=0;
    while(fgets(line,100,fp)!=NULL)
    {
        char* subline;
        subline=strtok(line," ");
        int j=0;
        while(subline!=NULL)
        {
            if(strcmp(subline,"\n")!=0)
           {
              if(j<2)
                 {
                     data[i][j++]=atof(subline);
                     printf("%f ",data[i][j-1]);
                 }
              else
                 {
                     label[i]=subline;
                     printf("%s ",label[i].c_str());
                 }
           }
              subline=strtok(NULL," ");
        }
        printf("\n");
        i++;
    }
	   fclose(fp);

    printf("\nplease input testdata:\n");
    KNN knn(k,data,label);
    knn.get_all_distance();
    knn.get_max_freq_label();
    return 0;
}



