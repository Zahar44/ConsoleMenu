#include "field.h"
#include <string.h>

Field** initAllFields() {
	Field** menu = new Field*[2];

	menu[MainMenu] = new Field[6];
	menu[MainMenu][0] = { "Edit database",	  SubMenuId::EditDatabase_m,   false };
	menu[MainMenu][1] = { "Export to file",   SubMenuId::ExportToFile_m,   true  };
	menu[MainMenu][2] = { "Import from file", SubMenuId::ImportFromFile_m, true  };
	menu[MainMenu][3] = { "Exit",             SubMenuId::Exit_m,           false };
	menu[MainMenu][4] = { "*",                SubMenuId::InvEnd_m,         false };

	menu[EditMemberMenu] = new Field[5];
	menu[EditMemberMenu][0] = { "Add new member",   SubMenuId::AddNewMember_m,   true  };
	menu[EditMemberMenu][1] = { "Delete member",    SubMenuId::DeleteMember_m,   true  };
	menu[EditMemberMenu][2] = { "Find member",      SubMenuId::FindMember_m,     true };
	menu[EditMemberMenu][3] = { "Back",             SubMenuId::Back,             false };
	menu[EditMemberMenu][4] = { "*",                SubMenuId::InvEnd_m,         false };

	return menu;

}

void deleteAllFields(Field** menu) {
	size_t i = 0, j = 0;
	while (strcmp(menu[Menu::MainMenu][i++].label, "*")) 
		delete[] menu[j++]; 
	delete[] menu;
}