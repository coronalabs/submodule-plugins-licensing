//////////////////////////////////////////////////////////////////////////////
//
// This file is part of the Corona game engine.
// For overview and more information on licensing please refer to README.md 
// Home page: https://github.com/coronalabs/corona
// Contact: support@coronalabs.com
//
//////////////////////////////////////////////////////////////////////////////

#include "CoronaLicensingLibrary.h"

#include "CoronaAssert.h"
#include "CoronaLibrary.h"

// ----------------------------------------------------------------------------

CORONA_EXPORT int CoronaPluginLuaLoad_licensing( lua_State * );
CORONA_EXPORT int CoronaPluginLuaLoad_CoronaProvider_licensing( lua_State * );

// ----------------------------------------------------------------------------

static const char kProviderName[] = "CoronaProvider.licensing";

CORONA_EXPORT
int luaopen_licensing( lua_State *L )
{
	using namespace Corona;

	Corona::Lua::RegisterModuleLoader(
		L, kProviderName, Corona::Lua::Open< CoronaPluginLuaLoad_CoronaProvider_licensing > );

	lua_CFunction factory = Corona::Lua::Open< CoronaPluginLuaLoad_licensing >;
	int result = CoronaLibraryNewWithFactory( L, factory, NULL, NULL );

	return result;
}

// ----------------------------------------------------------------------------
