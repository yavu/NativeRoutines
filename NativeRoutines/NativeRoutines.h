#pragma once

namespace NativeRoutines {

	typedef struct _NATIVE_ROUTINE {
		LPCSTR FunctionName;
		LPCSTR ModuleName;
		LPVOID Routine;
	} NATIVE_ROUTINE, * PNATIVE_ROUTINE;

	BOOL InitNativeRoutines(PNATIVE_ROUTINE NativeRoutines, SHORT nNumberOfNativeRoutines);
}