#ifndef DROWV2
#define DROWV2

#include "data.h"
#include "field.h"
/// <summary>
///		Put cursore higher
/// </summary>
void up();
/// <summary>
///		Put cursore down
/// </summary>
void down();
/// <summary>
///		Opens the menu
/// </summary>
void forward();

/// <summary>
///		Main func
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menu">fields array</param>
/// <param name="member">members array</param>
void chekField(int& _x, int& _y, Field** menu, Member*& member);

/// <summary>
///		Drow inform menu
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menu">fields array</param>
/// <param name="menuCnt">count of menus</param>
void drowInfMenu(int& _x, int& _y, Field** menu, size_t& menuCnt);

/// <summary>
///		Menu animation
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menu">fields array</param>
/// <param name="menuCnt">count of menus</param>
void menuAnim(int& _x, int& _y, Field** menu, size_t menuCnt);

/// <summary>
///		Menu overrun 
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menuCnt">count of menus</param>
void menuOverrun(int& _x, int& _y, size_t menuCnt);

/// <summary>
///		Drow frame around inf menu
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menu">fields array</param>
/// <param name="menuCnt">count of menus</param>
void drowFrame(int _x, int _y, Field* menu, size_t menuCnt);

/// <summary>
///		Drow menu with inputable table
/// </summary>
/// <param name="_x">relative x coord</param>
/// <param name="_y">relative y coord</param>
/// <param name="menu">fields array</param>
/// <param name="member">members array</param>
/// <param name="menuCnt">count of menus</param>
void drowWithInput(int& _x, int& _y, Field** menu, Member*& member, size_t& menuCnt);

/// <summary>
///		Check with input menu drow
/// </summary>
/// <param name="menu">fields array</param>
/// <param name="member">members array</param>
void inputData(Field** menu, Member*& member);

/// <summary>
///		Change menu
/// </summary>
/// <param name="menu">fields array</param>
void changeMenu(Field** menu);

/// <summary>
///		Find max length label
/// </summary>
/// <param name="menu">fields array</param>
/// <returns>length</returns>
size_t findMaxLen(Field* menu);

/// <summary>
///		Find menu count
/// </summary>
/// <param name="menu">fields array</param>
/// <returns>menu count</returns>
size_t findMenuCnt(Field** menu);
#endif // !DROWV2

