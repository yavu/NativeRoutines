#pragma once

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

typedef NTSYSAPI NTSTATUS(NTAPI* t_NtReadVirtualMemory)(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	OUT PVOID Buffer,
	IN ULONG BufferLength,
	OUT PULONG ReturnLength OPTIONAL);

extern t_NtReadVirtualMemory NtReadVirtualMemory;