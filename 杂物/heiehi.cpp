#include <iostream>
using namespace std;
/*PartSort()函数是进行一次快排的算法。
对于快速排序的一次排序，有很多种算法，我这里列举三种。
[1]左右指针法
1.选取一个关键字(key)作为枢轴，一般取整组记录的第一个数/最后一个，这里采用选取序列最后一个数为枢轴。
2.设置两个变量left = 0;right = N - 1;
3.从left一直向后走，直到找到一个大于key的值，right从后至前，直至找到一个小于key的值，然后交换这两个数。
4.重复第三步，一直往后找，直到left和right相遇，这时将key放置left的位置即可。
提问：下面的代码为什么还要判断left < right？
while(left < right && array[left] <= key)
key是整段序列最后一个，right是key前一个位置，如果array[right]这个位置的值和key相等，
满足array[left] <= key，然后++left,这时候left会走到key的下标处。 
[2]挖坑法
1.选取一个关键字(key)作为枢轴，一般取整组记录的第一个数/最后一个，这里采用选取序列最后一个数为枢轴，也是初始的坑位。
2.设置两个变量left = 0;right = N - 1;
3.从left一直向后走，直到找到一个大于key的值，然后将该数放入坑中，坑位变成了array[left]。
4.right一直向前走，直到找到一个小于key的值，然后将该数放入坑中，坑位变成了array[right]。
5.重复3和4的步骤，直到left和right相遇，然后将key放入最后一个坑位。
[3]前后指针法
1.定义变量cur指向序列的开头，定义变量pre指向cur的前一个位置。
2.当array[cur] < key时，cur和pre同时往后走，如果array[cur]>key，cur往后走，pre留在大于key的数值前一个位置。
3.当array[cur]再次 < key时，交换array[cur]和array[pre]。
通俗一点就是，在没找到大于key值前，pre永远紧跟cur，遇到大的两者之间机会拉开差距，中间差的肯定是连续的大于key的值，当再次遇到小于key的值时，交换两个下标对应的值就好了。
文为CSDN博主「清枫若待佳人醉」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_36528114/article/details/78667034
*/
int PartSort(int* array,int left,int right)
{//基于左右指针法实现的快速排序的一次排序
	int& key = array[right];
	while(left < right)
	{
		while(left < right && array[left] >= key)
		{
			++left;
		}
		while(left < right && array[right] <= key)
		{
			--right;
		}
		swap(array[left],array[right]);
	}
	swap(array[left],key);
	return left;
}
/*快速排序(Quick Sort)是对冒泡排序的一种改进，基本思想是选取一个记录作为枢轴，
经过一趟排序，将整段序列分为两个部分，其中一部分的值都小于枢轴，
另一部分都大于枢轴。然后继续对这两部分继续进行排序，从而使整个序列达到有序。
递归实现：
void QuickSort(int* array,int left,int right)
{
	assert(array);
	if(left >= right)//表示已经完成一个组
	{
		return;
	}
	int index = PartSort(array,left,right);//枢轴的位置
	QuickSort(array,left,index - 1);
	QuickSort(array,index + 1,right);
}*/
void QuickSort(int* array,int left,int right)
{
	if(left >= right)//表示已经完成一个组
	{
		return;
	}
	int index = PartSort(array,left,right);//枢轴的位置
	QuickSort(array,left,index - 1);
	QuickSort(array,index + 1,right);
}
int main()
{
    int a[10]={10,5,9,2,1,3,7,8,33,12};
    QuickSort(a,0,9);// start为a[0],end 为a[9]
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}

