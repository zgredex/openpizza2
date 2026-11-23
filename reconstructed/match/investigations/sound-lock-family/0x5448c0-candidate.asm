00000000 <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z>:
   0:	6a ff                	push   $0xffffffff
   2:	68 00 00 00 00       	push   $0x0
   7:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
   d:	50                   	push   %eax
   e:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  15:	51                   	push   %ecx
  16:	56                   	push   %esi
  17:	57                   	push   %edi
  18:	8b 7c 24 1c          	mov    0x1c(%esp),%edi
  1c:	8d b7 a0 00 00 00    	lea    0xa0(%edi),%esi
  22:	56                   	push   %esi
  23:	89 74 24 0c          	mov    %esi,0xc(%esp)
  27:	ff 15 00 00 00 00    	call   *0x0
  2d:	8b bf 98 00 00 00    	mov    0x98(%edi),%edi
  33:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
  3a:	00 
  3b:	85 ff                	test   %edi,%edi
  3d:	7d 1c                	jge    5b <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0x5b>
  3f:	56                   	push   %esi
  40:	ff 15 00 00 00 00    	call   *0x0
  46:	8b c7                	mov    %edi,%eax
  48:	5f                   	pop    %edi
  49:	5e                   	pop    %esi
  4a:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  4e:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  55:	83 c4 10             	add    $0x10,%esp
  58:	c2 0c 00             	ret    $0xc
  5b:	8b 44 24 20          	mov    0x20(%esp),%eax
  5f:	85 c0                	test   %eax,%eax
  61:	75 1f                	jne    82 <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0x82>
  63:	56                   	push   %esi
  64:	ff 15 00 00 00 00    	call   *0x0
  6a:	5f                   	pop    %edi
  6b:	b8 06 00 07 80       	mov    $0x80070006,%eax
  70:	5e                   	pop    %esi
  71:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  75:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  7c:	83 c4 10             	add    $0x10,%esp
  7f:	c2 0c 00             	ret    $0xc
  82:	8b 00                	mov    (%eax),%eax
  84:	8b 40 48             	mov    0x48(%eax),%eax
  87:	85 c0                	test   %eax,%eax
  89:	75 04                	jne    8f <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0x8f>
  8b:	32 c0                	xor    %al,%al
  8d:	eb 21                	jmp    b0 <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0xb0>
  8f:	8b 08                	mov    (%eax),%ecx
  91:	8d 54 24 1c          	lea    0x1c(%esp),%edx
  95:	52                   	push   %edx
  96:	50                   	push   %eax
  97:	c7 44 24 24 00 00 00 	movl   $0x0,0x24(%esp)
  9e:	00 
  9f:	ff 51 24             	call   *0x24(%ecx)
  a2:	85 c0                	test   %eax,%eax
  a4:	7d 04                	jge    aa <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0xaa>
  a6:	32 c0                	xor    %al,%al
  a8:	eb 06                	jmp    b0 <?QueryStatusLocked@@YGHPAUSoundBuffer@@PAXPAH@Z+0xb0>
  aa:	8a 44 24 1c          	mov    0x1c(%esp),%al
  ae:	24 01                	and    $0x1,%al
  b0:	8b 4c 24 24          	mov    0x24(%esp),%ecx
  b4:	56                   	push   %esi
  b5:	0f be c0             	movsbl %al,%eax
  b8:	89 01                	mov    %eax,(%ecx)
  ba:	ff 15 00 00 00 00    	call   *0x0
  c0:	5f                   	pop    %edi
  c1:	33 c0                	xor    %eax,%eax
  c3:	8b 4c 24 08          	mov    0x8(%esp),%ecx
  c7:	5e                   	pop    %esi
  c8:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  cf:	83 c4 10             	add    $0x10,%esp
  d2:	c2 0c 00             	ret    $0xc
  d5:	90                   	nop
  d6:	90                   	nop
  d7:	90                   	nop
  d8:	90                   	nop
  d9:	90                   	nop
  da:	90                   	nop
  db:	90                   	nop
  dc:	90                   	nop
  dd:	90                   	nop
  de:	90                   	nop
  df:	90                   	nop
