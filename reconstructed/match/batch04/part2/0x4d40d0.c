/* Cost_ComputeQuantityPrice: ten-unit packs times the unit price (0x4d40d0). */
int __fastcall Cost_ComputeQuantityPrice(int *cost)
{
    return (cost[3] / 10) * cost[0xf] * 10;
}
