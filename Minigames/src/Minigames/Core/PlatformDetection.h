#pragma once

#ifdef _WIN32

	/* Windows x64 / x84 */
	#define MG_PLATFORM_WINDOWS

	#ifdef _WIN64
		/* Windows x64*/
		#define MG_PLATFORM_WIN64
	#else 
		/* Windows x86 */
		#define MG_PLATFORM_WIN86
	#endif

#elif defined(__APPLE_) 
	
	/* Apple */
	#define MG_PLATFORM_APPLE
#endif

