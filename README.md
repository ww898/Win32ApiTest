### Win32 API tester

ARM64 process on Windows ARM64
```
GetSystemInfo: 12
GetNativeSystemInfo: 12
GetProcessInformation(ProcessMachineTypeInfo): ProcessMachine=0xAA64, MachineAttributes=3
IsWow64Process: wow64Process=FALSE
IsWow64Process2: processMachine=0x0000, nativeMachine=0xAA64
GetSystemWow64DirectoryW: dir=C:\Windows\SysWOW64
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: error=160
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: error=160
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=TRUE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

ARM process on Windows ARM64
```
GetSystemInfo: 5
GetNativeSystemInfo: 12
GetProcessInformation(ProcessMachineTypeInfo): ProcessMachine=0x01C4, MachineAttributes=5
IsWow64Process: wow64Process=TRUE
IsWow64Process2: processMachine=0x01C4, nativeMachine=0xAA64
GetSystemWow64DirectoryW: dir=C:\Windows\SysArm32
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: error=160
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: error=160
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=TRUE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

X64 process on Windows ARM64
```
GetSystemInfo: 9
GetNativeSystemInfo: 9
GetProcessInformation(ProcessMachineTypeInfo): ProcessMachine=0x8664, MachineAttributes=1
IsWow64Process: wow64Process=FALSE
IsWow64Process2: processMachine=0x0000, nativeMachine=0xAA64
GetSystemWow64DirectoryW: dir=C:\Windows\SysWOW64
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: error=160
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: error=160
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=TRUE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

X86 process on Windows ARM64
```
GetSystemInfo: 0
GetNativeSystemInfo: 9
GetProcessInformation(ProcessMachineTypeInfo): ProcessMachine=0x014C, MachineAttributes=5
IsWow64Process: wow64Process=TRUE
IsWow64Process2: processMachine=0x014C, nativeMachine=0xAA64
GetSystemWow64DirectoryW: dir=C:\Windows\SysWOW64
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: error=160
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: error=160
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=TRUE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

X64 process on Windows X64
```
GetSystemInfo: 9
GetNativeSystemInfo: 9
GetProcessInformation(ProcessMachineTypeInfo): error=87
IsWow64Process: wow64Process=FALSE
IsWow64Process2: processMachine=0x0000, nativeMachine=0x8664
GetSystemWow64DirectoryW: dir=C:\Windows\SysWOW64
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: dir=C:\Windows\SysX8664
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: dir=C:\Windows\SysArm64
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=FALSE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

X86 process on Windows X64

```
GetSystemInfo: 0
GetNativeSystemInfo: 9
GetProcessInformation(ProcessMachineTypeInfo): error=87
IsWow64Process: wow64Process=TRUE
IsWow64Process2: processMachine=0x014C, nativeMachine=0x8664
GetSystemWow64DirectoryW: dir=C:\Windows\SysWOW64
GetSystemWow64Directory2W: 
  0x0001: dir=C:\Windows\system32
  0x014C: dir=C:\Windows\SysWOW64
  0x8664: dir=C:\Windows\SysX8664
  0x01C4: dir=C:\Windows\SysArm32
  0xAA64: dir=C:\Windows\SysArm64
  0x0200: error=160
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=TRUE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=FALSE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```

X86 process on Windows X86
```
GetSystemInfo: 0
GetNativeSystemInfo: 0
GetProcessInformation(ProcessMachineTypeInfo): error=87
IsWow64Process: wow64Process=FALSE
IsWow64Process2: processMachine=0x0000, nativeMachine=0x014C
GetSystemWow64DirectoryW: error=120
GetSystemWow64Directory2W: 
  0x0001: error=120
  0x014C: error=120
  0x8664: error=120
  0x01C4: error=120
  0xAA64: error=120
  0x0200: error=120
IsWow64GuestMachineSupported: 
  0x014C: machineIsSupported=FALSE
  0x8664: machineIsSupported=FALSE
  0x01C4: machineIsSupported=FALSE
  0xAA64: machineIsSupported=FALSE
  0x0200: machineIsSupported=FALSE
```