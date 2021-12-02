/*
    模拟链表
    输入：
        9
        2 3 5 8 9 10 18 26 32
        6
    输出：
        2 3 5 6 8 9 10 18 26 32
    输入：
        3
        1 3 5
        7
    输出：1 3 5
*/
/*
# include <stdio.h>

int main(void)
{
    int data[101], right[101];
    int i, n, t, len;

    //读入已有的数
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &data[i]);
    }
    len = n;

    //初始化数组right
    for (i = 1; i <= n; ++i)
    {
        if (i != n)
        {
            right[i] = i+1;
        }
        else
        {
            right[i] = 0;
        }
    }

    //直接在数组data的末尾增加一个数
    len++;
    scanf("%d", &data[len]);

    //从链表的头部开始遍历
    t = 1;
    while(t != 0)
    {
        if (data[right[t]] > data[len]) // 如果当前节点下一个节点的值大于待插入数，
        //将数插入到中间
        {
            right[len] = right[t]; //新插入数的下一个节点标号等于当前
            //节点的下一个节点编号
            right[t] = len; //当前节点的下一个节点编号就是新插入数的编号
            break; // 插入完成跳出循环
        }
        t = right[t];
    }
    //输出链表中所有的数
    t = 1;
    while(t != 0)
    {
        printf("%d ", data[t]);
        t = right[t];
    }
    
    return 0;
}
*/

/*
核心思路：查找是否存在一个节点的下一个节点的数据大于待插入的节点，即data[right[t]]>data[len]
如果找到了，就修改right指针域。最后根据right指针域打印其数据域的值
*/
#include <stdio.h>
int data[101];
int right[101];//每个节点都有一个指针域，所以这里的数组长度要和data数组一样长
int main(){
	/*n为用户首次录入的节点总数，用于控制初始化节点时的循环次数
	len为当前节点总数，为方便操作，data[0]和right[0]不放内容，从下标1开始遍历，因此data[len]就是最后一个元素
	*/
    int n,i,len,t;
    int flag = 1;
    scanf("%d",&n);
    //初始化数组data
    for(i = 1;i<=n;i++){
        scanf("%d",&data[i]);
    }
    len = n;
    //初始化数组right
    for(i = 0;i<=n;i++){
        if(i!=n){
            right[i] = i+1;
        }else{
            right[i] = 0;//用0表示没有下一个元素
        }
    }
    //在data的末尾添加一个数
    len++;
    scanf("%d",&data[len]);
    /*
    通过遍历指针域，当找到某个节点的数据值大于插入的节点data[len]时，调整指针域的指向。
    直到指针域遍历完成为止
    */
    t = 1;
    //对插入节点小于第一个节点的情况做特殊处理。（这里放在if..else里是出于无需再走循环的目的）
    if(data[len]<data[1]){
    	right[0] = len;
    	right[len] = 1;
	}else{
		while(t!=0){
        	if(data[right[t]]>data[len]){
            	flag = 0;
            	right[len] = right[t];
            	right[t] = len;
           	 break; 
        	}
        	t = right[t];
    	}
    	//插入节点大于最后一个节点的情况 
    	if(flag == 1){
   		     right[len] = 0;
        	/*这里只做简单处理，也可以查找right[t]==0的节点修改其指针域，
       		 只需在上面循环中加入if(right[t]==0){temp = t;}
       		 这里再改成right[temp] = len;
        	*/
        	right[len-1] = len;
    	}
	}
	//t为right[0]头节点指向的首节点的下标 
    t = right[0];
    while(t!=0){
        printf("%d ",data[t]);
        t = right[t];
    }
    //等待用户键盘录入，以起到暂停程序目的
    getchar();
    getchar();
    return 0;
}
