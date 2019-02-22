cmake_minimum_required(VERSION 3.4.1)
project( licensing )

include_directories( 
	${LuaIncludePath}
	${CORONA_ROOT}/librtt/Corona
)

lua_2_c("${CORONA_ROOT}/plugins/licensing/shared/licensing.lua")
lua_2_c("${CORONA_ROOT}/plugins/licensing/shared/CoronaProvider.licensing.lua")

add_library( licensing SHARED 
				../shared/CoronaLicensingLibrary.cpp
				${Lua2CppOutputDir}/licensing.c
				${Lua2CppOutputDir}/CoronaProvider.licensing.c )

target_link_libraries ( licensing lua corona )
