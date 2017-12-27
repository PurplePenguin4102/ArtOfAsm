; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
include \masm32\include\masm32rt.inc
;.486
;.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
 
data_buf db "What up nigggaaaaaa %d /g/",0
crlf db 13,0
.code
main proc
	mov	eax, 5
	add	eax, 6
    ;INVOKE  GetStdHandle, STD_OUTPUT_HANDLE
	;mov     edx, ENABLE_PROCESSED_OUTPUT or ENABLE_WRAP_AT_EOL_OUTPUT
	;INVOKE  SetConsoleMode,eax,edx
	;INVOKE  WriteConsole,ebx,lpBuffer,nChars,addr nNumberOfCharsWritten,ecx
	printf("Sup biatch %d", eax)
	
	invoke ExitProcess,0
main endp
end main

;***********************************************************************************************

;awConOut PROC USES EBX lpBuffer:LPVOID,nChars:DWORD

;UNICODE aware Console Output - DednDave, 4-2013

;  Returns: EAX = number of characters written

;--------------------------------------------

;    LOCAL   dwOrigModeOut         :DWORD
;    LOCAL   nNumberOfCharsWritten :DWORD

;--------------------------------------------

;    INVOKE  GetStdHandle,STD_OUTPUT_HANDLE
;    xchg    eax,ebx
;    INVOKE  GetConsoleMode,ebx,addr dwOrigModeOut
;    mov     edx,ENABLE_PROCESSED_OUTPUT or ENABLE_WRAP_AT_EOL_OUTPUT
;    .if edx!=dwOrigModeOut
;        INVOKE  SetConsoleMode,ebx,edx
;    .endif
;    xor     ecx,ecx
;    mov     nNumberOfCharsWritten,ecx
;    INVOKE  WriteConsole,ebx,lpBuffer,nChars,addr nNumberOfCharsWritten,ecx
;    mov     edx,dwOrigModeOut
;    .if edx!=(ENABLE_PROCESSED_OUTPUT or ENABLE_WRAP_AT_EOL_OUTPUT)
;        INVOKE  SetConsoleMode,ebx,edx
;    .endif
;    mov     eax,nNumberOfCharsWritten
;    ret

awConOut ENDP

;***********************************************************************************************