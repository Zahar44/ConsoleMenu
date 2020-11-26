#ifndef DATA
#define DATA

#include "field.h"

/// <summary>
///		Contair member first and seconf name
/// </summary>
struct Member
{
	char name[200];
	char sname[200];
};

/// <summary>
///		Add new member to database
/// </summary>
/// <param name="member">members array</param>
void addNewMember(Member*& member);

/// <summary>
///		Delete member from database
/// </summary>
/// <param name="member">members array</param>
void deleteMember(Member*& member);

/// <summary>
///		Show all database and help find
/// </summary>
/// <param name="member">members array</param>
void findMember(Member* member);

/// <summary>
///		Drow all members
/// </summary>
/// <param name="member"></param>
void showMembersList(Member* member);

/// <summary>
///		Create file with all members in directore ./Files/
/// </summary>
/// <param name="member">members array</param>
void exportToFile(Member* member);

/// <summary>
///		Import iformation from txt file
/// </summary>
/// <param name="member">members array</param>
void importfromFile(Member* member);

#endif // !DATA

