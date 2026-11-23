00000000 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ>:
   0:	6a ff                	push   $0xffffffff
   2:	68 00 00 00 00       	push   $0x0
   7:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
   d:	50                   	push   %eax
   e:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  15:	51                   	push   %ecx
  16:	53                   	push   %ebx
  17:	56                   	push   %esi
  18:	8b f1                	mov    %ecx,%esi
  1a:	57                   	push   %edi
  1b:	8b 7e 38             	mov    0x38(%esi),%edi
  1e:	57                   	push   %edi
  1f:	89 7c 24 10          	mov    %edi,0x10(%esp)
  23:	ff 15 00 00 00 00    	call   *0x0
  29:	8a 46 53             	mov    0x53(%esi),%al
  2c:	33 db                	xor    %ebx,%ebx
  2e:	3a c3                	cmp    %bl,%al
  30:	89 5c 24 18          	mov    %ebx,0x18(%esp)
  34:	88 5e 54             	mov    %bl,0x54(%esi)
  37:	75 1e                	jne    57 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0x57>
  39:	57                   	push   %edi
  3a:	ff 15 00 00 00 00    	call   *0x0
  40:	5f                   	pop    %edi
  41:	5e                   	pop    %esi
  42:	b8 01 00 00 00       	mov    $0x1,%eax
  47:	5b                   	pop    %ebx
  48:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  4c:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  53:	83 c4 10             	add    $0x10,%esp
  56:	c3                   	ret
  57:	8a 4e 58             	mov    0x58(%esi),%cl
  5a:	b0 01                	mov    $0x1,%al
  5c:	3a cb                	cmp    %bl,%cl
  5e:	88 5e 53             	mov    %bl,0x53(%esi)
  61:	89 9e 88 00 00 00    	mov    %ebx,0x88(%esi)
  67:	88 86 8c 00 00 00    	mov    %al,0x8c(%esi)
  6d:	74 03                	je     72 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0x72>
  6f:	88 46 59             	mov    %al,0x59(%esi)
  72:	8b 76 28             	mov    0x28(%esi),%esi
  75:	8b 46 48             	mov    0x48(%esi),%eax
  78:	3b c3                	cmp    %ebx,%eax
  7a:	75 07                	jne    83 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0x83>
  7c:	be 06 00 07 80       	mov    $0x80070006,%esi
  81:	eb 37                	jmp    ba <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0xba>
  83:	8b 08                	mov    (%eax),%ecx
  85:	50                   	push   %eax
  86:	ff 51 48             	call   *0x48(%ecx)
  89:	85 c0                	test   %eax,%eax
  8b:	7d 07                	jge    94 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0x94>
  8d:	be 05 40 00 80       	mov    $0x80004005,%esi
  92:	eb 26                	jmp    ba <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0xba>
  94:	38 5e 34             	cmp    %bl,0x34(%esi)
  97:	74 07                	je     a0 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0xa0>
  99:	8b ce                	mov    %esi,%ecx
  9b:	e8 00 00 00 00       	call   a0 <?StopPlaybackLocked@SoundBuffer@@QAEHXZ+0xa0>
  a0:	8b 76 48             	mov    0x48(%esi),%esi
  a3:	53                   	push   %ebx
  a4:	56                   	push   %esi
  a5:	8b 16                	mov    (%esi),%edx
  a7:	ff 52 34             	call   *0x34(%edx)
  aa:	33 c9                	xor    %ecx,%ecx
  ac:	85 c0                	test   %eax,%eax
  ae:	0f 9d c1             	setge  %cl
  b1:	49                   	dec    %ecx
  b2:	81 e1 05 40 00 80    	and    $0x80004005,%ecx
  b8:	8b f1                	mov    %ecx,%esi
  ba:	57                   	push   %edi
  bb:	ff 15 00 00 00 00    	call   *0x0
  c1:	8b 4c 24 10          	mov    0x10(%esp),%ecx
  c5:	8b c6                	mov    %esi,%eax
  c7:	5f                   	pop    %edi
  c8:	5e                   	pop    %esi
  c9:	5b                   	pop    %ebx
  ca:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  d1:	83 c4 10             	add    $0x10,%esp
  d4:	c3                   	ret
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
