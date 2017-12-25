void search(char *tmpname){
       int i;
   for(i=0;i<filenumber;i++)
	{	
		if(strcmp(file[i].name,tmpname)==0)//比较插入文件名与已存在文件名是否相同 
		{  
           printf("\t找到了!\n");
		   printf("\t文件名  起始块号  文件长度\n");
		   printf("   %s       %d       %d\n",file[i].name,file[i].start,file[i].length); 
		}
	}	
}

void search2(int searchpoint)
{  int i;    int m;
    if(FAT[searchpoint]==0)
    printf("\t该点空缺,没有文件!"); 
	else if(FAT[searchpoint]==-1&&FAT[searchpoint-1]==-2||FAT[searchpoint]==-2&&FAT[searchpoint+1]==-1)
	{	printf("\t此处为系统空间!");		}
	else if(FAT[searchpoint]==-1&&FAT[searchpoint+1]==0)
	{ printf("\t找到了!此处的文件名为:%s",file[i].name);  	}
	else if(FAT[searchpoint]!=0&&FAT[searchpoint+1]!=-1)
	{    
        for(m=searchpoint;;m++)
		{
		if(FAT[m]==-1)
		printf("\t找到了!此处的文件名为:%s",file[i].name);
		break;
		}
	}
	else if(FAT[searchpoint]!=0&&FAT[searchpoint+1]==-1)
	{    
		printf("找到了!此处的文件名为:%s",file[i].name);
	}
}
