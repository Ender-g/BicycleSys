#include "util.h"
#include "menu_print.h"

Bike *head = NULL;
/*----------------------------------*/
void addBike_tool ( int id, const char* brand, const char* model, float price, const char* type, const char* status )
{
	Bike* newBike = ( Bike* ) malloc ( sizeof ( Bike ) );
	newBike->id = id;
	strcpy ( newBike->brand, brand );
	strcpy ( newBike->model, model );
	newBike->price = price;
	strcpy ( newBike->type, type );
	strcpy ( newBike->status, status );
	newBike->rentTime = 0;
	newBike->next = head;
	head = newBike; // 将新节点插入到链表头部
	printf ( "编号为 %d 的自行车已添加。\n", id );
}

void found_tool ( const char* status )
{
	Bike *current = head;
	int found = 0;
	printf ( "编号\t品牌\t\t型号\t\t价格\t\t类型\t\t状态\n" );
	printf ( "---------------------------------------------------------------------------------------\n" );

	while ( current != NULL )
	{
		if ( strcmp ( current->status, status ) == 0 )
		{
			printf ( "%d\t%-10s\t%-10s\t%.2f\t\t%-10s\t%-10s\n",
			         current->id, current->brand, current->model, current->price,
			         current->type, current->status );
			found = 1;
			Sleep ( 1 );
		}

		current = current->next;
	}

	printf ( "---------------------------------------------------------------------------------------\n" );
}

void addBike() // 录入
{
	int id;
	char brand[50], model[50], type[50], status[50];
	float price;
	printHeading ( "|            正在录入            |" );
	printSeparator ( 4 );
	printf ( "输入编号:" );
	scanf ( "%d", &id );
	printf ( "输入品牌:" );
	scanf ( "%s", brand );
	printf ( "输入型号:" );
	scanf ( "%s", model );
	printf ( "输入价格:" );
	scanf ( "%f", &price );
	printf ( "输入类型:" );
	scanf ( "%s", type );
	printf ( "输入状态(可用|维修中|已租赁):" );
	scanf ( "%s", status );
	printSeparator ( 2 );
	addBike_tool ( id, brand, model, price, type, status );
}

void modifyBike() // 修改
{
	int bikeId;
	printHeading ( "|            正在修改            |" );
	printSeparator ( 4 );
	printf ( "输入要修改的自行车编号: " );
	scanf ( "%d", &bikeId );
	printSeparator ( 1 );
	Bike *current = head;

	// 遍历链表查找节点
	while ( current != NULL )
	{
		if ( current->id == bikeId )
		{
			printf ( "当前自行车信息：\n" );
			printf ( "编号: %d\n品牌: %s\n型号: %s\n价格: %.2f\n类型: %s\n状态: %s\n",
			         current->id, current->brand, current->model,
			         current->price, current->type, current->status );
			printSeparator ( 1 );
			printf ( "输入新的信息：\n" );
			char input[50];
			printf ( "新品牌: " );
			scanf ( "%s", input );

			if ( strlen ( input ) > 0 ) strcpy ( current->brand, input );

			printf ( "新型号: " );
			scanf ( "%s", input );

			if ( strlen ( input ) > 0 ) strcpy ( current->model, input );

			printf ( "新价格: " );
			float price;

			if ( scanf ( "%f", &price ) == 1 ) current->price = price;

			printf ( "新类型: " );
			scanf ( "%s", input );

			if ( strlen ( input ) > 0 ) strcpy ( current->type, input );

			printf ( "新状态（可用/维修中/已租赁）: " );
			scanf ( "%s", input );

			if ( strlen ( input ) > 0 ) strcpy ( current->status, input );

			printSeparator ( 2 );
			printf ( "编号为 %d 的自行车信息已更新。\n", bikeId );
			return;
		}

		current = current->next;
	}

	printf ( "未找到编号为 %d 的自行车。\n", bikeId );
}

void printBikes() // 打印
{
	Bike* current = head;

	if ( current == NULL )
	{
		printf ( "\n当前没有自行车信息。\n" );
		return;
	}

	printSubheading ( "所有自行车信息：" );
	printf ( "\n" );
	printf ( "编号\t品牌\t\t型号\t\t价格\t\t类型\t\t状态\n" );
	printf ( "---------------------------------------------------------------------------------------\n" );

	while ( current != NULL )
	{
		printf (
		    "%d\t%-10s\t%-10s\t%.2f\t\t%-10s\t%-10s\n",
		    current->id,
		    current->brand,
		    current->model,
		    current->price,
		    current->type,
		    current->status
		);
		current = current->next;
		Sleep ( 1 );
	}

	printf ( "---------------------------------------------------------------------------------------\n" );
}

