cmake_minimum_required(VERSION 3.13)
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

if(ANDROID AND (ANDROID_ABI STREQUAL "arm64-v8a" OR ANDROID_ABI STREQUAL "x86_64"))
	# NDK version < 28
	target_link_options(licensing PRIVATE "-Wl,-z,max-page-size=16384")
	# NDK version <= 22
	target_link_options(licensing PRIVATE "-Wl,-z,common-page-size=16384")
endif()
target_link_libraries ( licensing lua corona )
