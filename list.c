#include<iostream>
#include<list>
using namespace std;
void out(list<int>);
int main()
{
	list<int> il;
	for (int i = 0; i < 10; i++)
		il.push_back(i);

	il.push_front(-1);
	out(il);

	list<int>::iterator it = il.begin();
	list<int>::iterator it2;
	it2 = il.insert(it, -2); /*前为iterator，后为同类型元素，*/
	out(il);         /*将后者插入前者地址之前，并返回一个iterator，指向被插入的元素*/

	*it2 = -3;
	out(il);

	il.pop_front(); /*删除最前端元素*/
	out(il);

	it = il.end();
	il.insert(it, 5, 10);  /*在前者地址之前插入n个元素，无返回值*/
	out(il);

	list<int>il2 = { 11, 12, 13 };
	it = il.end();
	it--; it--; it--; it--;/*我宣布这是迭代器最睿智的设计*/
	il.insert(it, il2.begin(), il2.end());/*在地址之前插入[first,last)范围的元素*/
	out(il);

	it = il.end(); it--;
	it2 = il.erase(it); /*删除iterator所指的元素，并返回其地址（黑人问号？？？）*/
	out(il);

	it2--; it2--; it2--;
	it = il.end(); it--;
	list<int>::iterator it3;
	it3 = il.erase(it2, it);/*删除[first,last)的元素，返回first地址，元素会自动填补空缺*/
	out(il);

	return 0;
}
void out(list<int> il)
{
	for (int z : il)
		cout << z << ' ';
	cout << '\n';
}
