00000000 <?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z>:
   0:	6a ff                	push   $0xffffffff
   2:	68 00 00 00 00       	push   $0x0
   7:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
   d:	50                   	push   %eax
   e:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  15:	51                   	push   %ecx
  16:	53                   	push   %ebx
  17:	56                   	push   %esi
  18:	57                   	push   %edi
  19:	8b 7c 24 20          	mov    0x20(%esp),%edi
  1d:	8d b7 a0 00 00 00    	lea    0xa0(%edi),%esi
  23:	56                   	push   %esi
  24:	89 74 24 10          	mov    %esi,0x10(%esp)
  28:	ff 15 00 00 00 00    	call   *0x0
  2e:	8b 5c 24 28          	mov    0x28(%esp),%ebx
  32:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%esp)
  39:	00 
  3a:	c7 03 00 00 00 00    	movl   $0x0,(%ebx)
  40:	8b bf 98 00 00 00    	mov    0x98(%edi),%edi
  46:	85 ff                	test   %edi,%edi
  48:	7d 1d                	jge    67 <?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z+0x67>
  4a:	56                   	push   %esi
  4b:	ff 15 00 00 00 00    	call   *0x0
  51:	8b c7                	mov    %edi,%eax
  53:	5f                   	pop    %edi
  54:	5e                   	pop    %esi
  55:	5b                   	pop    %ebx
  56:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  5a:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  61:	83 c4 10             	add    $0x10,%esp
  64:	c2 0c 00             	ret    $0xc
  67:	8b 44 24 24          	mov    0x24(%esp),%eax
  6b:	85 c0                	test   %eax,%eax
  6d:	75 20                	jne    8f <?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z+0x8f>
  6f:	56                   	push   %esi
  70:	ff 15 00 00 00 00    	call   *0x0
  76:	5f                   	pop    %edi
  77:	5e                   	pop    %esi
  78:	b8 06 00 07 80       	mov    $0x80070006,%eax
  7d:	5b                   	pop    %ebx
  7e:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  82:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  89:	83 c4 10             	add    $0x10,%esp
  8c:	c2 0c 00             	ret    $0xc
  8f:	8b 38                	mov    (%eax),%edi
  91:	8b 47 48             	mov    0x48(%edi),%eax
  94:	85 c0                	test   %eax,%eax
  96:	74 20                	je     b8 <?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z+0xb8>
  98:	8b 08                	mov    (%eax),%ecx
  9a:	8d 54 24 28          	lea    0x28(%esp),%edx
  9e:	52                   	push   %edx
  9f:	8d 54 24 24          	lea    0x24(%esp),%edx
  a3:	52                   	push   %edx
  a4:	50                   	push   %eax
  a5:	ff 51 10             	call   *0x10(%ecx)
  a8:	33 c9                	xor    %ecx,%ecx
  aa:	85 c0                	test   %eax,%eax
  ac:	8b 44 24 20          	mov    0x20(%esp),%eax
  b0:	0f 9c c1             	setl   %cl
  b3:	49                   	dec    %ecx
  b4:	23 c1                	and    %ecx,%eax
  b6:	eb 02                	jmp    ba <?Sound_GetPlayPosition@@YGHPAUSoundBuffer@@PAHPAI@Z+0xba>
  b8:	33 c0                	xor    %eax,%eax
  ba:	33 c9                	xor    %ecx,%ecx
  bc:	33 d2                	xor    %edx,%edx
  be:	66 8b 4f 24          	mov    0x24(%edi),%cx
  c2:	56                   	push   %esi
  c3:	f7 f1                	div    %ecx
  c5:	89 03                	mov    %eax,(%ebx)
  c7:	ff 15 00 00 00 00    	call   *0x0
  cd:	5f                   	pop    %edi
  ce:	5e                   	pop    %esi
  cf:	8b 4c 24 08          	mov    0x8(%esp),%ecx
  d3:	33 c0                	xor    %eax,%eax
  d5:	5b                   	pop    %ebx
  d6:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  dd:	83 c4 10             	add    $0x10,%esp
  e0:	c2 0c 00             	ret    $0xc
  e3:	90                   	nop
  e4:	90                   	nop
  e5:	90                   	nop
  e6:	90                   	nop
  e7:	90                   	nop
  e8:	90                   	nop
  e9:	90                   	nop
  ea:	90                   	nop
  eb:	90                   	nop
  ec:	90                   	nop
  ed:	90                   	nop
  ee:	90                   	nop
  ef:	90                   	nop
