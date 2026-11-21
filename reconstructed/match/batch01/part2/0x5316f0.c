struct BinarySearch8_t { int search(int, int); };
struct Child_t { void activate(); void clear(); };

struct UI_SetChildVisibleByID_t {
  int SetChildVisibleByID(int param_1, int param_2);
};

int UI_SetChildVisibleByID_t::SetChildVisibleByID(int param_1, int param_2)
{
  int iVar1;

  iVar1 = ((BinarySearch8_t *)this)->search(param_1, 0);
  if (iVar1 == -1) {
    return 0;
  }
  if (param_2 != 0) {
    (*(Child_t **)(*(int *)((char *)this + 0xe8) + iVar1 * 8))->activate();
    return 1;
  }
  (*(Child_t **)(*(int *)((char *)this + 0xe8) + iVar1 * 8))->clear();
  return 1;
}
