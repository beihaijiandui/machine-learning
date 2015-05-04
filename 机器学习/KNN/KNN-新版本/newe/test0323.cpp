#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[100]={'#'};
    double data[12][2]={0.0};
	char label[12]={'#'};
    FILE* fp;
    fp=fopen("D:\\xcxprograms\\codeblocks\\codeblocksproject\\github\\data.txt","r");
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
                     //printf("%f ",data[i][j-1]);
                 }
              else
                 {
                     label[i]=*subline;
                     //printf("%c ",label[i]);
                 }
           }
              subline=strtok(NULL," ");
        }
        printf("\n");
        i++;
    }
	   fclose(fp);
    //fgets(line,100,fp);
//    for(int j=0;j<i;j++ )
//    printf("%d",data[j]);
//    printf("%lf",data[5]);
	for(int i=0;i<12;i++)
    {for(int j=0;j<2;j++)
        printf("%lf ",data[i][j]);
        printf("\n");}
	for(int i=0;i<12;i++)
		printf("%c ",label[i]);

	//system("pause");
    return 0;
}
