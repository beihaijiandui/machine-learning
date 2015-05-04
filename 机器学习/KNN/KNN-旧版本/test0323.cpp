#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[100]={'#'};
    double data[100][2]={0.0};
    char* label[100]={NULL};
    FILE* fp;
    fp=fopen("D:\\codeblocksproject\\github\\data.txt","r");
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
                     printf("%s ",label[i]);
                 }
           }
              subline=strtok(NULL," ");
        }
        printf("\n");
        i++;
    }
    //fgets(line,100,fp);
//    for(int j=0;j<i;j++ )
//    printf("%d",data[j]);
//    printf("%lf",data[5]);
    fclose(fp);
    return 0;
}
