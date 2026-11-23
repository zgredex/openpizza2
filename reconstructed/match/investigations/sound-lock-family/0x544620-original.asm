
game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00544620 <.text+0x143620>:
  544620:	6a ff                	push   $0xffffffff
  544622:	68 78 b3 55 00       	push   $0x55b378
  544627:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  54462d:	50                   	push   %eax
  54462e:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  544635:	51                   	push   %ecx
  544636:	53                   	push   %ebx
  544637:	56                   	push   %esi
  544638:	8b f1                	mov    %ecx,%esi
  54463a:	57                   	push   %edi
  54463b:	8b 7e 38             	mov    0x38(%esi),%edi
  54463e:	57                   	push   %edi
  54463f:	89 7c 24 10          	mov    %edi,0x10(%esp)
  544643:	ff 15 b8 c1 55 00    	call   *0x55c1b8
  544649:	33 db                	xor    %ebx,%ebx
  54464b:	88 5e 54             	mov    %bl,0x54(%esi)
  54464e:	8a 46 53             	mov    0x53(%esi),%al
  544651:	3a c3                	cmp    %bl,%al
  544653:	89 5c 24 18          	mov    %ebx,0x18(%esp)
  544657:	75 1e                	jne    0x544677
  544659:	57                   	push   %edi
  54465a:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  544660:	5f                   	pop    %edi
  544661:	5e                   	pop    %esi
  544662:	b8 01 00 00 00       	mov    $0x1,%eax
  544667:	5b                   	pop    %ebx
  544668:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  54466c:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  544673:	83 c4 10             	add    $0x10,%esp
  544676:	c3                   	ret
  544677:	b0 01                	mov    $0x1,%al
  544679:	88 5e 53             	mov    %bl,0x53(%esi)
  54467c:	89 9e 84 00 00 00    	mov    %ebx,0x84(%esi)
  544682:	88 86 88 00 00 00    	mov    %al,0x88(%esi)
  544688:	38 5e 58             	cmp    %bl,0x58(%esi)
  54468b:	74 03                	je     0x544690
  54468d:	88 46 57             	mov    %al,0x57(%esi)
  544690:	8b 76 28             	mov    0x28(%esi),%esi
  544693:	8b 46 48             	mov    0x48(%esi),%eax
  544696:	3b c3                	cmp    %ebx,%eax
  544698:	75 07                	jne    0x5446a1
  54469a:	be 06 00 07 80       	mov    $0x80070006,%esi
  54469f:	eb 37                	jmp    0x5446d8
  5446a1:	8b 08                	mov    (%eax),%ecx
  5446a3:	50                   	push   %eax
  5446a4:	ff 51 48             	call   *0x48(%ecx)
  5446a7:	85 c0                	test   %eax,%eax
  5446a9:	7d 07                	jge    0x5446b2
  5446ab:	be 05 40 00 80       	mov    $0x80004005,%esi
  5446b0:	eb 26                	jmp    0x5446d8
  5446b2:	38 5e 34             	cmp    %bl,0x34(%esi)
  5446b5:	74 07                	je     0x5446be
  5446b7:	8b ce                	mov    %esi,%ecx
  5446b9:	e8 a2 c8 ff ff       	call   0x540f60
  5446be:	8b 76 48             	mov    0x48(%esi),%esi
  5446c1:	53                   	push   %ebx
  5446c2:	56                   	push   %esi
  5446c3:	8b 16                	mov    (%esi),%edx
  5446c5:	ff 52 34             	call   *0x34(%edx)
  5446c8:	33 c9                	xor    %ecx,%ecx
  5446ca:	85 c0                	test   %eax,%eax
  5446cc:	0f 9d c1             	setge  %cl
  5446cf:	49                   	dec    %ecx
  5446d0:	81 e1 05 40 00 80    	and    $0x80004005,%ecx
  5446d6:	8b f1                	mov    %ecx,%esi
  5446d8:	57                   	push   %edi
  5446d9:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  5446df:	8b 4c 24 10          	mov    0x10(%esp),%ecx
  5446e3:	8b c6                	mov    %esi,%eax
  5446e5:	5f                   	pop    %edi
  5446e6:	5e                   	pop    %esi
  5446e7:	5b                   	pop    %ebx
  5446e8:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  5446ef:	83 c4 10             	add    $0x10,%esp
