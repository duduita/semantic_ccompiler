int baitola;
int gdc(int u, int v)
{
	if (v == 0)
		return u;
	else
		return gdc(v, u - u / v * v);
}
int pifao;
void main(void)
{
	int x;
	int y;
	x = input();
	y = input();
	output(gdc(x, y));
}
int cu;