; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
include \masm32\include\masm32rt.inc

.stack 4096
ExitProcess proto,dwExitCode:dword
.data
 
data_buf db "What up nigggaaaaaa %d /g/",0
debug db "eax %08x | ebx %08x | ecx %08x | edx %08x",13,10,0
nNumberOfCharsWritten db 0
crlf db 13,10,0
.code
main proc
	printf(addr debug, eax, ebx, ecx, edx)
	printf(addr debug, eax, ebx, ecx, edx)		
	mov	eax, 5
	push eax
	printf(addr debug, eax, ebx, ecx, edx)
	pop eax
	add	eax, 6
	printf(addr debug, eax, ebx, ecx, edx)
	printf(addr debug, eax, ebx, ecx, edx)
    printf(addr data_buf, eax)		
;	INVOKE  GetStdHandle, STD_OUTPUT_HANDLE
;	printf("eax %d | ebx %d | ecx %d | edx %d \r\n", eax, ebx, ecx, edx)
;	mov     edx, ENABLE_PROCESSED_OUTPUT or ENABLE_WRAP_AT_EOL_OUTPUT
;	printf("eax %d | ebx %d | ecx %d | edx %d \r\n", eax, ebx, ecx, edx)
;	INVOKE  SetConsoleMode,eax,edx
;	printf("eax %d | ebx %d | ecx %d | edx %d \r\n", eax, ebx, ecx, edx)
;   xor ecx, ecx
;	printf("eax %d | ebx %d | ecx %d | edx %d \r\n", eax, ebx, ecx, edx)
;	INVOKE  WriteConsole,ebx, addr data_buf, 12,addr nNumberOfCharsWritten,ecx    
;	printf("eax %d | ebx %d | ecx %d | edx %d \r\n", eax, ebx, ecx, edx)
	
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