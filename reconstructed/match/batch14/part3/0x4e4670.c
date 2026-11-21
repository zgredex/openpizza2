/* Value_Approach (0x4e4670): moves a value toward a target by a step,
   clamping at the target and marking the value as settled. */
struct Value {
    char pad[0x10];
    double value;
    char pad2[0x1c - 0x18];
    unsigned char settled;

    void Approach(double step, double target);
};

void Value::Approach(double step, double target)
{
    double next;

    if (target > 0.0) {
        if (target <= value)
            return;
        next = step + value;
        value = next;
        if (next > target) {
            value = target;
            settled = 1;
            return;
        }
        settled = 1;
    }
    else {
        if (target >= 0.0)
            return;
        if (value <= target)
            return;
        next = step + value;
        value = next;
        if (next < target) {
            value = target;
            settled = 1;
            return;
        }
        settled = 1;
    }
}
