
int gcd(unsigned int p, unsigned int q)
{
    if(p == 0)
        return q;
    if(q == 0)
        return p;
    if(p == 1 || q == 1)
        return 1;

    unsigned int r = 0;
    if(p > q) {
        r = p%q;
        return gcd(q, r);
    }
    else {
        r = q%p;
        return gcd(p, r);
    }
}
