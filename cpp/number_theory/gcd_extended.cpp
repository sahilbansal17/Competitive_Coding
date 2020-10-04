// Extended Euclid algorithm
template <typename T>
tuple<T, T, T> gcdExtended(T a, T b){
    if(b == 0){
        return make_tuple(a, 1, 0);
    }
    else{
        T gcd, x, y;
        tie(gcd, x, y) = gcdExtended(b, a - (a / b) * b);
        return make_tuple(gcd, y, x - (a / b) * y);
    }
}
