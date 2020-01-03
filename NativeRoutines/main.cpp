#include "common.h"

t_NtReadVirtualMemory NtReadVirtualMemory = NULL;

int main() {

	NativeRoutines::NATIVE_ROUTINE NativeRoutines[] =
	{
		{"NtReadVirtualMemory", "ntdll.dll", &NtReadVirtualMemory}
	};

	SHORT nNumberOfNativeRoutines = sizeof(NativeRoutines) / sizeof(NativeRoutines::NATIVE_ROUTINE);

	BOOL bInitialized = NativeRoutines::InitNativeRoutines(NativeRoutines, nNumberOfNativeRoutines);

	if (!bInitialized) {
		printf("[-] Failed to initialize the native routines.\n");
		return FALSE;
	}

	printf("[+] The Native routines have been initialized.\n");

	int iValue = 1337;
	int iValueRead = 0;

	NTSTATUS status = NtReadVirtualMemory(GetCurrentProcess(), &iValue, &iValueRead, sizeof(int), 0);

	if (NT_SUCCESS(status)) {
		printf("Value read: %i\n", iValueRead);
		return TRUE;
	}

	printf("[-] NtReadVirtualMemory failed with error %ul\n", status);

	return FALSE;
}