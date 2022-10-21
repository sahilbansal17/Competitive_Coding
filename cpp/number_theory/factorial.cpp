template <typename T>
inline T fact(T a)
{
    return (a == 0) || (a == 1) ? 1 : fact(a - 1) * a;
}