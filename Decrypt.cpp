
#include <DMA/Memory/Memory.h>
#include <defs.h>


bool TEST_BITD(uint32_t Value, uint32_t BitPosition) {
	return (Value & (1 << BitPosition)) != 0;
}


uintptr_t Il2cppGetHandle_O = 0xBEB5B60;

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

	__int64* v4; // rdx
	int v5; // r8d
	unsigned int v6; // ecx
	unsigned int v7; // eax
	__int64 v8; // kr00_8
	__int64 v9; // rcx
	__int64 v26; // [rsp+20h] [rbp-28h] BYREF

	v4 = &v26;
	v26 = mem.Read<uintptr_t>(wrapper + 0x18);
	v5 = 2;
	do
	{
		v6 = *(_DWORD*)v4;
		v7 = *(_DWORD*)v4;
		v4 = (__int64*)((char*)v4 + 4);
		v8 = 8i64 * ((((v6 >> 3) | (v7 << 29)) ^ 0x1BD6DA3F) + 812328851);
		*((_DWORD*)v4 - 1) = v8 | HIDWORD(v8);
		--v5;
	} while (v5);
	v9 = v26;

	return Il2cppGetHandle(v26);
}


uintptr_t decrypt_list(uintptr_t pointer)
{
	__int64* v4; // rdx
	int v5; // r8d
	unsigned int v6; // ecx
	unsigned int v7; // eax
	__int64 v8; // rcx
	__int64 v23; // [rsp+20h] [rbp-28h] BYREF

	v4 = &v23;
	v23 = mem.Read<uintptr_t>(pointer + 24);
	v5 = 2;
	do
	{
		v6 = *(_DWORD*)v4;
		v7 = *(_DWORD*)v4;
		v4 = (__int64*)((char*)v4 + 4);
		*((_DWORD*)v4 - 1) = (((v7 << 23) | (v6 >> 9)) - 2051686922) ^ 0x51B6E58C;
		--v5;
	} while (v5);
	v8 = v23;

	return Il2cppGetHandle(v23);
}

auto decrypt_ClActiveItem(std::uint64_t a1) -> std::uint64_t {  // ClActiveItem
	__int64 v3; // rdx
	int* v6; // r8
	int v7; // r9d
	int v8; // eax
	uint64_t v29; // [rsp+20h] [rbp-18h] BYREF

	v6 = (int*)&v29;
	v7 = 2;
	v29 = a1;
	do
	{
		v8 = *v6++;
		v3 = (((v8 + 924573252) << 26) | ((unsigned int)(v8 + 924573252) >> 6)) ^ 0xABDB38BB;
		*(v6 - 1) = v3;
		--v7;
	} while (v7);

	return (uint64_t)v29;
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

auto decrypt_inventory_pointer(std::uint64_t a1) -> std::uint64_t // inventory and eyes
{
	auto il2cpp_object = Il2cppGetHandle((std::int32_t)decrypt_PlayerInventory(mem.Read<std::uint64_t>(a1 + 0x18)));
	return il2cpp_object;
}

