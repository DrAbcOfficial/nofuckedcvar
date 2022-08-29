#pragma once


#define IMPORT_FUNCTION_DLSYM(dll, name) name = (decltype(name))DLSYM((DLHANDLE)dll, #name);\
if (!name)\
{\
	LOG_ERROR(PLID, "Failed to get " #name " from " #dll " dll !");\
	return FALSE;\
}

#ifdef _WIN32

#define ENGINE_DLL_NAME "hw.dll"

#else

#ifndef _ARRAYSIZE
#define _ARRAYSIZE(A)   (sizeof(A)/sizeof((A)[0]))
#endif

#define ENGINE_DLL_NAME "hw.so"

#endif
