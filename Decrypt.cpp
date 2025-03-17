
#include <DMA/Memory/Memory.h>
#include <defs.h>


bool TEST_BITD(uint32_t Value, uint32_t BitPosition) {
	return (Value & (1 << BitPosition)) != 0;
}


uintptr_t Il2cppGetHandle_O = 0xBEC73C0;

uintptr_t Il2cppGetHandle(int32_t ObjectHandleID) {

	uint64_t rdi_1 = ObjectHandleID >> 3;
	uint64_t rcx_1 = (ObjectHandleID & 7) - 1;
	uint64_t baseAddr = Globals::_GameAssemblyBase + Il2cppGetHandle_O + rcx_1 * 0x28; 
	uint32_t limit = mem.Read<uint32_t>(baseAddr + 0x10);
	if (rdi_1 < limit) {
		uintptr_t objAddr = mem.Read<uintptr_t>(baseAddr);
		uint32_t bitMask = mem.Read<uint32_t>(objAddr + ((rdi_1 >> 5) << 2));
		if (TEST_BITD(bitMask, rdi_1 & 0x1f)) {
			uintptr_t ObjectArray = mem.Read<uintptr_t>(baseAddr + 0x8) + (rdi_1 << 3);
			return mem.Read<BYTE>(baseAddr + 0x14) > 1
				? mem.Read<uintptr_t>(ObjectArray)
				: ~mem.Read<uint32_t>(ObjectArray);
		}
	}
	return 0;
}




uintptr_t networkable_key(uintptr_t wrapper) {
	uint64_t v8, v24;
	uint64_t* v4;
	int v5;
	unsigned int v6, v7;

	v4 = &v24;
	v5 = 2;
	v24 = mem.Read<uint64_t>(wrapper + 24);

	do
	{
		v6 = *(unsigned int*)v4;
		v7 = *(unsigned int*)v4;
		v4 = (uint64_t*)((char*)v4 + 4);
		*((unsigned int*)v4 - 1) = (((v7 << 0x18) | (v6 >> 8)) ^ 0x904C85FC) - 0x6D9808D3;
		--v5;
	} while (v5);

	return Il2cppGetHandle(v24);
}


uintptr_t decrypt_list(uintptr_t pointer)
{
	uint64_t v24;
	uint64_t* v4;
	int v5;
	unsigned int v6, v7;

	v4 = &v24;
	v5 = 2;
	v24 = mem.Read<uint64_t>(pointer + 24);

	do
	{
		v6 = *(unsigned int*)v4;
		v7 = *(unsigned int*)v4;
		v4 = (uint64_t*)((char*)v4 + 4);
		*((unsigned int*)v4 - 1) = ((((v7 << 7) | (v6 >> 0x19)) + 0x20583B3A) << 0x16) | ((((v7 << 7) | (v6 >> 0x19))
			+ 0x20583B3A) >> 0xA);
		--v5;
	} while (v5);

	return Il2cppGetHandle(v24);
}

auto decrypt_ulong(std::uint64_t a1) -> std::uint64_t // clactiveitem
{
	std::uint64_t* v2; // rdx
	int v3; // r8d
	unsigned int v4; // ecx
	unsigned int v5; // eax
	std::uint64_t v9; // [rsp+20h] [rbp-18h] BYREF

	v2 = &v9;
	v9 = a1;
	v3 = 2;

	do
	{
		v4 = *(DWORD*)v2;
		v5 = *(DWORD*)v2;
		v2 = (std::uint64_t*)((char*)v2 + 4);
		*((DWORD*)v2 - 1) = ((((v5 << 13) | (v4 >> 19)) ^ 0xAEB589F8) - 1008461069) ^ 0x9287AD88;
		--v3;
	} while (v3);

	return v9;
}


auto decrypt_PlayerInventory(std::uint64_t a2) -> std::uint64_t {  // PlayerInventory
	signed __int64* a1;
	__int64 v2; // r8
	int v5; // ecx
	bool v6; // zf
	signed __int64 v7; // rcx
	signed __int64 v22; // [rsp+20h] [rbp-28h] BYREF
	a1 = &v22;
	v22 = a2;
	LODWORD(v2) = 2;
	do
	{
		v5 = *(DWORD*)a1;
		a1 = (signed __int64*)((char*)a1 + 4);
		*((DWORD*)a1 - 1) = (((v5 + 1869232143) ^ 0x3AA66D0A) << 21) | (((v5 + 1869232143) ^ 0x3AA66D0Au) >> 11);
		v6 = (DWORD)v2 == 1;
		v2 = (unsigned int)(v2 - 1);
	} while (!v6);
	v7 = v22;
	return v7;
}

