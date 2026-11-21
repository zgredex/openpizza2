void *operator new(unsigned int);
struct List { int Add(void *); };
struct GamePlan { char pad[0x30]; GamePlan(); void SetDifficulty(int); };
struct Player { int AddBranchPlan(void *); };
int Player::AddBranchPlan(void *param_1)
{
  int iVar1 = ((List *)((char *)this + 0x148))->Add(param_1);
  GamePlan *plan = new GamePlan;
  plan->SetDifficulty(2);
  *(int *)((char *)plan + 0xc) = iVar1;
  ((List *)((char *)this + 0x12c))->Add(plan);
  return iVar1;
}
