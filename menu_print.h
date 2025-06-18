#include "import.h"

#ifndef MENU_PRINT_H
#define MENU_PRINT_H

void printHeading ( const char *heading );				// 打印标题
void printSubheading ( const char *subheading );		// 打印子标题
void printOption ( int index, const char *option );	// 打印选项
void printSeparator();								// 打印分割线

#endif
