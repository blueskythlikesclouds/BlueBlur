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

public ??1CMessageActor@Universe@Hedgehog@@UAE@XZ
public ??1CUpdateUnit@Universe@Hedgehog@@UAE@XZ
public ??1CStateBase@CStateMachineBase@Universe@Hedgehog@@UAE@XZ
public ??1CStateMachineBase@Universe@Hedgehog@@UAE@XZ
public ??1CGameObjectModel@Sonic@@UAE@XZ
public ??1CGameObjectRigidBody@Sonic@@UAE@XZ
public ??1CGameObject3D@Sonic@@UAE@XZ
public ??1CGameObject@Sonic@@UAE@XZ

end