void deleteBike() // 删除
{
	int bikeId;
	printHeading ( "|            正在删除            |" );
	printSeparator ( 4 );
	printf ( "输入要删除的自行车编号: " );
	scanf ( "%d", &bikeId );
	Bike *current = head, *previous = NULL;

	// 遍历链表查找节点
	while ( current != NULL )
	{
		if ( current->id == bikeId )
		{
			// 如果是头节点
			if ( previous == NULL )
			{
				head = current->next;
			}

			else
			{
				previous->next = current->next;
			}

			free ( current );
			printSeparator ( 2 );
			printf ( "编号为 %d 的自行车已删除。\n", bikeId );
			return;
		}

		previous = current;
		current = current->next;
	}

	printf ( "未找到编号为 %d 的自行车。\n", bikeId );
}

void searchBike() // 查询
{
	printHeading ( "|            正在查询            |" );
	printSeparator ( 4 );
	int choice;
	printf ( "选择查询条件：\n" );
	printOption ( 1, "编号查询" );
	printOption ( 2, "品牌查询" );
	printOption ( 3, "状态查询" );
	printSeparator ( 1 );
	printf ( "请输入选项: " );
	scanf ( "%d", &choice );
	printSeparator ( 1 );
	Bike *current = head;
	int found = 0;

	if ( choice == 1 )
	{
		int bikeId;
		printf ( "输入编号: " );
		scanf ( "%d", &bikeId );
		printSeparator ( 1 );
		printf ( "查询结果：\n" );
		printf ( "编号\t品牌\t\t型号\t\t价格\t\t类型\t\t状态\n" );
		printf ( "---------------------------------------------------------------------------------------\n" );

		while ( current != NULL )
		{
			if ( current->id == bikeId )
			{
				printf ( "%d\t%-10s\t%-10s\t%.2f\t\t%-10s\t%-10s\n",
				         current->id, current->brand, current->model, current->price,
				         current->type, current->status );
				found = 1;
				break;
			}

			current = current->next;
		}

		printf ( "---------------------------------------------------------------------------------------\n" );
	}

	else if ( choice == 2 )
	{
		char brand[50];
		printf ( "输入品牌: " );
		scanf ( "%s", brand );
		printSeparator ( 1 );
		printf ( "查询结果：\n" );
		printf ( "编号\t品牌\t\t型号\t\t价格\t\t类型\t\t状态\n" );
		printf ( "---------------------------------------------------------------------------------------\n" );

		while ( current != NULL )
		{
			if ( strcmp ( current->brand, brand ) == 0 )
			{
				printf ( "%d\t%-10s\t%-10s\t%.2f\t\t%-10s\t%-10s\n",
				         current->id, current->brand, current->model, current->price,
				         current->type, current->status );
				found = 1;
			}

			current = current->next;
		}

		printf ( "---------------------------------------------------------------------------------------\n" );
	}

	else if ( choice == 3 )
	{
		char status[50];
		printf ( "输入状态（可用/维修中/已租赁）: " );
		scanf ( "%s", status );
		printSeparator ( 1 );
		printf ( "查询结果：\n" );
		printf ( "编号\t品牌\t\t型号\t\t价格\t\t类型\t\t状态\n" );
		printf ( "---------------------------------------------------------------------------------------\n" );

		while ( current != NULL )
		{
			if ( strcmp ( current->status, status ) == 0 )
			{
				printf ( "%d\t%-10s\t%-10s\t%.2f\t\t%-10s\t%-10s\n",
				         current->id, current->brand, current->model, current->price,
				         current->type, current->status );
				found = 1;
			}

			current = current->next;
		}

		printf ( "---------------------------------------------------------------------------------------\n" );
	}

	else
	{
		printf ( "无效的选项。\n" );
		return;
	}

	if ( !found )
	{
		printSeparator ( 1 );
		printf ( "未找到符合条件的自行车。\n" );
		printSeparator ( 1 );
	}
}

