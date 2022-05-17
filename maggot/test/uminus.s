	.text
	.file	"uminus.cpp"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %main
	movl	%edi, -8(%rsp)
	movl	%esi, -4(%rsp)
	movl	$1, -12(%rsp)
	movl	$0, -16(%rsp)
	.p2align	4, 0x90
.LBB0_1:                                # %COND
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_4 Depth 2
	cmpl	$3, -12(%rsp)
	jl	.LBB0_5
# %bb.2:                                # %LOOP
                                        #   in Loop: Header=BB0_1 Depth=1
	movl	$1, -16(%rsp)
	cmpl	$5, -12(%rsp)
	jl	.LBB0_1
	.p2align	4, 0x90
.LBB0_4:                                # %LOOP5
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	$5, -16(%rsp)
	cmpl	$5, -12(%rsp)
	jge	.LBB0_4
	jmp	.LBB0_1
.LBB0_5:                                # %ENDLOOP
	movl	-16(%rsp), %eax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.section	".note.GNU-stack","",@progbits
