#ifndef LUA_SCRIPT_H
#define LUA_SCRIPT_H

//For calling functions from a lua file simply call Load and close when done with the file
//For setting variables from a file use Load to open the file, close to close the file and Read_Variable_(var type) to assign variables

extern "C"{
	#include "Lua\lua.h"
	#include "Lua\lualib.h"
	#include "Lua\lauxlib.h"
}
#include <string>
using namespace std;
class lua_Script
{
public:
	lua_Script(void);
	~lua_Script(void);
	void Load(const char* fileName);
	void Close();
	int Read_Variable_Int(const char* varName);
	string Read_Variable_String(const char* varName);

private:
	lua_State*L;

	//int Read_Variable_Int(const char* varName);
};

#endif // lua_Script_h