#include "import.h"

#ifndef UTIL_H
#define UTIL_H

/* 声明结构体 */
typedef struct Bike
{
	/*----------------------------------------------------------*/
	int		id;				/* 自行车编号						*/
	char	brand[50];		/* 品牌								*/
	char	model[50];		/* 型号								*/
	float	price;			/* 价格								*/
	char	type[50];		/* 类型（公路车/山地车/电动车...）	*/
	char	status[50];		/* 状态（可用/维修中）				*/
	time_t	rentTime;		/* 租赁时间（Unix 时间戳）			*/
	/*----------------------------------------------------------*/
	struct Bike* next;		/* 指向下一个节点					*/
	/*----------------------------------------------------------*/
} Bike;

extern Bike *head; // 链表头指针

/* 声明函数 */
/*----------------------------------*/
void addBike_tool		/*录入工具	*/
(                                   //
    int			id,					//
    const char*	brand,				//
    const char*	model,				//
    float		price,				//
    const char*	type,				//
    const char*	status				//
);									//
void found_tool			/*查找工具	*/
(                                   //
    const char* status  			//
);									//
/*- - - - - - - - - - - - - - - - - */
void addBike();			/* 录入		*/
void modifyBike();		/* 修改		*/
void deleteBike();		/* 删除		*/
void searchBike();		/* 查询		*/
void printBikes();		/* 打印		*/
void insertBike();		/* 插入		*/
/*- - - - - - - - - - - - - - - - - */
void sortBikes();		/* 排列		*/
void calculateStats();	/* 统计		*/
/*- - - - - - - - - - - - - - - - - */
void rentBike();		/* 租赁		*/
void returnBike();		/* 归还		*/
/*- - - - - - - - - - - - - - - - - */
void saveToFile();		/* 保存		*/
void loadFromFile();	/* 读取		*/
/*- - - - - - - - - - - - - - - - - */
void quit_choose();		/* 退出选择	*/
/*----------------------------------*/

#endif
