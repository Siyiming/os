void write(char *tmpname,int tmplength)
{
	int last,i,j;
	strcpy(file[filenumber].name,tmpname);//复制文件名和文件块个数
	file[filenumber].length=tmplength;
	for(i=2;i<N;i++){	//存文件
		if(FAT[i]==0){          
			file[filenumber].start=i;//首个空闲块为文件开始块
			last=i;
			FAT[last]=FFF;
			break;
		}
	}
	for(i=1;i<tmplength;i++){	//last为上个记录的位置
		for(j=2;j<N;j++)
			if(FAT[j]==0){
	FAT[last]=j;	last=j;
FAT[last]=FFF;    break;
			}
	}
	FAT[last]=FFF;//文件末存结束标记
	freespace-=tmplength;//改变空闲块个数
	filenumber++;
	printf("文件名和长度:%s    %d\n",tmpname,tmplength);
}


void insert(char *tmpname,int insertpoint)
{
	int i;
	int last,brpoint;
	for(i=0;i<filenumber;i++)//寻找要执行插入操作的文件，将其数组下标存入last
	{	
		if(strcmp(file[i].name,tmpname)==0)//比较插入文件名与已存在文件名是否相同 
		{
			last=i;
			break;
		}
	}
	brpoint=file[last].start;	//brpoint记录当前文件扫描到的位置
	for(i=0;i<insertpoint-1;i++)
	{ brpoint=FAT[brpoint]; //扫描直到找到插入位置  	}
	for(i=0;i<N;i++)//寻找一个空闲块插入
	{     if(FAT[i]==0)
		{ FAT[i]=FAT[brpoint];
			FAT[brpoint]=i;
			break;
		}
	}
	file[last].length++;	//改变空闲块个数与文件长度
	freespace--;
	printf("\t文件名和长度:%s    %d\n",tmpname,file[last].length);
｝
