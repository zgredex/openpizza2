
game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

005448c0 <.text+0x1438c0>:
  5448c0:	6a ff                	push   $0xffffffff
  5448c2:	68 b8 b3 55 00       	push   $0x55b3b8
  5448c7:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  5448cd:	50                   	push   %eax
  5448ce:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  5448d5:	51                   	push   %ecx
  5448d6:	56                   	push   %esi
  5448d7:	8b 74 24 18          	mov    0x18(%esp),%esi
  5448db:	57                   	push   %edi
  5448dc:	8d be a0 00 00 00    	lea    0xa0(%esi),%edi
  5448e2:	57                   	push   %edi
  5448e3:	89 7c 24 0c          	mov    %edi,0xc(%esp)
  5448e7:	ff 15 b8 c1 55 00    	call   *0x55c1b8
  5448ed:	8b b6 98 00 00 00    	mov    0x98(%esi),%esi
  5448f3:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
  5448fa:	00 
  5448fb:	85 f6                	test   %esi,%esi
  5448fd:	7d 1c                	jge    0x54491b
  5448ff:	57                   	push   %edi
  544900:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  544906:	8b c6                	mov    %esi,%eax
  544908:	5f                   	pop    %edi
  544909:	5e                   	pop    %esi
  54490a:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  54490e:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  544915:	83 c4 10             	add    $0x10,%esp
  544918:	c2 0c 00             	ret    $0xc
  54491b:	8b 44 24 20          	mov    0x20(%esp),%eax
  54491f:	85 c0                	test   %eax,%eax
  544921:	75 1f                	jne    0x544942
  544923:	57                   	push   %edi
  544924:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  54492a:	5f                   	pop    %edi
  54492b:	b8 06 00 07 80       	mov    $0x80070006,%eax
  544930:	5e                   	pop    %esi
  544931:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  544935:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  54493c:	83 c4 10             	add    $0x10,%esp
  54493f:	c2 0c 00             	ret    $0xc
  544942:	8b 00                	mov    (%eax),%eax
  544944:	8b 40 48             	mov    0x48(%eax),%eax
  544947:	85 c0                	test   %eax,%eax
  544949:	75 04                	jne    0x54494f
  54494b:	32 c0                	xor    %al,%al
  54494d:	eb 21                	jmp    0x544970
  54494f:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  544953:	c7 44 24 1c 00 00 00 	movl   $0x0,0x1c(%esp)
  54495a:	00 
  54495b:	8b 08                	mov    (%eax),%ecx
  54495d:	52                   	push   %edx
  54495e:	50                   	push   %eax
  54495f:	ff 51 24             	call   *0x24(%ecx)
  544962:	85 c0                	test   %eax,%eax
  544964:	7d 04                	jge    0x54496a
  544966:	32 c0                	xor    %al,%al
  544968:	eb 06                	jmp    0x544970
  54496a:	8a 44 24 1c          	mov    0x1c(%esp),%al
  54496e:	24 01                	and    $0x1,%al
  544970:	8b 4c 24 24          	mov    0x24(%esp),%ecx
  544974:	57                   	push   %edi
  544975:	88 01                	mov    %al,(%ecx)
  544977:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  54497d:	5f                   	pop    %edi
  54497e:	33 c0                	xor    %eax,%eax
  544980:	8b 4c 24 08          	mov    0x8(%esp),%ecx
  544984:	5e                   	pop    %esi
  544985:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  54498c:	83 c4 10             	add    $0x10,%esp
  54498f:	c2                   	.byte 0xc2
  544990:	0c                   	.byte 0xc
