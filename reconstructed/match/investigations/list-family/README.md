# List family pilot

This is the first list-family batch after the cleanup inventory showed
`List_Node_Destroy` (`0x401480`) in 43 functions covering 36,931 indexed
bytes. The pilot proves the family recipe on the small, already-matched list
primitives and adds one new strict match.

## Result

```text
list-operations: 6/7 strict, 466/632 bytes
  0x401480  43   List_Node_Destroy      strict
  0x4014b0 251   List_Add               strict (new)
  0x4f1370  59   List_AppendNode        strict (new)
  0x539e00  32   List_PushFront         strict
  0x541250  51   List_FreeAll           strict
  0x544af0 166   List_RemoveNodeLocked  1 byte remaining
  0x545b00  30   List_ContainerDestroy  strict
```

Cold run compiles seven objects; a warm run reuses all seven with no compiler
invocation.

## New strict matches: `List_Add` and `List_AppendNode`

### `List_Add` (`0x4014b0`, 251 bytes)

Source: `reconstructed/match/batch19/part4/0x4014b0.cpp`

The reconstruction is:

```cpp
struct CriticalSection {
    char storage[0x58];
    void Enter();
    void Leave();
};

extern CriticalSection g_listLock;

struct List {
    char pad[4];
    int *arrayA;
    int *arrayB;
    int count;
    int capacity;
    int field14;
    int field18;

    int Add(int value);
};

int List::Add(int value)
{
    g_listLock.Enter();
    if (count >= capacity) {
        if (arrayA == 0) {
            arrayA = (int *)operator new(0x50);
            arrayB = (int *)operator new(0x50);
        } else {
            int *newA = (int *)operator new(capacity * 4 + 0x50);
            memcpy(newA, arrayA, capacity * 4);
            int *newB = (int *)operator new(capacity * 4 + 0x50);
            memcpy(newB, arrayB, capacity * 4);
            operator delete(arrayA);
            arrayA = newA;
            operator delete(arrayB);
            arrayB = newB;
        }
        capacity += 0x14;
    }
    arrayA[count] = value;
    arrayB[count] = field18;
    ++field18;
    ++count;
    ++field14;
    g_listLock.Leave();
    return field18 - 1;
}
```

Important source details:

- `if (count >= capacity)` is the operand order that produces the shipped
  `cmp count,capacity; jl`. The reverse `if (capacity <= count)` emits
  `cmp capacity,count; jg` and leaves a 2-byte difference.
- `memcpy` is recognised by VC6 without a pragma and inlines to
  `rep movsl` + `rep movsb`; the size is `capacity * 4`.
- The arrays grow by `0x14` entries, but allocation is `capacity * 4 + 0x50`
  (the old bytes plus the growth tail).
- The global lock is `0x579af0`; `Enter`/`Leave` are `0x401320`/`0x401340`.

Reproduce:

```sh
sh reconstructed/match/batch19/part4/verify_strict.sh
# strict 1 / 1

python3 tools/match_decomp.py 0x4014b0 \
  reconstructed/match/batch19/part4/0x4014b0.cpp \
  --length 251 --entry '?Add@List@@QAEHH@Z' \
  --flags '/O2 /TP' --strict --auto-symbols \
  --symbol '?g_listLock@@3UCriticalSection@@A=0x579af0' \
  --symbol '?Enter@CriticalSection@@QAEXXZ=0x401320' \
  --symbol '?Leave@CriticalSection@@QAEXXZ=0x401340'
```

### `List_AppendNode` (`0x4f1370`, 59 bytes)

Source: `reconstructed/match/batch08/part4/0x4f1370.c`

The winning shape re-reads the head for the loop cursor after the null check:

```cpp
Node *head = *(Node **)((char *)this + 0xbc);
if (head == 0) {
    *(Node **)((char *)this + 0xbc) = node;
    node->next = 0;
    return;
}
Node *current = *(Node **)((char *)this + 0xbc);
while (current->next != 0)
    current = current->next;
current->next = node;
node->next = 0;
```

Using `current = head` encoded the peeled first test as `mov eax,[eax+0x70]`; the
re-read keeps the cursor in ECX and matches the shipped `mov eax,[ecx+0x70]`.

## Near miss: `List_RemoveNodeLocked` (`0x544af0`, 166 bytes)

Source: `reconstructed/match/batch16/part4/nonmatching/0x544af0.cpp`

The guard/EH recipe and the whole list splice are exact. The shipped
`current == node` update uses EAX and a conditional store:

```asm
mov eax,[edi+0x10]
cmp esi,eax
jne 544b3e
mov eax,[eax+4]
mov [edi+0x10],eax
```

The candidate's best source is the null-first ternary:

```cpp
current = (current == node) ? current->next : current;
```

That reproduces the shipped EAX choice and every downstream register, but
VC6 hoists the store out of the branch, leaving one byte in the `jne`
displacement. The plain `if` keeps the conditional store but allocates EDX
instead of EAX. This is a single-byte scheduling/register residue; leave it
to a bounded permuter rather than adding a fake source trick.

## Family runner

```sh
python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/list-family/family.json \
  --out /tmp/pc2-list-family --cache /tmp/pc2-list-cache --jobs 4

# Warm run: every object reused.
python3 tools/run_family_batch.py \
  --config reconstructed/match/investigations/list-family/family.json \
  --out /tmp/pc2-list-family-warm --cache /tmp/pc2-list-cache \
  --jobs 4 --cache-only
```

## Next list-family targets

The inventory’s `List_Node_Destroy` family includes several small
constructors/destructors and list utilities. Use the family runner to score
them in groups; do not hand-match one at a time. Candidates worth extracting
next:

- `0x4014b0` siblings that use the same two-array growth layout
- the small `Player_Construct`/`Recipe_Destroy`/`UI_BriefingList_Destroy`
  destructors that call `List_Node_Destroy`
- the 43-function `List_Node_Destroy` group as a generator once the member
  layout variants are known

The payoff is a generator/spec that accepts a list member signature, field
offsets, growth increment and lock object, and emits the family member.
