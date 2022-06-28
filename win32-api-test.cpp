#define _WIN32_WINNT _WIN32_WINNT_WIN2K

#include <sdkddkver.h>
#include <windows.h>

#include <iostream>
#include <iomanip>

#pragma warning(disable: 4229)

int main()
{
    auto const kernel32_handle = GetModuleHandleW(L"kernel32.dll");
    auto const kernelbase_handle = GetModuleHandleW(L"kernelbase.dll");

    {
        std::cout << "GetSystemInfo: ";
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        std::cout << std::dec << si.wProcessorArchitecture << std::endl;
    }

    {
        typedef VOID (WINAPI * tGetNativeSystemInfo)(
            _Out_ LPSYSTEM_INFO lpSystemInfo);
        auto const fnGetNativeSystemInfo = reinterpret_cast<tGetNativeSystemInfo>(GetProcAddress(kernel32_handle, "GetNativeSystemInfo"));

        std::cout << "GetNativeSystemInfo: ";
        if (fnGetNativeSystemInfo)
        {
            SYSTEM_INFO nsi;
            fnGetNativeSystemInfo(&nsi);
            std::cout << std::dec << nsi.wProcessorArchitecture << std::endl;
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef BOOL (WINAPI * tGetProcessInformation)(
            _In_ HANDLE hProcess,
            _In_ PROCESS_INFORMATION_CLASS ProcessInformationClass,
            _Out_writes_bytes_(ProcessInformationSize) LPVOID ProcessInformation,
            _In_ DWORD ProcessInformationSize);
        auto const fnGetProcessInformation = reinterpret_cast<tGetProcessInformation>(GetProcAddress(kernel32_handle, "GetProcessInformation"));

        std::cout << "GetProcessInformation(ProcessMachineTypeInfo): ";
        if (fnGetProcessInformation)
        {
            PROCESS_MACHINE_INFORMATION pmi;
            if (!fnGetProcessInformation(GetCurrentProcess(), ProcessMachineTypeInfo, &pmi, sizeof pmi))
                std::cout << "error=" << std::dec << GetLastError() << std::endl;
            else
                std::cout << "ProcessMachine=0x" << std::hex << std::uppercase<< std::setw(4) << std::setfill('0') << pmi.ProcessMachine << ", MachineAttributes=" << std::dec << pmi.MachineAttributes << std::endl;
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef BOOL (WINAPI * tIsWow64Process)(
            _In_ HANDLE hProcess,
            _Out_ PBOOL Wow64Process);
        auto const fnIsWow64Process = reinterpret_cast<tIsWow64Process>(GetProcAddress(kernel32_handle, "IsWow64Process"));

        std::cout << "IsWow64Process: ";
        if (fnIsWow64Process)
        {
            BOOL wow64_process;
            if (!fnIsWow64Process(GetCurrentProcess(), &wow64_process))
                std::cout << "error=" << std::dec << GetLastError() << std::endl;
            else
                std::cout << "wow64Process=" << std::dec << (wow64_process ? "TRUE" : "FALSE") << std::endl;
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef BOOL (WINAPI * tIsWow64Process2)(
            _In_ HANDLE hProcess,
            _Out_ USHORT* pProcessMachine,
            _Out_opt_ USHORT* pNativeMachine);
        auto const fnIsWow64Process2 = reinterpret_cast<tIsWow64Process2>(GetProcAddress(kernel32_handle, "IsWow64Process2"));

        std::cout << "IsWow64Process2: ";
        if (fnIsWow64Process2)
        {
            USHORT process_machine, native_machine;
            if (!fnIsWow64Process2(GetCurrentProcess(), &process_machine, &native_machine))
                std::cout << "error=" << std::dec << GetLastError() << std::endl;
            else
                std::cout << "processMachine=0x" << std::hex << std::uppercase<< std::setw(4) << std::setfill('0') << process_machine << ", nativeMachine=0x" << std::hex << std::uppercase<< std::setw(4) << std::setfill('0') << native_machine << std::endl;
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef UINT (WINAPI * tGetSystemWow64DirectoryW)(
            _Out_writes_to_opt_(uSize,return + 1) LPWSTR lpBuffer,
            _In_ UINT uSize);
        auto const fnGetSystemWow64DirectoryW = reinterpret_cast<tGetSystemWow64DirectoryW>(GetProcAddress(kernel32_handle, "GetSystemWow64DirectoryW"));

        std::cout << "GetSystemWow64DirectoryW: ";
        if (fnGetSystemWow64DirectoryW)
        {
            WCHAR buffer[16384];
            UINT const size = fnGetSystemWow64DirectoryW(buffer, static_cast<UINT>(std::size(buffer)));
            if (size == 0)
                std::cout << "error=" << std::dec << GetLastError() << std::endl;
            else
                std::wcout << L"dir=" << buffer << std::endl;
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef UINT (WINAPI * tGetSystemWow64Directory2W)(
            _Out_writes_to_opt_(uSize,return + 1) LPWSTR lpBuffer,
            _In_ UINT uSize,
            _In_ WORD ImageFileMachineType);
        auto const fnGetSystemWow64Directory2W = reinterpret_cast<tGetSystemWow64Directory2W>(GetProcAddress(kernelbase_handle, "GetSystemWow64Directory2W"));

        std::cout << "GetSystemWow64Directory2W: ";
        if (fnGetSystemWow64Directory2W)
        {
            std::cout << std::endl;
            auto const fn = [fnGetSystemWow64Directory2W] (USHORT machine)
                {
                    std::cout << "  0x" << std::hex << std::uppercase<< std::setw(4) << std::setfill('0') << machine << ": ";
                    WCHAR buffer[16384];
                    UINT const size = fnGetSystemWow64Directory2W(buffer, static_cast<UINT>(std::size(buffer)), machine);
                    if (size == 0)
                        std::cout << "error=" << std::dec << GetLastError() << std::endl;
                    else
                        std::wcout << L"dir=" << buffer << std::endl;
                };

            fn(IMAGE_FILE_MACHINE_TARGET_HOST);
            fn(IMAGE_FILE_MACHINE_I386);
            fn(IMAGE_FILE_MACHINE_AMD64);
            fn(IMAGE_FILE_MACHINE_ARMNT);
            fn(IMAGE_FILE_MACHINE_ARM64);
            fn(IMAGE_FILE_MACHINE_IA64);
        }
        else
            std::cout << "not_impl" << std::endl;
    }

    {
        typedef HRESULT (WINAPI * tIsWow64GuestMachineSupported)(
            _In_ USHORT WowGuestMachine,
            _Out_ BOOL* MachineIsSupported);
        auto const fnIsWow64GuestMachineSupported = reinterpret_cast<tIsWow64GuestMachineSupported>(GetProcAddress(kernelbase_handle, "IsWow64GuestMachineSupported"));

        std::cout << "IsWow64GuestMachineSupported: ";
        if (fnIsWow64GuestMachineSupported)
        {
            std::cout << std::endl;
            auto const fn = [fnIsWow64GuestMachineSupported] (USHORT machine)
                {
                    std::cout << "  0x" << std::hex << std::uppercase<< std::setw(4) << std::setfill('0') << machine << ": ";
                    BOOL machine_is_supported;
                    HRESULT const hr = fnIsWow64GuestMachineSupported(machine, &machine_is_supported);
                    if (FAILED(hr))
                        std::cout << "error=" << std::dec << hr << std::endl;
                    else
                        std::cout << "machineIsSupported=" << std::dec << (machine_is_supported ? "TRUE" : "FALSE") << std::endl;
                };

            fn(IMAGE_FILE_MACHINE_I386);
            fn(IMAGE_FILE_MACHINE_AMD64);
            fn(IMAGE_FILE_MACHINE_ARMNT);
            fn(IMAGE_FILE_MACHINE_ARM64);
            fn(IMAGE_FILE_MACHINE_IA64);
        }
        else
            std::cout << "not_impl" << std::endl;
    }
}
