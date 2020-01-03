#include "common.h"

BOOL NativeRoutines::InitNativeRoutines(PNATIVE_ROUTINE NativeRoutines, SHORT nNumberOfNativeRoutines)
{
	for (int i = 0; i < nNumberOfNativeRoutines; i++) {
		PCSTR FunctionName = NativeRoutines[i].FunctionName;
		PCSTR ModuleName = NativeRoutines[i].ModuleName;

		HMODULE hModule = LoadLibraryA(ModuleName);

		if (!hModule) {
			return FALSE;
		}

		PVOID RoutineAddress = GetProcAddress(hModule, FunctionName);

		if (!RoutineAddress) {
			return FALSE;
		}

		*(PVOID*)NativeRoutines[i].Routine = RoutineAddress;
	}

	return TRUE;
}