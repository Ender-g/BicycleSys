#include "service.h"

/* 定义文件路径 */
#define K_D "key.DATA"			// 哈希密码
#define K_T "key.TEMP"			// 未加密
#define K_H_T "key_hash.TEMP"	// 哈希
#define pyHash1 "key_hash_1.py"	// 注册加密 key.TEMP->key.DATA
#define pyHash2 "key_hash_2.py"	// 登录加密 key.TEMP->key_hash.TEMP


_Bool enroll_and_login()   // 登录注册
{
	{
		/*伪代码*/
		//if key.DATA为空
		//	让用户输入管理员密码
		//	将管理员密码保存到key.TEMP
		//	调用key_hash_1.py，生成key.DATA
		//	删除key.TEMP
		//	return 1
		//if key.DATA为不为空
		//	让用户输入管理员密码
		//	将管理员密码保存到key.TEMP
		//	调用key_hash_2.py，生成key_hash.TEMP
		//	读取key.DATA和key_hash.TEMP内容
		//	删除key.DATA和key_hash.TEMP
		//	if key.DATA和key_hash.TEMP内容相同（密码正确）
		//		return 1
		//	if key.DATA和key_hash.TEMP内容不同（密码错误）
		//		return 0
	}

	char key[20], key_make_temp[20], hash1[256], hash2[256];
	FILE* k = fopen ( K_D, "r" );

	if ( k == NULL ) // 注册密码
	{
		while ( 1 )
		{
			system ( "cls" );
			printHeading ( "|        单车库存管理系统        |" );
			printSeparator ( 4 );
			FILE* k_temp = fopen ( K_T, "w" );
			printf ( "请 创建 管理员密码:\n" );
			cord ( key );
			printf ( "\n" );
			printSeparator ( 1 );
			printf ( "请 确认 管理员密码:\n" );
			cord ( key_make_temp );

			if ( strcmp ( key, key_make_temp ) == 0 )
			{
				fprintf ( k_temp, "%s", key );
				fclose ( k_temp );
				system ( pyHash1 ); // 加密
				DeleteFile ( K_T ); // 释放缓存文件
				system ( "cls" );
				printHeading ( "|        单车库存管理系统        |" );
				printSeparator ( 4 );
				printSubheading ( "\t恭喜您创建成功!\n\tHi!Admin" );
				printSeparator ( 1 );
				Sleep ( 1000 );
				system ( "cls" );
				return 1;
			}
			else
			{
				fclose ( k_temp );
				DeleteFile ( K_T ); // 释放缓存文件
				system ( "cls" );
				printHeading ( "|        单车库存管理系统        |" );
				printSeparator ( 4 );
				printSubheading ( "两次密码不相同" );
				printSeparator ( 2 );
				system ( "pause" );
			}
		}
	}
	else // 登录
	{
		printHeading ( "|        单车库存管理系统        |" );
		printSeparator ( 4 );
		FILE* k_temp = fopen ( K_T, "w" );
		printf ( "请 输入 管理员密码:\n" );
		cord ( key );
		fprintf ( k_temp, "%s", key );
		fclose ( k_temp );
		system ( pyHash2 );
		DeleteFile ( K_T ); // 释放缓存文件（关闭文件通道）
		FILE* k_hash_temp = fopen ( K_H_T, "r" );
		fscanf ( k, "%s", hash1 );
		fscanf ( k_hash_temp, "%s", hash2 );
		fclose ( k );
		fclose ( k_hash_temp );
		DeleteFile ( K_H_T ); // 释放缓存文件（关闭文件通道）

		if ( strcmp ( hash1, hash2 ) == 0 )
		{
			system ( "cls" );
			printHeading ( "|        单车库存管理系统        |" );
			printSeparator ( 4 );
			printSubheading ( "\t密 码 正 确 !\n\tHi!Admin" );
			printSeparator ( 1 );
			Sleep ( 1000 );
			system ( "cls" );
			return 1;
		}
		else
		{
			system ( "cls" );
			printHeading ( "|        单车库存管理系统        |" );
			printSeparator ( 4 );
			printSubheading ( "\t密 码 错 误 !\n\tSee you!" );
			printSeparator ( 1 );
			Sleep ( 1000 );
			system ( "cls" );
			return 0;
		}
	}
}

void revise_password() // 密码修改（类似注册）
{
	char key[20], key_make_temp[20], hash1[256], hash2[256];
	FILE* k = fopen ( K_D, "r" );

	while ( 1 )
	{
		system ( "cls" );
		printHeading ( "|        单车库存管理系统        |" );
		printSeparator ( 4 );
		FILE* k_temp = fopen ( K_T, "w" );
		printf ( "请 修改 管理员密码:\n" );
		cord ( key );
		printf ( "\n" );
		printSeparator ( 1 );
		printf ( "请 确认 管理员密码:\n" );
		cord ( key_make_temp );

		if ( strcmp ( key, key_make_temp ) == 0 )
		{
			fprintf ( k_temp, "%s", key );
			fclose ( k_temp );
			system ( pyHash1 ); // 加密
			DeleteFile ( K_T ); // 释放缓存文件
			system ( "cls" );
			printHeading ( "|        单车库存管理系统        |" );
			printSeparator ( 4 );
			printSubheading ( "\t恭喜您修改成功!" );
			printSeparator ( 1 );
			Sleep ( 1000 );
			system ( "cls" );
			return;
		}
		else
		{
			fclose ( k_temp );
			DeleteFile ( K_T ); // 释放缓存文件
			system ( "cls" );
			printHeading ( "|        单车库存管理系统        |" );
			printSeparator ( 4 );
			printSubheading ( "两次密码不相同" );
			printSeparator ( 2 );
			system ( "pause" );
		}
	}
}

void cord ( char* str ) // 掩码功能
{
	int i = 0;

	while ( 1 )
	{
		char ch = _getch();		// _getch读取一个字符，但不显示

		if ( ch == '\r' )			// 读取到回车，代表输入完成，加上'\0'
		{
			str[i] = '\0';
			break;
		}
		else if ( ch == '\b' )		// 读取到退格，需要删除一个掩码，并将光标前移
		{
			i--;				// 删除一个字符

			if ( i < 0 ) i = 0;

			printf ( "\b \b" );	// \b :删除一个掩码,\b:光标前移
		}
		else					// 正常输入字符
		{
			str[i] = ch;
			++i;
			printf ( "X" );		// 掩码
		}
	}
}
