#ifndef FIELD
#define FIELD


enum SubMenuId { InvEnd_m, EditDatabase_m, ExportToFile_m, ImportFromFile_m, Exit_m, ShowAllMembers_m, AddNewMember_m, DeleteMember_m, FindMember_m, Back };

enum Menu
{
	MainMenu, EditMemberMenu
};

/// <summary>
///		Field witch contair label name, id, answer 
/// </summary>
struct Field
{
	const char* label;
	size_t id;
	bool isInputTable;
	char answer[200];
};
/// <summary>
///		Initialization all fields
/// </summary>
/// <returns> menu[][] </returns>
Field** initAllFields();
/// <summary>
///		Free space
/// </summary>
/// <param name="menu">menu array</param>
void deleteAllFields(Field** menu);

#endif // !FIELD