void insertBike() // 插入
{
	printHeading ( "|            正在插入            |" );
	printSeparator ( 4 );
	int id;
	char brand[50], model[50], type[50], status[50];
	float price;
	printf ( "输入编号: " );
	scanf ( "%d", &id );
	printf ( "输入品牌: " );
	scanf ( "%s", brand );
	printf ( "输入型号: " );
	scanf ( "%s", model );
	printf ( "输入价格: " );
	scanf ( "%f", &price );
	printf ( "输入类型: " );
	scanf ( "%s", type );
	printf ( "输入状态（可用/维修中/已租赁）: " );
	scanf ( "%s", status );
	Bike *newBike = ( Bike * ) malloc ( sizeof ( Bike ) );
	newBike->id = id;
	strcpy ( newBike->brand, brand );
	strcpy ( newBike->model, model );
	newBike->price = price;
	strcpy ( newBike->type, type );
	strcpy ( newBike->status, status );
	newBike->rentTime = 0;
	newBike->next = NULL;

	// 插入到链表中
	if ( head == NULL || head->id > id )
	{
		newBike->next = head;
		head = newBike;
	}

	else
	{
		Bike *current = head;

		while ( current->next != NULL && current->next->id < id )
		{
			current = current->next;
		}

		newBike->next = current->next;
		current->next = newBike;
	}

	printSeparator ( 2 );
	printf ( "编号为 %d 的自行车已插入。\n", id );
}

/*----------------------------------*/
void sortBikes() // 排序
{
	printHeading ( "|            正在排序            |" );
	printSeparator ( 4 );
	int choice;
	printf ( "\n选择排序方式：\n" );
	printSeparator ( 1 );
	printOption ( 1, "编号排序" );
	printOption ( 2, "价格排序" );
	printSeparator ( 1 );
	printf ( "请输入选项: " );
	scanf ( "%d", &choice );
	printSeparator ( 2 );

	if ( head == NULL || head->next == NULL )
	{
		printf ( "无需排序，链表中没有足够的元素。\n" );
		return;
	}

	Bike *i, *j;

	for ( i = head; i != NULL; i = i->next )
	{
		for ( j = i->next; j != NULL; j = j->next )
		{
			if ( ( choice == 1 && i->id > j->id ) || ( choice == 2 && i->price > j->price ) )
			{
				// 交换节点内容
				int tempId = i->id;
				char tempBrand[50], tempModel[50], tempType[50], tempStatus[50];
				float tempPrice = i->price;
				time_t tempRentTime = i->rentTime;
				strcpy ( tempBrand, i->brand );
				strcpy ( tempModel, i->model );
				strcpy ( tempType, i->type );
				strcpy ( tempStatus, i->status );
				i->id = j->id;
				strcpy ( i->brand, j->brand );
				strcpy ( i->model, j->model );
				i->price = j->price;
				strcpy ( i->type, j->type );
				strcpy ( i->status, j->status );
				i->rentTime = j->rentTime;
				j->id = tempId;
				strcpy ( j->brand, tempBrand );
				strcpy ( j->model, tempModel );
				j->price = tempPrice;
				strcpy ( j->type, tempType );
				strcpy ( j->status, tempStatus );
				j->rentTime = tempRentTime;
			}
		}
	}

	printf ( "成功排序\n" );
}

void calculateStats() // 统计
{
	printHeading ( "|            正在统计            |" );
	printSeparator ( 4 );
	int totalCount = 0;
	float totalPrice = 0.0;
	Bike *current = head;

	while ( current != NULL )
	{
		totalCount++;                   // 统计总数量
		totalPrice += current->price;   // 累加总价格
		current = current->next;
	}

	if ( totalCount == 0 )
	{
		printf ( "当前没有自行车数据。\n" );
		return;
	}

	float averagePrice = totalPrice / totalCount; // 计算平均价格
	printf ( "统计信息：\n" );
	printSeparator ( 1 );
	printf ( "总自行车数量:%d台\n", totalCount );
	printf ( "平均价格:%.2f元\n", averagePrice );
	printSeparator ( 2 );
}

