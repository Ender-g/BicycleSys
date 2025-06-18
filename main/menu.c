/* 目录 */
#include "menu.h"
#include "menu_print.h"

void menu()
{
	printHeading ( "|        单车库存管理系统        |" );
	printSeparator ( 4 );
	printOption ( 1, " 录入自行车信息" );
	printOption ( 2, " 修改自行车信息" );
	printOption ( 3, " 删除自行车信息" );
	printOption ( 4, " 查询自行车信息" );
	printOption ( 5, " 打印自行车信息" );
	printOption ( 6, " 插入自行车信息" );
	printSeparator ( 1 );
	printOption ( 7, " 排序" );
	printOption ( 8, " 数据统计" );
	printSeparator ( 1 );
	printOption ( 9, " 租赁自行车" );
	printOption ( 10, "归还自行车" );
	printSeparator ( 1 );
	printOption ( 11, "保存自行车信息" );
	printOption ( 12, "读取自行车信息" );
	printSeparator ( 1 );
	printOption ( 0, " 退出系统" );
	printOption ( -1, "更改密码" );
	printSeparator ( 3 );
	printf ( "请选择功能: " );
}
