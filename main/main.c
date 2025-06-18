#include "miku.h"		// Miku镇楼,BUG辟易 ✿ヽ(°▽°)ノ✿
#include "import.h"		// C标准库
#include "util.h"		// 数据处理
#include "menu_print.h"	// 目录美化
#include "service.h"	// 管理员登录
#include "menu.h"		// 目录

int main()
{
	/*--------------------------------------------*/
	{
		//					/* 登录&注册 */
		int pass_num = enroll_and_login();

		if ( !pass_num ) return 0;
	}

	/*--------------------------------------------*/
	loadFromFile();			/* 初始化数据 */
	system ( "cls" );
	int choice;

	/*--------------------------------------------*/
	while ( 1 )
	{
		menu();
		scanf ( "%d", &choice );

		switch ( choice )
		{
			/*----------------------------------*/
			case 1:			/* 录入 */
			{
				system ( "cls" );
				addBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;
			}

			case 2:			/* 修改 */
				system ( "cls" );
				modifyBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			case 3:			/* 删除 */
				system ( "cls" );
				deleteBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			case 4:			/* 查询 */
				system ( "cls" );
				searchBike();
				system ( "pause" );
				system ( "cls" );
				break;

			case 5:			/* 打印 */
				system ( "cls" );
				printBikes();
				system ( "pause" );
				system ( "cls" );
				break;

			case 6:			/* 插入 */
				system ( "cls" );
				insertBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			/*----------------------------------*/
			case 7:			/* 排序 */
				system ( "cls" );
				sortBikes();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			case 8:			/* 统计 */
				system ( "cls" );
				calculateStats();
				system ( "pause" );
				system ( "cls" );
				break;

			/*----------------------------------*/
			case 9:			/* 租赁 */
				system ( "cls" );
				rentBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			case 10:		/* 归还 */
				system ( "cls" );
				returnBike();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			/*----------------------------------*/
			case 11:		/* 保存 */
				system ( "cls" );
				saveToFile();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			case 12:		/* 读取 */
				system ( "cls" );
				loadFromFile();
				Sleep ( 1000 );
//				system("pause");
				system ( "cls" );
				break;

			/*----------------------------------*/
			case 0:			/* 退出 */
				system ( "cls" );
				quit_choose();
				Sleep ( 500 );
				return 0;

			case -1:		/* 改密码 */
				system ( "cls" );
				revise_password();
				Sleep ( 1000 );
				break;

			/*----------------------------------*/
			case 114514:	/* Debug<不要管这个> */
				printf ( "debug......" );
				system ( "key.DATA" );
				system ( "cls" );
				break;

			default:
				system ( "cls" );
				printf ( "\n无效的选择！\n" );
				Sleep ( 1000 );
				system ( "cls" );
		}
	}
}