/*----------------------------------*/
void rentBike() // 租赁
{
	printHeading ( "|            正在租赁            |" );
	printSeparator ( 4 );
	int bikeId;
	printf ( "             收费规则             \n" );
	printSeparator ( 3 );
	printf ( "按2￥/时进行收费\n" );
	printf ( "不足一小时的以一小时收费\n" );
	printf ( "于用户租赁时的北京第一时间开始计算\n" );
	printf ( "于用户归还时的北京第一时间截至计算\n" );
	printSeparator ( 1 );
	printf ( "可租赁的自行车\n" );
	found_tool ( "可用" );
	printSeparator ( 3 );
	printf ( "输入要租赁的自行车编号: " );
	scanf ( "%d", &bikeId );
	Bike* current = head;

	while ( current != NULL )
	{
		if ( current->id == bikeId )
		{
			if ( strcmp ( current->status, "可用" ) != 0 )
			{
				printf ( "\n该自行车不可租赁（可能已租赁或维修中）！\n" );
				return;
			}

			// 更新租赁状态和时间
			strcpy ( current->status, "已租赁" );
			current->rentTime = time ( NULL ); // 记录当前时间
			printf ( "\n租赁成功！您已租赁编号为 %d 的自行车。\n", bikeId );
			return;
		}

		current = current->next;
	}

	printf ( "\n未找到编号为 %d 的自行车。\n", bikeId );
}

void returnBike() // 归还
{
	printHeading ( "|            正在归还            |" );
	printSeparator ( 4 );
	int bikeId;
	printf ( "可归还的自行车\n" );
	found_tool ( "已租赁" );
	printf ( "输入要归还的自行车编号: " );
	scanf ( "%d", &bikeId );
	Bike* current = head;

	while ( current != NULL )
	{
		if ( current->id == bikeId )
		{
			if ( strcmp ( current->status, "已租赁" ) != 0 )
			{
				printf ( "\n该自行车未被租赁，无法归还！\n" );
				return;
			}

			// 获取当前时间和租赁时间
			time_t currentTime = time ( NULL );
			time_t rentTime = current->rentTime;

			if ( rentTime == 0 )
			{
				printf ( "\n租赁时间记录错误，无法计算费用。\n" );
				return;
			}

			// 计算租赁时长（以秒为单位）
			double duration = difftime ( currentTime, rentTime );
			int hours = ( int ) ( duration / 3600 ) + ( ( int ) duration % 3600 > 0 ? 1 : 0 ); // 不足 1 小时按 1 小时算
			int fee = hours * 2; // 每小时 2 元
			// 更新自行车状态
			strcpy ( current->status, "可用" );
			current->rentTime = 0; // 清除租赁时间
			printf ( "\n归还成功！编号为 %d 的自行车已归还。\n", bikeId );
			printf ( "租赁时长：%d 小时\n", hours );
			printf ( "总费用：%d 元。\n", fee );
			return;
		}

		current = current->next;
	}

	printf ( "\n未找到编号为 %d 的自行车。\n", bikeId );
}

/*----------------------------------*/
void saveToFile() // 保存
{
	FILE *file = fopen ( "bikes.data", "w" );

	if ( file == NULL )
	{
		printHeading ( "\n无法打开文件\n" );
		return;
	}

	Bike *current = head;

	while ( current != NULL )
	{
		fprintf ( file, "%d %s %s %.2f %s %s\n",
		          current->id, current->brand, current->model,
		          current->price, current->type, current->status );
		current = current->next;
	}

	fclose ( file );
	printHeading ( "\n数据已保存\n" );
}

void loadFromFile() // 读取
{
	FILE *file = fopen ( "bikes.data", "r" );

	if ( file == NULL )
	{
		printHeading ( "\n文件未找到\n" );
		return;
	}

	head = NULL; // 清空当前链表

	while ( !feof ( file ) )
	{
		Bike *newBike = ( Bike * ) malloc ( sizeof ( Bike ) );

		if ( fscanf ( file, "%d %s %s %f %s %s\n",
		              &newBike->id, newBike->brand, newBike->model,
		              &newBike->price, newBike->type, newBike->status ) == 6 )
		{
			newBike->next = head;
			head = newBike; // 插入到链表头部
		}

		else
		{
			free ( newBike );
		}
	}

	fclose ( file );
	printHeading ( "\n数据已加载。\n" );
}

/*----------------------------------*/
void quit_choose()
{
	while ( 1 ) // 退出选择
	{
		printf ( "需要进行最后的保存吗？\n" );
		printf ( "q\t直接退出\ns\t保存并退出\n" );
		printf ( "请输入你的选择(q|s)：" );
		getchar();
		char end_choose = getchar();

		switch ( end_choose )
		{
			case 'q': // 直接退出
				return; // 结束程序

			case 's': // 保存并退出
				saveToFile(); // 保存
				return; // 结束程序

			default: // 输入报错，并回到循环开头
				printf ( "ERROR:NOT_FIND_STR\n\n" ); // 提示错误信息
				system ( "pause" );
				system ( "cls" );
				break;
		}
	}
}
