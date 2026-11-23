
game/fastfood2.exe:     file format pei-i386


Disassembly of section .text:

00544760 <.text+0x143760>:
  544760:	6a ff                	push   $0xffffffff
  544762:	68 98 b3 55 00       	push   $0x55b398
  544767:	64 a1 00 00 00 00    	mov    %fs:0x0,%eax
  54476d:	50                   	push   %eax
  54476e:	64 89 25 00 00 00 00 	mov    %esp,%fs:0x0
  544775:	51                   	push   %ecx
  544776:	53                   	push   %ebx
  544777:	56                   	push   %esi
  544778:	57                   	push   %edi
  544779:	8b 7c 24 20          	mov    0x20(%esp),%edi
  54477d:	8d b7 a0 00 00 00    	lea    0xa0(%edi),%esi
  544783:	56                   	push   %esi
  544784:	89 74 24 10          	mov    %esi,0x10(%esp)
  544788:	ff 15 b8 c1 55 00    	call   *0x55c1b8
  54478e:	8b 5c 24 28          	mov    0x28(%esp),%ebx
  544792:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%esp)
  544799:	00 
  54479a:	c7 03 00 00 00 00    	movl   $0x0,(%ebx)
  5447a0:	8b bf 98 00 00 00    	mov    0x98(%edi),%edi
  5447a6:	85 ff                	test   %edi,%edi
  5447a8:	7d 1d                	jge    0x5447c7
  5447aa:	56                   	push   %esi
  5447ab:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  5447b1:	8b c7                	mov    %edi,%eax
  5447b3:	5f                   	pop    %edi
  5447b4:	5e                   	pop    %esi
  5447b5:	5b                   	pop    %ebx
  5447b6:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  5447ba:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  5447c1:	83 c4 10             	add    $0x10,%esp
  5447c4:	c2 0c 00             	ret    $0xc
  5447c7:	8b 44 24 24          	mov    0x24(%esp),%eax
  5447cb:	85 c0                	test   %eax,%eax
  5447cd:	75 20                	jne    0x5447ef
  5447cf:	56                   	push   %esi
  5447d0:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  5447d6:	5f                   	pop    %edi
  5447d7:	5e                   	pop    %esi
  5447d8:	b8 06 00 07 80       	mov    $0x80070006,%eax
  5447dd:	5b                   	pop    %ebx
  5447de:	8b 4c 24 04          	mov    0x4(%esp),%ecx
  5447e2:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  5447e9:	83 c4 10             	add    $0x10,%esp
  5447ec:	c2 0c 00             	ret    $0xc
  5447ef:	8b 38                	mov    (%eax),%edi
  5447f1:	8b 47 48             	mov    0x48(%edi),%eax
  5447f4:	85 c0                	test   %eax,%eax
  5447f6:	74 1e                	je     0x544816
  5447f8:	8b 08                	mov    (%eax),%ecx
  5447fa:	8d 54 24 28          	lea    0x28(%esp),%edx
  5447fe:	52                   	push   %edx
  5447ff:	8d 54 24 24          	lea    0x24(%esp),%edx
  544803:	52                   	push   %edx
  544804:	50                   	push   %eax
  544805:	ff 51 10             	call   *0x10(%ecx)
  544808:	33 c9                	xor    %ecx,%ecx
  54480a:	85 c0                	test   %eax,%eax
  54480c:	8b 44 24 20          	mov    0x20(%esp),%eax
  544810:	0f 9c c1             	setl   %cl
  544813:	49                   	dec    %ecx
  544814:	23 c1                	and    %ecx,%eax
  544816:	33 c9                	xor    %ecx,%ecx
  544818:	33 d2                	xor    %edx,%edx
  54481a:	66 8b 4f 24          	mov    0x24(%edi),%cx
  54481e:	56                   	push   %esi
  54481f:	f7 f1                	div    %ecx
  544821:	89 03                	mov    %eax,(%ebx)
  544823:	ff 15 a0 c1 55 00    	call   *0x55c1a0
  544829:	5f                   	pop    %edi
  54482a:	5e                   	pop    %esi
  54482b:	8b 4c 24 08          	mov    0x8(%esp),%ecx
  54482f:	33 c0                	xor    %eax,%eax
  544831:	5b                   	pop    %ebx
  544832:	64 89 0d 00 00 00 00 	mov    %ecx,%fs:0x0
  544839:	83 c4 10             	add    $0x10,%esp
  54483c:	c2                   	.byte 0xc2
  54483d:	0c                   	.byte 0xc
