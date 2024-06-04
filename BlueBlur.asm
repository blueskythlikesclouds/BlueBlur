.model flat
.code

; This file contains stub constructors/destructors 
; that jump to the original game code.

; To add your own, provide no implementation
; in the header and implement the function here
; using the mangled name the linker outputs when
; it complains about unresolved externals.

; You cannot use proc/endp as it inserts 
; an underscore to the beginning of function names.

; This file can be compiled by running BlueBlur.py
; through Visual Studio or Developer Command Prompt.

??1CMessageActor@Universe@Hedgehog@@UAE@XZ:
    mov eax, 768660h
    jmp eax

??1CUpdateUnit@Universe@Hedgehog@@UAE@XZ:
    mov eax, 76A8E0h
    jmp eax

??1CStateBase@CStateMachineBase@Universe@Hedgehog@@UAE@XZ:
    mov eax, 76D720h
    jmp eax

??1CStateMachineBase@Universe@Hedgehog@@UAE@XZ:
    mov eax, 76E2F0h
    jmp eax

??1CGameObjectModel@Sonic@@UAE@XZ:
    push edi
    push ecx
    mov edi, ecx
    mov eax, 11D1730h
    call eax
    pop ecx
    pop edi
    retn
    
??1CGameObjectRigidBody@Sonic@@UAE@XZ:
    mov eax, 1106C70h
    jmp eax

??1CGameObject3D@Sonic@@UAE@XZ:
    mov eax, 0D5D790h
    jmp eax

??1CGameObject@Sonic@@UAE@XZ:
    mov eax, 0D60110h
    jmp eax

??0CGameObjectCSD@Sonic@@QAE@MVCStringSymbol@Base@Hedgehog@@@Z:
    mov eax, ecx
    mov ecx, 10DBBC0h
    jmp ecx

??0CGameObjectCSD@Sonic@@QAE@V?$RCPtr@VCProject@CSD@Chao@@@CSD@Chao@@MVCStringSymbol@Base@Hedgehog@@_N@Z:
    mov eax, ecx
    mov ecx, 10DBB20h
    jmp ecx

??1CGameObjectCSD@Sonic@@UAE@XZ:
    mov eax, 10DBA90h
    jmp eax

??1RCObject@RCPtrAbs@CSD@Chao@@UAE@XZ:
    mov eax, 41C1F0h
    jmp eax

??0SArchiveParam@Database@Hedgehog@@QAE@HI@Z:
    mov eax, 446F90h
    jmp eax

??1SArchiveParam@Database@Hedgehog@@QAE@XZ:
    mov eax, 446E30h
    jmp eax

??0CArchiveList@Database@Hedgehog@@QAE@XZ:
    mov eax, 6AA7D0h
    jmp eax

??1CArchiveList@Database@Hedgehog@@QAE@XZ:
    mov eax, 69D9D0h
    jmp eax

??0CDecompressCAB@Database@Hedgehog@@QAE@XZ:
    mov eax, 6A0FC0h
    jmp eax

??1CDecompressCAB@Database@Hedgehog@@QAE@XZ:
    mov eax, 6A1760h
    jmp eax

??0COptimalBundle@Mirage@Hedgehog@@QAE@XZ:
    mov eax, 71B940h
    jmp eax

??0CBundle@Mirage@Hedgehog@@QAE@XZ:
    mov eax, 6FA910h
    jmp eax

public ??1CMessageActor@Universe@Hedgehog@@UAE@XZ
public ??1CUpdateUnit@Universe@Hedgehog@@UAE@XZ
public ??1CStateBase@CStateMachineBase@Universe@Hedgehog@@UAE@XZ
public ??1CStateMachineBase@Universe@Hedgehog@@UAE@XZ
public ??1CGameObjectModel@Sonic@@UAE@XZ
public ??1CGameObjectRigidBody@Sonic@@UAE@XZ
public ??1CGameObject3D@Sonic@@UAE@XZ
public ??1CGameObject@Sonic@@UAE@XZ
public ??0CGameObjectCSD@Sonic@@QAE@MVCStringSymbol@Base@Hedgehog@@@Z
public ??0CGameObjectCSD@Sonic@@QAE@V?$RCPtr@VCProject@CSD@Chao@@@CSD@Chao@@MVCStringSymbol@Base@Hedgehog@@_N@Z
public ??1CGameObjectCSD@Sonic@@UAE@XZ
public ??1RCObject@RCPtrAbs@CSD@Chao@@UAE@XZ
public ??0SArchiveParam@Database@Hedgehog@@QAE@HI@Z
public ??1SArchiveParam@Database@Hedgehog@@QAE@XZ
public ??0CArchiveList@Database@Hedgehog@@QAE@XZ
public ??1CArchiveList@Database@Hedgehog@@QAE@XZ
public ??0CDecompressCAB@Database@Hedgehog@@QAE@XZ
public ??1CDecompressCAB@Database@Hedgehog@@QAE@XZ
public ??0COptimalBundle@Mirage@Hedgehog@@QAE@XZ
public ??0CBundle@Mirage@Hedgehog@@QAE@XZ

end