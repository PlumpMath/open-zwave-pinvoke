#pragma once
// Compilation export flags
#if (defined _WINDOWS || defined WIN32 || defined _MSC_VER) && !defined MINGW
#	if defined OPENZWAVE_MAKEDLL	// Create the dynamic library.
#		define OPENZWAVE_EXPORT    __declspec(dllexport)
#	elif defined OPENZWAVE_USEDLL	// Use the dynamic library
#		define OPENZWAVE_EXPORT    __declspec(dllimport)
#	else							// Create/Use the static library
#		define OPENZWAVE_EXPORT
#	endif
// Disable export warnings
#	define OPENZWAVE_EXPORT_WARNINGS_OFF	__pragma( warning(push) )\
											__pragma( warning(disable: 4251) ) \
											__pragma( warning(disable: 4275) )
#	define OPENZWAVE_EXPORT_WARNINGS_ON		__pragma( warning(pop) )
#else
#	define OPENZWAVE_EXPORT
#	define OPENZWAVE_EXPORT_WARNINGS_OFF
#	define OPENZWAVE_EXPORT_WARNINGS_ON
#endif