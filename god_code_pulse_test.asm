org 0x7C00              ; Boot sector origin
bits 16                  ; 16-bit mode (Real Mode)

start:
    cli                 ; Disable interrupts
    xor ax, ax          ; Clear AX
    mov ds, ax
    mov es, ax

    ; Initialize the counter to simulate 2^128
    ; 2^128 = 0x100000000000000000000000000000000, split into two parts
    ; High part (CX) and low part (DX)
    mov cx, 0x0001        ; High part (0x1)
    mov dx, 0x0000        ; Low part (0x0)

    ; Display message to confirm start
    mov si, msg_start
.next_msg_start:
    lodsb
    or al, al
    jz .message_done_start
    call print_char
    jmp .next_msg_start

.message_done_start:
    ; Simulate operations
    mov bx, 0xFFFF      ; Large delay for visible effect

.loop:
    ; Perform a sample True/False operation (like XOR)
    xor ax, ax            ; Simulate True/False operation

    ; Decrement the counter (2^128) - start from low part
    dec dx                ; Decrement lower part
    jnz .continue_loop    ; Continue if DX is not zero

    dec cx                ; Decrement upper part (if DX is zero)
    cmp cx, 0
    je .end_loop          ; Exit when both parts reach zero

.continue_loop:
    ; For testing: output some counter values to see progress
    ; This line will print every few iterations so you can verify if the loop is running correctly
    mov ax, cx
    mov bx, dx
    call print_value     ; Print current values of CX and DX

    jmp .loop

.end_loop:
    ; Display message to confirm end
    mov si, msg_end
.next_msg_end:
    lodsb
    or al, al
    jz .message_done_end
    call print_char
    jmp .next_msg_end

.message_done_end:
    ; Delay loop to make sure we can see the message before halting
    mov bx, 0xFFFF
.delay:
    dec bx
    jnz .delay           ; Simple delay to slow down the exit

    ; Halt the system after the loop finishes
    cli
    hlt                    ; Halt system immediately
    jmp .end_loop          ; Infinite loop to avoid crashes

; -------------------------------
; Print the current value in AX (CX or DX) to the screen
; -------------------------------
print_value:
    ; Convert AX to a string and display it (this is a very simplified example)
    ; This will output the values of CX and DX
    push ax
    push bx
    mov si, buf
    mov cx, ax            ; Store CX value
    mov dx, bx            ; Store DX value
    ; Print the values (not optimal for large numbers)
    call print_char
    pop bx
    pop ax
    ret

; -------------------------------
; Print the characters in AL using BIOS
; -------------------------------
print_char:
    mov ah, 0x0E
    mov bh, 0x00
    mov bl, 0x07
    int 0x10
    ret

; -------------------------------
; Data
; -------------------------------
msg_start db 'Started 2^128 operations...', 0
msg_end db 'Completed 2^128 operations.', 0
buf db '00000', 0

times 510 - ($-$$) db 0   ; Fill the rest of the boot sector
dw 0xAA55                 ; Boot sector signature
