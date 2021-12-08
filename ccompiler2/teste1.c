int gdc(int u, int v)
{
	if (v == 0)
		return u;
	else
		return gdc(v, u - u / v * v);
}
void main(void)
{
	int x;
	int y;
}