#ifndef EXPORT_DEFINE
#define EXPORT_DEFINE

#ifdef _MSC_VER
	#ifdef ALGORITHM_EXPORT
		#define ALGORITHM_API __declspec(dllexport)
	#else
		#define ALGORITHM_API __declspec(dllimport)
	#endif
#endif // _MSC_VER

#if __GNUC__
	#ifdef COMMON2_DLL
		#define COMMON2_API __attribute__((visibility("default")))
	#else
		#define COMMON2_API __attribute__((visibility("default")))
	#endif
#endif // __GNUC__
#endif