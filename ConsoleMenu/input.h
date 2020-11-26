#ifndef INPUT
#define INPUT

enum decision { dup, ddown, din, dnothing };

/// <summary>
///		Chek command
/// </summary>
/// <param name="_x">relative x coords</param>
/// <param name="_y">relative y coords</param>
void madeInput(int& _x, int& _y);

/// <summary>
///		Moves cursor to relative coords
/// </summary>
/// <param name="x">relative x coords</param>
/// <param name="y">relative y coords</param>
void gotoxy(int x, int y);

int input();
char pushWay();

#endif // !INPUT