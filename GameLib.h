#include <Windows.h>

#ifndef GAME_H
#define GAME_H

struct ToaDo{
	int x;
	int y;
};

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height);
// Hàm tô màu.
void textcolor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);

// Hàm xóa màn hình.
void XoaManHinh();

#endif